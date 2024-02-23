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

	//Return the result of multiplication of two big numbers represented as strings
	static std::string MultiplyNumbers(const std::string& firstNumber, const std::string& secondNumber);

private:

	//The implementation of karatsuba algorithm for fast multiplication of two big numbers represented as strings
	static std::string KaratsubaAlgorithm(std::string firstNumber, std::string secondNumber);
	
	//Adds leading zeros from a number represented as a string
	static void AddLeadingZeros(std::string& number, int length);

	//Removes leading zeros from a number represented as a string
	static void RemoveLeadingZeros(std::string& number);

	//Adds two numbers represented as strings
	//Works with floating numbers
	static std::string Addition(const std::string& firstNumber, const std::string& secondNumber);

	//Substracts the second number for the first, but only works if first is greater than second
	//In the constext of karatsuba multiplication you won't have the second number greater than the first number.
	//Both numbers are represented as strings
	static std::string Subtraction(const std::string& firstNumber, const std::string& secondNumber);

	//Returns a substring of the given string from a position to another position, the end position excluded
	static std::string Split(const std::string& number, int begin, int end);
};

