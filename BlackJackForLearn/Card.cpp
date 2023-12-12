#include<iostream>
#include "Card.h"

using namespace std;

const char* suitName[SUIT_NUM] = { "SPADE", "DIAMOND", "HEART", "CLUB", };

Card::Card()
{
	_num = -1;
	_suit = -1;
}

Card::~Card()
{

}

bool Card::operator==(const Card& other)const
{
	if (other._num == _num && other._suit == _suit)
	{
		return true;
	}
	else
	{
		return false;
	}
}


void Card::ShowCard()const	
{
	printf("%s‚Ì%d\n", suitName[_suit], _num + 1); // ‚P`‚P‚R‚¾‚ªƒf[ƒ^ã‚Í‚O`‚P‚Q
}