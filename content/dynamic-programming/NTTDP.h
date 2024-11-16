/**
 * Author: Nguyen Phuoc Thanh
 * License: CC0
 * Description: DP with convolution optimized using Number Theoretic Transform (NTT).
 * Time: O(N \log N)
 */
#pragma once

const int mod=998244353, root=3;
void ntt(vector<int>& a, bool inv) {
	int n=a.size(), j=0;
	for(int i=1;i<n;++i) {
		int bit=n>>1;
		for(;j&bit;bit>>=1) j^=bit;
		j^=bit; if(i<j) swap(a[i],a[j]);
	}
	for(int len=2;len<=n;len<<=1) {
		int wlen=powmod(root,(mod-1)/len);
		if(inv) wlen=powmod(wlen,mod-2);
		for(int i=0;i<n;i+=len) {
			int w=1;
			for(int j=0;j<len/2;++j) {
				int u=a[i+j], v=(int)(1LL*a[i+j+len/2]*w%mod);
				a[i+j]=u+v<mod?u+v:u+v-mod;
				a[i+j+len/2]=u-v>=0?u-v:u-v+mod;
				w=(int)(1LL*w*wlen%mod);
			}
		}
	}
	if(inv) {
		int nrev=powmod(n,mod-2);
		for(int& x:a) x=(int)(1LL*x*nrev%mod);
	}
}

void dp_ntt(vector<int>& a, vector<int>& b) {
	int n=1;
	while(n<a.size()+b.size()) n<<=1;
	a.resize(n); b.resize(n);
	ntt(a,false); ntt(b,false);
	rep(i,n) a[i]=(int)(1LL*a[i]*b[i]%mod);
	ntt(a,true);
}
