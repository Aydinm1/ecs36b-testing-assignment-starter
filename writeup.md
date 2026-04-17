# Google Test And Debugging Writeup

## Things I Thought To Test
1. An array of the same number
2. An array with elements that are not integers
3. Test if the inputs are properly read
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

You need to swap the values by dereferencing the values. temp does not need to be a pointer, the value of temp should be the value at memory location of a. Then set the value at mem address a to be the val at mem address b. Lastly, we have to set the value at mem address b to be temp. 

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
This code creates a pointer to the same array, it does not create a new array. I'm sure the SimpleCopyWasMade would've exposed this, but I completed my implementation after the first test failed. 
### Fix

Explain how you fixed the bug

To properly copy an array, you need to allocate memory using malloc of ints with length of len integers, 
then iterate through each element and copy the element to the new copied array, then return the new array. 
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
Minimum Index Array implementation was not right
### Location
Sorting.ccp Lines 56-61
Line number(s) of the bugs.

```c++
Copy of the buggy code
  int min_index = 0;

  for (int i = 1; i < len; ++i) {
    if (ar[i] > ar[min_index]) {
      min_index = i;
    }
  }
  return ar[min_index];
```

### How the bug was located

Explain how you found the bug
My test SimpleMinIndexAtFrontOfArray failed. 
### Description

Describe the bug
The if statement checks to see if arr[i] is greater than arr[min_index] but really we want to find the smallest value so we have to check if arr[i] < arr[min_index]
We are returning the value of the array at min_index instead of min_index. This one tripped me up for a bit as I could not figure out what was wrong with my implementation until it clicked.
### Fix

Explain how you fixed the bug
I flipped the equality to be less than, returned min_index
```c++
Copy of the fixed code
  int min_index = 0;

  for (int i = 1; i < len; ++i) {
    if (ar[i] < ar[min_index]) {
      min_index = i;
    }
  }
  return min_index;
```