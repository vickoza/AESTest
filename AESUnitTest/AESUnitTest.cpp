#include "AESModule.h"
#include "AESTester.h"
#include "CppUnitTest.h"
#include <array>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AESUnitTest
{
	TEST_CLASS(AESUnitTest)
	{
	public:
		
		/*TEST_METHOD(TestAESEncyption)
		{
			AESModule aes({ 0x000462D5ULL, 0x3C8ABAC0ULL });
			auto encrypted = aes.EncryptBlock("hello world!!");
			Assert::AreEqual(std::string{"s4UwPvnVsEHNarfUu1kKpQ=="}, encrypted);
		}*/
		TEST_METHOD(TestAESBlockShiftRows)
		{
			AESModule aes({ 0x000462D5ULL, 0x3C8ABAC0ULL });
			AESTester tester{ aes };
			auto result = tester.TestShiftRows();
			Assert::IsTrue(result);
		}
		TEST_METHOD(TestAESAddRoundKey)
		{
			AESModule aes({ 0x00'04'62'D5ULL, 0x3C'8A'BA'C0ULL });
			AESTester tester{ aes };
			std::array<uint8_t, 16> inputBlock = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10 };
			std::span<uint8_t, 16> inputSpan = inputBlock;
			std::array<uint8_t, 16> expectOutput = { 212, 96, 7, 4, 5, 6, 7, 8, 201, 176, 129, 48, 13, 14, 15, 16 };
			std::span<uint8_t, 16> expectSpan = expectOutput;
			auto result = tester.TestAddRoundKey(inputSpan, expectSpan);
			Assert::IsTrue(result);
		}
		TEST_METHOD(TestAESSubBytes)
		{
			AESModule aes({ 0x000462D5ULL, 0x3C8ABAC0ULL });
			AESTester tester{ aes };
			auto result = tester.TestSubBytes();
			Assert::IsTrue(result);
		}
		TEST_METHOD(TestAESMixColumns)
		{
			AESModule aes({ 0x000462D5ULL, 0x3C8ABAC0ULL });
			AESTester tester{ aes };
			auto result = tester.TestMixColumns();
			Assert::IsTrue(result);
		}
	};
}
// 