#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
    Stack s1(StackContainer::List);
    s1.push(1);
    s1.push(2);
    cout << s1.size() << "\n";
    s1.pop();
    cout << s1.size()<< "\n";
	cout << s1.top() << "\n";
    bool flag = s1.isEmpty();
    if(flag)
        cout << "true";
    else
        cout << "false";
	system("pause");

    return 0;
}
