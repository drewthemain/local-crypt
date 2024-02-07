#pragma once

#include <iostream>
#include <string>

class Debug
{
public:
	template<typename T>
	static void Log(const T& message);

};

template <typename T>
void Debug::Log(const T& message)
{
	std::cout << message << std::endl;
}
