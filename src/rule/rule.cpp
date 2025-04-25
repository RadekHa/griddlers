#include "Rule.h"

#include <array>
#include <bitset>
#include <iostream>
#include <memory>
#include <sstream>

using namespace griddler;
using namespace std;

#define DUMP(x) {cout << # x << " : " << x << endl;}


template<size_t N>
constexpr array<uint64_t, N + 1> generateLUT ()
{
    array<uint64_t, N + 1> lut{};

    for (size_t i = 0; i <= N; ++i)
    {
        lut [i] = (i < 64) ? (1ULL << i) - 1 : ~0ULL;
    }
    return lut;
}

constexpr size_t MAX_BITS = 64;
constexpr auto LUT = generateLUT<MAX_BITS>();

void printBits (uint64_t value, size_t n)
{
    bitset<64> bits (value);
    cout << bits.to_string ().substr (64 - n) << endl;
}

///////////////////////////////////////////////////////////////////////////////
// Factory functions.

IRule* griddler::createNewRule (uint8_t width, const char* rule)
{
    auto instance = make_unique<Rule> (width);

    istringstream stream (rule);
    unsigned int number;

    while (stream >> number)
    {
        instance->addRule (number);
    }
    return instance.release ();
}

///////////////////////////////////////////////////////////////////////////////
// Rule class.
Rule::Rule (uint8_t width)
    : m_width {width}
    , m_count {}
    , m_sum {}
{
}

Rule::~Rule () = default;

void Rule::addRule (uint8_t rule)
{
    ++m_count;
    m_sum += rule;
    m_rules.push_back (rule);
}

uint64_t Rule::getSize () const
{
    const uint8_t spaceCount = m_width - m_sum;
    return getComb (spaceCount + 1, m_count);
}

uint64_t Rule::getValue (uint64_t index) const
{
    uint64_t result = 0;
    // TODO
    return result;
}

uint8_t Rule::getWidth () const
{
    return m_width;
}

uint64_t Rule::getComb (uint8_t n, uint8_t k) const
{
    k = n - k;

    uint64_t result = 1;

    for (int i = 0; i < k; ++i)
    {
        result *= (n - i);
        result /= (i + 1);
    }
    return result;
}
