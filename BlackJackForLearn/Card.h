#pragma once
#include"Common.h"

class Card
{
public:
	Card();						// �R���X�g���N�^
	virtual ~Card();			// �f�X�g���N�^

	bool operator==(const Card& other)const;	// ==��r�ɑΉ�

	void ShowCard()const;		// �J�[�h���\��

	// �ǂݎ��A��������
	int GetNum() const { return _num; }const
	int GetSuit() const { return _suit; }const

	void SetNum(int num)
	{
		_num = num;
	}
	void SetSuit(int suit)
	{
		_suit = suit;
	}

private:
	int _num;
	int _suit;
};



