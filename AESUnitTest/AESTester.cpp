#include "AESTester.h"
#include <array>
#include <algorithm>

bool AESTester::TestShiftRows()
{
    std::array<uint8_t,16> inputBlock = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
	std::span<uint8_t, 16> inputSpan = inputBlock;
    std::array<uint8_t, 16> const expectOutput = { 1, 2, 3, 4, 6, 7, 8, 5, 11, 12, 9, 10, 16, 13, 14, 15 };
	aesModule.ShiftRows(inputSpan);
	return std::ranges::equal(inputBlock, expectOutput);
}

bool AESTester::TestAddRoundKey(std::span<uint8_t, 16> input, std::span<uint8_t, 16> expected)
{
	aesModule.AddRoundKey(input);
	return std::ranges::equal(input, expected);
}

bool AESTester::TestSubBytes()
{
	std::array<uint8_t, 16> inputBlock = { 0x32, 0x88, 0x31, 0xe0, 0x43, 0x5a, 0x31, 0x37, 0xf6, 0x30, 0x98, 0x07, 0xa8, 0x8d, 0xa2, 0x34 };
	std::span<uint8_t, 16> inputSpan = inputBlock;
	aesModule.SubBytes(inputSpan);
	std::array<uint8_t, 16> const expectOutput = { 0x23, 0xc4, 0xc7, 0xe1, 0x1a, 0xbe, 0xc7, 0x9a, 0x42, 0x04, 0x46, 0xc5, 0xc2, 0x5d, 0x3a, 0x18 };
	return std::ranges::equal(inputBlock, expectOutput);
}

bool AESTester::TestMixColumns()
{
	std::array<uint8_t, 16> inputBlock = { 0xdb, 0x13, 0x53, 0x45, 0xf2, 0x0a, 0x22, 0x5c, 0x01, 0x01, 0x01, 0x01, 0xc6, 0xc6, 0xc6, 0xc6 };
	std::span<uint8_t, 16> inputSpan = inputBlock;
	aesModule.MixColumns(inputSpan);
	std::array<uint8_t, 16> const expectOutput = { 0x67, 0xff, 0x07, 0xa9, 0xe1, 0xc2, 0xd2, 0x38, 0x7a, 0x4a, 0x22, 0x4a, 0x12, 0xa9, 0x41, 0x05 };
	return std::ranges::equal(inputBlock, expectOutput);
}
