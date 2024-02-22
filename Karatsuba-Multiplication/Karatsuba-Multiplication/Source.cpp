#include <iostream>
#include "Karatsuba.h"

int main()
{
	std::cout << Karatsuba::MultiplyNumbers("7145523523", "0.553721") << '\n';                                  // 3956626430.679083
	std::cout << Karatsuba::MultiplyNumbers("123456789", "987654321") << '\n';                                  // 121932631112635269
	std::cout << Karatsuba::MultiplyNumbers("0.00000123", "-0.140001111") << '\n';                              // -0.00000017220136653
	std::cout << Karatsuba::MultiplyNumbers("0.0134", "1115523") << '\n';                                       // 14948.0082
	std::cout << Karatsuba::MultiplyNumbers("4738347", "37372594") << '\n';                                     // 177084318662118
	std::cout << Karatsuba::MultiplyNumbers("-383.48393", "-44.429111") << '\n';                                // 17037.85009268623
	std::cout << Karatsuba::MultiplyNumbers("0.22556", "8.0666223") << '\n';                                    // 1.819507325988
	std::cout << Karatsuba::MultiplyNumbers("0.0014577", "23.32") << '\n';                                      // 0.033993564
	std::cout << Karatsuba::MultiplyNumbers("2734983274", "31242141.41235341") << '\n';                         // 85446734206729313.32686434
	std::cout << Karatsuba::MultiplyNumbers("87645232375892356", "9852378327509831567301856732098") << '\n';    // 863513987969804871728105048311758546938778042888
	std::cout << Karatsuba::MultiplyNumbers("5893672.63457634263", "6532.532532") << '\n';                      // 38500608218.32810626805343916
	std::cout << Karatsuba::MultiplyNumbers("-0.14513", "1244.65432") << '\n';                                  // -180.6366814616
	return 0;
}