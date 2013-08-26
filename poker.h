//---------------------------------------------------------------------------
//Programmer:  Matthew Thorne
//Date: 11/27/11
//cocs 220 project card 
//---------------------------------------------------------------------------  
#include "cardclass.h"
#ifndef POKER_H
#define POKER_H
class Poker : public card//inherits the public functions of card class
{	
	private://createing private array and variables
		ACard pokerhand[5];//private array of 5
		ACard Firsthand[5];//priavte array of 5
		int Xcard;//creates xcard variable used as iterator
	public:
		Poker();//constructor to initialize pokerhand and firsthand
		~Poker(){};//destructor
		ACard Receivecard();//gives next card in the deck
		void Hand();//initializes hand for dealer and player
		void Redraw();//asks player to redraw or stay
		void Show();//shows card hand
		void Selectionsort();//sorts hand from smallest to largest
		int CheckHands(int);//evaluates hand
		void TestHand();//test function to check for logical breaks
};
#endif
