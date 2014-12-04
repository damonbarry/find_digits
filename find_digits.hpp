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
    inline bool number_divides(size_t divisor, size_t dividend)
    {
        return dividend % divisor == 0;
    }

    struct number;
    number parse_number(const std::string&);

    struct number
    {
        const size_t value;
        const std::vector<unsigned char> digits;

        explicit number(const std::string& num) : number(parse_number(num)) {}
        number(size_t value, std::vector<unsigned char>&& digits) :
            value(value), digits(std::forward<std::vector<unsigned char>>(digits)) {}

        size_t count_divisor_digits()
        {
            size_t count = 0;
            for (unsigned char digit : digits)
            {
                if (number_divides(digit, value)) { ++count; }
            }
            return count;
        }
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
}

#endif // FIND_DIGITS_HPP