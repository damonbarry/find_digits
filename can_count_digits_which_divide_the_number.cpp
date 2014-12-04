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
            size_t count = number("24").count_divisor_digits();
            Assert::AreEqual(2U, count);
        }

    };
}}
