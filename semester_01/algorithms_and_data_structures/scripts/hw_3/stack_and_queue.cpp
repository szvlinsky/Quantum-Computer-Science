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
}