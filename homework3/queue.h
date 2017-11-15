#include <cassert>
#include <iostream>
using namespace std;

template <typename T>
class Queue {
  struct Node {
    T data;
    Node* next;
  };
  int size = 0;
  Node* tail = nullptr;
  Node* head = nullptr;

public:
  Queue() = default;
  Queue(const Queue& a) = delete;
  void operator=(const Queue& a) = delete;
  Queue(Queue&& other): size(other.size), tail(other.tail), head(other.head) {
    other.tail = nullptr;
    other.head = nullptr;
  }
  Queue& operator=(Queue&& other) {
    if (&other == this) {
      return *this;
    }
    delete tail;
    delete head;
    size = other.size;
    tail = other.tail;
    head = other.head;
    other.tail = nullptr;
    other.head = nullptr;
    return *this;
  }
  ~Queue() {
    while (head != nullptr) {
      dequeue();
    }
  }

  friend std::ostream& operator<< (std::ostream& os, const Queue& Q){
    Node* tempHead = Q.head;
    if(tempHead != nullptr) {
        os << tempHead->data << " ";

    }
    while(tempHead->next != nullptr) {
      tempHead = tempHead->next;
      os << tempHead->data << " ";
    }
    return os;
  }

  int get_size() {
    return size;
  }

  T get_tail() {
    if (tail == nullptr) {
      throw std::underflow_error("No tail");
    }
    return tail->data;
  }

  T get_head() {
    if (head == nullptr) {
      throw std::underflow_error("No head");
    }
    return head->data;
  }

  void enqueue(T x) {
    Node* newTail = new Node {x, nullptr};
    if (head != nullptr) {
      tail->next = newTail;
    } else {
      head = newTail;
    }
    tail = newTail;
    size++;
  }

  T dequeue() {
    if (head == nullptr) {
      throw std::underflow_error("Empty queue");
    }
    Node* newHead = head->next;
    T valueToReturn = head->data;
    delete head;
    head = newHead;
    size--;
    return valueToReturn;
  }
};
