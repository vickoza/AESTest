#pragma once
#include <string>
#include <ranges>
#include <algorithm>
#include <concepts>
#include <cstddef>
#include <span>

template <typename T>
std::string slideEncypt(std::string text, T key) requires std::integral<T>
{
	std::span<char> mask	{ reinterpret_cast<char*>(&key), sizeof(T) };
	for (auto window : text | std::views::slide(sizeof(T)))
	{
		std::ranges::transform(window, mask, window.begin(), [](char a, char b) { return a ^ b; });
	}
	return text;
}
