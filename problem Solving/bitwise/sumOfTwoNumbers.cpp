/*
Write a function Add() that returns sum of two integers. The function should not use
any of the arithmetic operators (+, ++, –, -, .. etc).

*/

#include <bits/stdc++.h>
using namespace std;

int Add(int x, int y)
{
	// Iterate till there is no carry
	while (y != 0)
	{
		// carry now contains common
		//set bits of x and y
		int carry = x & y;

		// Sum of bits of x and y where at
		//least one of the bits is not set
		x = x ^ y;

		// Carry is shifted by one so that adding
		// it to x gives the required sum
		y = carry << 1;
	}
	return x;
}

// Driver code
int main()
{
	cout << Add(15, 32);
	return 0;
}