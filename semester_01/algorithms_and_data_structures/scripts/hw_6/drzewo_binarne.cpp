#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

class Tree {
    class Node {
        int key; // można wartości tutaj np key = 0, ale korzystamy z listy inicjalizacyjnej
        Node* p;
        Node* left;
        Node* right;

    public:
        Node(int key);
        void setP(Node* x) {this->p = x;} //setter dla p, żeby nie wyrzucało błędów
        void setLeft(Node* x) {this->left = x;}
        Node* getLeft() {return this->left;}
        void setRight(Node* x) {this->right = x;}
        Node* getRight() {return this->right;}
        int getKey() {return this->key;}
    };
    Node* root = nullptr;
    void walkTree(Node* x, ostream& o, int d = 0) const;
    void preorderRec(Node* x) const;
    void inorderRec(Node* x) const;
    void postorderRec(Node* x) const;
    void clearRec(Node* x);

public:
    Tree(int n); //robi za komende makeTree
    friend ostream& operator<<(ostream& o, const Tree& t);
    ~Tree(); //destruktor zamiast funkcji clear

    void clear() {
        if (!root) return;
        clearRec(root);
        root = nullptr;
    }

    void preorder_Tree()  { preorderRec(root); cout << endl; }
    void inorder_Tree()   { inorderRec(root); cout << endl; }
    void postorder_Tree() { postorderRec(root); cout << endl; }
};

Tree::Tree(int n) {
    for(int i = 0; i<n; i++) {
        int key = rand() % 100 + 1;
        Tree::Node* nowynode = new Node(key);

        if (this->root == nullptr) {
            this-> root = nowynode;
        }
        else {
            Tree::Node* x = this->root;
            Tree::Node* y = nullptr;
            int r = 0;

            while (x != nullptr) {
                r = rand() % 2; // 0 => left, 1 => right
                y = x;
                if(r == 0){ 
                    x = x->getLeft();
                }
                else {
                    x = x->getRight();
                }
            }
            nowynode -> setP(y);
            if(r == 0) {
                y->setLeft(nowynode);
            }
            else {
                y->setRight(nowynode);
            }
        }
    }
}

Tree::Node::Node(int key): key(key), p(nullptr), left(nullptr), right(nullptr) { //lista inicjalizująca
    // cout << "new Node:" << key << endl;
}

ostream& operator<<(ostream& o, const Tree& t) {
    t.walkTree(t.root, o);
    return o;
}

void Tree::walkTree(Tree::Node* x, ostream& o, int d) const{
    if(x != nullptr) {
        walkTree(x->getLeft(), o, d + 1);

        for(int i = 0; i < d; i++) {
            o << '\t';
        }
        o << x->getKey() << endl;
        walkTree(x->getRight(), o, d + 1);
    }
}

void Tree::preorderRec(Node* x) const {
    if (!x) return;
    cout << x->getKey() << ' ';
    preorderRec(x->getLeft());
    preorderRec(x->getRight());
}

void Tree::inorderRec(Node* x) const {
    if (!x) return;
    inorderRec(x->getLeft());
    cout << x->getKey() << ' ';
    inorderRec(x->getRight());
}

void Tree::postorderRec(Node* x) const {
    if (!x) return;
    postorderRec(x->getLeft());
    postorderRec(x->getRight());
    cout << x->getKey() << ' ';
}

void Tree::clearRec(Node* x) {
    if (!x) return;
    clearRec(x->getLeft());
    clearRec(x->getRight());
    // cout << "delete Node: " << x->getKey() << endl;
    delete x;
}

Tree::~Tree() {
    clear();
}

int main() {
    srand(time(NULL));
    Tree t(10);
    cout << t;

    t.preorder_Tree();
    t.inorder_Tree();
    t.postorder_Tree();

    t.clear();
    cout << t;

    return 0;
}