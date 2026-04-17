# Google Test And Debugging Writeup

## Things I Thought To Test
1. An array of the same number
2. An array with elements that are not integers
3. The inputs are properly parsed
...

## Bugs

### Bug 1
Swap is Wrong
### Location
Sorting.cpp
Line number(s) of the bugs.
Lines 71-73
```c++
Copy of the buggy code
int* temp = a;
a = b;
b = temp;
```

### How the bug was located

Explain how you found the bug
I wrote the SimpleSwapTwoValues test and it failed. 
### Description

Describe the bug

if we have int x=2 and y=3 and use the swap(&x,&y),
a will point to x and b to y. When the code runs, a points to y and b points to x but the values of x is still 2 and the value of y is still 3 because the local variables change but not the actual values. 

### Fix 

Explain how you fixed the bug

You need to swap the values by dereferencing the values. temp does not need to be a pointer, the value of temp should be the value at memory location of a. Then set the value at  mem address a to be the val at mem address b. Lastly, we have to set the value at mem address b to be temp. 

```c++
Fixed Code:
int temp = *a;
*a = *b;
*b = temp;
```

### Bug 2

### Location

Line number(s) of the bugs.

```c++
Copy of the buggy code
```

### How the bug was located

Explain how you found the bug

### Description

Describe the bug

### Fix

Explain how you fixed the bug

```c++
Copy of the fixed code
```

### Bug 3

### Location

Line number(s) of the bugs.

```c++
Copy of the buggy code
```

### How the bug was located

Explain how you found the bug

### Description

Describe the bug

### Fix

Explain how you fixed the bug

```c++
Copy of the fixed code
```