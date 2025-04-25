#include "IRule.h"

#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

#include <memory>

using namespace griddler;
using namespace std;

TEST_CASE ("Check size of the Rule", "![rule]")
{
    constexpr int WIDTH = 5;
    auto data = GENERATE (table<char const*, unsigned long long> ({
        {"5", 1},
        {"1", 5},
        {"1 3", 1},
        {"1 2", 3},
        {"1 1", 6},
        {"1 1 1", 1}
    }));

    auto [textRule, expectedSize] = data;
    auto rule = createRule (WIDTH, textRule);

    CAPTURE (textRule);
    CHECK (rule->getSize () == expectedSize);
}

TEST_CASE ("Check generated values", "[rule]")
{
    constexpr int WIDTH = 5;
    auto data = GENERATE (table<char const*, unsigned long long> ({
        {"1", 5},
        {"1 1", 6}
    }));

    auto [textRule, expectedSize] = data;
    auto rule = createRule (WIDTH, textRule);

    CAPTURE (textRule);

    for (int i = 0; i < expectedSize; ++i )
    {
        rule->getValue (i);
    }
}

// 012345 -> 3 / 10
// x x
// x  x
// x   x
// x    x
//  x x
//  x  x
//  x   x
//   x x
//   x  x
//    x x

// 012345 -> 2 / 6
// x xx
// x  xx
// x   xx
//  x xx
//  x  xx
//   x xx

// 012345 -> 1 / 4
// .x.x.x
// x..x.x
// x.x..x
// x.x.x.
