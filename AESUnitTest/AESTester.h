#pragma once
#include "AESModule.h"
class AESTester
{
	AESModule& aesModule;
public:
	AESTester(AESModule& module) : aesModule{ module } {}
	bool TestShiftRows();
	bool TestAddRoundKey(std::span<uint8_t, 16> input, std::span<uint8_t, 16> expected);
	bool TestSubBytes();
	bool TestMixColumns();
};

