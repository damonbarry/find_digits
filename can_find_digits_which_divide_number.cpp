#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace find_digits
{
    bool number_divides(size_t divisor, size_t dividend)
    {
        return true;
    }

    namespace tests
    {
        TEST_CLASS(can_find_digits_which_divide_number)
        {
        public:

            TEST_METHOD(a_digit_which_divides_the_number_is_added_to_the_list)
            {
                bool divides = number_divides(5, 10);
                Assert::AreEqual(true, divides);
            }

        };
    }
}
