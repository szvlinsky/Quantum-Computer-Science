#include <iostream>
using namespace std;

class Heap {
    int data[20];
    int len;
    int heapSize;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void maxHeapify(int i);

public:
    Heap(int tab[], int n);
    void buildMaxHeap();
    void insert(int key);
    int maximum() const;
    int extractMax();
    void increaseKey(int i, int key);

    friend ostream& operator<<(ostream& o, const Heap& h);
};

Heap::Heap(int tab[], int n) {
    for (int i = 0; i < n; i++)
        data[i] = tab[i];
    len = heapSize = n;
    buildMaxHeap();
}

void Heap::maxHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int largest = i;

    if (l < heapSize && data[l] > data[largest]) largest = l;
    if (r < heapSize && data[r] > data[largest]) largest = r;

    if (largest != i) {
        swap(data[i], data[largest]);
        maxHeapify(largest);
    }
}

void Heap::buildMaxHeap() {
    for (int i = heapSize / 2 - 1; i >= 0; i--)
        maxHeapify(i);
}

int Heap::maximum() const {
    return data[0];
}

int Heap::extractMax() {
    int max = data[0];
    data[0] = data[--heapSize];
    maxHeapify(0);
    return max;
}

void Heap::increaseKey(int i, int key) {
    data[i] = key;
    while (i > 0 && data[parent(i)] < data[i]) {
        swap(data[i], data[parent(i)]);
        i = parent(i);
    }
}

void Heap::insert(int key) {
    data[heapSize] = -1;
    heapSize++;
    increaseKey(heapSize - 1, key);
}

ostream& operator<<(ostream& o, const Heap& h) {
    for (int i = 0; i < h.heapSize; i++)
        o << h.data[i] << " ";
    o << endl;
    return o;
}

int main() {
    constexpr int size = 10;
    int tab[size] = {4,1,3,2,16,9,10,14,8,7};

    Heap h(tab, size);

    cout << h;                     // 16 14 10 8 7 9 3 2 4 1
    h.insert(15);
    cout << h;                     // 16 15 10 8 14 9 3 2 4 1 7
    cout << h.maximum() << endl;   // 16
    cout << h;                     
    cout << h.extractMax() << endl;// 16
    cout << h;                     // 15 14 10 8 7 9 3 2 4 1
    h.increaseKey(4, 19);
    cout << h;                     // 19 15 10 14 7 9 3 2 4 1
}
