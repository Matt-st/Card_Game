//---------------------------------------------------------------------------
//Programmer:  Matthew Thorne
//Date: 11/27/11
//cocs 220 project card 
//---------------------------------------------------------------------------  
#include <iostream>
#include "blackjack.h"
#include "poker.h"
using namespace std;
int main()
{	
	char test;
	char selection;
	do 
	{//ask player what they want to play loop checks for correct input
	cout << "-----------------------------------------------" << endl;
	cout << "|               Welcome To Casino!            |" << endl;
	cout << "| Would you like to play Poker 'P', or        |" << endl;
	cout << "| Would you like to play BlackJack 'B',       |" << endl;
	cout << "-----------------------------------------------" << endl;
	cin >> selection;		
	}while(selection != 'p' and selection != 'P' and selection != 'B' and selection != 'b');
	if(selection == 'P' || selection == 'p')
	{	
	int balance = 0;
	int currentbalance = 0;
	char decision;
	char choice;
	int winning = 0;
	int amount = 0;
	int bet = 0;
	do 
	{//make sure input is correct type of input
	cout << "-----------------------------------------------" << endl;
	cout << "|        Welcome To Casino Poker Game!        |" << endl;
	cout << "| How much money would you like to play with? |" << endl;
	cout << "-----------------------------------------------" << endl;
	cin >> amount;
	}while(amount <= 0);
	int money = amount;
	int M = amount;
	while(amount != 0)
	{
		do
		{//make sure input is correct type of input
		cout << "Do you want to play Game? (Y,N)" << endl;
		cin >> choice;
		}while(choice != 'Y' and choice != 'y' and choice != 'N' and choice != 'n');
		if (choice == 'y'|| choice == 'Y')//choose to play
		{	
			do
			{ //start do while
			do{//make sure input is correct type of input
			cout << "Would you like to test the poker game?(y,n)" << endl;
			cin >> test;
			}while(test != 'Y' and test != 'y' and test != 'N' and test != 'n');
			if( test == 'y' || test == 'Y')//choose to test
			{
			do{//make sure input is correct type of input
				cout << "How much do you want to bet?" << endl;
				cin >> bet;//get the bet
			}while(bet <= 0 || bet > amount);//have to bet an amount greater then 0
				Poker z;//create poker object
				z.TestHand();//call test hand
				//show hand
				money = money - bet;//money that is left over after - bet 
					winning = z.CheckHands(bet);//calling check function
					currentbalance = money + winning;//finding balance
					if ( winning < 0)//sets winning to 0
						winning = 0;
					else
						winning = winning;
		cout << "Your Initial Balance Was: $ " << M << endl;
		cout << "Your Current Balance Is: $ " << currentbalance << endl;
		cout << "You Win: $ " << winning << endl;
		amount = currentbalance;
		if(amount == 0)//if they are broke
		{
			cout << "Game Over" << endl;
			break;
		}


				
			}//end if
			else
			{//begin else
				do{
				cout << "How much do you want to bet?" << endl;
				cin >> bet;//get bet
				}while(bet <= 0 || bet > amount);
				if( bet == amount)//if player goes all in
				{
					cout << "All IN!!!!!!" << endl;
					Poker x;//create object of poker
					x.Hand();//call hand function
					x.Show();//show the cards
					money = amount;
					money = money - bet;
					winning = x.CheckHands(bet);//evaluate the hand
					currentbalance = money + winning;
					if ( winning < 0)
						winning = 0;
					else
						winning = winning;


		cout << "Your Initial Balance Was: $ " << M << endl;
		cout << "Your Current Balance Is: $ " << currentbalance << endl;
		cout << "You Win: $ " << winning << endl;
		amount = currentbalance;
		if(amount == 0)//if current balance is 0 break out
		{
			cout << "Game Over" << endl;
			break;
		}
		do{
		cout << "You want play again? (y,n) " << endl;
		cin >> decision;//check if player wants to play again
		}while(decision != 'Y' and decision != 'y' and decision != 'N' and decision != 'n');	
				}//end else if
				else
				{
					Poker x;//create poker object
					x.Hand();//call hand function
					x.Show();//show hand
					money = amount;
					money = money - bet;
					winning = x.CheckHands(bet);
					currentbalance = money + winning;
					if ( winning < 0)//sets winning to 0 
						winning = 0;
					else
						winning = winning;


		cout << "Your Initial Balance Was: $ " << M << endl;
		cout << "Your Current Balance Is: $ " << currentbalance << endl;
		cout << "You Win: $ " << winning << endl;
		amount = currentbalance;
		if(amount == 0)//if current balance is 0 break out
		{
			cout << "Game Over" << endl;
				break;
		}
		do{
		cout << "You want play again? (y,n) " << endl;
		cin >> decision;//find out if player wants to keep playing
		}while(decision != 'Y' and decision != 'y' and decision != 'N' and decision != 'n');		
		
				}//end else
				}//end test else
			}while (decision == 'y');//end do while
			}//end if
			else
			{
				break;
			}
	}//end while
	}//end selection if
//begins blackjack main
else if(selection == 'B' || selection == 'b')
{
	char choice2;
	char choice;
	int A, B, C, win;	
	int result1 = 0;
	int result = 0;
	int results = 0;
	int insurance = 0;
	
	cout << "welcome to casino game!" << endl;
	cout << "welcome to blackjack" << endl;
	choice = 'y';
	
	do{
	cout << "How much money would you like to play with?" << endl;
	cin >> A;
	}while(A <= 0);//check input
	int m = A;//set seed to m
	do{//start loop for amount must be greater then 0
		if (choice == 'y' || choice == 'Y')//if they want to play
		{	do{
			cout << "How much money do you want to bet?" << endl;
			cin >> B;
				if(A == 0 )//if they are broke
				{
					cout << "Game Over" << endl; 
					break;
				}
			}while(B <= 0 || B > A);
			while (B > 0)
			{	C = A-B;//total minus bet
				insurance = .5 * B;
				blackjack something;
				result1 = something.checkcards(B, A);
				if( result1 > insurance)
				{
					cout << "Your Initial Balance: " << m << endl;
					cout << "Your current balance: " << result1 << endl;
					cout << "You win: " << 0 << endl;
					A = result1;
					if(A == 0 )//if they are broke
					{
						cout << "Game Over" << endl;
						break;
					}
				}//end if	
				else if (result1 == insurance)
				{
					result = something.Comparescore(B, A);
					results = result - result1;
					win = results - A;
					if (win > 0)
					win = win;
					else if (win < 0)
					win = 0;
					cout << "Your Initial Balance: " << m << endl;
					cout << "Your current balance: " << results << endl;
					cout << "You win: " << win << endl;
					A = results;
					if(A == 0)//if they are broke
					{
						cout << "Game Over" << endl;
						break;
					}
				}//end else if
				else if ( (result1 != 0 and A != 0)and(result1 == A))
				{
					cout << "Your Initial Balance: " << m << endl;
					cout << "Your current balance: " << A << endl;
					cout << "You win: " << 0 << endl;
					if(A == 0)//if they are broke
					{
						cout << "Game over" << endl;
						break;
					}
				}//end else if
				else if(result1 == C)
				{
				
					result = something.Comparescores(B,A);
					if(result == 999999)
					{
						cout << "Your Initial Balance: " << m << endl;
						cout << "Your current balance: " << A << endl;
						cout << "You win: " << 0 << endl;
					}	
					else if(result == 0)//sets result = to 0
					{
						result1 = 0;
						A = A - B;
						cout << "Your Initial Balance: " << m << endl;
						cout << "Your current balance: " << A << endl;
						cout << "You win: " << 0 << endl;
					}	
					else
					{	
						result1 = (A - B) + result; 
						cout << "Your Initial Balance: " << m << endl;
						cout << "Your current balance: " << result1 << endl;
						cout << "You win: " << result << endl;
						A = result1;
					}
					if( A == 0)//if they are broke
					{
						cout << "Game Over" << endl;
						break;
					}
				}//end else if
				else
				{
					result = something.Comparescore(B ,A );
					results = result + result1;
					win = result - A;
					if (win > 0)
					win = win;
					else if (win < 0)
					win = 0;
					cout << "Your Initial Balance: " << m << endl;
					cout << "Your current balance: " << results << endl;
					cout << "You win: " << win << endl;
					A = results;	
				}//end else
				if (A == 0)//if they are broke
				{
					cout << "Game Over " << endl;
					break;
				}
				do{
				cout << "Would you like to play again?(y,n)" << endl;
				cin >> choice;
				}while(choice != 'Y' and choice != 'y' and choice != 'N' and choice != 'n');
			
				if ( choice == 'y' || choice == 'Y')
				{	do{
					cout << "How much money do you want to bet?" << endl;
					cin >> B;
					}while(B <= 0 || B > A);
				}//end if	
				else
					break;
			
			}//end while
		if(choice == 'n' || choice == 'N' )
			break;
		}//end if
	}while(A > 0);//end do while for checking to check if player is broke
	}
	else
	
return 0; 
}
