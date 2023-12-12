#pragma once
#include"Common.h"

class Card
{
public:
	Card();						// �R���X�g���N�^
	virtual ~Card();			// �f�X�g���N�^

	bool operator==(const Card& other)const;	// ==��r�ɑΉ�

	void ShowCard()const;

	// �ǂݎ��A��������
	int GetNum() const{ return _num; }const
	int GetSuit() const{ return _suit; }const
	void SetNum(int num) 
	{ 
		if (num < 0) return;
		_num = num; 
	}
	void SetSuit(int suit) 
	{ 
		if (suit < 0) return;
		_suit = suit; 
	}

private:
	int _num;
	int _suit;
};



