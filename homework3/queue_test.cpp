#include <iostream>
#include <string>
#include <cassert>
#include "queue.h"

using namespace std;

void test_empty_queue_has_zero_size() {
  cout << "Start Test 1\n";
  Queue<string> q;
  assert(q.get_size() == 0);
  cout << "Test 1\n";
}

void test_some_insertions_and_deletions() {
  cout << "Start Test 2\n";
  Queue<string> q;
  q.enqueue("one");
  assert(q.get_size() == 1);
  q.enqueue("two");
  q.enqueue("three");
  assert(q.get_size() == 3);
  assert(q.dequeue() == "one");
  assert(q.get_size() == 2);
  assert(q.dequeue() == "two");
  assert(q.dequeue() == "three");
  q.enqueue("four");
  assert(q.get_size() == 1);
  cout << "Test 2\n";
}

void test_no_copies() {
  cout << "Start Test 3\n";
  Queue<int> p;
  Queue<int> q;
  // No way to test this at run time, but uncomment the following lines
  // and look for compile time errors.
  // p = q;
  // Queue<int> r(p);
  cout << "Test 3\n";
}

Queue<int> one_two_three() {
  Queue<int> q;
  for (int i = 1; i <= 3; i++) q.enqueue(i);
  return q;
}

void test_moves() {
  cout << "Start Test 4\n";
  // Assignment of a temporary is a move
  Queue<int> p = Queue<int>();

  // Construction via a function return call is a move
  Queue<int> q = one_two_three();
  assert(q.get_size() == 3);
  assert(q.dequeue() == 1);

  // Test move assignment
  q = one_two_three();
  assert(q.get_size() == 3);
  assert(q.dequeue() == 1);
  cout << "Test 4\n";
}

void test_dequeue_from_empty_queue_throws_underflow_error() {
  cout << "Start Test5\n";
  Queue<bool> q;
  try {
    q.dequeue();
    assert(false);
  } catch (const underflow_error& ue) {
    assert(true);
    cout << "Test5\n";
  } catch (...) {
    // Caught the wrong exception
    assert(false);
  }
}

int main() {
  cout << "before1\n";
  test_empty_queue_has_zero_size();
  cout << "before2\n";
  test_some_insertions_and_deletions();
  cout << "before3\n";
  test_dequeue_from_empty_queue_throws_underflow_error();
  cout << "before4\n";
  test_no_copies();
  cout << "before5\n";
  test_moves();
  cout << "All tests passed\n";
}
