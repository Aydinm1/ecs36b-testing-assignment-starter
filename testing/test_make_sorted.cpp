#include <cstdlib>
#include <vector>
#include "gtest/gtest.h"
#include "sorting.h"
#include "rapidcheck/gtest.h"
#include "test_helpers.h"

TEST(MakeSortedTests, SimpleSortSortedArray) {
    /*
     * Check that we can sort an array that is already sorted.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int arr[] = {1,2,3,4,5};
    make_sorted(arr,5);
    for (int i = 0; i < 5; ++i)
    {
        const int checkAnswer[] = {1,2,3,4,5};
        ASSERT_EQ(checkAnswer[i], arr[i]);
    }
}

TEST(MakeSortedTests, SimpleSortReverseSortedArray) {
    /*
     * Check that we can sort an array that is reverse sorted order.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int arr[] = {5,4,3,2,1};
    make_sorted(arr,5);
    for (int i = 0; i < 5; ++i)
    {
        const int checkAnswer[] = {1,2,3,4,5};
        ASSERT_EQ(checkAnswer[i], arr[i]);
    }
}



TEST(MakeSortedTests, SimpleSortAverageArray) {
    /*
     * Check that we can sort an array where the elements in it are in random order.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int arr[] = {3,1,5,4,2};
    make_sorted(arr,5);
    for (int i = 0; i < 5; ++i)
    {
        const int checkAnswer[] = {1,2,3,4,5};
        ASSERT_EQ(checkAnswer[i], arr[i]);
    }
}


TEST(MakeSortedTests, SimpleSortArrayWithDuplicates) {
    /*
     * Check that we can sort an array where there are duplicate elements in it.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int arr[] = {3,1,1,2,2};
    make_sorted(arr,5);
    for (int i = 0; i < 5; ++i)
    {
        const int checkAnswer[] = {1,1,2,2,3};
        ASSERT_EQ(checkAnswer[i], arr[i]);
    }

}

RC_GTEST_PROP(MakeSortedTests,
              PropertyAfterSortingValuesAreInAscendingOrder,
              ( std::vector<int> values)
) {
    /* Test that after sorting an array, the values are in ascending order
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    RC_PRE(!values.empty());
    int* arr = new int[values.size()];
    copy_vector_to_array(values,arr);
    make_sorted(arr,values.size());
    bool sorted = true;
    for (size_t i = 0; i < values.size()-1; ++i)
    {
         if(arr[i] > arr[i+1])
         {
             sorted = false;
         }
    }
    delete[] arr;
    RC_ASSERT(sorted);
}
