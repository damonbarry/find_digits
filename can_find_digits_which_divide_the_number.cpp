#include "stdafx.h"
#include "CppUnitTest.h"
#include "find_digits.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace find_digits { namespace tests
{
    TEST_CLASS(can_find_digits_which_divide_number)
    {
    public:

        TEST_METHOD(a_digit_should_divide_the_number)
        {
            bool divides = number_divides(5, 10);
            Assert::AreEqual(true, divides);
        }

        TEST_METHOD(a_digit_should_not_divide_the_number)
        {
            bool divides = number_divides(7, 10);
            Assert::AreEqual(false, divides);
        }

    };
}}
