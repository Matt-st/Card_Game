//---------------------------------------------------------------------------
//Programmer:  Matthew Thorne
//Date: 11/22/11
//cocs 220 project card 
//header file for the card class and struct file.  
//--------------------------------------------------------------------------- 

#ifndef	CARDCLASS_H
#define CARDCLASS_H
	const char spade[4]="\xe2\x99\xa0";//unicode for spade
	const char club[4]="\xe2\x99\xa3";//unicode for club
	const char heart[4]="\xe2\x99\xa5";//unicode for heart
	const char diamond[4]="\xe2\x99\xa6";//unicode for diamond

//creates a struct of type acard
struct ACard{
	int Num;//value of cards
	char Pic[4];//pic array
};


class card
{	
	private:
		ACard cards[52];//array that includes the info for num ,Pic
		int Nextcard;//iterator used to move through the array index
	public:
	
		card();//constructor 
		~card(){};
		void shufflecard();//function to shuffle the cards
		ACard getcard();//to get the next card in the index
		void cardace(const char Pic[]);//picture for ace
		void cardtwo(const char Pic[]);//picture for two
		void cardthree(const char Pic[]);//picture for three
		void cardfour(const char Pic[]);//picture for four
		void cardfive(const char Pic[]);//picture for five
		void cardsix(const char Pic[]);//picture for six
		void cardseven(const char Pic[]);//picture for seven
		void cardeight(const char Pic[]);//picture for eight
		void cardnine(const char Pic[]);//picture for nine
		void cardten(const char Pic[]);//picture for ten
		void cardjack(const char Pic[]);//picture for jack
		void cardqueen(const char Pic[]);//picture for queen
		void cardking(const char Pic[]);//picture for king
		void dumbcard();//picture for blank card
};
#endif

