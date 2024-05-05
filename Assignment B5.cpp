/*
 * A book consists of chapters, chapters consist of sections
 * and sections consist of subsections. Construct a tree and
 * print the nodes. Find the time and space requirements of your method.
 */

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    string data;
    vector<Node*> children;

    Node(string d) {
        this->data = d;
    }

    Node* addChild(string d) {
        Node* temp = new Node(std::move(d));
        this->children.push_back(temp);
        return temp;
    }
};

void display(Node* root) {
    cout << "Book Name: " << root->data << endl;
    int i = 1;
    for (auto chapter : root->children) {
        cout << "Chapter " << i << ": " << chapter->data << endl;
        int j = 1;
        for (auto section : chapter->children) {
            cout << "\t" << i << "." <<  j << ": " << section->data << endl;
            int k = 1;
            for (auto subsection : section->children) {
               cout << "\t\t" << i << "." <<  j << "." << k << ": " << subsection->data << endl;
               k++;
            }
            j++;
        }
        i++;
    }
}

int main() {
    auto* book = new Node("DSA");

    auto* chapter1 = book->addChild("HASHING");
    auto* chapter2 = book->addChild("TREES");
    auto* chapter3 = book->addChild("GRAPHS");
    auto* chapter4 = book->addChild("SEARCH TREES");
    auto* chapter5 = book->addChild("INDEXING AND MULTIWAY TREES");
    auto* chapter6 = book->addChild("FILE ORGANIZATION");

    auto* section1 = chapter1->addChild("HASH TABLE");
    auto* section2 = chapter1->addChild("SKIP LIST");

    auto* section1_2 = section1->addChild("SUBSECTION 1");
    auto* section1_3 = section1->addChild("SUBSECTION 2");

    display(book);

    return 0;
}
