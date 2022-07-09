#include <iostream>
#include <string>
#include <math.h>
using namespace std;


class reverseExponents
{
private:
	int a, b;

public:
	string c;

	reverseExponents(int a)
	{
		this->a = a;
		string temp = to_string(a);
		string b_string = "";
		for (int i = temp.length() - 1; i >= 0; i--)
		{
			b_string += temp.at(i);
		}
		b = stoi(b_string);
		findC();
	}

	int getA()
	{
		return a;
	}

	int getB()
	{
		return b;
	}

	string getC()
	{
		return c;
	}

	void findC()
	{
		c = "1";
		for (int i = 0; i < b; i++)
		{
			c = multiply(c, to_string(a));
		}
	}

	string multiply(string c, string a)
	{
		int current;
		int carry;
		string leading0;
		string result = "";
		string result_temp;
		for (int i = 0; i < a.length(); i++)
		{
			leading0 = "";
			for (int j = 0; j < i; j++)
				leading0 += "0";
			result_temp = leading0;
			carry = 0;

			//multiply c by a at index i
			for (int j = 0; j < c.length(); j++)
			{
				current = ((int)a.at(a.length() - i - 1) - 48) * ((int)c.at(c.length() - j - 1) - 48);
				current += carry;
				result_temp = to_string(current % 10) + result_temp;
				carry = current / 10;
			}
			if (carry != 0)
				result_temp = to_string(carry) + result_temp;

			//add recently calculated muliplication to current sum
			int resultNum, result_tempNum;
			carry = 0;
			for (int j = 0; j < max(result_temp.length(), result.length()); j++) // max of result_temp and result
			{
				if (j >= result.length()) //do this for result temp 2 incase was multiiplied by 0
					resultNum = 0;
				else
					resultNum = (result.at(result.length() - j - 1) - 48);
				if (j >= result_temp.length())
					result_tempNum = 0;
				else
					result_tempNum = (result_temp.at(result_temp.length() - j - 1) - 48);

				current = resultNum + result_tempNum + carry;
				if (j < result.length())
					result.at(result.length() - j - 1) = char(48 + current % 10); //add 48 to get correct ascii value
				else
					result = to_string(current % 10) + result;
				carry = current / 10;
			}
			if (carry != 0)
				result = to_string(carry) + result;
			if (result.at(0) == '0')
				result = result.substr(1, result.length() - 1);
		}
		return result;
	}

};


int main()
{
	char keep_going = 'y';
	int a;

	while (keep_going == 'y')
	{
		cout << "Enter a number (0-99999): ";
		cin >> a;
		reverseExponents test = reverseExponents(a);
		cout << "Result: " << test.getA() << "^" << test.getB() << " is\n";
		cout << test.getC() << endl << endl;

		cout << "y to continue: ";
		cin >> keep_going;
		cout << endl;
	}

	return 0;
}