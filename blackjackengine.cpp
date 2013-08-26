//---------------------------------------------------------------------------
//Programmer:  Matthew Thorne
//Date: 11/22/11
//cocs 220 project card 
//--------------------------------------------------------------------------- 

#include <iostream>
#include "blackjack.h"



using namespace std;
int main()
{
	char choice2;
	char choice;
	int A;
	int B;
	int win;
	int result1 = 0;
	int result = 0;
	int results = 0;
	cout << "welcome to casino game!" << endl;
	cout << "welcome to blackjack do you want to play? (y,n)" << endl;
	cin >> choice;
	cout << "How much money would you like to play with?" << endl;
	cin >> A;
	if (choice == 'y' || choice == 'Y')
	{	
		cout << "How much money do you want to bet?" << endl;
		cin >> B;
		while (B > 0)
		{
			blackjack something;
			result1 = something.checkcards(B, A);
			result = something.Comparescore(B, A);
			cout << result1 << endl;
			cout << result << endl;
			 if(result1 != 0 and result != 0)
				results = result - result1;
			else
				results = result + result1;
			win = result - A;
			if (win > 0)
				win = win;
			else if (win < 0)
				win = 0;
			cout << "Your Initial Balance: " << A << endl;
			cout << "Your current balance: " << results << endl;
			cout << "You win: " << win << endl;
			A = result;
			cout << "Would you like to play again?" << endl;
			cin >> choice2;
			if ( choice2 == 'y' || choice2 == 'Y')
			{
				cout << "How much money do you want to bet?" << endl;
				cin >> B;
			}	
			else
				break;
			
		}

	}
	else
	{
	cout << " wrong choice" << endl;
		

	}
return 0;
}
