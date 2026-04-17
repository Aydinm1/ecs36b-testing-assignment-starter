#include <cstdlib>
#include <vector>
#include <algorithm>
#include "test_helpers.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "sorting.h"
#include "rapidcheck/gtest.h"


TEST(SwapTests, SimpleSwapTwoValues)
{
    /*
     * Swap two values and see if the swap was successful.
     */
    int a = 2;
    int b = 3;
    swap(&a, &b);
    EXPECT_EQ(a, 3);
    ASSERT_EQ(b, 2);
}
TEST(SwapTests, SimpleSwapValuesInArray) {
    /*
     * Swap a few values in an array.
     * Check that the ones that swapped did swap and the ones that didn't swap
     * are still at the same locations
     */
    int values[] = {1,2,3,4};
    swap(&values[0], &values[2]);
    EXPECT_EQ(values[0], 3);
    EXPECT_EQ(values[1], 2);
    EXPECT_EQ(values[2], 1);
    ASSERT_EQ(values[3], 4);
}

RC_GTEST_PROP(SwapTests,
              PropertySwapTwoValues,
              (int a_start, int b_start)
) {
    /*
     * Swap two values and see if the swap was successful.
     */
    int a = a_start;
    int b = b_start;
    swap(&a, &b);
    RC_ASSERT(a == b_start);
    RC_ASSERT(b == a_start);
}


RC_GTEST_PROP(SwapTests,
              PropertySwapValuesInArray,
              (const std::vector<int>& values)
) {
    /*
     * Swap two values in an array. See that they swapped and the others did not
     */
    int* arr = new int[values.size()];
    copy_vector_to_array(values, arr);
    int OG_first = arr[0];
    int OG_last = arr[values.size()-1];
    swap(&arr[0], &arr[values.size()-1]);
    RC_ASSERT(arr[0] == OG_last);
    RC_ASSERT(arr[values.size()-1] == OG_first);

    for (size_t i=1;i<values.size();i++)
    {
        RC_ASSERT(arr[i] == values[i]);
    }


}
