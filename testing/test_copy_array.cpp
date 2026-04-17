#include <cstdlib>
#include <vector>
#include <algorithm>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "sorting.h"
#include "test_helpers.h"
#include "rapidcheck/gtest.h"

TEST(CopyArrayTests, SimpleValuesAreSame) {
    /*
     * Check that the values in the copy are the same as the values in the original array.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int arr[]= {1,2,3,4,5};
    int* copied_arr = copy_array(arr,5);
    for(int i=0;i<5;i++)
    {
        EXPECT_EQ(arr[i],copied_arr[i]);
    }
    free(copied_arr);

}

TEST(CopyArrayTests, SimpleOriginalDoesNotChange) {
    /*
     * Check that the  values in the original array did not change.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int arr[] = {1,2,3,4,5};
    int* copied_arr = copy_array(arr,5);
    for(int i=0;i<5;i++)
    {
        EXPECT_EQ(arr[i],i+1);
    }
    free(copied_arr);

}

TEST(CopyArrayTests, SimpleCopyWasMade) {
    /*
     * Check that a copy was actually made
     * (ar and copy point to different locations in memory and no parts of the two arrays overlap)
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int arr[] = {1,2,3,4,5};
    int* copied_arr = copy_array(arr,5);
    EXPECT_NE(arr,copied_arr);
    free(copied_arr);

}


RC_GTEST_PROP(CopyArrayTests,
              PropertyValuesAreSame,
              (const std::vector<int>& values)
) {
    /*
     * Check that the values in the copy are the same as the values in the original array.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int* arr = new int[values.size()];
    copy_vector_to_array(values, arr);
    int* copied_arr = copy_array(arr,values.size());
    EXPECT_TRUE(elements_in_vector_and_array_are_same(values, copied_arr));
    free(copied_arr);
    delete[] arr;

}

RC_GTEST_PROP(CopyArrayTests,
              PropertyOriginalDoesNotChange,
              (const std::vector<int>&values)
) {
    /*
     * Check that the  values in the original array did not change.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int* arr = new int[values.size()];
    copy_vector_to_array(values, arr);
    int* copied_arr = copy_array(arr,values.size());
    bool same = (elements_in_vector_and_array_are_same(values, arr));
    free(copied_arr);
    delete[] arr;
    RC_ASSERT(same);

}

RC_GTEST_PROP(CopyArrayTests,
              PropertyCopyWasMade,
              (const std::vector<int>&values)
) {
    /*
  * Check that a copy was actually made
  * (ar and copy point to different locations in memory and no parts of the two arrays overlap)
  * Don't forget to free any memory that was dynamically allocated as part of your test.
  */
    int* arr = new int[values.size()];
    copy_vector_to_array(values, arr);
    int* copied_arr = copy_array(arr,values.size());
    bool copy_made = (arr != copied_arr);
    free(copied_arr);
    delete[] arr;
    RC_ASSERT(copy_made);

}



