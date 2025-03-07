#include <iostream>
using namespace std;

class Stack {
private:
    int* a;
    int max;
    int top;
    int size;

public:
    Stack(int capacity) {
        max = capacity;
        a = new int[capacity];
        top = -1;
        size = 0;
    }

    void push(int x) {
        if (top == max - 1) {
            return;
        }
        top++;
        a[top] = x;
        size++;
    }

    void pop() {
        if (top == -1) {
            return;
        }
        top--;
        size--;
    }

    void print() {
        if (top == -1) {
            return;
        }
        for (int i = 0; i <= top; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.pop();
    s.pop();
    s.push(5);
    s.print();
    return 0;
}
