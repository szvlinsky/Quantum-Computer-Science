#include <iostream>
using namespace std;

class Stack {
private:
    int data[5];
    int top = 0;

public:
    void push(int k) {
        if (top >= 5) {
            cout << "nadmiar" << endl;
            return;
        }
        data[top++] = k;
    }

    void pop() {
        if (top > 0)
            top--;
    }

    bool stack_empty() {
        return top == 0;
    }

    void write() { // WRITE(S)
        for (int i = 0; i < top; i++)
            cout << data[i] << " ";
        cout << endl;
    }

    void write_pop() { // WRITE(POP(S))
        if (top == 0) {
            cout << "niedomiar" << endl;
            return;
        }
        cout << data[top - 1] << endl;
        pop();
    }

    void write_empty() { // WRITE(STACK-EMPTY(S))
        cout << boolalpha << stack_empty() << endl;
    }
};

class Queue {
private:
    int data[6];
    int length = 6;
    int head = 0;
    int tail = 0;
public:
    void enqueue(int k) {
        if ((tail + 1) % length == head) {
            cout << "nadmiar" << endl;
            return;
        }
        data[tail] = k;
        tail = (tail + 1) % length;
    }

    void dequeue() {
        if (head != tail) {
            head = (head + 1) % length;
        }
    }

    bool queue_empty() {
        return head == tail;
    }

    void write() { // WRITE(Q)
        int i = head;
        while (i != tail) {
            cout << data[i] << " ";
            i = (i + 1) % length;
        }
        cout << endl;
    }

    void write_dequeue() { // WRITE(DEQUEUE(Q))
        if (head == tail) {
            cout << "niedomiar" << endl;
            return;
        }
        cout << data[head] << endl;
        dequeue();
    }

    void write_empty() { // WRITE(QUEUE-EMPTY(Q))
        cout << boolalpha << queue_empty() << endl;
    }
};



int main() {
    // STACK
    Stack s;

    s.push(1);
    s.push(2);
    s.write();

    s.push(3);
    s.write();

    s.write_empty(); // false

    s.push(4);
    s.push(5);
    s.push(6); // nadmiar

    s.write_pop();
    s.write_pop();
    s.write_pop();
    s.write_pop();
    s.write();

    s.write_pop();
    s.write_pop(); // niedomiar
    s.write();
    s.write_empty(); // true

    // QUEUE
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.write();

    q.enqueue(3);
    q.write();

    q.write_empty(); // false
    q.write_dequeue();
    q.write_dequeue();
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8); // nadmiar

    q.write();
    q.write_dequeue();
    q.write_dequeue();
    q.write_dequeue();
    q.write_dequeue();
    q.write_dequeue();
    q.write_dequeue(); // niedomiar

    q.write();
    q.write_empty(); // true
}