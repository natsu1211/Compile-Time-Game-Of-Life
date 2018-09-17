/* ------------------------------
# author  : natsu1211
# date    : 2018-09-16
------------------------------- */

#ifndef RANDOM_H_0SME9H54
#define RANDOM_H_0SME9H54

#include <cstdint>

class Random
{
public:
    constexpr Random(unsigned seed) : prev_(seed) {}

    constexpr unsigned next()
    {
        unsigned bit  = ((prev_ >> 0) ^ (prev_ >> 2) ^ (prev_ >> 3) ^ (prev_ >> 5) ) & 1;
        prev_ =  (prev_ >> 1) | (bit << 15);

        return prev_;
    }

    // [min, max)
    constexpr unsigned range(unsigned min, unsigned max)
    {
        return next() % (max - min) + min;
    }

private:
    unsigned prev_;
};

#endif /* end of include guard: RANDOM_H_0SME9H54 */

