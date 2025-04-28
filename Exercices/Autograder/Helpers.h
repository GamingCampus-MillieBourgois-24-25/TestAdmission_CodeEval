#pragma once

#include <stdexcept>
#include <string>
#include <type_traits>

template<typename T>
T ConvertFromString(const std::string& _str)
{
	if constexpr (std::is_same_v<T, int>)
	{
		return std::stoi(_str);
	}
	else if constexpr (std::is_same_v<T, float>)
	{
		return std::stof(_str);
	}
	else if constexpr (std::is_same_v<T, std::string>)
	{
		return _str;
	}
	else
	{
		throw std::invalid_argument("Unsupported type for conversion.");
	}
}
