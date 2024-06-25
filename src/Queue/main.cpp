#include <iostream>
#include "queue.h"

template <typename T>
void PeekAt(const Queue<T>& queue) {
    if (auto ret = queue.Peek()) {
        std::cout << "At Head = " << ret.value() << "\n";
    }
    else {
        std::cout << "Empty Queue\n";
    }
}


int main() {
    std::vector<char> queList = { 'a', 'b' , 'c', 'd', 'e' };
    Queue<char> myQueue(queList);

    std::cout << "Head = " << myQueue.Peek().value() << "\n";
    std::cout << "Dequed = " << myQueue.Dequeue().value() << "\n";
    std::cout << "Dequed = " << myQueue.Dequeue().value() << "\n";
    std::cout << "Dequed = " << myQueue.Dequeue().value() << "\n";
    std::cout << "Dequed = " << myQueue.Dequeue().value() << "\n";

    PeekAt(myQueue);

    std::cout << "Reseting and then Peeking at Queue" << std::endl;
    myQueue.Reset();
    PeekAt(myQueue);

    std::cout << "Queing '5'\n";
    myQueue.Enqueue('5');
    PeekAt(myQueue);
    myQueue.Dequeue();
    PeekAt(myQueue);

}