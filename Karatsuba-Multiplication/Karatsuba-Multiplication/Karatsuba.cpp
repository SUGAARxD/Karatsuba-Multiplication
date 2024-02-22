#include "Karatsuba.h"

std::string Karatsuba::MultiplyNumbers(const std::string& firstNumber, const std::string& secondNumber)
{
	std::regex pattern("-?[0-9]+(\\.[0-9]+)?");
	if (firstNumber.empty() || secondNumber.empty() || !std::regex_match(firstNumber, pattern) || !std::regex_match(secondNumber, pattern))
		return "Invalid numbers!";

	bool isResultNegative = false;
	if ((firstNumber[0] == '-' || secondNumber[0] == '-') && firstNumber[0] != secondNumber[0])
		isResultNegative = true;

	std::string firstNumberWithoutDot, secondNumberWithoutDot;
	int decimalsCountAfterDot = 0;
	
	bool dotFound = false;
	for (const auto& chr : firstNumber)
	{
		if (dotFound)
			decimalsCountAfterDot++;
		if (chr == '.')
			dotFound = true;
		else if (chr != '-')
			firstNumberWithoutDot += chr;
	}
	dotFound = false;
	for (const auto& chr : secondNumber)
	{
		if (dotFound)
			decimalsCountAfterDot++;
		if (chr == '.')
			dotFound = true;
		else if (chr != '-')
			secondNumberWithoutDot += chr;
	}
	RemoveFrontZeros(firstNumberWithoutDot);
	RemoveFrontZeros(secondNumberWithoutDot);

	std::string result = KaratsubaAlgorithm(firstNumberWithoutDot, secondNumberWithoutDot);

	if (decimalsCountAfterDot != 0)
	{
		if (decimalsCountAfterDot >= result.length())
			AddFrontZeros(result, decimalsCountAfterDot + 1);
		result += '.';
		for (int index = result.length() - 1; index >= result.length() - decimalsCountAfterDot; index--)
			std::swap(result[index], result[index - 1]);

		if (isResultNegative)
			result = '-' + result;
	}

	return result;
}

std::string Karatsuba::KaratsubaAlgorithm(std::string firstNumber, std::string secondNumber)
{
	if (firstNumber.length() < secondNumber.length())
		std::swap(firstNumber, secondNumber);

	if (secondNumber.length() == 1)
	{
		if (firstNumber == "0" || secondNumber == "0")
			return "0";
		std::string multiplied = "0";
		int multiplier = secondNumber[0] - '0';
		while (multiplier--)
			multiplied = Addition(firstNumber, multiplied);
		return multiplied;
	}

	if (firstNumber.length() == secondNumber.length() && firstNumber.length() % 2 != 0)
		firstNumber = '0' + firstNumber;
	if (secondNumber.length() % 2 != 0)
		secondNumber = '0' + secondNumber;

	int n = secondNumber.length();

	std::string firstNumberFirstHalf = Half(firstNumber, 0, firstNumber.length() - (secondNumber.length() / 2));
	std::string firstNumberSecondHalf = Half(firstNumber, firstNumber.length() - (secondNumber.length() / 2), firstNumber.length());

	std::string secondNumberFirstHalf = Half(secondNumber, 0, secondNumber.length() / 2);
	std::string secondNumberSecondHalf = Half(secondNumber, secondNumber.length() / 2, secondNumber.length());

	std::string ac = KaratsubaAlgorithm(firstNumberFirstHalf, secondNumberFirstHalf);
	std::string bd = KaratsubaAlgorithm(firstNumberSecondHalf, secondNumberSecondHalf);
	std::string ab_cd = Subtraction(Subtraction(KaratsubaAlgorithm(Addition(firstNumberFirstHalf, firstNumberSecondHalf), Addition(secondNumberFirstHalf, secondNumberSecondHalf)), ac), bd);

	for (int i = 0; i < secondNumber.length(); i++)
		ac += '0';
	for (int i = 0; i < secondNumber.length() / 2; i++)
		ab_cd += '0';
	std::string result = Addition(Addition(ac, ab_cd), bd);
	return result;
}

void Karatsuba::AddFrontZeros(std::string& number, int length)
{
	for (int i = number.length(); i < length; i++)
		number = '0' + number;
}

void Karatsuba::RemoveFrontZeros(std::string& number)
{
	int i = 0;
	while (i < number.length() && number[i] == '0')
		i++;
	std::string newnumber;
	for (int j = i; j < number.length(); j++)
		newnumber += number[j];
	number = std::move(newnumber);
}

