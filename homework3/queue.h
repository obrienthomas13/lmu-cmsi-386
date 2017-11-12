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

  Queue(const Queue& a) = delete;
  void operator=(const Queue& a) = delete;

  ~Queue() {
    cout << "head->data: " << head->data << "\n";
    cout << "tail->data: " << tail->data << "\n";
    cout << "size: " << size << "\n";
    while (head != nullptr) {
      dequeue();
    }
    cout << "size: " << size << "\n";
    cout << "tail->data: " << tail->data << "\n";
    // delete tail;
  }

  Queue() = default;

  int get_size() {
    return size;
  }

  T get_tail() {
    return tail->data;
  }

  T get_head() {
    return head->data;
  }

  void enqueue(T x) {
    Node* newTail = new Node {x, nullptr};
    if (tail != nullptr) {
      tail->next = newTail;
    } else {
      head = newTail;
    }
    tail = newTail;
    size++;
  }

  T dequeue() {
    // cout << "Running dequeue\n";
    Node* newHead = head->next;
    T valueToReturn = head->data;
    // if (head == tail) {
    //   cout << "I'M HAPPENING\n";
    //   delete tail;
    // }
    // cout << "1\n";
    delete head;
    // cout << "2\n";
    head = newHead;
    size--;
    return valueToReturn;
  }

};
