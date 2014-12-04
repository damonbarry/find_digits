#ifndef FIND_DIGITS_HPP
#define FIND_DIGITS_HPP

#include <algorithm>
#include <iterator>
#include <cassert>
#include <string>
#include <cctype>
#include <vector>

namespace find_digits
{
    struct number
    {
        const size_t value;
        const std::vector<unsigned char> digits;
    };

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

    inline number parse_number(const std::string& in)
    {
        size_t len;
        unsigned long num = std::stoul(in, &len);

        auto it = std::find_if(in.begin(), in.end(), [](const unsigned char& ch){
            return std::isdigit(ch);
        });

        return number { num, parse_digits(in.substr(std::distance(in.begin(), it), len)) };
    }

    inline bool number_divides(size_t divisor, size_t dividend)
    {
        return dividend % divisor == 0;
    }
}

#endif // FIND_DIGITS_HPP