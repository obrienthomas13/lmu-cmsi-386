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

  Node* copy(Node* n) {
    delete;
    return new Node {n->data, n->next ? copy(n->next) : nullptr};
  }


public:

  Queue(const Queue& a) = delete;
  void operator=(const Queue& a) = delete;
  ~Queue() {
    while (head != nullptr) {
      pop();
    }
  }

  Queue() = default;

  int get_size() {
    return size;
  }

  T get_tail() {
    return tail->data;
  }

  void enqueue(T x) {
    Node newTail = new Node {x, tail};
    tail = &newTail;
    size++;
  }

  T dequeue() {
    Node* nodeToDelete = head;
    T valueToReturn = head->data;
    delete nodeToDelete;

    Node findNewHead = *tail;
    while(findNewHead.next != nullptr) {
      findNewHead = *(findNewHead.next);
    }
    head = &findNewHead;
    size--;
    return valueToReturn;
  }

};

int main() {
  Queue<int> s;
  assert(s.get_size() == 0);
  s.enqueue(100);
  assert(s.get_tail() == 100);
  assert(s.get_size() == 1);
  s.enqueue(200);
  assert(s.get_tail() == 200);
  assert(s.get_size() == 2);
  assert(s.dequeue() == 200);
  assert(s.get_size() == 1);
  assert(s.dequeue() == 100);
  assert(s.get_size() == 0);
  s.enqueue(300);
  s.enqueue(400);

  cout << "All tests passed\n";

  // Queue<int> t = s;   // COPY CONSTRUCTOR

}
