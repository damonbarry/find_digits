#include "stdafx.h"
#include "CppUnitTest.h"
#include <iterator>
#include <cstdlib>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace find_digits
{
    struct number
    {
        size_t value;
        size_t digits;
    };

    struct number_exception {};

    number parse_number(const string& in)
    {
        const char* begin = in.c_str();
        char* end;
        unsigned long num = strtoul(begin, &end, 0);
        if (num == 0 && begin == end) throw number_exception {};
        return number { num, distance(begin, static_cast<const char*>(end)) };
    }

    namespace tests
    {
        TEST_CLASS(can_decompose_the_number)
        {
        public:

            TEST_METHOD(should_determine_the_number_from_the_string_input)
            {
                auto num = parse_number("12345");
                Assert::AreEqual(12345U, num.value);
            }

            TEST_METHOD(should_throw_if_the_input_is_not_a_number)
            {
                Assert::ExpectException<number_exception>([]{
                    parse_number("abc");
                });
            }

            TEST_METHOD(should_recognize_zero_as_a_number)
            {
                auto num = parse_number("0");
                Assert::AreEqual(0U, num.value);
            }

            TEST_METHOD(should_determine_the_number_of_digits_from_the_string_input)
            {
                auto num = parse_number("12345");
                Assert::AreEqual(5U, num.digits);
            }

        };
    }
}