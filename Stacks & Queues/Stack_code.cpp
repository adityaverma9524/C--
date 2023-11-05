#include<iostream>
using namespace std;
#include "StackUsingTemplates.h"

int main() {
    StackUsingArray<char> s;
    s.push(100);
    s.push(101);
    s.push(103);
    s.push(104);
    s.push(105);

    cout << s.top() << endl;

    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    cout << "size : " << s.size() << endl;

    cout << "isEmpty : " << s.isEmpty() << endl;
}