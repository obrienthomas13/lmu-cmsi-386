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
  // These will cause compliation errors, hence why they are commented out
  // f("Hello")("there")
  // f("Hello")(1)()
	cout << "All tests passed!" << "\n";
}
