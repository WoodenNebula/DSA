#include <iostream>
#include "stack.h"

template <typename T>
void PeekAt(const Stack<T>& stack) {
    if (auto ret = stack.Peek()) {
        std::cout << "At Top = " << ret.value() << "\n";
    }
    else {
        std::cout << "Empty Stack\n";
    }
}


int main() {
    Stack<std::string> myStack;
    PeekAt(myStack);

    std::cout << "Popped = " << myStack.Pop().value_or("Nothing") << std::endl;

    myStack.Push("First");
    myStack.Push("In");
    myStack.Push("Last");
    myStack.Push("Out");

    myStack.StackTraceView();

    std::cout << "Popped = " << myStack.Pop().value_or("Nothing") << std::endl;

    myStack.StackTraceView();
    PeekAt<std::string>(myStack);

    myStack.Reset();

}