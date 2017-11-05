#include <iostream>
#include <cassert>
#include <string>

using namespace std;

struct Sayer {
private:
    string say = "";
public:
    Sayer(string s = ""): say(s) {}

    Sayer operator()(string next) {
        return (say == "") ? Sayer(next) : Sayer (say + " " + next);
    }

    string operator()() {
        return say;
    }
} f;

int main() {
  assert(f() == "");
  assert(f("Our")("Toal")("and")("Savior")() == "Our Toal and Savior");
  assert(f("Our")() == "Our");
  // assert(f("Hello")("there") == NULL);
  // assert(f("Hello")(1)() == NULL);
	cout << "All tests passed!" << "\n";
}
