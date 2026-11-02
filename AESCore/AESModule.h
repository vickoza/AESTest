#pragma once
#include <cstdint>
#include <string_view>
#include <string>
#include <array>
#include <deque>
#include <tuple>

using uint128_t = uint64_t[2];
enum class AESStep
{
	AddRoundKey,
	SubBytes,
	ShiftRows,
	MixColumns
};

enum class AESType
{
	Encrypt,
	Decrypt
};

class AESModule
{
	uint128_t key;
	std::deque<std::tuple<std::array<uint8_t, 16>, AESStep, AESType, uint8_t>> processQueue;
	friend class AESTester;
public:
	AESModule(uint128_t const&);
	~AESModule();
	void KeyExpansion(uint128_t const&);
	std::string EncryptBlock(std::string_view);
	std::string DecryptBlock(std::string_view);
private:
	void ProcessQueue();
	void AddRoundKey(std::array<uint8_t, 16>&);
	void SubBytes(std::array<uint8_t, 16>&);
	void ShiftRows(std::array<uint8_t, 16>&);
	void MixColumns(std::array<uint8_t, 16>&);
	uint8_t xtime(uint8_t x);
	uint8_t mul(uint8_t x, uint8_t factor);
};

