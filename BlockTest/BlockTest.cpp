#include <BlockEncryp.hpp>
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BlockTest
{
	TEST_CLASS(BlockTest)
	{
	public:
		
		TEST_METHOD(SlideTest1)
		{
			using namespace std::string_literals;
			auto result = slideEncypt("Hello World!"s, 0x12'345'678);
			Assert::AreEqual(result, "0Kvdg(_gzB3"s);
			auto result2 = slideEncypt(result, 0x12345678);
			Assert::AreEqual(result2, "Hello World!"s);
		}
	};
}
