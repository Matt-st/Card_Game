//---------------------------------------------------------------------------
//Programmer:  Matthew Thorne
//Date: 11/22/11
//cocs 220 project card 
//---------------------------------------------------------------------------  

#include <ctime>//included for rand num
#include <cstdlib>//included for rand num
#include <iostream>
#include <iomanip>//included to make pictures for cards
#include "cardclass.h"
using namespace std;

card::card()//constructor 
{
	Nextcard = 0;//initializeig nextcard iterator to 0
		for(int i = 0; i < 13; i++)//to initialize the deck
		{	cards[i].Num = i +1;
				for(int p = 0; p < 4; p++)
				{
/*initialize the picture to the individual card index and the picture is an array of four*/				cards[i].Pic[p] = spade[p];
				}
		}
		for(int j = 0; j < 13; j++)//to initialize the deck
		{	
			cards[j + 13].Num = j +1;
			for(int p = 0; p < 4; p++)
			{/*initialize the picture to the individual card index and the picture is an array of four*/
				cards[j + 13].Pic[p] = club[p];
			}
		}
		for(int n = 0; n < 13; n++)//to initialize the deck
		{	
			cards[n + 26].Num = n +1;
			for(int p = 0; p < 4; p++)
			{/*initialize the picture to the individual card index and the picture is an array of four*/
				cards[n + 26].Pic[p] = heart[p];
			}
		}
		for(int m = 0; m < 13; m++)//to initialize the deck
		{	
			cards[m + 39].Num = m + 1;
			for(int p = 0; p < 4; p++)
			{/*initialize the picture to the individual card index and the picture is an array of four*/
				cards[m + 39].Pic[p] = diamond[p];
			}
		}
}
void card::shufflecard ()
{	
	Nextcard = 0;//set to 0
	int rnum;//creates a variable rnum of int type
	/*code to give a random number generator between 0 and 51*/
	srand(time(0));
	srand( (unsigned)time(NULL));
	ACard tmp;
	for (int i = 0; i < 52; i++)
	{
		rnum = rand() % 52;
		tmp = cards[i];
		cards[i] = cards[rnum];
		cards[rnum] = tmp;
	}
}
/*function to provide a way for the deck to move through the index*/
ACard card::getcard()
{
	return cards[Nextcard++];/*nextcard iterates through the index starting at 0*/
}
void card::cardtwo(const char Pic[])//picture for two
{

	cout << "---------" << endl;
	cout <<"|"<<"2"<<setw(7)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(6)<<Pic<<setw(4)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(6)<<Pic<<setw(4)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(7)<<"2"<<"|"<<endl;
	cout << "---------" << endl;
}
void card::cardthree(const char Pic[])//picture for three
{
	cout << "---------" << endl;
	cout <<"|"<<"3"<<setw(7)<<"|"<<endl;
	cout <<"|"<<setw(6)<<Pic<<setw(4)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(6)<<Pic<<setw(4)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(6)<<Pic<<setw(4)<<"|"<<endl;
	cout <<"|"<<setw(7)<<"3"<<"|"<<endl;
	cout << "---------" << endl;
}
void card::cardfour(const char Pic[])//picture for four
{
	cout << "---------" << endl;
	cout <<"|"<<"4"<<setw(7)<<"|"<<endl;
	cout <<"|"<<setw(2)<<Pic<<setw(8)<<Pic<<setw(1)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(2)<<Pic<<setw(8)<<Pic<<setw(1)<<"|"<<endl;
	cout <<"|"<<setw(7)<<"4"<<"|"<<endl;
	cout << "---------" << endl;
}
void card::cardfive(const char Pic[])//picture for five
{
	cout << "---------" << endl;
	cout <<"|"<<"5"<<setw(7)<<"|"<<endl;
	cout <<"|"<<setw(2)<<Pic<<setw(8)<<Pic<<setw(1)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(6)<<Pic<<setw(4)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(2)<<Pic<<setw(8)<<Pic<<setw(1)<<"|"<<endl;
	cout <<"|"<<setw(7)<<"5"<<"|"<<endl;
	cout << "---------" << endl;
	
}	
void card::cardsix(const char Pic[])//picture for six
{	
	cout << "---------" << endl;
	cout <<"|"<<"6"<<setw(7)<<"|"<<endl;
	cout <<"|"<<setw(2)<<Pic<<setw(8)<<Pic<<setw(1)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(2)<<Pic<<setw(8)<<Pic<<setw(1)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(2)<<Pic<<setw(8)<<Pic<<setw(1)<<"|"<<endl;
	cout <<"|"<<setw(7)<<"6"<<"|"<<endl;
	cout << "---------" << endl;
}
void card::cardseven(const char Pic[])//picture for seven
{
	cout << "---------" << endl;
	cout <<"|"<<"7"<<setw(7)<<"|"<<endl;
	cout <<"|"<<setw(2)<<Pic<<setw(8)<<Pic<<setw(1)<<"|"<<endl;
	cout <<"|"<<setw(6)<<Pic<<setw(4)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(2)<<Pic<<setw(8)<<Pic<<setw(1)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(2)<<Pic<<setw(8)<<Pic<<setw(1)<<"|"<<endl;
	cout <<"|"<<setw(7)<<"7"<<"|"<<endl;
	cout << "---------" << endl;
	
}
void card::cardeight(const char Pic[])//picture for eight
{
	cout << "---------" << endl;
	cout <<"|"<<"8"<<setw(7)<<"|"<<endl;
	cout <<"|"<<setw(2)<<Pic<<setw(8)<<Pic<<setw(1)<<"|"<<endl;
	cout <<"|"<<setw(6)<<Pic<<setw(4)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(2)<<Pic<<setw(8)<<Pic<<setw(1)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(6)<<Pic<<setw(4)<<"|"<<endl;
	cout <<"|"<<setw(2)<<Pic<<setw(8)<<Pic<<setw(1)<<"|"<<endl;
	cout <<"|"<<setw(7)<<"8"<<"|"<<endl;
	cout << "---------" << endl;
}
void card::cardnine(const char Pic[])//picture for nine
{
	cout << "---------" << endl;
	cout <<"|"<<"9"<<setw(7)<<"|"<<endl;
	cout <<"|"<<setw(2)<<Pic<<setw(8)<<Pic<<setw(1)<<"|"<<endl;
	cout <<"|"<<setw(6)<<Pic<<setw(4)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(2)<<Pic<<setw(8)<<Pic<<setw(1)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(2)<<Pic<<setw(8)<<Pic<<setw(1)<<"|"<<endl;
	cout <<"|"<<setw(2)<<Pic<<setw(8)<<Pic<<setw(1)<<"|"<<endl;
	cout <<"|"<<setw(7)<<"9"<<"|"<<endl;
	cout << "---------" << endl;
}
void card::cardten(const char Pic[])//picture for ten
{
	cout << "---------" << endl;
	cout <<"|"<<"10"<<setw(6)<<"|"<<endl;
	cout <<"|"<<setw(2)<<Pic<<setw(8)<<Pic<<setw(1)<<"|"<<endl;
	cout <<"|"<<setw(6)<<Pic<<setw(4)<<"|"<<endl;
	cout <<"|"<<setw(2)<<Pic<<setw(8)<<Pic<<setw(1)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(2)<<Pic<<setw(8)<<Pic<<setw(1)<<"|"<<endl;
	cout <<"|"<<setw(6)<<Pic<<setw(4)<<"|"<<endl;
	cout <<"|"<<setw(2)<<Pic<<setw(8)<<Pic<<setw(1)<<"|"<<endl;
	cout <<"|"<<setw(7)<<"10"<<"|"<<endl;
	cout << "---------" << endl;
}
void card::cardjack(const char Pic[])//picture for jack
{
	cout << "---------" << endl;
	cout <<"|"<<Pic<<"J"<<setw(6)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(6)<<"J"<<Pic<<"|"<<endl;
	cout << "---------" << endl;
}
void card::cardqueen(const char Pic[])//picture for queen
{
	cout << "---------" << endl;
	cout <<"|"<<Pic<<"Q"<<setw(6)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(6)<<"Q"<<Pic<<"|"<<endl;
	cout << "---------" << endl;
}
void card::cardking(const char Pic[])//picture for king
{
	cout << "---------" << endl;
	cout <<"|"<<Pic<<"K"<<setw(6)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(6)<<"K"<<Pic<<"|"<<endl;
	cout << "---------" << endl;
}
void card::cardace(const char Pic[])//picture for ace
{
	cout << "---------" << endl;
	cout <<"|"<<"A"<<setw(7)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(6)<<Pic<<setw(4)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(7)<<"A"<<"|"<<endl;
	cout << "---------" << endl;

}
void card::dumbcard()//picture for dummy card used in blackjack
{
	cout << "---------" << endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout <<"|"<<setw(8)<<"|"<<endl;
	cout << "---------" << endl;
}
