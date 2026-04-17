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
Copy Array implementation is not correct
### Location

Line number(s) of the bugs.
Sorting.cpp Line 34
```c++
Copy of the buggy code
int* copy = ar;
```

### How the bug was located

Explain how you found the bug
I wrote the test for SimpleValuesAreSame and the warning that len wasn't being used was my first inclination. 
### Description

Describe the bug
This code creates a pointer to the same array, it does not create a new array. I'm sure the SimpleCopyWasMade would've exposed this but I completed my implementation after the first test failed. 
### Fix

Explain how you fixed the bug
To properly copy an array, you need to allocate memory using malloc of ints with length of len integers, then iterate through each element and copy the element to the new copied array, then return the new array. 
```c++
Copy of the fixed code
  int* copy = (int*)malloc(sizeof(int) * len);
  for (int i = 0; i < len; i++)
  {
    copy[i] = ar[i];
  }
  return copy;
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