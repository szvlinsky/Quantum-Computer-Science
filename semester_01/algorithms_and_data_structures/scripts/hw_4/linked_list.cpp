#include <iostream>

using namespace std;

class LinkedList {
    // Pojedyńczy element listy
    class Node {
    public:
        int key = 0;
        Node * next = nullptr;
        Node * prev = nullptr;

        Node(int key) {
            this->key = key;
        }
        friend ostream& operator<<(ostream& os, const LinkedList& obj);
    };

    Node * head = nullptr;
    Node * tail = nullptr;

// Funkcje klasy
public:
    void insert(int key);
    Node * search(int key); // zwraca wskaznik na node
    void insert_after(int j, int key);
    void insert_before(int j, int key);
    void del(int key); // funkcja delete (slowo klucz)
    void clear();
    void write_search(int key);

    friend ostream& operator<<(ostream& os, const LinkedList& obj);
};

void LinkedList::insert(int key) {
    Node * n = new Node(key);
    if(this->head == nullptr) {
        this->head = n;
        this->tail = n;
    } else {
         n->next = head;
         head->prev = n;
         head = n;
    }
}

LinkedList::Node * LinkedList::search(int key) {
    Node * x = head;
    while(x != nullptr && x->key != key) {
        x = x->next;
    }
    return x;
}

void LinkedList::insert_after(int j, int key) {
    Node * x = this->search(key);
    if(x == nullptr) {
        return;
    }

    Node * n = new Node(j);
    n->prev = x;
    n->next = x->next;
    if(x->next != nullptr) {
        x->next->prev = n;
    } else {
        tail = n;
    }
    x->next = n;
}

void LinkedList::insert_before(int j, int key) {
    Node * x = search(key);
    if(x == nullptr) {
        return;
    }

    Node * n = new Node(j);
    n->next = x;
    n->prev = x->prev;

    if(x->prev != nullptr) {
        x->prev->next = n;
    } else {
        head = n;
    }
    x->prev = n;
}
void LinkedList::del(int key) {
    Node * x = this->search(key);
    if(x == nullptr) {
        return;
    }
    if(x->prev != nullptr) {
        x->prev->next = x->next;
    } else {
        head = x->next;
    }
    if(x->next != nullptr) {
        x->next->prev = x->prev;
    } else {
        tail = x->prev;
    }

    delete x;
}

void LinkedList::clear() {
    Node * x = head;
    while(x != nullptr) {
        Node * temp = x;
        x = x->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
}

void LinkedList::write_search(int key) {
    if (search(key))
        cout << key << endl;
    else
        cout << -1 << endl;
}


ostream& operator<<(ostream& os, const LinkedList& obj) {
    LinkedList::Node * x = obj.head;
    while(x != nullptr) {
        os << x->key << " ";
        x = x->next;
    }
    os << endl;
    return os;
}

int main() {
    LinkedList l;
    cout << l;

    l.insert(1);
    l.insert(2);
    cout << l;

    l.insert(3);
    l.write_search(2);
    l.write_search(4);
    l.insert_after(4, 2);
    cout << l;

    l.del(2);
    cout << l;

    l.del(5);
    cout << l;

    l.insert_before(5, 3);
    cout << l;

    l.del(5);
    cout << l;

    l.del(1);
    cout << l;

    l.clear();
    cout << l;
    
    return 0;
}