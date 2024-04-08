#include <iostream>
#include <iomanip>
using namespace std;


// function to display static balance
void displayStaticBalance(double openingAmount, int numYears, int months, double interest) {
  // declare variables
  double depositedAmount = 0;
  double total;
  double interestAmount;
  double closingBalance;
  double interestAccrued = 0;
  double interestRate = interest/100;

  // print amounts 2 digits after the .
  std::cout << std::setprecision(2) << std::fixed;

  cout << "Balance and Interest W/o Additional Monthly Deposits" << endl;
  cout << "*******************************" << endl;
  printf("%-8s%-21s%-7s\n", "Year", "End of Year Balance", "Interest");

  total = openingAmount + depositedAmount;
  // calculate interest amount, total, and closing balance each month
  for (int i = 1; i <= months; i++ ) {
    interestAmount = total * (interestRate/12);
    closingBalance = total + interestAmount;
    interestAccrued += closingBalance - total;
  // print closing balance and interest end of each year
    if (i % 12 == 0) {
      printf("%-8d%-21f%-7f\n", i/12, closingBalance, interestAccrued);
     // cout << i/12 << " " << closingBalance << " " << interestAccrued << endl;
      interestAccrued = 0;
    }
    // update closing balance
    total = closingBalance;
  }
}
// display balance with monthly deposits
void displayBalance(double openingAmount, double depositedAmount, int numYears, int months, double interest) {
  std::cout << std::setprecision(2) << std::fixed;
  double total;
  double interestAmount;
  double closingBalance;
  double interestRate = interest/100;
  double interestAccrued = 0;
  cout << "Balance and Interest W/ Additional Monthly Deposits" << endl;
  cout << "********************************" << endl;
  cout << endl;
  printf("%-8s%-21s%-7s\n", "Year", "End of Year Balance", "Interest");
  total = openingAmount + depositedAmount;

  for (int i = 1; i <= months; i++) {
  interestAmount = total * (interestRate/12);
  closingBalance = total + interestAmount;

  interestAccrued += closingBalance - total;

  if (i % 12 == 0 ) {
    printf("%-8d%-21f%-7f\n", i/12, closingBalance, interestAccrued);
    //cout << i<< " " << closingBalance << " " << interestAccrued << endl;
    interestAccrued = 0;
  }
  // update balance with monthly deposit
  total = closingBalance + depositedAmount;
  }


}

// function to display menu
void displayMenu() {
  cout << "Data Input" << endl;
  cout << "1.Initial Investment Amount: $" << endl;
  cout << "2.Monthly Deposit: $" << endl;
  cout << "3.Annual Interest: " << endl;
  cout << "4.Number of Years: " << endl;
  cout << "5.Continue" << endl;
  cout << "6.Exit" << endl;
}

int main() {
  // declare variables
  int userChoice;
  double openingAmount = 1;
  double depositedAmount = 0;
  double interest;
  int numYears = 1;
  int months = 12;

  // loop to get user input
  while(userChoice != 6 || userChoice != 5) {
    // display menu function
    displayMenu();
    cin >> userChoice;
    // if statement to get user input or display balances
    if (userChoice == 1) {
      cout << "Enter Initial Investment Amount: " << endl;
      cin >> openingAmount;

    }
    else if (userChoice == 2) {
      cout << "Enter Monthly Deposit: " << endl;
      cin >> depositedAmount;

    }
    else if (userChoice == 3) {
      cout << "Enter Annual Interest: " << endl;
      cin >> interest;

    }
    else if (userChoice == 4) {
      cout << "Enter Number of Years: " << endl;
      cin >> numYears;

    }
    else if (userChoice == 5) {
      // call display functions
      months = numYears * 12;
      displayStaticBalance(openingAmount,numYears, months, interest);
      cout << endl;
      displayBalance(openingAmount, depositedAmount, numYears, months, interest);
      cout << endl;
    }
    else if (userChoice == 6) {
      cout << "Exiting the program" << endl;
      break;
    }
    else {
      cout << "Invalid input" << endl;
    }
  }

  return 0;
}
