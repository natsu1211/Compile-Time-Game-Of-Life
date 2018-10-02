/* ------------------------------
# author  : natsu1211
# date    : 2018-09-22
------------------------------- */

#ifndef UTIL_H_7WJEFSO6
#define UTIL_H_7WJEFSO6

#include "engine.h"
#include "printer.h"
#include <tuple>

template<std::size_t N>
struct to_tuple
{
    constexpr static auto apply(Engine engine)
    {
        engine.update();
        return std::tuple_cat(std::make_tuple(engine.getBoard()), to_tuple<N-1>::apply(engine));
    }
};

template<>
struct to_tuple<1>
{
    constexpr static auto apply(Engine engine)
    {
        engine.update();
        return std::make_tuple(engine.getBoard());
    }
};

template<template<typename> typename TFuncObj, std::size_t I=0, typename ...Tp>
constexpr auto for_each_tuple(const std::tuple<Tp...>& t)
{
    if constexpr (I < sizeof...(Tp))
    {
        const auto& board = std::get<I>(t);
        TFuncObj<decltype(board)>::print(board, I);
        for_each_tuple<TFuncObj, I+1, Tp...>(t);
    }
}


#endif /* end of include guard: UTIL_H_7WJEFSO6 */


