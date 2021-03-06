#include "stdafx.h"
#include "CppUnitTest.h"
#include "find_digits.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace find_digits { namespace tests
{
    TEST_CLASS(can_count_digits_which_divide_the_number)
    {
    public:
        
        TEST_METHOD(should_find_two_divisor_digits_in_24)
        {
            uint32_t count = number("24").count_divisor_digits();
            Assert::AreEqual(2U, count);
        }

        TEST_METHOD(should_find_one_divisor_digit_in_32)
        {
            uint32_t count = number("32").count_divisor_digits();
            Assert::AreEqual(1U, count);
        }

        TEST_METHOD(should_not_find_any_divisor_digits_in_23)
        {
            uint32_t count = number("23").count_divisor_digits();
            Assert::AreEqual(0U, count);
        }

        TEST_METHOD(repeated_divisor_digits_should_be_counted)
        {
            uint32_t count = number("22222").count_divisor_digits();
            Assert::AreEqual(5U, count);
        }
    };
}}
