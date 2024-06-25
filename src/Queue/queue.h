#include <vector>
#include <exception>
#include <optional>

template <typename T>
class Queue {
public:
    Queue(const std::vector<T>& array);
    ~Queue();

    void Enqueue(T value);

    std::optional<T> Dequeue();

    std::optional<T> Peek() const;

    void Reset();

    inline size_t GetLength() const { return m_Length; }

private:
    struct QNode {
        T value;
        QNode* next;

        QNode(T val) : value(val), next(nullptr) {}
    };

    QNode* m_Head = nullptr;
    QNode* m_Tail = nullptr;

    size_t m_Length = 0;
};


template <typename T>
Queue<T>::Queue(const std::vector<T>& array) {
    for (int i = 0; i < array.size(); i++) {
        this->Enqueue(array[i]);
    }
}


template <typename T>
void Queue<T>::Enqueue(T value) {
    if (m_Head == nullptr) {
        m_Head = new QNode(value);
        m_Tail = m_Head;
    }
    else {
        m_Tail->next = new QNode(value);
        m_Tail = m_Tail->next;
    }
    m_Length++;
}


template <typename T>
std::optional<T> Queue<T>::Dequeue() {
    if (m_Head != nullptr) {
        QNode* oldHead = m_Head;
        T retVal = oldHead->value;

        m_Head = oldHead->next;

        delete oldHead;

        m_Length--;
        return retVal;
    }
    return {};
}


template <typename T>
std::optional<T> Queue<T>::Peek() const {
    if (m_Head != nullptr)
        return m_Head->value;
    else
        return {};
}


template <typename T>
void Queue<T>::Reset() {
    while (m_Length) {
        Dequeue();
    }
}


template <typename T>
Queue<T>::~Queue() { Reset(); }