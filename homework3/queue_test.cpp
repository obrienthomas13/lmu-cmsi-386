#include <iostream>
#include <string>
#include <cassert>
#include "queue.h"

using namespace std;

/*
 * There is no way to test for copying or assignment being prohibited in the unit test.
 * This is because both are compile time errors, so we cannot test for these errors.
 */

void test_empty_queue_has_zero_size() {
  Queue<string> q;
  assert(q.get_size() == 0);
}

void test_some_insertions_and_deletions() {
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
}

void test_no_copies() {
  Queue<int> p;
  Queue<int> q;
  // No way to test this at run time, but uncomment the following lines
  // and look for compile time errors.
  // p = q;
  // Queue<int> r(p);
}

Queue<int> one_two_three() {
  Queue<int> q;
  for (int i = 1; i <= 3; i++) q.enqueue(i);
  return q;
}

void test_moves() {
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
}

void test_dequeue_from_empty_queue_throws_underflow_error() {
  Queue<bool> q;
  try {
    q.dequeue();
    assert(false);
  } catch (const underflow_error& ue) {
    assert(true);
  } catch (...) {
    // Caught the wrong exception
    assert(false);
  }
}

void test_enqueue_then_dequeue_then_enqueue() {
  Queue<int> q;
  assert(q.get_size() == 0);
  q.enqueue(100);
  assert(q.get_tail() == 100);
  assert(q.get_head() == 100);
  assert(q.get_size() == 1);
  q.enqueue(200);
  assert(q.get_tail() == 200);
  assert(q.get_head() == 100);
  assert(q.get_size() == 2);
  q.dequeue();
  assert(q.get_tail() == 200);
  assert(q.get_head() == 200);
  assert(q.get_size() == 1);
  q.dequeue();
  assert(q.get_size() == 0);
  q.enqueue(300);
  assert(q.get_tail() == 300);
  assert(q.get_head() == 300);
  assert(q.get_size() == 1);
}

int main() {
  test_empty_queue_has_zero_size();
  test_some_insertions_and_deletions();
  test_dequeue_from_empty_queue_throws_underflow_error();
  test_no_copies();
  test_moves();
  test_enqueue_then_dequeue_then_enqueue();
  cout << "All tests passed\n";
}
