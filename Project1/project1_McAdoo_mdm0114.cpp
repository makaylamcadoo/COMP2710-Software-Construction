//Makayla McAdoo
//mdm0114
//project1_McAdoo_mdm0114.cpp
//Compile - g++ project1_McAdoo_mdm0114.cpp -o Project1.out
//Run - ./Project1.out
//Spoke to Kyle Ackerman about if and while statements


#include <iostream> 
using namespace std;


int main()
{

   int numPayment = 0;
   float loan, interestRate, interestRateC, monthlyPayments, totalInterest, interestTotal, interest_payment, principal_payment;
   int currentMonth;
	//CURRENCY FORMATTING
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   std::cout.precision(2);

	//USER INPUT
   cout <<"\nLoan Amount: ";
   cin >> loan;
	
	//Program will not move forward until a positive loan is entered
   if (loan < 0){
      while (loan < 0) {
         cout << "\n\t***Loan Amount must be a positive value***\n";
         cout << "\nLoan Amount: ";
         cin >> loan;
      }
   }

	//USER INPUT
   cout << "Interest Rate (% per year): ";
   cin >> interestRate;

	//Program will notmove forward until a positive interest rate is entered
   if (interestRate < 0) {
      while (interestRate < 0) {
         cout << "\n\t***Interest Rate must be a positive value***\n";
         cout << "\nInterest rate: ";
         cin >> interestRate;
      }
   } 
	//GET PROPER INTEREST RATES FOR CALCULATIONS
   interestRate /= 12;
   interestRateC = interestRate / 100;
   cout << "Monthly Payments: ";
   cin >> monthlyPayments;

	//Program will not move forward until a monthly payment is sufficient
   if (monthlyPayments <= loan * interestRateC) {
      while (monthlyPayments < interestRateC * loan) {
         cout << "\n\t***Monthly payment must be larger than monthly interest***\n";
         cout << "\nMonthly Payments: ";
         cin >> monthlyPayments;
      }
   }
   cout << endl;


	// AMORTIZATION TABLE
   cout << "*****************************************************************\n";
   cout <<"\tAmortization Table\n";
   cout << "*****************************************************************\n";
   cout << "Month\tBalance\t\tPayment\tRate\tInterest\tPrincipal\n";

   currentMonth = 0;

		
	//Loop to fill table
   while (loan > 0) {
   	
      if (currentMonth == 0) {
         cout << currentMonth++ << "\t$" << loan;
      
         if (loan < 1000) cout << "\t";
         cout << "\t" << "N/A\tN/A\tN/A\t\tN/A\n";
      
      }
      
      else {
      	//calculations
         interest_payment = loan * interestRateC;
         principal_payment = monthlyPayments - interest_payment;
      
         interestTotal += interest_payment;
      	//code for last payment
         if (loan > monthlyPayments) {
            loan -= principal_payment;
         }
         else { 			
            principal_payment = loan;
            monthlyPayments =  loan + interest_payment;
            loan = 0;
         } 
      	
      
      
      	//formatting			
         if (loan < 1000) {
            cout << currentMonth++;
            cout << "\t$" << loan;
         
            cout << "\t\t$" << monthlyPayments
               << "\t" << interestRate
               << "\t$" << interest_payment
               << "\t\t$" << principal_payment << "\n";
         	
         }
         else { 
            cout << currentMonth++
                 << "\t$" << loan
                  <<"\t$" << monthlyPayments
                  << "\t" << interestRate 
                       << "\t$" << interest_payment
                  << "\t\t$" << principal_payment << "\n";
         }
      }
   }
   cout << "****************************************************************\n";
   cout << "\nIt takes " << --currentMonth << " months to pay off "
             << "the loan.\n"
             << "Total interest paid is: $" << interestTotal;
   cout << endl << endl;
   return 0;
	
} 




