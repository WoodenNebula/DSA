#include <iostream>
#include ".\LinkedList.h"

int main() {

    LinkedList list;
    list.PrintAllValue();
    list.Push(0);
    list.Push(1);
    list.Push(2);
    list.Push(3);

    unsigned int ind = list.GetListLength();
    std::cout << "Indexed Push at " << ind - 1 << ":\n";
    list.InsertAt(ind - 1, ind * 10);
    list.PrintAllValue();


    ind = list.GetListLength();
    std::cout << "Indexed Pop at " << ind - 1 << ":\n";
    list.DeleteAt(ind - 1);
    list.PrintAllValue();


    std::cout << "\nPush:\n";
    ind = list.GetListLength();
    list.Push(ind * 10);
    list.PrintAllValue();

    std::cout << "Pop:\n";
    list.Pop();
    list.PrintAllValue();


    std::cout << "\n\nIndexed Shift:\n";
    list.InsertAt(0, 10);
    list.PrintAllValue();

    std::cout << "Indexed Unshift:\n";
    list.DeleteAt(0);
    list.PrintAllValue();


    std::cout << "\nShift:\n";
    list.Shift(10);
    list.PrintAllValue();

    std::cout << "Unshift:\n" << std::endl;
    list.Unshift();
    list.PrintAllValue();


    std::cout << "\n\nInserting aroung middle:\n";
    unsigned int index = (int)(list.GetListLength() / 2);
    list.InsertAt(index, index + 1);
    list.PrintAllValue();

    std::cout << "\nDeleting that index data:\n";
    list.DeleteAt(index);
    list.PrintAllValue();


    return 0;
}