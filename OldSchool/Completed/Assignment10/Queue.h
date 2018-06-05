#ifndef _Queue_h_
#define _Queue_h_

template <class T>
class Queue;

template <class T>
class QueueNode
{
    friend class Queue<T>;

private:
    QueueNode() : element(), next(nullptr), previous(nullptr) {}
    QueueNode(const T & e, QueueNode * next0, QueueNode * previous0);

    T element;
    QueueNode<T> * next;
    QueueNode<T> * previous;
};

template <class T>
QueueNode<T>::QueueNode(const T & e, QueueNode * next0, QueueNode * previous0) : element(e), next(next0), previous(previous0) {}

template <class T>
class Queue
{
public:
    Queue();
    Queue(const Queue<T> & q);
    ~Queue();

    int size() const { return size_; }

    bool empty() { return (size_ == 0); }

    T front() { return p_head_node->next->element; }

    T pop();

    void push(const T & e);

    void clear();

    Queue<T> & operator=(const Queue<T> & rhs);

private:
    int size_ = 0;
    QueueNode<T> * p_head_node;
};

template <class T>
inline Queue<T>::Queue()
{
    p_head_node = new QueueNode<T>;
    p_head_node->next = p_head_node->previous = p_head_node;
}

template <class T>
Queue<T>::Queue(const Queue<T> & q) : Queue<T>()
{
    QueueNode<T> * p_q_head_node = q.p_head_node;
    QueueNode<T> * p_location = p_q_head_node->next;
    while (p_location != p_q_head_node)
    {
        push(p_location->element);
        p_location = p_location->next;
    }
}

template <class T>
Queue<T>::~Queue()
{
    clear();
    delete p_head_node;
}

template <class T>
inline T Queue<T>::pop()
{
    QueueNode<T> * p_first_node = p_head_node->next;
    T first_element = p_first_node->element;
    QueueNode<T> * p_new_first_node = p_first_node->next;
    p_head_node->next = p_new_first_node;
    p_new_first_node->previous = p_head_node;
    p_first_node->next = p_first_node->previous = nullptr;
    delete p_first_node;
    --size_;
    return first_element;
}

template <class T>
inline void Queue<T>::push(const T & e)
{
    QueueNode<T> * p_last_node = p_head_node->previous;
    QueueNode<T> * p_new_node = new QueueNode<T>(e, p_head_node, p_last_node);
    p_last_node->next = p_new_node;
    p_head_node->previous = p_new_node;
    ++size_;
}

template <class T>
inline void Queue<T>::clear()
{
    while (!(empty())) pop();
}

template <class T>
inline Queue<T> & Queue<T>::operator=(const Queue<T> & rhs)
{
    clear();
    Queue<T> copy_of_rhs = rhs;
    QueueNode<T> * p_location = copy_of_rhs.p_head_node->next;
    while (p_location != copy_of_rhs.p_head_node)
    {
        push(p_location->element);
        p_location = p_location->next;
    }
    return *this;
}

#endif
