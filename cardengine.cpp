//---------------------------------------------------------------------------
//Programmer:  Matthew Thorne
//Date: 11/22/11
//cocs 220 project card 
//---------------------------------------------------------------------------  

#include "cardclass.h"
#include <iostream>


using namespace std;

int main()
{	
	card x;
	x.shufflecard();
	for(int i = 0; i < 52; i++)
	{	
			ACard tmp;
			tmp = x.getcard();
			
		switch(tmp.Num)
			{
			case 1:
				x.cardace(tmp.Pic);
				break;
			case 2:
				x.cardtwo(tmp.Pic);
				break;
			case 3:
				x.cardthree(tmp.Pic);
				break;
			case 4:
				x.cardfour(tmp.Pic);
				break;
			case 5:
				x.cardfive(tmp.Pic);
				break;
			case 6:
				x.cardsix(tmp.Pic);
				break;
			case 7:
				x.cardseven(tmp.Pic);
				break;
			case 8:
				x.cardeight(tmp.Pic);
				break;
			case 9:
				x.cardnine(tmp.Pic);
				break;
			case 10:
				x.cardten(tmp.Pic);
				break;
			case 11:
				x.cardjack(tmp.Pic);
				break;
			case 12:
				x.cardqueen(tmp.Pic);
				break;
			case 13:
				x.cardking(tmp.Pic);
				break;
			}
		}		

return 0;
}


