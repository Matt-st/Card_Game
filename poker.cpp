//---------------------------------------------------------------------------
//Programmer:  Matthew Thorne
//Date: 11/27/11
//cocs 220 project card 
//---------------------------------------------------------------------------  

#include <iomanip>
#include <iostream>
#include "cardclass.h"
#include "poker.h"
using namespace std;
/*constructor for poker class. At this point the constructor for my parent class "class card" has run and the deck has been initialized to 52 cards.  In this constructor the int Xcard (which is used as a incrementor for my receive card function) is initialized to 0.  Also the function from my parent class shufflecard has been called to shuffle my deck of cards.*/
Poker::Poker()
{	
	Xcard = 0;
	shufflecard();
}
/*This function is used to show the player there first hand.  It uses a for loop that iterates five times to show all five cards.  I call the getcard function which iterates me through my shuffled deck one by one starting at the first memory location of 0.  when this function returns it gives me my index for the card that i want to show to the player.  This index(tmp) goes into a switch statment, that checks it's value against the cases in the switch statement.  Then when it finds the correct statement it calls functioon inside that case statement to show the card.  At the end of every for loop i use my private array firsthand to copy the card info ( the num and Pic) into each corresponding i value index.  Doing this gives me an array that will just deal with my card hand.  Then I call the redraw function.*/
void Poker::Hand()
{
	ACard tmp2;
	for(int i = 0; i < 5; i++)
	{
		ACard tmp;
		tmp = getcard();
		tmp2 = tmp;
		switch(tmp.Num)
			{
			case 1:
				cardace(tmp.Pic);
				break;
			case 2:
				cardtwo(tmp.Pic);
				break;
			case 3:
				cardthree(tmp.Pic);
				break;
			case 4:
				cardfour(tmp.Pic);
				break;
			case 5:
				cardfive(tmp.Pic);
				break;
			case 6:
				cardsix(tmp.Pic);
				break;
			case 7:
				cardseven(tmp.Pic);
				break;
			case 8:
				cardeight(tmp.Pic);
				break;
			case 9:
				cardnine(tmp.Pic);
				break;
			case 10:
				cardten(tmp.Pic);
				break;
			case 11:
				cardjack(tmp.Pic);
				break;
			case 12:
				cardqueen(tmp.Pic);
				break;
			case 13:
				cardking(tmp.Pic);
				break;
			}
		Firsthand[i].Num = tmp2.Num;//initialize my array to my card hand
			for(int p = 0; p < 4; p++)
				Firsthand[i].Pic[p] = tmp2.Pic[p];
			
	}Redraw();//redraw funtion 		
}
/* This function gives the player the option to hold or redraw there card. It does this useing a for loop that iterates five times to check for every card in my hand. The player has the option to choose 1 or 0 to make a desicion.  at the end of each loop i initialize the position i in my pokerhand array so at the end of this function the player now has a finalized hand that will be sorted now.*/
void Poker::Redraw()
{
	for(int i = 0; i < 5; i++)
	{
		int select;
		if(Firsthand[i].Num == 1)
		{
		cout << "A" << " " << Firsthand[i].Pic << ": Hold (1) OR REDRAW (0)?" << endl;
		cin >> select;
		}
		else if(Firsthand[i].Num < 11)
		{
			cout << Firsthand[i].Num << " " << Firsthand[i].Pic << ": Hold (1) OR REDRAW (0)?" << endl;
			cin >> select;
		}
		else if(Firsthand[i].Num == 11)
		{
			
			cout << "J" << " " << Firsthand[i].Pic << ": Hold (1) OR REDRAW (0)?" << endl;
			cin >> select;
		}
		else if(Firsthand[i].Num == 12)
		{
			cout << "Q" << " " << Firsthand[i].Pic << ": Hold (1) OR REDRAW (0)?" << endl;
			cin >> select;
		}
		else if(Firsthand[i].Num == 13)
		{
			cout << "K" << " " << Firsthand[i].Pic << ": Hold (1) OR REDRAW (0)?" << endl;
			cin >> select;
		}		
		if (select == 0)
		{
			ACard tmp2;
			tmp2 = getcard();
			pokerhand[i].Num = tmp2.Num;
				for(int p = 0; p < 4; p++)
					pokerhand[i].Pic[p] = tmp2.Pic[p];
		}
		else
		{
			pokerhand[i].Num = Firsthand[i].Num;
			for(int p = 0; p < 4; p++)
				pokerhand[i].Pic[p] = Firsthand[i].Pic[p];
		}
	}		
}
/*This function is used to show a sorted array of cards AKA the players hand.  The first thing to occur in this function is the array gets sorted by selection sort.  This uses another for loop that iterates five times. Inside the for loop a tmp is created that is set to the returning value of the function recievecard.  Then tmp goes into a switch statement to check it's num value against the case values to print out the correct cards. */	
void Poker::Show()
{
	Selectionsort();
	for(int i = 0; i < 5; i++)
	{
		ACard tmp;
		tmp = Receivecard();
		switch(tmp.Num)
			{
			case 1:
				cardace(tmp.Pic);
				break;
			case 2:
				cardtwo(tmp.Pic);
				break;
			case 3:
				cardthree(tmp.Pic);
				break;
			case 4:
				cardfour(tmp.Pic);
				break;
			case 5:
				cardfive(tmp.Pic);
				break;
			case 6:
				cardsix(tmp.Pic);
				break;
			case 7:
				cardseven(tmp.Pic);
				break;
			case 8:
				cardeight(tmp.Pic);
				break;
			case 9:
				cardnine(tmp.Pic);
				break;
			case 10:
				cardten(tmp.Pic);
				break;
			case 11:
				cardjack(tmp.Pic);
				break;
			case 12:
				cardqueen(tmp.Pic);
				break;
			case 13:
				cardking(tmp.Pic);
				break;
			}
	}
	
}
/*Used to iterate through the pokerhand array.  An important issue to note is that this function uses a post iterator.*/
ACard Poker::Receivecard()
{
	return pokerhand[Xcard++];
}
/*This function uses the sorting algorithm selection sort to sort my new array of pokerhand that has five cards.  an Important thing to remember is that the ace is set to a value of one so it will always be first in any hand after it has gone through this function*/
void Poker::Selectionsort()
{ 
	int n = 5;
	int count = 0;
	int min,j;
	for(int i = 0; i < n; i++)
	{
		min = i;
		for(j = i +1; j < n; j++)
		{
			if (pokerhand[j].Num < pokerhand[min].Num)
			{
				min = j;
			}
		}
		if(min != 1)
		{
			ACard temp = pokerhand[i];
			pokerhand[i] = pokerhand[min];
			pokerhand[min] = temp;
			
		}
	}
}
/*This function is used to check what the players hand is.  It brings in the amount of money that the plyer bets then it returns how much he wins or loses.*/
int Poker::CheckHands(int money)
{	
/*This if statement checks the hand for a royal flush.  There is only one case for that.*/
	if(pokerhand[0].Num == 1 and pokerhand[1].Num == 10 and pokerhand[2].Num == 11 and pokerhand[3].Num == 12 and pokerhand[4].Num == 13 and pokerhand[0].Pic[2] == pokerhand[1].Pic[2] and pokerhand[1].Pic[2] == pokerhand[2].Pic[2] and pokerhand[2].Pic[2] == pokerhand[3].Pic[2] and pokerhand[3].Pic[2] == pokerhand[4].Pic[2])
		{
			cout << "royal flush" << endl;
			money = money * 1000;
			return money;
		}
	/*This else if statement checks the hand for a straight flush there is only one case for that.  The way this happens is that all cads should be one greater then the previous so if you subtract one from the greater value card then both cards should be equivalent.*/
	else if(pokerhand[0].Num == pokerhand[1].Num - 1 and pokerhand[1].Num == pokerhand[2].Num -1 and pokerhand[2].Num == pokerhand[3].Num - 1 and pokerhand[3].Num == pokerhand[4].Num -1 and pokerhand[0].Pic[2] == pokerhand[1].Pic[2] and pokerhand[1].Pic[2] == pokerhand[2].Pic[2] and pokerhand[2].Pic[2] == pokerhand[3].Pic[2] and pokerhand[3].Pic[2] == pokerhand[4].Pic[2])
		{
			cout << "straight flush" << endl;
			money = money * 100;
			return money;
		}
	/*This if statement checks for a four of a kind hand.  There are 2 cases where this occurs. Either the first four cards or the last four cards*/ 
	else if((pokerhand[0].Num == pokerhand[1].Num and pokerhand[1].Num == pokerhand[2].Num and pokerhand[2].Num == pokerhand[3].Num) ||( pokerhand[1].Num == pokerhand[2].Num and pokerhand[2].Num == pokerhand[3].Num and pokerhand[3].Num == pokerhand[4].Num ))
		{
			cout << "four card." << endl;
			money = money * 20;
			return money;
		}
	/*This if statement checks for a full house.  there are two cases where this occurs.*/
	else if((pokerhand[0].Num == pokerhand[1].Num and pokerhand[1].Num == pokerhand[2].Num and pokerhand[3].Num == pokerhand[4].Num) ||( pokerhand[0].Num == pokerhand[1].Num and pokerhand[2].Num == pokerhand[3].Num and pokerhand[3].Num == pokerhand[4].Num))
		{
			cout << "full house" << endl;
			money = money * 10;
			return money;
		}
	/*This if statement checks for a flush.  There is only one case when this occurs.*/
	else if( pokerhand[0].Pic[2] == pokerhand[1].Pic[2] && pokerhand[1].Pic[2] == pokerhand[2].Pic[2] && pokerhand[2].Pic[2] == pokerhand[3].Pic[2] && pokerhand[3].Pic[2] == pokerhand[4].Pic[2])
		{		
			cout << "flush" << endl;
			money = money * 8;
			return money;
		}
		/*This if statement is checking for a straight. there is only one case where this occurs.*/
	else if(pokerhand[0].Num == pokerhand[1].Num - 1 and pokerhand[1].Num == pokerhand[2].Num -1 and pokerhand[2].Num == pokerhand[3].Num - 1 and pokerhand[3].Num == pokerhand[4].Num -1)
		{
			cout << "straight" << endl;
			money = money * 6;
			return money;
		}
	/*This if statement checks for three of a kind. There are three cases where this occurs.*/
	else if((pokerhand[0].Num == pokerhand[1].Num and pokerhand[1].Num == pokerhand[2].Num) ||( pokerhand[1].Num == pokerhand[2].Num and pokerhand[2].Num == pokerhand[3].Num) ||( pokerhand[2].Num == pokerhand[3].Num and pokerhand[3].Num == pokerhand[4].Num) )
		{
			cout << "three of a kind" << endl;
			money = money * 4;
			return money;
		}
	else if(pokerhand[0].Num == pokerhand[1].Num and pokerhand[2].Num == pokerhand[3].Num || pokerhand[0].Num == pokerhand[1].Num and pokerhand[3].Num == pokerhand[4].Num || pokerhand[1].Num == pokerhand[2].Num and pokerhand[3].Num == pokerhand[4].Num)
		{
			cout << "2 pair" << endl;
			money = money * 2;
			return money;

		}
	/* This if statement checks for a pair of cards that are jack or higher.  There are a whole lot of cases where this occurs.*/
	else if((pokerhand[0].Num == 1 and pokerhand[1].Num == 1) || (pokerhand[0].Num == 11 and pokerhand[1].Num == 11) || (pokerhand[0].Num == 12 and pokerhand[1].Num == 12) ||( pokerhand[0].Num == 13 and pokerhand[1].Num == 13 )||(pokerhand[1].Num == 1 and pokerhand[2].Num == 1) ||( pokerhand[1].Num == 11 and pokerhand[2].Num == 11) || (pokerhand[1].Num == 12 and pokerhand[2].Num == 12) || (pokerhand[1].Num == 13 and pokerhand[2].Num == 13) || (pokerhand[2].Num == 1 and pokerhand[3].Num == 1) ||( pokerhand[2].Num == 11 and pokerhand[3].Num == 11 )||( pokerhand[2].Num == 12 and pokerhand[3].Num == 12) || (pokerhand[2].Num == 13 and pokerhand[3].Num == 13) || (pokerhand[3].Num == 1 and pokerhand[4].Num == 1) || (pokerhand[3].Num == 11 and pokerhand[4].Num == 11) ||( pokerhand[3].Num == 12 and pokerhand[4].Num == 12) || (pokerhand[3].Num == 13 and pokerhand[4].Num == 13))
		{
			cout << "jack or higher" << endl;
			money = money * 1;
			return money;
		}
		else 
		{
			cout << "you lose"<< endl;
			money = 0;
			return money;
		}

}