std::string Karatsuba::Addition(const std::string& firstNumber, const std::string& secondNumber)
{
	if (firstNumber == "0")
		return secondNumber;
	if (secondNumber == "0")
		return firstNumber;
	int digitsAfterDotFirstNumber = 0, digitsAfterDotSecondNumber = 0;
	int dotFoundNumber1 = 0, dotFoundNumber2 = 0;
	std::string number1WithoutDecimals, number2WithoutDecimals;
	int i = 0;
	for (i; i < firstNumber.length(); i++)
	{
		if (dotFoundNumber1)
			digitsAfterDotFirstNumber++;
		if (firstNumber[i] == '.')
			dotFoundNumber1 = 1;
		else
			number1WithoutDecimals += firstNumber[i];
	}
	i = 0;
	for (i; i < secondNumber.length(); i++)
	{
		if (dotFoundNumber2)
			digitsAfterDotSecondNumber++;
		if (secondNumber[i] == '.')
			dotFoundNumber2 = 1;
		else
			number2WithoutDecimals += secondNumber[i];
	}

	int digitsDifference = digitsAfterDotFirstNumber - digitsAfterDotSecondNumber;
	if (digitsDifference < 0)
	{
		std::swap(digitsAfterDotFirstNumber, digitsAfterDotSecondNumber);
		digitsDifference *= -1;
	}

	while (digitsDifference--)
	{
		number2WithoutDecimals += '0';
	}

	if (number1WithoutDecimals.length() < number2WithoutDecimals.length())
		std::swap(number1WithoutDecimals, number2WithoutDecimals);

	if (number2WithoutDecimals.length() < number1WithoutDecimals.length())
		AddFrontZeros(number2WithoutDecimals, number1WithoutDecimals.length());

	std::string add;
	int carry = 0;
	for (int i = number1WithoutDecimals.length() - 1; i >= 0; i--)
	{
		int sum = (number1WithoutDecimals[i] - '0') + (number2WithoutDecimals[i] - '0');
		if (carry)
			sum++;
		if (sum > 9)
			carry = 1;
		else
			carry = 0;
		add = std::to_string(sum % 10) + add;
	}
	if (carry)
		add = std::to_string(1) + add;
	RemoveFrontZeros(add);
	int maxDecimals = std::max(digitsAfterDotFirstNumber, digitsAfterDotSecondNumber);
	if (digitsAfterDotFirstNumber || digitsAfterDotSecondNumber) {

		int position = add.length() - 1;
		if (maxDecimals > 20)
			position -= (maxDecimals - 20);
		std::string added;

		while (maxDecimals--)
			if (position >= 0)
				added = add[position--] + added;
			else
				added = '0' + added;
		added = '.' + added;
		if (maxDecimals == add.length())
			added = '0' + added;
		else
			while (position >= 0)
				added = add[position--] + added;
		add = added;
	}
	i = add.length() - 1;
	while (i >= 0 && add[i] == '0' && maxDecimals)
		add.pop_back();
	if (add.length() < 1)
		add += '0';
	else
		if (add[0] == '.')
			add = '0' + add;
	return add;
}

std::string Karatsuba::Subtraction(const std::string& firstNumber, const std::string& secondNumber)
{
	std::string sub;

	std::string tempFirstNumber = firstNumber;
	std::string tempSecondNumber = secondNumber;

	if (tempFirstNumber.length() < tempSecondNumber.length())
		AddFrontZeros(tempFirstNumber, tempSecondNumber.length());

	if (tempSecondNumber.length() < tempFirstNumber.length())
		AddFrontZeros(tempSecondNumber, tempFirstNumber.length());

	int carry = 0;
	for (int i = tempFirstNumber.length() - 1; i >= 0; i--)
	{
		int dif = (tempFirstNumber[i] - '0') - (tempSecondNumber[i] - '0');
		if (dif < 0)
		{
			dif *= -1;
			dif = 10 - dif;
			carry = 1;
		}
		if (carry)
		{
			if (i > 0)
				if (tempFirstNumber[i - 1] != '0')
					tempFirstNumber[i - 1] -= 1;
				else
				{
					int j = i;
					while (j > 0 && tempFirstNumber[j - 1] == '0')
					{
						tempFirstNumber[j - 1] = '9';
						j--;
					}
					tempFirstNumber[--j] -= 1;
				}
			carry = 0;
		}
		sub = std::to_string(dif) + sub;
	}
	RemoveFrontZeros(sub);
	if (sub.length() < 1)
		sub += '0';
	return sub;
}
std::string Karatsuba::Half(const std::string& number, int begin, int end)
{
	std::string hlf;
	for (int i = begin; i < end; i++)
		hlf += number[i];
	return hlf;
}