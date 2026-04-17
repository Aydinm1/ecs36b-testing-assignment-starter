#include <cstdlib>
#include <string>
#include "gtest/gtest.h"
#include "formatting.h"
#include "test_helpers.h"
#include "rapidcheck/gtest.h"

auto word_generator() {
    /* Creates a generator for a string made up of
     * characters from [a - z]
     */
    return rc::gen::string<std::string>();
}

auto vector_of_ints_to_vector_of_strings(const std::vector<int>& numbers) {
    /* Create a vector of strings from a vector of ints
     */
    std::vector<std::string> result;
    for (int value: numbers)
    {
        result.push_back(std::to_string(value));
    }
    return result;
}


TEST(ParseArgsTests, SimpleCheckArgumentsParsedSuccessfully) {
    /*
     * Check that you parse the command line arguments correctly.
     * (ar_out and len_out are set to the right values).
     * Don't forget to free any memory that was dynamically allocated as part of your test.'
     */
    char program[] = "program";
    char arg1[] = "10";
    char arg2[] = "-3";
    char arg3[] = "25";
    char* argv[] = {program, arg1, arg2,arg3};
    int* ar_out= nullptr;
    int len_out = 0;
    parse_args(4, argv,&ar_out, &len_out);

    ASSERT_EQ(len_out, 3);
    ASSERT_NE(ar_out, nullptr);
    EXPECT_EQ(ar_out[0], 10);
    EXPECT_EQ(ar_out[1], -3);
    EXPECT_EQ(ar_out[2], 25);
    free(ar_out);

}

TEST(ParseArgsTests, SimpleCheckParseNoArgs) {
    /*
     * Check that you parse you can successfully parse "no" command line arguments.
     */
    char program[] = "program";
    char* argv[] = {program};
    int* ar_out= nullptr;
    int len_out = -1;
    parse_args(1, argv, &ar_out, &len_out);

    ASSERT_EQ(len_out, 0);
    ASSERT_EQ(ar_out, nullptr);
    free(ar_out);

}


RC_GTEST_PROP(ParseArgsTests,
              PropertyCheckArgumentsParsedSuccessfully,
              ()
) {
    /* Check that we can correctly parse the command line
     * arguments when we receive 1 or more arguments.
     * Don't forget to free any memory that was dynamically allocated as part of this test
     */
}

RC_GTEST_PROP(ParseArgsTests,
              PropertyCheckParseNoArgs,
              ()
) {
    /*
     * Check that you parse you can successfully parse "no" command line arguments.
     */
}
