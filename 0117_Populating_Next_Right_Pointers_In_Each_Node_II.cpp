#include <iostream>
using namespace std;

// Definition for binary tree with next pointer.
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
class Solution {
  public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *head = root; // head of the treeLinklist for next level
        TreeLinkNode *prev = NULL; // previous node to connect to current child
        TreeLinkNode *cur = NULL; // current node working on 
        // checking if the is more treeLinkedlist to connect
        while (head) {
            cur = head; // we are on new level, start connection this level's children
            head = NULL;
            while (cur) {
                // connection left child
                if (cur->left) {
                    if (!prev)
                        head = cur->left; // next level head
                    else
                        prev->next = cur->left;
                    prev = cur->left;
                }
                //connection right child
                if (cur->right) {
                    if (!prev)
                        head = cur->right; // next level head
                    else
                        prev->next = cur->right;
                    prev = cur->right;
                }
                //Going to the new node of current level
                cur = cur->next;
            }
            prev = NULL;
        }
    }
};

int main() {
    TreeLinkNode *one = new TreeLinkNode(1);
    TreeLinkNode *two = new TreeLinkNode(2);
    TreeLinkNode *three = new TreeLinkNode(3);
    one->left = two;
    one->right = three;
    Solution t;
    t.connect(one);
}