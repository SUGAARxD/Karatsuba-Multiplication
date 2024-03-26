# Karatsuba-Multiplication
This program uses Karatsuba's fast multiplication algorithm to multiply two large numbers represented as strings.
# Karatsuba Algorithm

The Karatsuba algorithm is a fast multiplication algorithm based on the divide-and-conquer strategy.

## Description

The Karatsuba algorithm splits the numbers to be multiplied into smaller parts, performs intermediate multiplications, and then combines the results.

## Formula

The formula for Karatsuba multiplication is as follows:

$$
x \cdot y = 10^n \cdot x_1 \cdot y_1 + 10^{n/2} \cdot [(x_1 + x_0) \cdot (y_1 + y_0) - x_1 \cdot y_1 - x_0 \cdot y_0] + x_0 \cdot y_0
$$

## Complexity Analysis

The Karatsuba algorithm has a time complexity of $O(n^{log_{2}3})$ or $O(n^{1.585})$, which is better than the traditional multiplication algorithm.

