# Tyler Edmiston and Thomas O'Brien Homework 3

### Question 1

On our machines we get the follow memory addresses for the respective calls on a unique call.
```c++
assert(&A[0][0] == 0x10510e0d0)
assert(&A[3][7] == 0x10510e1f8)
```

Notice if a programmer were to run this code again and check the memory addresses, the location of memory is different, but still maintains the same offset.
```c++
assert(&A[0][0] == 0x10a0f50d0)
assert(&A[3][7] == 0x10a0f51f8)
```

The struct A[10][10] allocates 0x0000003f0 of memory somewhere on the stack, assuming that when the struct is called, it is called locally. Within this range, there are 100 **A** s that each have 8 bytes. The first 4 bytes of one of the A structs belongs to the integer n. This is due to integers using 4 bytes in C++. After that, the next 4 bytes in that range belongs to the character c. Note that even though it allocates 4 bytes of memory, a character will only use 1 byte to store its value. This is due to characters using 1 byte in C++. The last 3 bytes are not used for direct storage, but are still allocated to maintain consistent memory allocation.
