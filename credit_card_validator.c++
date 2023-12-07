#include<iostream>

// Function to get the sum of the digits of a number
int getDigit(const int number);

// Function to sum the odd-positioned digits in the card number
int sumOddDigit(std::string cardNumber);

// Function to sum the even-positioned digits in the card number
int sumEvenDigit(std::string cardNumber);

int main() {
  // Declare a string variable to store the credit card number
  std::string cardNumber;
  
  // Declare a variable to store the result of the validation
  int result = 0;

  // Prompt the user to enter a credit card number
  std::cout << "Enter a credit card number: ";
  std::cin >> cardNumber;

  // Calculate the result by summing even and odd digits
  result = sumEvenDigit(cardNumber) + sumOddDigit(cardNumber);

  // Check if the result is divisible by 10 to determine the validity
  if (result % 10 == 0) {
    std::cout << cardNumber << " is valid" << "\n";
  } else {
    std::cout << cardNumber << " is not valid";
  }

  // The program terminates with the main function's return statement
  return 0;
}

// Function to get the sum of the digits of a number
int getDigit(const int number) {
  return (number % 10) + (number / 10 % 10);
}

// Function to sum the odd-positioned digits in the card number
int sumOddDigit(std::string cardNumber) {
  int sum = 0;
  // Iterate through the card number in reverse, starting from the last digit
  for (int i = cardNumber.size() - 1; i >= 0; i -= 2) {
    // Add the digit or the sum of its digits to the overall sum
    sum += getDigit(cardNumber[i] - '0');
  }
  return sum;
}

// Function to sum the even-positioned digits in the card number
int sumEvenDigit(std::string cardNumber) {
  int sum = 0;
  // Iterate through the card number in reverse, starting from the second-to-last digit
  for (int i = cardNumber.size() - 2; i >= 0; i -= 2) {
    // Multiply the digit by 2 and add the sum of its digits to the overall sum
    sum += getDigit((cardNumber[i] - '0') * 2);
  }
  return sum;
}
