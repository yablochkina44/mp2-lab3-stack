#pragma once
#include <exception>

class MyExceptoin : public std::exception
{
public:
	MyExceptoin(const char* msg) : std::exception(msg) {}
};
