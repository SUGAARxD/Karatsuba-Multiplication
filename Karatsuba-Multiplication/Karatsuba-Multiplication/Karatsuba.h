#pragma once
#include <string>
#include <regex>

class Karatsuba
{
public:
	Karatsuba() = delete;
	~Karatsuba() = delete;
	Karatsuba(const Karatsuba& other) = delete;
	Karatsuba& operator=(const Karatsuba& other) = delete;
	Karatsuba(Karatsuba&& other) noexcept = delete;
	Karatsuba& operator=(Karatsuba&& other) noexcept = delete;


	static std::string MultiplyNumbers(const std::string& firstNumber, const std::string& secondNumber);

private:

	static std::string KaratsubaAlgorithm(std::string firstNumber, std::string secondNumber);
	static void AddFrontZeros(std::string& number, int length);
	static void RemoveFrontZeros(std::string& number);
	static std::string Addition(const std::string& firstNumber, const std::string& secondNumber);
	static std::string Subtraction(const std::string& firstNumber, const std::string& secondNumber);
	static std::string Half(const std::string& number, int begin, int end);
};

