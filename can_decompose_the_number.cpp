#include "stdafx.h"
#include "CppUnitTest.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace find_digits
{
    size_t parse_number(string)
    {
        return 12345;
    }

    namespace tests
    {
        TEST_CLASS(can_decompose_the_number)
        {
        public:

            TEST_METHOD(should_can_determine_the_number_from_the_string_input)
            {
                auto num = parse_number("12345");
                Assert::AreEqual(12345U, num);
            }

        };
    }
}