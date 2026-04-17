#include <cstdlib>
#include <ranges>
#include <string>
#include "gtest/gtest.h"
#include "formatting.h"
#include "test_helpers.h"
#include "rapidcheck/gtest.h"

auto word_generator() {
    /* Creates a generator for a string made up of
     * characters from [a - z]
     */
    return rc::gen::container<std::string>(
        rc::gen::map(rc::gen::inRange<int>('a','z'+1),[](int c) { return static_cast<char>(c);}));
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
    std::vector<int> values = {10,-3,25};
    std::vector<std::string> arg_strings = vector_of_ints_to_vector_of_strings(values);
    std::vector<std::string> all_args = {"program"};
    std::vector<char*> argv;
    for (const std::string& s : arg_strings) {
        all_args.push_back(s);
    }

    for (std::string&s: all_args)
    {
        argv.push_back(s.data());
    }
    int* ar_out= nullptr;
    int len_out = 0;
    parse_args(argv.size(), argv.data(),&ar_out, &len_out);

    bool len_correct = (len_out == 3);
    bool values_correct = (ar_out != nullptr);
    EXPECT_TRUE(elements_in_vector_and_array_are_same(values,ar_out));
    free(ar_out);
    ASSERT_EQ(len_correct, true);
    ASSERT_EQ(values_correct, true);

}

TEST(ParseArgsTests, SimpleCheckParseNoArgs) {
    /*
     * Check that you parse you can successfully parse "no" command line arguments.
     */
    std::vector<std::string> all_args = {"program"};
    std::vector<char*> argv;
    for (std::string& s : all_args)
    {
        argv.push_back(s.data());
    }
    int* ar_out= nullptr;
    int len_out = -1;
    parse_args(argv.size(), argv.data(), &ar_out, &len_out);
    bool len_correct = (len_out == 0);
    bool values_correct = (ar_out == nullptr);
    free(ar_out);
    ASSERT_EQ(len_correct, true);
    ASSERT_EQ(values_correct, true);


}


RC_GTEST_PROP(ParseArgsTests,
              PropertyCheckArgumentsParsedSuccessfully,
              ()
) {
    /* Check that we can correctly parse the command line
     * arguments when we receive 1 or more arguments.
     * Don't forget to free any memory that was dynamically allocated as part of this test
     */
    auto values = *rc::gen::arbitrary<std::vector<int>>();
    RC_PRE(!values.empty());
    std::vector<std::string> const arg_strings = vector_of_ints_to_vector_of_strings(values);
    std::string const word = *word_generator();
    std::vector<std::string> all_args = {word};
    std::vector<char*> argv;
    for (const std::string& s : arg_strings) {
        all_args.push_back(s);
    }

    for (std::string&s: all_args)
    {
        argv.push_back(s.data());
    }
    int* ar_out= nullptr;
    int len_out = 0;
    parse_args(argv.size(), argv.data(),&ar_out, &len_out);
    bool len_correct = (len_out == static_cast<int>(values.size()));
    bool values_correct = (ar_out != nullptr) && elements_in_vector_and_array_are_same(values,ar_out);
    free(ar_out);
    RC_ASSERT(len_correct);
    RC_ASSERT(values_correct);
}

RC_GTEST_PROP(ParseArgsTests,
              PropertyCheckParseNoArgs,
              ()
) {
    /*
     * Check that you parse you can successfully parse "no" command line arguments.
     */
    std::vector<std::string> all_args = {*word_generator()};
    std::vector<char*> argv;
    for (std::string& s : all_args)
    {
        argv.push_back(s.data());
    }
    int* ar_out= nullptr;
    int len_out = -1;
    parse_args(argv.size(), argv.data(), &ar_out, &len_out);
    bool len_correct = (len_out == 0);
    bool values_correct = (ar_out == nullptr);
    free(ar_out);
    RC_ASSERT(len_correct);
    RC_ASSERT(values_correct);
}
