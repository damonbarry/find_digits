#ifndef FIND_DIGITS_HPP
#define FIND_DIGITS_HPP

#include <algorithm>
#include <iterator>
#include <cassert>
#include <cstdint>
#include <utility>
#include <string>
#include <cctype>
#include <vector>

namespace find_digits
{
    namespace details
    {
        inline bool number_divides(uint64_t divisor, uint64_t dividend)
        {
            if (divisor == 0) { return false; }
            return dividend % divisor == 0;
        }

        inline std::vector<char> parse_digits(const std::string& in)
        {
            std::vector<char> digits;
            for (auto ch : in)
            {
                assert(isdigit(ch));
                digits.push_back(ch - '0');
            }

            return digits;
        }

        struct num_state
        {
            const uint64_t value;
            const std::vector<char> digits;
        };

        inline num_state parse(const std::string& in)
        {
            size_t len;
            unsigned long long num = std::stoull(in, &len);

            auto it = std::find_if(in.begin(), in.end(), [](const std::string::value_type& ch){
                return std::isdigit(ch);
            });

            return num_state { num, parse_digits(in.substr(std::distance(in.begin(), it), len)) };
        }
    }

    class number
    {
        details::num_state state;

    public:
        explicit number(const std::string& num) : number(details::parse(num)) {}
        number(const details::num_state& st) : state(st) {}

        uint32_t count_divisor_digits()
        {
            uint32_t count = 0;
            for (char digit : state.digits)
            {
                if (details::number_divides(digit, state.value)) { ++count; }
            }
            return count;
        }
    };
}

#endif // FIND_DIGITS_HPP
