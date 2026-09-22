This is a credit card validator. It takes a card number and tells you if it's valid or not.

The validation is based on the Luhn algorithm. Hans Luhn came up with it at IBM in the 1950s and card companies still use it today.

A card number has to pass three checks. It needs 13 to 16 digits. It has to start with 4, 5, 6, or 37 depending on the card type. And it has to pass the Luhn checksum.

The checksum works by walking through the number from right to left. Digits in odd positions get added as they are. Digits in even positions get doubled first. If doubling gives you two digits, you add those two together. So 8 doubled is 16, and 1 plus 6 is 7. Then everything gets added up. If the total is divisible by 10, it passes.

The code is broken into small functions. "getSize" tells  how many digits a number has. It does this by dividing by 10 repeatedly.
 getDigit returns a single digit. If the number is under 10 it returns it as is, otherwise it adds the two digits together.
Then  "sumOfOddPlace" adds up the odd-position digits. 
"sumOfDoubleEvenPlace" doubles the even-position digits and adds them. 
"getPrefix" gives you the first k digits of a number. 
prefixMatched checks if a number starts with a specific digit. 
"isValid" calls all of them and returns true only if the length, prefix, and checksum all pass.

Try it with 4388576018410707. That one is valid. 4388576018402626 is not.
