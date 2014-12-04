#include "stdafx.h"
#include "CppUnitTest.h"
#include "find_digits.hpp"
#include <stdexcept>
#include <sstream>
#include <string>
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Microsoft { namespace VisualStudio { namespace CppUnitTestFramework
{
    template<>
    wstring ToString<vector<unsigned char>>(const vector<unsigned char>& vec)
    {
        wostringstream out;
        for (auto val : vec)
        {
            out << L"{" << val << L"} ";
        }
        return out.str();
    }
}}}


namespace find_digits
{
    namespace tests
    {
        TEST_CLASS(can_decompose_the_number)
        {
        public:

            TEST_METHOD(should_determine_the_number_from_the_string_input)
            {
                auto num = number::parse("12345");
                Assert::AreEqual(12345U, num.value);
            }

            TEST_METHOD(should_recognize_a_number_with_preceding_whitespace)
            {
                auto num = number::parse(" 12345");
                Assert::AreEqual(12345U, num.value);
            }

            TEST_METHOD(should_throw_if_the_input_is_not_a_number)
            {
                Assert::ExpectException<invalid_argument>([]{
                    number::parse("abc");
                });
            }

            TEST_METHOD(should_throw_if_the_input_is_out_of_range)
            {
                Assert::ExpectException<out_of_range>([]{
                    number::parse(to_string(static_cast<unsigned long long>(ULONG_MAX) + 1));
                });
            }

            TEST_METHOD(should_recognize_zero_as_a_number)
            {
                auto num = number::parse("0");
                Assert::AreEqual(0U, num.value);
            }

            TEST_METHOD(should_determine_the_number_of_digits_from_the_string_input)
            {
                auto num = number::parse("12345");
                Assert::AreEqual(5U, num.digits.size());
            }

            TEST_METHOD(should_expose_a_vector_of_digits_in_the_number)
            {
                auto num = number::parse("12345");
                Assert::AreEqual(
                    vector<unsigned char> { { 1 }, { 2 }, { 3 }, { 4 }, { 5 } },
                    num.digits);
            }

        };
    }
}