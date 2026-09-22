#include <iostream>
#include <cmath>
using namespace std;

// Function prototypes
bool isValid(long long number);
int sumOfDoubleEvenPlace(long long number);
int getDigit(int number);
int sumOfOddPlace(long long number);
bool prefixMatched(long long number, int d);
int getSize(long long d);
long long getPrefix(long long number, int k);

// getSize counts how many digits are in the number
// It keeps dividing by 10 until nothing is left
int getSize(long long d)
{
    if (d == 0)
        return 0;

    int count = 0;
    while (d > 0)
    {
        d = d / 10;
        count++;
    }
    return count;
}

// getDigit takes a number and returns a single digit
// If the number is already below 10, it returns it as is
// If it is two digits, it adds the tens and ones together
int getDigit(int number)
{
    if (number < 10)
        return number;
    else
        return (number / 10) + (number % 10);
}

// sumOfOddPlace adds up all digits in odd positions from the right
// Position 1 is the rightmost digit, position 3 is the next odd one, and so on
int sumOfOddPlace(long long number)
{
    int position = 1;
    int sum = 0;

    while (number > 0)
    {
        int digit = number % 10;
        if (position % 2 != 0)
        {
            sum += digit;
        }
        number = number / 10;
        position++;
    }
    return sum;
}

// sumOfDoubleEvenPlace adds up all digits in even positions from the right
// Each even-position digit is doubled first, then passed to getDigit
int sumOfDoubleEvenPlace(long long number)
{
    int position = 1;
    int sum = 0;

    while (number > 0)
    {
        int digit = number % 10;
        if (position % 2 == 0)
        {
            sum += getDigit(digit * 2);
        }
        number = number / 10;
        position++;
    }
    return sum;
}

// getPrefix returns the first k digits of the number
// For example, getPrefix(4388576018410707, 2) returns 43
long long getPrefix(long long number, int k)
{
    int size = getSize(number);

    if (size <= k)
    {
        return number;
    }
    else
    {
        return number / (long long)pow(10, size - k);
    }
}

// prefixMatched checks if the number starts with d
// It figures out how many digits d has, grabs that many from the front,
// and compares the two
bool prefixMatched(long long number, int d)
{
    int k = getSize(d);
    return getPrefix(number, k) == d;
}

// isValid ties everything together
// It checks the length, the prefix, and the Luhn checksum
bool isValid(long long number)
{
    int size = getSize(number);
    bool validLength = (size >= 13 && size <= 16);

    bool validPrefix = (prefixMatched(number, 4) ||
                        prefixMatched(number, 5) ||
                        prefixMatched(number, 6) ||
                        prefixMatched(number, 37));

    int total = sumOfDoubleEvenPlace(number) + sumOfOddPlace(number);
    bool validChecksum = (total % 10 == 0);

    return validLength && validPrefix && validChecksum;
}

int main()
{
    long long cardnumber;
    cout << "Enter a credit card number (add LL at the end): ";
    cin >> cardnumber;

    if (isValid(cardnumber))
    {
        cout << "The number " << cardnumber << " is valid";
    }
    else
    {
        cout << "The number " << cardnumber << " is invalid";
    }

    return 0;
}
