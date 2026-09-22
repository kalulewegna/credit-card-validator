This program checks if a credit card number is valid. It uses the Luhn algorithm. That algorithm was made by Hans Luhn at IBM in the 1950s. It is still used today.

The program checks three things. First, the length. The number must have 13 to 16 digits. Second, the prefix. Visa starts with 4. MasterCard starts with 5. American Express starts with 37. Discover starts with 6. Third, the Luhn checksum.

For the checksum, the program reads the number from right to left. Digits in odd positions are added as they are. Odd positions are the 1st, 3rd, 5th from the right. Digits in even positions are doubled first. If doubling gives two digits, those two digits are added together. For example, 8 doubled is 16. Then 1 plus 6 is 7. All the results are added up. If the total is divisible by 10, the number passes.

The code is split into small functions. getSize counts how many digits a number has. It divides by 10 over and over and counts each time. getDigit returns a single digit. If the number is below 10, it returns it as is. Otherwise it adds the two digits together. sumOfOddPlace adds up the digits in odd positions. sumOfDoubleEvenPlace doubles the digits in even positions and adds them up. getPrefix returns the first k digits of a number. prefixMatched checks if a number starts with a given digit. isValid puts it all together. It checks the length, the prefix, and the Luhn sum. It returns true only if all three pass.

A valid number is 4388576018410707. An invalid one is 4388576018402626.
