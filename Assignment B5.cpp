/*
 * A book consists of chapters, chapters consist of sections
 * and sections consist of subsections. Construct a tree and
 * print the nodes. Find the time and space requirements of your method.
 */

#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    string data;
    vector<Node*> children;

    Node(string d = "") {
        this->data = std::move(d);
    }

    Node* addChild(string d) {
        Node* temp = new Node(std::move(d));
        this->children.push_back(temp);
        return temp;
    }

    friend class Tree;
};

class Tree {
private:
    Node *root;

public:
    Tree(string d) {
        root = new Node(std::move(d));
    }

    Node* addChild(string d) {
        return root->addChild(std::move(d));
    }

    void display() {
        cout << "Book Name: " << root->data << endl;
        auto chapter = root->children.begin();
        for (int i = 0 ; i < root->children.size() ; i++, chapter++ ) {
            cout << "Chapter " << i+1 << ": " << (*chapter)->data << endl;
            auto section = (*chapter)->children.begin();
            for (int j = 0 ; j < (*chapter)->children.size() ; j++, section++ ) {
                cout << "\t" << i+1 << "." <<  j+1 << ": " << (*section)->data << endl;
                auto subsection = (*section)->children.begin();
                for (int k = 0 ; k < (*section)->children.size() ; k++, subsection++) {
                   cout << "\t\t" << i+1 << "." <<  j+1 << "." << k+1 << ": " << (*subsection)->data << endl;
                }
            }
        }
    }
};

int main() {
    auto* book = new Tree("DSA");

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

    book->display();

    return 0;
}
