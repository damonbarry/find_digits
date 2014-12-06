#ifndef FIND_DIGITS_HPP
#define FIND_DIGITS_HPP

#include <algorithm>
#include <iterator>
#include <cassert>
#include <utility>
#include <string>
#include <cctype>
#include <vector>

namespace find_digits
{
    namespace details
    {
        inline bool number_divides(size_t divisor, size_t dividend)
        {
            if (divisor == 0) { return false; }
            return dividend % divisor == 0;
        }

        inline std::vector<unsigned char> parse_digits(const std::string& in)
        {
            std::vector<unsigned char> digits;
            for (auto ch : in)
            {
                assert(isdigit(ch));
                digits.push_back(ch - '0');
            }

            return digits;
        }

        struct num_state
        {
            const size_t value;
            const std::vector<unsigned char> digits;
        };

        inline num_state parse(const std::string& in)
        {
            size_t len;
            unsigned long num = std::stoul(in, &len);

            auto it = std::find_if(in.begin(), in.end(), [](const unsigned char& ch){
                return std::isdigit(ch);
            });

            return num_state { num, parse_digits(in.substr(std::distance(in.begin(), it), len)) };
        }
    }

    struct number
    {
        details::num_state state;

        explicit number(const std::string& num) : number(details::parse(num)) {}

        number(const details::num_state& st) : state(st) {}

        size_t count_divisor_digits()
        {
            size_t count = 0;
            for (unsigned char digit : state.digits)
            {
                if (details::number_divides(digit, state.value)) { ++count; }
            }
            return count;
        }
    };
}

#endif // FIND_DIGITS_HPP
