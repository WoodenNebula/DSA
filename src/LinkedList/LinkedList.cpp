#include "LinkedList.h"

int LinkedList::operator[](unsigned int index) {
    if (index > m_ListLength - 1) {
        std::cerr << "Index doesnot exist!" << std::endl;
    }
    // Ensure the list is not emmpty
    else if (m_Head == nullptr) {
        std::cerr << "Empty List" << std::endl;
        return 0;
    }

    m_Traverser = m_Head;

    for (unsigned int i = 0; i != index; i++) {
        Node::MoveFwd(m_Traverser);
    }

    m_Traverser = nullptr;
    return m_Traverser->GetData();
}


void LinkedList::PrintAllValue() {
    if (m_Head != nullptr) {
        m_Traverser = m_Head;
        std::cout << "[ ";
        while (!(m_Traverser->IsAtEnd() || m_Traverser->_initialized == false)) {
            std::cout << m_Traverser->GetData() << " , ";
            Node::MoveFwd(m_Traverser);
        }

        std::cout << m_Traverser->GetData() << " ]" << std::endl;
    }
    else std::cout << "[ ]" << std::endl;

    m_Traverser = nullptr;
}

void LinkedList::InsertAt(unsigned int index, int data) {
    if (index > m_ListLength || index < 0) {
        std::cerr << "Index doesnot exist!" << std::endl;
        std::terminate();
    }
    else if (index == 0) {
        Shift(data);
    }
    else if (index == m_ListLength - 1) {
        Push(data);
    }
    else if (m_Head != nullptr) {
        m_Traverser = m_Head;

        // inserts after the current index, so loop ends 1 step before
        for (unsigned int i = 0; i < index - 1; i++) {
            Node::MoveFwd(m_Traverser);
        }

        Node* temp = new Node(data);
        temp->Next = m_Traverser->Next;
        m_Traverser->Next = temp;

        m_Traverser = nullptr;
        m_ListLength++;
    }
}

void LinkedList::Shift(int intData) {
    if (m_Head == nullptr)
        m_Head = new Node(intData);
    else {
        m_Traverser = m_Head;
        m_Head = new Node(intData);
        m_Head->Next = m_Traverser;
    }

    m_Traverser = nullptr;
    m_ListLength++;
}


void LinkedList::Unshift() {
    if (m_Head == nullptr)
        throw "List is Empty!";
    else {
        m_Traverser = m_Head;
        Node::MoveFwd(m_Head);
        delete m_Traverser;
        m_Traverser = nullptr;
    }
    m_ListLength--;
}


void LinkedList::Push(int intData) {
    // Ensure the head is not emmpty
    if (m_Head == nullptr) {
        m_Head = new Node(intData);
    }
    else {
        m_Traverser = m_Head;

        // Loop till we are at the last index
        while (!(m_Traverser->IsAtEnd())) {
            Node::MoveFwd(m_Traverser);
        }

        // We are at the last index, so make a new node and insert there
        m_Traverser->Next = new Node(intData);
    }

    m_Traverser = nullptr;
    m_ListLength++;
}


void LinkedList::Pop() {
    if (m_Head == nullptr)
        throw "List is Empty!";
    else {
        m_Traverser = m_Head;
        while (!(m_Traverser->Next->IsAtEnd()))
            Node::MoveFwd(m_Traverser);

        delete m_Traverser->Next;
        m_Traverser->Next = nullptr;
        m_Traverser = nullptr;
    }
    m_ListLength--;
}


void LinkedList::DeleteAt(unsigned int index) {
    if (index > m_ListLength - 1) {
        std::cerr << "Index doesnot exist!" << std::endl;
    }
    else if (index == 0) { Unshift(); }
    else if (index == m_ListLength - 1) { Pop(); }
    else if (m_Head != nullptr) {
        m_Traverser = m_Head;

        for (unsigned int i = 0; i < index - 1; i++) {
            Node::MoveFwd(m_Traverser);
        }

        Node* temp = m_Traverser->Next->Next;
        delete m_Traverser->Next;
        m_Traverser->Next = temp;

        m_Traverser = nullptr;
        m_ListLength--;
    }
}


void LinkedList::Clear() {
    if (m_Head != nullptr) {
        while (!(m_Head->IsAtEnd())) {
            m_Traverser = m_Head;
            Node::MoveFwd(m_Head);

            delete m_Traverser;
            m_Traverser = nullptr;
        }
        delete m_Head;
        m_Head = nullptr;
    }
    m_ListLength = 0;
}
