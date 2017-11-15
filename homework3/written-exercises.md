# Tyler Edmiston, Thomas O'Brien and Eddie Azinge Homework 3

### Question 1

On our machines we get the follow memory addresses for the respective calls on a unique call.
```c++
assert(&A[0][0] == 0x10510e0d0);
assert(&A[3][7] == 0x10510e1f8);
```

Notice if a programmer were to run this code again and check the memory addresses, the location of memory is different, but still maintains the same offset.
```c++
assert(&A[0][0] == 0x10a0f50d0);
assert(&A[3][7] == 0x10a0f51f8);
```

The struct A[10][10] allocates 0x0000003f0 of memory somewhere on the stack, assuming that when the struct is called, it is called locally. Within this range, there are 100 **A**s that each have 8 bytes. The first 4 bytes of one of the A structs belongs to the integer n. This is due to integers using 4 bytes in C++. After that, the next 4 bytes in that range belongs to the character c. Note that even though it allocates 4 bytes of memory, a character will only use 1 byte to store its value. This is due to characters using 1 byte in C++. The last 3 bytes are not used for direct storage, but are still allocated to maintain consistent memory allocation.

### Question 2

```c++
double *a[n];
```

&ast;a[n] creates an array of pointers of length n. In order to populate &ast;a[n] with values, each index must be filled with the memory address of some value. Once given a value a[x], while x is some integer within &ast;a[n]'s range, will return the memory address that was given to it. &a[x] will return the memory address of a[x] itself. &ast;a[x] will point the value found at the memory address given to a[x]. This behavior is shown below.

```c++
double a[4] = {1232.2, 400.21, 2.0, 9.4};
double *b[4];
for (int i = 0; i < 4; i++) {
  b[i] = &a[i];
}
assert(b[0] == 0x7fff517b48d0);
assert(&b[0] == 0x7fff517b48b0);
assert(*b[0] == 1232.2);
assert(b[1] == 0x7fff517b48d8);
assert(&b[1] == 0x7fff517b48b8);
assert(*b[1] == 400.21);
// And so on...
```

```c++
double (*b)[n];
```
(&ast;b)[n] creates a pointer to an empty array of double values that has a length of n. The behavior is shown below.

```c++
double (*b)[4];
assert((*b)[0] == 0);
assert(&(*b)[0] == 0x7fff5074f838);
assert((*b)[1] == 4.94066e-324);
assert(&(*b)[1] == 0x7fff5074f840);
// And so on...
```

```c++
double (*c[n])();
```
((&ast;c[n])() creates an array of n pointers to functions that return doubles.

```c++
double (*d())[n];
```
(&ast;d())[n] creates a function that returns a pointer to an array of n doubles.

### Question 3

```c++
double (*f(double (*)(double, double[]), double)) (double, ...);
```

This declaration is easier when viewed as 3 separate parts.

`double (*) (double, double[])`

describes a function pointer that accepts a double and a double array and returns a double.

We'll call this function pointer innerFunction.

`*f(innerFunction, double)`

creates a pointer to a function called f that accepts a function pointer (defined by innerFunction) and a double, with it's return type specified by the next part.

We'll call this intermediary state outerFunction

`double (outerFunction) (double, ...)`

modifies the return type of f to be a function that accepts a double followed by a variable number of arguments.

### Question 4

A **Derived** object will contain two **b** fields. Not only that, but both **b** fields from a **Derived** object and its parent **Base** class are accessible. It is important to note that since both **b** fields are public, they are capable of being accessed and manipulated. Looking at the code snippet below, the second line is how to get the **b** field from the **Derived** class while the third line is the **b** field from the **Base** class.

```c++
Derived sampleDerived = Derived();
// sampleDerived.b
// sampleDerived.Base::b
```
Since the field **b** within the **Derived** class is a public field, a programmer is able to directly access and manipulate it through the dot notation.

To gain access to the field **b** within the **Base** class is more tricky. This **b** is not in the direct scope of a **Derived** object, but rather in its parent class **Base**. To gain access, the programming must use the dot notation and then refer specifically to the scope of the **Base** class by using _Base::_. Now since the previous statement refers to the scope of the **Base** class, the programmer can access and manipulate the proper field **b**.

### Question 5

The result of the following program is as follows.
```shell
>>> g++ -std=c++14 question5.cpp && ./a.out
2
5
2
```

The reason for this output is due to C++ being **statically scoped**. In a statically scoped language, the value of a function or variable depends both on the location of the source code and where named function or variable is defined within the program. Look at the C++ program, **int x** is first defined global at the beginning of the program. After the function **f()** simply prints out x, which is equal to **2** at declaration. Next, the function **g()** defined **int x** internally to be equal to **5**, calls the function **f()**, and then prints out x. When the function **f()** is called within **g()**, **f()** will still print out **2**, despite **int x** being equal to **5** within **g()**. This is due to function **f()** printing **2** at declaration, thus this cannot change. However, when function **g()** prints out x in the end, this prints out **5** due to **int x** being modified within the scope of function **g()**. Lastly within, the function **main()**, after calling function **g()** and printing out the previously described results, **main()** prints out x as well. In this case since **int x** is not internally called within the function **main()**, the program looks up one level of hierarchy and sees **int x** equal to 2, thus printing out 2. This same behavior can be replicated in Javascript, another statically scoped language.

```js
let x = 2;
const f = () => { console.log(x); };
const g = () => { let x = 5; f(); console.log(x); };
g();
console.log(x);
```
```shell
>>> node question5.js
2
5
2
```

If C++ were to be a **dynamically scoped** language, then the output would be the following.

```shell
>>> g++ -std=c++14 question5.cpp && ./a.out
5
5
2
```

The reason for this is that the value of **int x** within the various functions would not be necessarily defined at declaration. When the function **g()** is called within the function **main()**, this would then modify **int x** to be equal to 5. Then when function **f()** is called within **g()**, **f()** would print out 5 instead due to the value being modified. The print statement within **g()** would still print out 5. Back to the function **main()**, the print statement would now print 2 due to the initial **int x** being set to it and never being modified within that scope.

This behavior can also be seen in Perl, a programming language that is dynamically scoped.

```perl
local $x = 2;
sub f { print "$x\n"; }
sub g { local $x = 5; f(); print "$x\n"; }
g();
print "$x\n";
```
```shell
>>> perl question5.pl
5
5
2
```

### Question 6

```c++
// This is the function signature for a raw array
template <typename T>
void scramble(T theArray[], int size) {}

// This is a function signature for a std::array
template <typename Y, size_t N>
void scramble(std::array<Y, N>& theArray) {}
```

In C++, **raw arrays** are just pointers to a memory address. They do not store a size value, so you must pass size in as a parameter.
**std::array**s, on the other hand, have **size()** as a function. Though when defining the function signature, it requires you define the size. We must use a template *size_t* named *N* to allow variable sized **std:array**s to be passed in.
