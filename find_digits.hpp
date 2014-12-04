#ifndef FIND_DIGITS_HPP
#define FIND_DIGITS_HPP

namespace find_digits
{
    bool number_divides(size_t divisor, size_t dividend)
    {
        return dividend % divisor == 0;
    }
}

#endif // FIND_DIGITS_HPP