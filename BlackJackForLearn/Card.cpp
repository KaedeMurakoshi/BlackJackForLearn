#include<iostream>
#include "Card.h"

using namespace std;

const char* suitName[SUIT_NUM] = { "SPADE", "DIAMOND", "HEART", "CLUB", };

Card::Card()
{
	_num = 0;
	_suit = 0;
}

// �R�s�[�R���X�g���N�^
Card::Card(const Card& other)
{
	_num = other._num;
	_suit = other._suit;
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

Card& Card::operator=(Card& other)
{
	_num = other.GetNum();
	_suit = other.GetSuit();
	return *this;
}

void Card::ShowCard()const	
{
	printf("%s��%d\n", suitName[_suit], _num + 1); // �P�`�P�R�����f�[�^��͂O�`�P�Q
}