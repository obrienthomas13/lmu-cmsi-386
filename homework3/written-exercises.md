# Tyler Edmiston and Thomas O'Brien Homework 3

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
assert(b[0] == 0x7fff517b48d0)
assert(&b[0] == 0x7fff517b48b0)
assert(*b[0] == 1232.2)
assert(b[1] == 0x7fff517b48d8)
assert(&b[1] == 0x7fff517b48b8)
assert(*b[1] == 400.21)
// And so on...
```
