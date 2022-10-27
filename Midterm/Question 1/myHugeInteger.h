#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class myHugeInteger
{
private:
	int size = 3000; // 3000 for the 1000! factorial
	int sizen = size - 1; // for instances where the value is counting down
	int hi[3000]; // this should be equal to the size
	bool negative; // flag to state if the number is negative
public:


	myHugeInteger() // empty constructor
	{
		negative = false; // not negative
		for (int i = 0; i < size; i++) // fill the entire thing with zeros for now
		{
			hi[i] = 0; // fill with zeros
		}
	}

	myHugeInteger(int x)
	{
		negative = (x < 0); // is it negative or nah
		int temp = x; // we're gonna mess with the number, so copy the provided value
		for (int i = 0; i < size; i++) // fill with whatever was inputted
		{
			hi[i] = abs(temp % 10); // pull the last digit
			temp /= 10; // shift over
		}
	}

	bool greaterThan(myHugeInteger x, myHugeInteger y)
	{
		if (x.negative == y.negative) // are they the same sign?
		{
			for (int i = sizen; i > 0; i--) // check every digit, from the top
			{
				if (x.hi[i] > y.hi[i]) // if we run into one digit
				{
					if (x.negative) // if it's negative, bigger is smaller
					{
						return false;
					}
					else
					{
						return true;
					}
				}
				else if (x.hi[i] < y.hi[i]) // see above
				{
					if (x.negative)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
			}
			return false;
		}
		else if (!x.negative && y.negative) // x is positive, y is negative, by definition x is bigger
		{
			return true;
		}
		return false; // x is negative, y is positive, by definition y is bigger
	}

	bool greaterThanL(myHugeInteger x, myHugeInteger y) // same as above, but only checks for value, not sign.
	{
		for (int i = sizen; i >= 0; i--)
		{
			if (x.hi[i] > y.hi[i])
			{
				return true;
			}
			else if (x.hi[i] < y.hi[i])
			{
				return false;
			}
		}
		return false;
	}

	bool lessThan(myHugeInteger x, myHugeInteger y)
	{
		if (x.negative == y.negative) // are they the same sign?
		{
			for (int i = sizen; i >= 0; i--) // check every digit, from the top
			{
				if (x.hi[i] < y.hi[i]) // if we run into one digit
				{
					if (x.negative) // if it's negative, bigger is smaller
					{
						return false;
					}
					else
					{
						return true;
					}
				}
				else if (x.hi[i] > y.hi[i]) // see above
				{
					if (x.negative)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
			}
			return false;
		}
		else if (x.negative && !y.negative) // x is negative, y is positive, by definition y is bigger
		{
			return true;
		}
		return false; // x is positive, y is negative, by definition x is bigger
	}

	bool lessThanL(myHugeInteger x, myHugeInteger y) // same as above, but only checks for value, not sign.
	{
		if (x.negative == y.negative)
		{
			for (int i = sizen; i >= 0; i--)
			{
				if (x.hi[i] < y.hi[i])
				{
					return true;
				}
				else if (x.hi[i] > y.hi[i])
				{
					return false;
				}
			}
			return false;
		}
	}

	bool equalTo(myHugeInteger x, myHugeInteger y)
	{
		if (x.negative == y.negative) // are they both the same sign?
		{
			for (int i = sizen; i >= 0; i--)
			{
				if (x.hi[i] > y.hi[i])
				{
					return false;
				}
				else if (x.hi[i] < y.hi[i])
				{
					return false;
				}
			}
			return true;
		}
		return false; // not same sign = 
	}

	bool isZero(myHugeInteger x)  // check for zero so we don't run into a -0 situation
	{
		for (int i = sizen; i >= 0; i--) // every digit is zero, right
		{
			if (x.hi[i] != 0) // no :(
			{
				return false; // false
			}
		}
		return true;
	}

	void printHugeInteger()
	{
		bool start = false;
		bool neg = true;
		for (int i = sizen; i >= 0; i--)
		{
			if (hi[i] != 0) // Don't bother printing leading zeros.
			{
				if (negative && neg) // Is the value negative?
				{
					cout << "-"; // Print out negative sign first.
					neg = false; // Don't print negative signs anymore.
				}
				start = true; // We've started printing now, zeros are okay.
				cout << hi[i]; // Print number.
			}
			else if (hi[i] == 0 && start) // Did we start printing zeros?
			{
				cout << hi[i]; // Print zero.
			}
		}
		if (!start)
		{
			cout << "0";
		}
	}

	int numberOfDigits() // This can be derived from the printHugeInteger function.  Actually, it should have been the opposite, but I did it the other way.
	{
		int x = size;
		for (int i = sizen; i >= 0; i--)
		{
			if (hi[i] != 0) // No leading zeros.
			{
				x = i+1; // array starts at 0, so add 1
				break; // get outta here!
			}
		}
		return x; // return value
	}

	myHugeInteger addhi(myHugeInteger x, myHugeInteger y)
	{
		int carry = 0;
		myHugeInteger result = myHugeInteger();
		if (x.negative == y.negative) // both positive or negative
		{
			for (int i = 0; i < size; i++) // add digit by digit
			{
				result.hi[i] = x.hi[i] + y.hi[i] + carry; // sum with carry
				carry = result.hi[i] / 10; // whatever is over 10 is skimmed off to the carry
				result.hi[i] %= 10; // remove what was skimmed off
			}
			if (x.negative && y.negative) // both negative
			{
				result.negative = true; // negative and negative is negative
			}
		}
		else if (!x.negative && y.negative) // x + (-y), or just x - y
		{
			if (greaterThanL(x, y)) // x value is greater than y - simple subtraction
			{
				for (int i = 0; i < size; i++) // digit by digit
				{
					result.hi[i] = x.hi[i] - y.hi[i] + carry; // sum with carry
					if (result.hi[i] < 0) // oh no! x digit is less than y digit.
					{
						carry = -1; // take one off
						result.hi[i] += 10; // carryover
					}
				}
			}
			else // x is less than y - thus, value is -(y - x)
			{
				for (int i = 0; i < size; i++) // digit by digit
				{
					result.hi[i] = y.hi[i] - x.hi[i] + carry; // sum with carry
					if (result.hi[i] < 0) // oh no! y digit is less than x digit.
					{
						carry = -1; // take one off
						result.hi[i] += 10; // carryover
					}
				}
				result.negative = true; // negative is greater, stay negative
			}
		}
		else // -x + y, or just y - x
		{
			if (lessThanL(x, y)) // x value is less than y - simple subtraction
			{
				for (int i = 0; i < size; i++) // digit by digit
				{
					result.hi[i] = y.hi[i] - x.hi[i] + carry; // sum with carry
					if (result.hi[i] < 0) // oh no! y digit is less than x digit.
					{
						carry = -1; // take one off
						result.hi[i] += 10; // carryover
					}
				}
			}
			else // y is less than x - thus, value is -(x - y)
			{
				for (int i = 0; i < size; i++) // digit by digit
				{
					result.hi[i] = x.hi[i] - y.hi[i] + carry;
					if (result.hi[i] < 0) // oh no! x digit is less than y digit.
					{
						carry = -1; // take one off
						result.hi[i] += 10; // carryover
					}
				}
				result.negative = true; // negative is greater, stay negative
			}
		}
		if (isZero(result)) // is it zero? lets not run into a -0 situation
		{
			result.negative = false;
		}
		return result;
	}

	myHugeInteger subhi(myHugeInteger x, myHugeInteger y) // this is just addition but just flip the sign of the lower value - delegation time
	{
		myHugeInteger result = myHugeInteger(); // result
		myHugeInteger z = y; // gonna mess with the signs real quick
		z.negative = !z.negative; // flip flop
		result = addhi(x, z); // add like normal
		return result;
	}

	myHugeInteger mulhi(myHugeInteger x, myHugeInteger y)
	{
		myHugeInteger result = myHugeInteger(); // resulting
		int xl = x.numberOfDigits() + 1; // number of digits to travel for x
		int yl = y.numberOfDigits() + 1; // number of digits to travel for y
		int carry = 0; // initialize carry
		for (int i = 0; i < xl; i++) // digit by digit
		{
			for (int j = 0; j < yl; j++) // digit by digit
			{
				result.hi[i+j] += (x.hi[i] * y.hi[j] + carry); // multiply, accounting for shift as well
				carry = result.hi[i + j] / 10; // carryover
				result.hi[i + j] %= 10; // skim off carryover
			}
		}
		if (x.negative != y.negative) // negative on positive is negative
		{
			result.negative = true;
		}
		if (isZero(result)) // is it zero? lets not run into a -0 situation
		{
			result.negative = false;
		}
		return result;
	}

	string toString()
	{
		string res = "";
		stringstream result;
		bool start = false;
		bool neg = true;
		for (int i = sizen; i >= 0; i--)
		{
			if (hi[i] != 0) // Don't bother printing leading zeros.
			{
				if (negative && neg) // Is the value negative?
				{
					result << "-"; // Print out negative sign first.
					neg = false; // Don't print negative signs anymore.
				}
				start = true; // We've started printing now, zeros are okay.
				result << hi[i]; // Print number.
			}
			else if (hi[i] == 0 && start) // Did we start printing zeros?
			{
				result << hi[i]; // Print zero.
			}
		}
		if (!start)
		{
			result << "0";
		}
		result >> res;
		return res;
	}
};



