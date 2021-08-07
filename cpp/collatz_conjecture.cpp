#include <iostream>
using namespace std;

int getNumber();
int collatz(int inputNum);

int main() {
  int num = 0;
  int count = 0;
  bool keepGoing = true;
  bool validInput = false;
  char userInput = 'y';

  while (keepGoing == true) {
    num = getNumber();
    while (num != 1) {
      num = collatz(num);
      count += 1;
    }
    cout << "It took " << count << " iterations to reach 1.\n";
    validInput = false;

    while (validInput == false) {
      cout << "Would you like to continue? (y/n): ";
      cin >> userInput;
      if (userInput == 'y') {
        validInput = true;
      }
      else if (userInput == 'n') {
        validInput = true;
        keepGoing = false;
        cout << "Goodbye.\n";
      }
      else {
        cout << "Invalid input.  Please try again.\n";
      }
    }
  }
  return 0;
}

int getNumber() {
  int userInput = 0;

  while (userInput <= 1) {
    cout << "Please enter a number greater than 1: ";
    cin >> userInput;
    if (userInput <= 1) {
      cout << "Invalid input. Please try again.\n";
    }
  }
  return userInput;
}

int collatz(int inputNum) {
  int outputNum = 0;

  if ((inputNum % 2) == 0) {  //If even, divide number by two.
    outputNum = inputNum / 2;
  }
  else if ((inputNum % 2) != 0) { //If odd, multiply number by 3, and add 1.
    outputNum = inputNum * 3 + 1;
  }
  else {
    cout << "Error collatz(): Invalid input.\n";
  }
  return outputNum;
}
