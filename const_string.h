/* ------------------------------
# author  : natsu1211
# date    : 2018-09-14
------------------------------- */

#ifndef CONST_STRING_H_79RZVOIE
#define CONST_STRING_H_79RZVOIE

#include <cstdlib>
#include <stdexcept>

class ConstString
{
public:
    template<std::size_t N>
    constexpr ConstString(const char (&str)[N])
        :size_(N-1), str_(str)
    {
    }

    constexpr std::size_t size()
    {
        return size_;
    }

    constexpr char operator[](std::size_t index)
    {
        return index < size_ ? 
            str_[index] :
            throw std::out_of_range("");
    }

private:
    const std::size_t size_;
    const char* const str_;
};

#endif /* end of include guard: CONST_STRING_H_79RZVOIE */

