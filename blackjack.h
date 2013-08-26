//---------------------------------------------------------------------------
//Programmer:  Matthew Thorne
//Date: 11/22/11
//cocs 220 project card 
//--------------------------------------------------------------------------- 


#include "cardclass.h"
#ifndef BLACKJACK_H
#define BLACKJACK_H

class blackjack : public card
{
	private:
		ACard dealer[10];//this is the most hits that can occur
		ACard player[11];//because 11 is the most hits that can occur
		int ScoreP;
		int ScoreD;
	public:
		blackjack();//used to initialize the player and dealer hands
		//~blackjack();
		void showhands();//used to display the 2 hands
		int checkcards(int, int);//used to check card values
		void scores(int);//calculates hand score
		int checkscores();//evaluates the score
		void checkscoresD();//evaluate the dealer score
		int scoresD(int);//calculate dealer score
		int hithold(int);//function to hit or hold
		int Comparescore(int, int);//comparescore to finds winner
		int Comparescores(int, int);//compare score for speacial case
};
#endif

