#include <cstdlib>
#include "gtest/gtest.h"
#include "sorting.h"
#include "test_helpers.h"
#include "rapidcheck/gtest.h"

TEST(GetSortedTests, SimpleSortSortedArray) {
    /*
     * Check that we can sort an array that is already sorted.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int arr[] = {1,2,3,4,5};
    int* sortedarr = get_sorted(arr,5);
    for (int i = 0; i < 5; ++i)
    {
        const int checkAnswer[] = {1,2,3,4,5};
        ASSERT_EQ(checkAnswer[i], sortedarr[i]);
    }
    free(sortedarr);
}


TEST(GetSortedTests, SimpleSortReverseSortedArray) {
    /*
     * Check that we can sort an array that is reverse sorted order.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int arr[] = {5,4,3,2,1};
    int* sortedarr = get_sorted(arr,5);
    for (int i = 0; i < 5; ++i)
    {
        const int checkAnswer[] = {1,2,3,4,5};
        ASSERT_EQ(checkAnswer[i], sortedarr[i]);
    }
    free(sortedarr);

}

TEST(GetSortedTests, SimpleSortAverageArray) {
    /*
     * Check that we can sort an array where the elements in it are in random order.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int arr[] = {3,1,5,4,2};
    int* sortedarr = get_sorted(arr,5);
    for (int i = 0; i < 5; ++i)
    {
        const int checkAnswer[] = {1,2,3,4,5};
        ASSERT_EQ(checkAnswer[i], sortedarr[i]);
    }
    free(sortedarr);

}

TEST(GetSortedTests, SimpleSortArrayWithDuplicates) {
    /*
     * Check that we can sort an array where there are duplicate elements in it.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int arr[] = {3,1,1,2,2};
    int* sortedarr = get_sorted(arr,5);
    for (int i = 0; i < 5; ++i)
    {
        const int checkAnswer[] = {1,1,2,2,3};
        ASSERT_EQ(checkAnswer[i], sortedarr[i]);
    }
    free(sortedarr);


}

TEST(GetSortedTests, SimpleOriginalDoesNotChange) {
    /*
     * Check that the original array was not modified.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int arr[] = {3,1,1,2,2};
    int* sortedarr = get_sorted(arr,5);
    for (int i = 0; i < 5; ++i)
    {
        const int checkAnswer[] = {3,1,1,2,2};
        ASSERT_EQ(checkAnswer[i], arr[i]);
    }
    free(sortedarr);



}

TEST(GetSortedTests, SimpleCopyWasMade) {
    /*
     * Check that the sorted array is copy of the original array in sorted order.
     * (ar and copy point to different locations in memory and no parts of the two arrays overlap)
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int arr[] = {3,1,1,2,2};
    int* sortedarr = get_sorted(arr,5);
    EXPECT_NE(sortedarr, arr);
    free(sortedarr);


}


RC_GTEST_PROP(GetSortedTests,
              PropertyAfterSortingValuesAreInAscendingOrder,
              ( std::vector<int> values)
) {
    /* Check that after sorting an array, the values are in ascending order
     * Don't forget to free any memory that was dynamically allocated as part of this test
     */
    (void)values;

}

RC_GTEST_PROP(GetSortedTests,
              PropertyOriginalDoesNotChange,
              (const std::vector<int>&values)
) {
    /*
     * Check that the original array was not modified.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    (void)values;
}

RC_GTEST_PROP(GetSortedTests,
              PropertyCopyWasMade,
              (const std::vector<int>&values)
) {
    /*
     * Check that the sorted array is copy of the original array in sorted order.
     * (ar and copy point to different locations in memory and no parts of the two arrays overlap)
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    (void)values;

}











