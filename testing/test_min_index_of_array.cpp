#include <vector>
#include <algorithm>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "rapidcheck/gtest.h"
#include "sorting.h"
#include "test_helpers.h"

TEST(MinIndexOfArrayTests, SimpleMinIndexAtFrontOfArray)
{
    /*
     * See if we can find the index of the minimum value when it is at the front of the array
     */
    int arr[] = {1, 2, 3};
    const int min_pos = min_index_of_array(arr, 3);
    ASSERT_EQ(min_pos,0);
}

TEST(MinIndexOfArrayTests, SimpleMinIndexAtEndOfArray) {
    /*
     * See if we can find the index of the minimum value when it is at the end of the array
     */
    int arr[] = {3, 2, 1};
    const int min_pos = min_index_of_array(arr, 3);
    ASSERT_EQ(min_pos,2);
}

TEST(MinIndexOfArrayTests, SimpleMinIndexAtMiddleOfArray) {
    /*
     * See if we can find the index of the minimum value when it is somewhere
     * in the "middle" of the array.
     */
    int arr[] = {8, 5, 2, 1, 6, 9};
    const int min_pos = min_index_of_array(arr, 6);
    ASSERT_EQ(min_pos,3);
}

TEST(MinIndexOfArrayTests, SimpleDuplicateMinimums) {
    /*
     * See if we return the index of the first minimum in the array
     * When there are multiple values that are the minimum.
     */
    int arr[] = {1, 2, 1};
    const int min_pos = min_index_of_array(arr, 3);
    ASSERT_EQ(min_pos,0);
}

TEST(MinIndexOfArrayTests, SimpleArrayDoesNotChange) {
    /*
     * Check that finding the minimum of the array did not change the contents of the array.
     */
    int arr[] = {1, 2, 3};
    const int min_pos = min_index_of_array(arr, 3);
    ASSERT_EQ(min_pos,0);
    for (int i = 0; i < 3; i++)
    {
        ASSERT_EQ(arr[i],i+1);
    }
}


RC_GTEST_PROP(MinIndexOfArrayTests,
              PropertyFindMinIndex,
              ()) {
    /* Check that the value at the location of the minimum index
     * is not larger than any of the other values in the array
     */
    auto values = *rc::gen::arbitrary<std::vector<int>>();
    RC_PRE(!values.empty());
    int* arr = new int[values.size()];
    copy_vector_to_array(values,arr);
    int min_pos = min_index_of_array(arr, values.size());
    int min_val = arr[min_pos];
    for (size_t i = 0; i < values.size(); i++)
    {
        RC_ASSERT(min_val <= arr[i]);
    }
    delete[] arr;
}

RC_GTEST_PROP(MinIndexOfArrayTests,
              PropertyArrayDoesNotChange,
              ()) {
    /*
     * Check that finding the minimum of the array did not change the contents of the array.
     */
    auto values = *rc::gen::arbitrary<std::vector<int>>();
    RC_PRE(!values.empty());
    int* arr = new int[values.size()];
    copy_vector_to_array(values,arr);
    min_index_of_array(arr, values.size());
    for (size_t i = 0; i < values.size(); i++)
    {
        RC_ASSERT(elements_in_vector_and_array_are_same(values,arr));
    }
    delete[] arr;
}
