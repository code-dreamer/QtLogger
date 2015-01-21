#pragma once

namespace logging {
namespace impl {
namespace bit_tools {
;
bool check_bit(const int bitset, const int bit)
{
	return ((bitset & bit) == 0) ? false : true;
}

int add_bit(int& bitset, const int bit)
{
	return (bitset |= bit);
}

} // namespace bit_tools
} // namespace impl
} // namespace logging
