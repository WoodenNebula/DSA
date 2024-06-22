#pragma once
#include <iostream>

struct Node {
    Node* Next;
    int m_Data;
    bool _initialized;

    Node() :Next(nullptr), _initialized(false) {}

    Node(int data)
        :Next(nullptr), _initialized(true) {
        m_Data = data;
    }

    int GetData() { return m_Data; }

    bool IsAtEnd() { return (Next == nullptr ? true : false); }

    static void MoveFwd(Node*& node) {
        if (node->Next != nullptr)
            node = node->Next;
        else
            std::cerr << "Node is at end! Can't Move forward" << std::endl;
    }

};


class LinkedList {
public:
    LinkedList()
        :m_Head(nullptr), m_Traverser(m_Head), m_ListLength(0) {}

    inline unsigned int GetListLength() const { return m_ListLength; }

    void Shift(int intData);
    void Unshift();

    void Push(int intData);
    void Pop();

    void InsertAt(unsigned int index, int data);

    void DeleteAt(unsigned int index);

    void Clear();

    void PrintAllValue();

    int operator[](unsigned int index);


private:
    Node* m_Head;
    Node* m_Traverser;

    unsigned int m_ListLength;
};