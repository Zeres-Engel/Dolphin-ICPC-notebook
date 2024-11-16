#pragma once

struct Node {
    int sum;
    Node *left, *right;
    Node(int sum = 0, Node* left = nullptr, Node* right = nullptr)
        : sum(sum), left(left), right(right) {}
};

class PersistentSegmentTree {
    int n; // Kích thước của mảng
    vector<Node*> roots; // Lưu trữ các phiên bản gốc

    // Hàm xây dựng cây đoạn
    Node* build(int l, int r, const vector<int>& arr) {
        if (l == r) return new Node(arr[l]);
        int mid = (l + r) / 2;
        return new Node(0, build(l, mid, arr), build(mid + 1, r, arr));
    }

    // Hàm cập nhật, trả về phiên bản gốc mới
    Node* update(Node* node, int l, int r, int idx, int value) {
        if (l == r) return new Node(value); // Nút lá mới
        int mid = (l + r) / 2;
        if (idx <= mid)
            return new Node(0, update(node->left, l, mid, idx, value), node->right);
        else
            return new Node(0, node->left, update(node->right, mid + 1, r, idx, value));
    }

    // Hàm truy vấn tổng trên đoạn
    int query(Node* node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0; // Giá trị mặc định cho tổng
        if (ql <= l && r <= qr) return node->sum;
        int mid = (l + r) / 2;
        return query(node->left, l, mid, ql, qr) + query(node->right, mid + 1, r, ql, qr);
    }

public:
    PersistentSegmentTree(const vector<int>& arr) {
        n = arr.size();
        roots.push_back(build(0, n - 1, arr)); // Tạo phiên bản gốc đầu tiên
    }

    void update(int idx, int value) {
        roots.push_back(update(roots.back(), 0, n - 1, idx, value)); // Thêm phiên bản mới
    }

    int query(int version, int l, int r) {
        return query(roots[version], 0, n - 1, l, r); // Truy vấn trên phiên bản `version`
    }
};