void Poker::TestHand()
{
	int B = 0;//test menu
	cout << "To test please select one of the options presented." << endl;
	cout << "1. Royal Straight Flush " << endl;
	cout << "2. Straight Flush" << endl;
	cout << "3. Four Card" << endl;
	cout << "4. Full House" << endl;
	cout << "5. Flush" << endl;
	cout << "6. Straight" << endl; 
	cout << "7. Three of a Kind" << endl;
	cout << "8. Two Pair" << endl;
	cout << "9. Pair (Jack or better)" << endl;
	cin >> 	B;
	
	switch(B)//parameter to check for switch statement
	{
		case 1://royal straight flush
		{ 
			pokerhand[0].Num = 1;
			for(int p = 0; p < 4; p++)
				pokerhand[0].Pic[p] = spade[p];
			pokerhand[1].Num = 10;
			for(int p = 0; p < 4; p++)
				pokerhand[1].Pic[p] = spade[p];
			pokerhand[2].Num = 11;
			for(int p = 0; p < 4; p++)
				pokerhand[2].Pic[p] = spade[p];
			pokerhand[3].Num = 12;
			for(int p = 0; p < 4; p++)
				pokerhand[3].Pic[p] = spade[p];
			pokerhand[4].Num = 13;
			for(int p = 0; p < 4; p++)
				pokerhand[4].Pic[p] = spade[p];
			Show();
			break;
		}
		case 2://Straight Flush
		{
			pokerhand[0].Num = 2;
			for(int p = 0; p < 4; p++)
				pokerhand[0].Pic[p] = spade[p];
			pokerhand[1].Num = 3;
			for(int p = 0; p < 4; p++)
				pokerhand[1].Pic[p] = spade[p];
			pokerhand[2].Num = 4;
			for(int p = 0; p < 4; p++)
				pokerhand[2].Pic[p] = spade[p];
			pokerhand[3].Num = 5;
			for(int p = 0; p < 4; p++)
				pokerhand[3].Pic[p] = spade[p];
			pokerhand[4].Num = 6;
			for(int p = 0; p < 4; p++)
				pokerhand[4].Pic[p] = spade[p];
			Show();
			break;
		}
		case 3://Four Card
		{
			pokerhand[0].Num = 4;
			for(int p = 0; p < 4; p++)
				pokerhand[0].Pic[p] = spade[p];
			pokerhand[1].Num = 4;
			for(int p = 0; p < 4; p++)
				pokerhand[1].Pic[p] = club[p];
			pokerhand[2].Num = 4;
			for(int p = 0; p < 4; p++)
				pokerhand[2].Pic[p] = heart[p];
			pokerhand[3].Num = 4;
			for(int p = 0; p < 4; p++)
				pokerhand[3].Pic[p] = diamond[p];
			pokerhand[4].Num = 13;
			for(int p = 0; p < 4; p++)
				pokerhand[4].Pic[p] = spade[p];
			Show();
			break;
		}
		case 4://Full House
		{
			pokerhand[0].Num = 3;
			for(int p = 0; p < 4; p++)
				pokerhand[0].Pic[p] = spade[p];
			pokerhand[1].Num = 3;
			for(int p = 0; p < 4; p++)
				pokerhand[1].Pic[p] = diamond[p];
			pokerhand[2].Num = 3;
			for(int p = 0; p < 4; p++)
				pokerhand[2].Pic[p] = club[p];
			pokerhand[3].Num = 5;
			for(int p = 0; p < 4; p++)
				pokerhand[3].Pic[p] = spade[p];
			pokerhand[4].Num = 5;
			for(int p = 0; p < 4; p++)
				pokerhand[4].Pic[p] = diamond[p];
			Show();
			break;
		}
		case 5://Flush
		{			
			pokerhand[0].Num = 3;
			for(int p = 0; p < 4; p++)
				pokerhand[0].Pic[p] = spade[p];
			pokerhand[1].Num = 7;
			for(int p = 0; p < 4; p++)
				pokerhand[1].Pic[p] = spade[p];
			pokerhand[2].Num = 9;
			for(int p = 0; p < 4; p++)
				pokerhand[2].Pic[p] = spade[p];
			pokerhand[3].Num = 10;
			for(int p = 0; p < 4; p++)
				pokerhand[3].Pic[p] = spade[p];
			pokerhand[4].Num = 13;
			for(int p = 0; p < 4; p++)
				pokerhand[4].Pic[p] = spade[p];
			Show();
			break;
		}
		case 6://Straight
		{
			pokerhand[0].Num = 5;
			for(int p = 0; p < 4; p++)
				pokerhand[0].Pic[p] = spade[p];
			pokerhand[1].Num = 6;
			for(int p = 0; p < 4; p++)
				pokerhand[1].Pic[p] = heart[p];
			pokerhand[2].Num = 7;
			for(int p = 0; p < 4; p++)
				pokerhand[2].Pic[p] = diamond[p];
			pokerhand[3].Num = 8;
			for(int p = 0; p < 4; p++)
				pokerhand[3].Pic[p] = club[p];
			pokerhand[4].Num = 9;
			for(int p = 0; p < 4; p++)
				pokerhand[4].Pic[p] = spade[p];
			Show();
			break;
		}
		case 7://three of a kind
		{
			pokerhand[0].Num = 7;
			for(int p = 0; p < 4; p++)
				pokerhand[0].Pic[p] = spade[p];
			pokerhand[1].Num = 7;
			for(int p = 0; p < 4; p++)
				pokerhand[1].Pic[p] = club[p];
			pokerhand[2].Num = 7;
			for(int p = 0; p < 4; p++)
				pokerhand[2].Pic[p] = diamond[p];
			pokerhand[3].Num = 12;
			for(int p = 0; p < 4; p++)
				pokerhand[3].Pic[p] = heart[p];
			pokerhand[4].Num = 13;
			for(int p = 0; p < 4; p++)
				pokerhand[4].Pic[p] = spade[p];
			Show();
			break;			
		}
		case 8://Two Pair
		{
			pokerhand[0].Num = 1;
			for(int p = 0; p < 4; p++)
				pokerhand[0].Pic[p] = diamond[p];
			pokerhand[1].Num = 1;
			for(int p = 0; p < 4; p++)
				pokerhand[1].Pic[p] = heart[p];
			pokerhand[2].Num = 11;
			for(int p = 0; p < 4; p++)
				pokerhand[2].Pic[p] = club[p];
			pokerhand[3].Num = 11;
			for(int p = 0; p < 4; p++)
				pokerhand[3].Pic[p] = spade[p];
			pokerhand[4].Num = 13;
			for(int p = 0; p < 4; p++)
				pokerhand[4].Pic[p] = spade[p];
			Show();
			break;
		}
		case 9://Pair jack or better
		{
			pokerhand[0].Num = 1;
			for(int p = 0; p < 4; p++)
				pokerhand[0].Pic[p] = heart[p];
			pokerhand[1].Num = 10;
			for(int p = 0; p < 4; p++)
				pokerhand[1].Pic[p] = spade[p];
			pokerhand[2].Num = 11;
			for(int p = 0; p < 4; p++)
				pokerhand[2].Pic[p] = diamond[p];
			pokerhand[3].Num = 12;
			for(int p = 0; p < 4; p++)
				pokerhand[3].Pic[p] = club[p];
			pokerhand[4].Num = 12;
			for(int p = 0; p < 4; p++)
				pokerhand[4].Pic[p] = spade[p];
			Show();
			break;

		}
	}//end switch

}
