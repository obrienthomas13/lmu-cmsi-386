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

  // Node* copy(Node* n) {
  //   return new Node {n->data, n->next ? copy(n->next) : nullptr};
  // }


public:
  // initial assignment
  Queue() = default;
  // copy constructor
  Queue(const Queue& a) = delete;
  // copy assignment
  void operator=(const Queue& a) = delete;



  // move constructor
  Queue(Queue&& other): size(other.size), tail(other.tail), head(other.head) {
    other.tail = nullptr;
    other.head = nullptr;
  }
  // move assignment
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
  // deconstructor
  ~Queue() {
    // cout << "head->data: " << head->data << "\n";
    // cout << "tail->data: " << tail->data << "\n";
    // cout << "size: " << size << "\n";
    while (head != nullptr) {
      // cout << "inside while loop\n";
      dequeue();
    }
    // cout << "size: " << size << "\n";
    // cout << "tail->data: " << tail->data << "\n";
    // delete tail;
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
    // cout << "tail: " << tail << "\n";
    if (tail == nullptr) {
      throw std::underflow_error("Empty queue");
    }
    // cout << "tail: " << tail << "\n";
    return tail->data;
  }

  T get_head() {
    if (head == nullptr) {
      throw std::underflow_error("Empty queue");
    }
    // cout << "head: " << head << "\n";
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
    // if (head->next == nullptr) {
    //   tail = newHead;
    // }
    size--;
    return valueToReturn;
  }

};
