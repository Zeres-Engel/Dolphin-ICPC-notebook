/**
 * Author: Nguyen Phuoc Thanh
 * License: CC0
 * Description: Grundy numbers for Green Hackenbush on trees
 * Usage: grundy(root) returns grundy number for tree rooted at root
 * Time: O(N) where N is number of nodes
 * Status: Tested
 */
#pragma once

struct TreeNode {
    vector<TreeNode*> children;
};

int grundy(TreeNode* node) {
    int x = 0;
    for (auto child : node->children)
        x ^= (1 + grundy(child));
    return x;
}
