#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
class Stack {
private:
    vector<T> items;

public:
    void push(T item);
    T pop();
    T peek() const;
    bool isEmpty() const;
    int size() const;
};

int main() {
    Stack<int> s1;

    s1.push(10);
    s1.push(20);
    s1.push(30); 
    (!s1.isEmpty()) ? cout << "Top (peek): " << s1.peek() << "\n" : cout << "Error: Stack is empty!\n";
    cout << "Size: " << s1.size() << "\n";
    (!s1.isEmpty()) ? cout << "Popped: " << s1.pop() << "\n" : cout << "Error: Stack is empty!\n";
    cout << "Size after pop: " << s1.size() << "\n";

    cout << "\n";

    Stack<string> s2;

    s2.push("hello");
    s2.push("abc");
    (!s2.isEmpty()) ? cout << "Top (peek): " << s2.peek() << "\n" : cout << "Error: Stack is empty!\n";
    cout << "Size: " << s2.size() << "\n";
    (!s2.isEmpty()) ? cout << "Popped: " << s2.pop() << "\n" : cout << "Error: Stack is empty!\n";
    cout << "Size after pop: " << s2.size() << "\n";

    cout << "\n";

    Stack<double> s3;
    s3.push(1.0);
    (!s3.isEmpty()) ? cout << "Top (peek): " << s3.peek() << "\n" : cout << "Error: Stack is empty!\n";
    cout << "Size: " << s3.size() << "\n";
    (!s3.isEmpty()) ? cout << "Popped: " << s3.pop() << "\n" : cout << "Error: Stack is empty!\n";
    cout << "Size after pop: " << s3.size() << "\n";

    cout << "\n";

    Stack<int> s4;

    (!s4.isEmpty()) ? cout << "Top (peek): " << s4.peek() << "\n" : cout << "Error: Stack is empty!\n";
    cout << "Size: " << s4.size() << "\n";
    (!s4.isEmpty()) ? cout << "Popped: " << s4.pop() << "\n" : cout << "Error: Stack is empty!\n";
    cout << "Size after pop: " << s4.size() << "\n";

    return 0;
}

template <typename T>
void Stack<T> :: push(T item) {
    items.push_back(item);
    cout << "Pushed: " << item << "\n";
}

template <typename T>
T Stack<T>::pop() {
    if (items.empty()) {
        cout << "Error: Stack is empty!\n";
        return T();   
    }
    T top = items.back();
    items.pop_back();
    return top;
}

template <typename T>
T Stack<T> :: peek() const {return items.back();}

template <typename T>
bool Stack<T> :: isEmpty() const {return (size() == 0);}

template <typename T>
int Stack<T> :: size() const {return items.size();}
