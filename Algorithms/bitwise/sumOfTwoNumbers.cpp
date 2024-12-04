/*
Write a function Add() that returns sum of two integers. The function should not use
any of the arithmetic operators (+, ++, –, -, .. etc).

*/

#include <bits/stdc++.h>
using namespace std;

int Add(int a , int b )
{
	// Iterate till there is no carry
	while (b != 0)
	{
		int sum = a ^ b ;
		int carry = a & b ;
		carry = carry << 1 ; // transferring the carry bits to next higher bit position

		a = sum ;

		b = carry ;
	}
	return a;
}

int main()
{
	cout << Add(-5, 32);
	return 0;
}