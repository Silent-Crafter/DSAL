#include <bits/stdc++.h>
using namespace std;

class AVLNode {
public:
    string word;
    string definition;
    int balanceFactor;
    AVLNode *left, *right;

    AVLNode(string w, string d, int b): word(w), definition(d), balanceFactor(b), left(nullptr), right(nullptr) {}
};

class AVLTree {
private:
    AVLNode* root;

public:

    AVLTree(): root(nullptr) {}

    AVLNode* __insert(AVLNode* node, string w, string d) {
        if (!node) return(new AVLNode(w, d, 0));

        if (w < node->word)
            node->left = __insert(node->left, w, d);
        else if (w > node->word)
            node->right = __insert(node->right, w, d);
        else
            return node;

        node->balanceFactor = 1 + max(__height(node->left), __height(node->right));

        int balance = calculateBalance(node);

        if (balance > 1 && w < node->left->word)
            return RR(node);

        if (balance < -1 && w > node->right->word)
            return LL(node);

        if (balance > 1 && w > node->left->word) {
            node->left = LL(node->left);
            return RR(node);
        }

        if (balance < -1 && w < node->right->word) {
            node->right = RR(node->right);
            return LL(node);
        }

        return node;
    }

    void insert(string w, string d) {
        this->root = __insert(root, w, d);
    }

    AVLNode* search(string w) {
        if (!root) return nullptr;

        AVLNode* curr = root;
        while (curr) {
            if (curr->word == w) {
                return curr;
            } else if (w < curr->word) {
                curr = curr->left;
            } else if (w > curr->word) {
                curr = curr->right;
            }
        }

        return curr;
    }

    AVLNode* __remove(AVLNode* node, string w) {
        if (!node) return nullptr;

        AVLNode* temp;
        if (w > node->word) {
            node->right = __remove(node->right, w);
            if (calculateBalance(node) == 2) {
                if (calculateBalance(node->left) >= 0)
                    node = RR(node);
                else {
                    node->left = LL(node->left);
                    node = RR(node);
                }
            }
        } else if (w < node->word) {
            node->left = __remove(node->left, w);
            if (calculateBalance(node) == -2) {
                if (calculateBalance(node->right) <= 0)
                    node = LL(node);
                else {
                    node->right = RR(node->right);
                    node = LL(node);
                }
            }
        } else {
            if (!node->right)
                return node->left;

            temp = node->right;
            while (temp->left)
                temp = temp->left;

            node->word = temp->word;
            node->right = __remove(node->right, temp->word);
            if (calculateBalance(node) == 2) {
                if (calculateBalance(node->left) >= 0)
                    node = RR(node);
                else {
                    node->left = LL(node->left);
                    node = RR(node);
                }
            }
        }
        node->balanceFactor = __height(node);
        return node;
    }

    void remove(string w) { __remove(this->root, w); }

    int height() {
        return __height(this->root);
    }

    int __height(AVLNode* node) {
        if (!node) {
            return 0;
        }

        int leftHeight = __height(node->left);
        int rightHeight = __height(node->right);

        return max(leftHeight, rightHeight) + 1;
    }

    int calculateBalance(AVLNode* node) {
        if (!node) return 0;
        return __height(node->left) - __height(node->right);
    }

    AVLNode* RR(AVLNode* node) {
        AVLNode* x = node->left;
        AVLNode* y = x->right;

        x->right = node;
        node->left = y;

        node->balanceFactor = calculateBalance(node);
        x->balanceFactor = calculateBalance(x);

        return x;
    }

    AVLNode* LL(AVLNode* node) {
        AVLNode* x = node->right;
        AVLNode* y = x->left;

        x->left = node;
        node->right = y;

        node->balanceFactor = calculateBalance(node);
        x->balanceFactor = calculateBalance(x);

        return x;
    }


    // OPTIONAL FUNCTION
    void __inorder(AVLNode *node){
        if (!node) return;
        __inorder(node->left);
        cout << "( " << node->word << ": " << node->definition << " ) ";
        __inorder(node->right);
    }

    inline void inorder() { __inorder(this->root); cout << endl; }
};

int main() {
    AVLTree dict;

    dict.insert("yo", "greeting");
    dict.insert("imo", "in my opinion");
    dict.insert("rn", "right now");
    dict.insert("ig", "i guess");

    if (dict.search("wg")) {
        cout << "Found " << endl;
    } else {
        cout << "Not Found" << endl;
    }

    dict.inorder();
    dict.remove("imo");
    dict.inorder();

    return 0;
}
