//---------------------------------------------------------------------------
//Programmer:  Matthew Thorne
//Date: 11/29/11
//cocs 220 project card 
//--------------------------------------------------------------------------- 

#include <iostream>
#include "cardclass.h"
#include "blackjack.h"

using namespace std;
/*constructor for the blackjack class*/
/*This function is used to deal the initial four cards(two to the dealer and two to the player).  Both cards to the player will be visible for the player to see.  However only one card will be visible that has been dealt to the dealer.*/
blackjack::blackjack()
{
	shufflecard();
	for(int i = 0; i < 4; i++)
	{
		ACard tmp;
		tmp = getcard();//to get the top most card on the deck
		if(i == 0)//player card
		{
			player[i].Num = tmp.Num;
			for (int p = 0; p < 4; p++)
				player[i].Pic[p] = tmp.Pic[p];
		}
		else if(i == 1)//dealer card
		{
			dealer[i - 1].Num = tmp.Num;
			for (int p = 0; p < 4; p++)
				dealer[i - 1].Pic[p] = tmp.Pic[p];
		}
		else if(i == 2)//player card
		{
			player[i- 1].Num = tmp.Num;
			for (int p = 0; p < 4; p++)
				player[i - 1].Pic[p] = tmp.Pic[p];
		}
		else if(i == 3)//dealer card
		{
			dealer[i - 2].Num = tmp.Num;
			for (int p = 0; p < 4; p++)
				dealer[i - 2].Pic[p] = tmp.Pic[p];
		}
	}
	showhands();
}	
/* This function shows the hands for the dealer and the player.  Important to note that a dummy card is created so that the player only sees one of the dealers cards.*/
void blackjack::showhands()
{
	cout << "-------------------------------------------" << endl;
	cout << "|                 Dealers Cards           |" << endl;
	cout << "-------------------------------------------" << endl;

	for(int i = 0; i < 2; i++)
	{
		switch(dealer[i].Num)//switch statement used to print cards
		{
			case 1://printing cards for the dealers hand
			{
			if(i == 1)//the array index 1 is the card that will be hidden
				dumbcard();
				else
				cardace(dealer[i].Pic);
				break;
			}
			case 2:
			{
				if(i == 1)
				dumbcard();
				else
				cardtwo(dealer[i].Pic);
				break;
			}
			case 3:
			{
				if(i == 1)
				dumbcard();
				else
				cardthree(dealer[i].Pic);
				break;
			}
			case 4:
			{
				if(i == 1)
				dumbcard();
				else
				cardfour(dealer[i].Pic);
				break;
			}
			case 5:
			{
				if(i == 1)
				dumbcard();
				else
				cardfive(dealer[i].Pic);
				break;
			}
			case 6:
			{
				if(i == 1)
				dumbcard();
				else
				cardsix(dealer[i].Pic);
				break;
			}
			case 7:
			{
				if(i == 1)
				dumbcard();
				else
				cardseven(dealer[i].Pic);
				break;
			}
			case 8:
			{
				if(i == 1)
				dumbcard();
				else
				cardeight(dealer[i].Pic);
				break;
			}
			case 9:
			{
				if(i == 1)
				dumbcard();
				else
				cardnine(dealer[i].Pic);
				break;
			}
			case 10:
			{
				if(i == 1)
				dumbcard();
				else
				cardten(dealer[i].Pic);
				break;
			}
			case 11:
			{
				if(i == 1)
				dumbcard();
				else
				cardjack(dealer[i].Pic);
				break;
			}
			case 12:
			{
				if(i == 1)
				dumbcard();
				else
				cardqueen(dealer[i].Pic);
				break;
			}
			case 13:
			{
				if(i == 1)
				dumbcard();
				else
				cardking(dealer[i].Pic);
				break;
			}
		}
	}
	cout << "-------------------------------------------" << endl;
	cout << "|                 Players Cards           |" << endl;
	cout << "-------------------------------------------" << endl;
	for( int i = 0; i < 2; i++)//for loop to print out players cards
	{
		switch(player[i].Num)
			{
			case 1:
				cardace(player[i].Pic);
				break;
			case 2:
				cardtwo(player[i].Pic);
				break;
			case 3:
				cardthree(player[i].Pic);
				break;
			case 4:
				cardfour(player[i].Pic);
				break;
			case 5:
				cardfive(player[i].Pic);
				break;
			case 6:
				cardsix(player[i].Pic);
				break;
			case 7:
				cardseven(player[i].Pic);
				break;
			case 8:
				cardeight(player[i].Pic);
				break;
			case 9:
				cardnine(player[i].Pic);
				break;
			case 10:
				cardten(player[i].Pic);
				break;
			case 11:
				cardjack(player[i].Pic);
				break;
			case 12:
				cardqueen(player[i].Pic);
				break;
			case 13:
				cardking(player[i].Pic);
				break;
			}
	}
}
int blackjack::checkcards(int b, int a)
{	
char select;
int choice = 0;
int insurancemoney = 0;
	if (dealer[0].Num == 1)//if the dealer has an ace
	{	
		do{
		cout << "The dealer has an ace!" << endl;
		cout << "Would you like to buy insurance?(y,n)" << endl;
		cin >> select;//asking if they want insurance
		}while(select != 'y' and select != 'Y' and select != 'n' and select != 'N');
		//bet has to less then 2/3 of total actually purchase insurance
		if ( select == 'y')//if they do 
		{	
				insurancemoney = b * .5;
			/*if statement to show if they both have blackjack and then nothing happens with the money */
			if(dealer[1].Num > 9 )//if the dealer has blackjack and player bought insurance
			{
				//if player has blackjack and bought insurance
				if((player[0].Num == 1 && player[1].Num > 9 )||(player[0].Num > 9 && player[1].Num == 1))//player has BJ
				{
					//total subtract insurance
					a = a - insurancemoney;
					cout << "Both the dealer and the player have blackjack." << endl;
					cout << "The player gets all of his bet back because this casino gives a tie to no one.  But he still loses the insurance." << endl;
					return a ;//!needs to give 100% back
				}
				else//player doesnt have BJ but bought insurance
				{//player loses insurance and bet
					a = a -(b + insurancemoney);
					cout << "dealer has blackjack" << endl;
					return a;//gives 50% back to player
				}
			}
			else//Dealer doesnt have BJ so player needs to hold or hit and get cards dealt
			{//begin else for player hitting or holding 
				hithold(insurancemoney); //call this function
				return insurancemoney;
			}//end else for player hitting	or holding
		}//end of the 'y' if
		else//if player doesnt buy insurance
		{//begin no insurance else
			if(dealer[1].Num > 9 )//if the dealer has blackjack and player doesnt buy insurance
			{
				//if player has blackjack and didnt buy insurance
				if((player[0].Num == 1 && player[1].Num > 9 )||(player[0].Num > 9 && player[1].Num == 1))
				{//subtract bet from total
					cout << "Both the dealer and the player have blackjack." << endl;
					cout << "The player gets his bet money back cause he is lucky." << endl;
					return a;//nothing happens he gets all money back
				}
				else//player doesnt have BJ and dealer does so player loses the bet 
				{//subtract bet from total
					a = a - b;
					cout << "dealer has blackjack" << endl;
					return a;//player loses all money return 0 
				}
			}
			else//dealer doesnt have blackjack and didnt buy insurance so player needs to hold or hit and get cards dealt to them
			{//being dealer no BJ and no insurance for player else
				hithold(b);//call the hithold function
				return 0;
			}//end dealer doesnt have BJ and no insurance else		
		}//end no insurance else
	}//end if dealer has an ace if statement 
	else//if dealer has no ace showing  ask player if he wants to hit or hold
	{
		hithold(b);
		return 0;
	}
}
void blackjack::scores(int i)
{
	ScoreP = 0;
	char num = 0;//used to select if ace counts for 1 or 11
	int score = 0;
	for (int count = 0; count < (i + 1); count++)
	{
		if(player[count].Num == 1)
		{//ask if ace is worth a 1 or 11
			if (score > 11)
				score = score + 1;
			else if (score < 11)
				score = score + 11;
		}
		else if(player[count].Num > 1 && player[count].Num < 10)
		{//if card is worth face value
			int tmpnum = player[count].Num;//sets the value to tmpvalue
			score = tmpnum + score;//adds tmpvalue to the score
		}
		else if( player[count].Num >= 10)///checks to see if the card is greater than 9
			score = score + 10;//adds the score of face cards to the score that was brought in  as a parameter to the function
	}
ScoreP = score;
//return score;
}
int blackjack::scoresD(int i)
{
	ScoreD = 0;
	int num = 0;//used to select if ace counts for 1 or 11
	int score = 0;//
	for (int count = 0; count < (i + 1); count++)
	{
		if(dealer[count].Num == 1)
		{
			if (score > 11)
				score = score + 1;
			else if (score < 11)
				score = score + 11;
		}
		else if(dealer[count].Num > 1 && dealer[count].Num < 10)
		{//if card is worth face value
			int tmpnum = dealer[count].Num;//sets the value to tmpvalue
			score = tmpnum + score;//adds tmpvalue to the score
		}
		else if( dealer[count].Num >= 10)///checks to see if the card is greater than 9
		{
			score = score + 10;//adds the score of face cards to the score that was brought in  as a parameter to the function
		}  	
	}
ScoreD = score;
return score;
}
int blackjack::checkscores()
{
	int score = 0;
		if(ScoreP > 21)//if the score is greater then 21 they bust
			ScoreP = 99;//program looks for score of 99 to show that a card hand is bust
		else if(ScoreP == 21)//if the hand is blackjack
			cout << "This is your score " << ScoreP <<  " stop hitting" << endl;//tells player to stop hitting however they still have the option to hit
		else
			cout << "This is your score " << ScoreP << "." << endl;
score = ScoreP;
return score;
}
/*recieves the score amount and checks to see if it is a bust, a blackjack or a score less then 21*/
void blackjack::checkscoresD()
{
		if(ScoreD > 21)//if the score is greater then 21 they bust
			ScoreD = 99;//program looks for score of 99 to show that a card hand is bust
		else
			cout << "This is Dealer score " << ScoreD << "." << endl;
}
int blackjack::hithold(int money)
{
		char choice = 0;
		int scoreP = 0;
		int scoreD = 0;
		int i = 2;
		scoreD = scoresD(1);
		scores(1);//calculate the score for player first 2 cards
		scoreP = checkscores();//check that it's not blackjack and bust
do{		
cout << "Would you like to hit or hold?(1 for hit 2 for hold)" << endl;
cin >> choice;//find out if they want to hit
}while(choice != '1' and choice != '2');
		if (choice == '1')//checking parameter if they want to hit
		{//hit choice if begins
			while (choice == '1')//do this as long as they still want to hit
			{//while begin
				ACard tmp;//create tmp variable to recieve new card
				tmp = getcard();//tmp recieves new card
					/*switch statement used to show the player what card they received*/
					switch(tmp.Num)//parameter to check values to find out what card has been dealt
					{//switch begin
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
					}//end switch
		/*initializeing new card to the player's hand*/		
				player[i].Num = tmp.Num;
				for(int p = 0; p < 4; p++)
					player[i].Pic[p] = tmp.Pic[p];
				scores(i);//calculateing the new score
				scoreP = checkscores();//checking the score for bust or BJ
				if ( scoreP == 99)
					break;
				i++;//incrementing array index
do{
cout << "Would you like to hit or hold?(1 for hit 2 for hold)" << endl;
cin >> choice;//asking if they want to hit or hold then checking the while loop again
}while(choice != '1' and choice != '2');
			}//end while
		}//end hit choice if statement	
/*code for dealer to hit or hold he must have a score of over 16 before he can hold*/
		if (choice != '1')
		{
			scoreD = scoresD(1);
			if(scoreD < 16)
			{//begin less than 16 if 
				while( scoreD < 16 )
				{
					if (ScoreP == 99)
						break;
					ACard tmp;
					tmp = getcard();
					dealer[i].Num = tmp.Num;
					for(int p = 0; p < 4; p++)
						dealer[i].Pic[p] = tmp.Pic[p];
					scoreD = scoresD(i);
					checkscoresD();
					i++;
				}
			
			}//end if
			else
			{//begin greater than 16 else
				scoreD = scoresD(1);
				checkscoresD();	
			}//end greater than 16 else
		}//end if choice
cout << "This is the player score " << ScoreP << endl;//show player score
cout << "This is the dealer score " << ScoreD << endl;//show dealer score
}
int blackjack::Comparescore( int b, int a)
{	int bet = 0;
	int result = 0;
	int player = ScoreP;//initializes the player to this score
	int dealer = ScoreD;//initializes the dealer to this score
	a = a - b;
	if(dealer == 99)//dealer bust 
	{// wins all bet
		cout << "dealer bust player wins!!" << endl;
		if (player == 21)
		{	bet = b * 2;//multiple of 2
			b = b * .5;//multipl of .5
			result = b + bet;//add these together to get result for blackjack
			result = a + result;//add total to bet
			return result;//send to main
		}
		else
		{
			result = b * 2;//result equal to bet X 2
			result = a + result;//add total and result
			return result;//send to main
		}
	}
	else if(player == 99)//check parameter for bust
	{//loses all bet
		cout << "Player busts.  The dealer wins" << endl;
		return result = a;
	}
	else if( player > dealer)//player wins
	{//wins bet
		cout << "player wins" << endl;
		if(player == 21)//check program for BJ
			{
				cout <<"player has blackjack and recieves 1.5 more return" << endl;
				bet = b * 2;//multiple of 2
				b = b * .5;//half of bet
				result = b + bet;//add them together 
				result = a + result;
				return result;//send to main
			}
		else
		{		
			result = b * 2;//multiple of 2
			result = a + result;//add them together
			return result;//send to main	
		}
	}
	else if(dealer > player)//dealer wins
	{//loses bet
		cout << "dealer wins" << endl;
		return result = a;//send to main
	}
	else if(dealer == player)
	{//tie money doesnt change 
		cout << "it's a tie" << endl;
		return a + b;//send to main
	}
}
//specific for all in 
int blackjack::Comparescores( int b, int a)
{	int bet = 0;
	int result = 0;
	int player = ScoreP;//initializes the player to this score
	int dealer = ScoreD;//initializes the dealer to this score
	a = a - b;//subtract bet from total
	if(dealer == 99)//dealer bust 
	{// wins all bet
		cout << "dealer bust player wins!!" << endl;
		if (player == 21)//check parameter to see if they have black jack
		{	bet = b * 2;//multiple of 2
			b = b * .5;//multiple of half the bet
			result = b + bet;//add them together
			return result;//send result back to main
		}
		else
		{
			result = b * 2;//multiple of 2
			return result;//send result back to main
		}
	}
	else if(player == 99)//check parameter for player bust
	{//loses all bet
		cout << "Player busts.  The dealer wins" << endl;
		return result = a;//send to main
	}
	else if( player > dealer)//player wins
	{//wins bet
		cout << "player wins" << endl;
		if(player == 21)//check parameter
			{
				cout <<"player has blackjack and recieves 1.5 more return" << endl;
				bet = b * 2;
				b = b * .5;
				result = b + bet;
				result = a + result;
				return result;//send to main
			}
		else
		{		
			result = b * 2;
			return result;//send to main	
		}
	}
	else if(dealer > player)//dealer wins
	{//loses bet
		cout << "dealer wins" << endl;
		return result = a;//returns this result
	}
	else if(dealer == player)
	{//tie money doesnt change 
		cout << "it's a tie" << endl;
		b = 999999;//sets value for a tie computer checks for this value
		return b;//returns this value
	}
}
