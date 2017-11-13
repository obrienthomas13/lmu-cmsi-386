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
      cout << "inside while loop\n";
      dequeue();
    }
    // cout << "size: " << size << "\n";
    // cout << "tail->data: " << tail->data << "\n";
    // delete tail;
  }

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
    cout << "Running dequeue\n";
    if (head == nullptr) {
      throw std::underflow_error("Empty queue");
    }
    Node* newHead = head->next;
    T valueToReturn = head->data;
    // if (head == tail) {
    //   cout << "I'M HAPPENING\n";
    //   delete tail;
    // }
    cout << "1\n";
    delete head;
    cout << "2\n";
    head = newHead;
    size--;
    return valueToReturn;
  }

};

int main() {
  Queue<int> s;
  assert(s.get_size() == 0);
  s.enqueue(100);
  assert(s.get_tail() == 100);
  assert(s.get_head() == 100);
  assert(s.get_size() == 1);
  s.enqueue(200);
  assert(s.get_tail() == 200);
  assert(s.get_head() == 100);
  assert(s.get_size() == 2);
  s.enqueue(300);
  assert(s.get_tail() == 300);
  assert(s.get_head() == 100);
  assert(s.get_size() == 3);
  s.enqueue(400);
  assert(s.get_tail() == 400);
  assert(s.get_head() == 100);
  assert(s.get_size() == 4);
  s.enqueue(500);
  assert(s.get_tail() == 500);
  assert(s.get_head() == 100);
  assert(s.get_size() == 5);
  s.dequeue();
  s.dequeue();
  s.dequeue();
  s.dequeue();
  s.dequeue();
  cout << "before enqueue\n";
  s.enqueue(2);
  cout << "after enqueue\n";
  assert(s.get_tail() == 2);
  // cout << "tail\n";
  // assert(s.get_head() == 2);
  // cout << "head\n";
  // assert(s.get_size() == 1);
  // cout << "size\n";
  // assert(s.dequeue() == 200);
  // assert(s.get_size() == 1);
  // assert(s.dequeue() == 100);
  // assert(s.get_size() == 0);
  // s.enqueue(300);
  // s.enqueue(400);

  cout << "All tests passed\n";

  // Queue<int> t = s;   // COPY CONSTRUCTOR

}
