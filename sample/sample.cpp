#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <sstream>
#include <limits>
#include <array>
#include "..\find_digits.hpp"

using namespace std;
using namespace find_digits;

int main()
{
    cout << "Enter number of tests [1 <= T <= 15]: ";

    size_t num_args;
    cin >> num_args;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (num_args == 0 || num_args > 15)
    {
        cout << "T out of range\n";
        return 1;
    }

    vector<string> args;

    for (size_t i = 0; i < num_args; ++i)
    {
        const size_t max_digits = 10;
        const size_t buffer_len = max_digits + 1 /* so we know if user entered too many chars */ + 1 /* null terminator */;
        array<char, buffer_len> value;

        cout << "(" << i + 1 << ") Enter a number: ";

        cin.getline(value.data(), buffer_len);

        if (string("0") == value.data() || strlen(value.data()) > max_digits)
        {
            cout << "N out of range\n";
            return 1;
        }

        args.push_back(std::move(value.data()));
    }

    cout << "\nResults:\n";

    for (auto arg : args)
    {
        cout << number(arg).count_divisor_digits() << "\n";
    }

    return 0;
}

