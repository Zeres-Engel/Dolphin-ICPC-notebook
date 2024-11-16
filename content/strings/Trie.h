/**
 * Author: Nguyen Vi Khang
 * Description: Trie implementation for binary strings
 * Time: O(N) per operation where N is string length
 */
#pragma once

struct TrieNode {
	TrieNode* child[2];
	int cnt, id;
	
	TrieNode() {
		cnt = id = 0;
		for(int i = 0;i < 2;++i) child[i] = nullptr;
	}
};

TrieNode* root = new TrieNode();

void add_string(const string &s, int id) {
	TrieNode* p = root;
	for(auto c: s) {
		int nxt = c - '0';
		if(p -> child[nxt] == nullptr) p -> child[nxt] = new TrieNode();
		p = p -> child[nxt];
		p -> cnt++; 
	}
	p -> id = id;
}

bool find_string(const string &s) {
	TrieNode* p = root;
	for(auto c: s) {
		int nxt = c - '0';
		if(p -> child[nxt] == nullptr) return false;
		p = p -> child[nxt];
	}
	return true;
}

bool del_string(TrieNode* p, const string &s, int pos) {
	if (pos != (int)s.size()) {
		int c = s[pos] - '0';
		bool is_deleted = del_string(p -> child[c], s, pos + 1);
		if(is_deleted) p -> child[c] = nullptr;
	} 
	if(p != root) {
		p -> cnt--;
		if(p -> cnt == 0) {
			delete(p);
			return true;
		}
	}
	return false;
}