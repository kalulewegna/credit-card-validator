# Credit Card Validator

This program checks whether a credit card number is valid. It uses the Luhn algorithm, which was created by Hans Luhn at IBM in 1954. The same method is still used today to catch mistyped or fake card numbers before they get processed.

## What the program checks

Three things have to be true for a card number to pass.

First, the length. A valid card number has between 13 and 16 digits. Anything shorter or longer fails immediately.

Second, the starting digits. Visa cards start with 4. MasterCard starts with 5. American Express starts with 37. Discover starts with 6. If the number does not start with one of those, it fails.

Third, the Luhn checksum. This is where most of the work happens.

## How the Luhn checksum works

The program reads the number from right to left.

For digits in odd positions (1st, 3rd, 5th from the right), it just adds them as they are.

For digits in even positions (2nd, 4th, 6th from the right), it doubles each one. If doubling gives a two digit number, the two digits are added together to make a single digit. For example, 8 doubled is 16, and 1 + 6 = 7.

Then it adds all those results together. If the final total is divisible by 10, the number passes. If not, it fails.

## The functions

getSize takes a number and returns how many digits it has. It does this by dividing by 10 repeatedly and counting how many times it can do that.

getDigit takes a number and returns a single digit. If the number is below 10, it returns it as is. Otherwise it adds the tens digit and the ones digit together.

sumOfOddPlace walks through the number from the right, picks out the digits in odd positions, and adds them up.

sumOfDoubleEvenPlace does the same walk but picks the even positions, doubles each digit, runs it through getDigit, and adds the result.

getPrefix returns the first k digits of a number. It figures out the total size and divides by 10 raised to the right power to chop off the end.

prefixMatched checks whether a number starts with a given digit or digits. It works out how many digits the target has, grabs that many from the front, and compares.

isValid pulls everything together. It checks the length, checks the prefix, runs the Luhn sum, and returns true only if all three pass.

## How to build and run

Compile it with g++:

g++ credit_card.cpp -o validator

Then run it:

./validator

It will ask for a card number. Type the number followed by LL. The LL tells C++ to treat it as a long long, which matters because regular int cannot hold 16 digits.

Example:

Enter a credit card number (add LL at the end): 4388576018410707LL
The number 4388576018410707 is valid

Enter a credit card number (add LL at the end): 4388576018402626LL
The number 4388576018402626 is invalid
