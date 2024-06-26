#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    char op;
    Node* left;
    Node* right;

    Node(char o): op(o), left(nullptr), right(nullptr) {}

    ~Node() {
        delete left;
        delete right;
        this->left = nullptr;
        this->right = nullptr;
        this->op = '\0';
    }
};

class ExpressionTree {
private:
    Node* root;

public:
    ExpressionTree(): root(nullptr) {}

    void fromPrefixNotation(const string& expression) {
        stack<Node*> operations;
        Node* curr = root;
        for (char c : expression) {
            if (!curr) {
                curr = new Node(c);
                if (!root) {root = curr;}
                operations.emplace(curr);
                continue;
            }

            if (!curr->left) {
                curr->left = new Node(c);
                // Change current operation if c is an operator
                if (!isalnum(c)) {
                    curr = curr->left;
                    operations.emplace(curr);
                }
            } else if (!curr->right) {
                curr->right = new Node(c);
                // Remove operator from stack because it already has 2 operands
                operations.pop();
                if (!isalnum(c)) {
                    curr = curr->right;
                    operations.emplace(curr);
                } else {
                    if (!operations.empty())
                        curr = operations.top();
                }
            }
        }
    }

    void __postfix(Node* node) {
        if (!node) return;

        __postfix(node->left, order);
        __postfix(node->right, order);
        cout << node->op;
    }

    void postfix() {
        __postfix(this->root);
        cout << endl;
    }

    void clear() {
        delete this->root;
        this->root = nullptr;
    }
};


int main() {
    ExpressionTree et;
    et.fromPrefixNotation("+--a*bc/def");
    cout << "POST ORDER: ";
    et.postfix();
    et.clear();
    return 0;
}
