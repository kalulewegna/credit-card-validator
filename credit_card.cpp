#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Read number into a vector
vector<int> readCardNumber();
int getPrefix(vector<int> number, int k);
bool prefixMatched(vector<int> number);
int getSize(vector<int> number);
int sumOfOddPlace(vector<int> number);
int getDigit(int number);
int sumOfDoubleEvenPlace(vector<int> number);
bool isValid(vector<int> number);

// Return true if sum of (sum of doubles) and (sum of odds) is divisible by 10 and prefixMatch is true
bool isValid(vector<int> number)
{
    if (((sumOfDoubleEvenPlace(number) + sumOfOddPlace(number)) % 10 == 0) &&
        prefixMatched(number) &&
        13 <= getSize(number) && getSize(number) <= 16)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int sumOfDoubleEvenPlace(vector<int> number)
{
    int sum = 0;
    // Start at position i = 0 and increment through with steps of 2
    for (int i = 0; i < (int)number.size(); i += 2)
    {
        int digit = number[i];
        // Double even number
        digit = digit * 2;
        sum += getDigit(digit);
    }
    return sum;
}

// Return this number if it is a single digit, otherwise, return the sum of the two digits
int getDigit(int number)
{
    if (number < 10)
    {
        return number;
    }
    else
    {
        return number / 10 + number % 10;
    }
}

// Return sum of odd place digits in number
int sumOfOddPlace(vector<int> number)
{
    int sum = 0;
    for (int i = 1; i < (int)number.size(); i += 2)
    {
        sum += number[i];
    }
    return sum;
}

// Return the number of digits in number
int getSize(vector<int> number)
{
    return number.size();
}

// Return true if the digit d is a prefix for number
bool prefixMatched(vector<int> number)
{
    if ((getPrefix(number, 1)) == 4 ||
        (getPrefix(number, 1)) == 5 ||
        (getPrefix(number, 2)) == 37 ||
        (getPrefix(number, 1)) == 6)
    {
        return true;
    }
    else
    {
        return false;
    }
}

vector<int> readCardNumber()
{
    std::string number;
    std::cout << "Enter number: \n";
    std::cin >> number;

    std::vector<int> card_digits;

    for (int i = 0; i < (int)number.size(); ++i)
    {
        // Convert number into an integer
        card_digits.push_back(number[i] - '0');
    }

    return card_digits;
}

// Return the first k number of digits from number.
int getPrefix(std::vector<int> number, int k)
{
    int k_prefix = 0;
    int length = number.size();

    if (k > length)
    {
        k = length;
    }

    for (int i = 0; i < k; i++)
    {
        k_prefix = k_prefix * 10 + number[i];
    }

    return k_prefix;
}

int main()
{
    vector<int> number = readCardNumber();
    cout << "Prefix: " << getPrefix(number, 3) << "\n";
    cout << "Matched: " << prefixMatched(number) << "\n";
    cout << "Size: " << getSize(number) << "\n";
    cout << "Sum of Odd Numbers: " << sumOfOddPlace(number) << "\n";
    cout << "Sum of double even numbers: " << sumOfDoubleEvenPlace(number) << "\n";
    cout << "Valid: " << isValid(number) << "\n";

    return 0;
}



