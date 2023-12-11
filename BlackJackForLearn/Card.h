#pragma once
#include"Common.h"

class Card
{
public:
	Card();						// �R���X�g���N�^
	Card(const Card& other);	// �R�s�[�R���X�g���N�^�i���������̑���ɑΉ��j
	virtual ~Card();			// �f�X�g���N�^

	bool operator==(const Card& other)const;	// ==��r�ɑΉ�
	Card& operator=(Card& other);				// ����ɑΉ�

	void ShowCard()const;

	// �ǂݎ��A��������
	int GetNum() const{ return _num; }const
	int GetSuit() const{ return _suit; }const
	void SetNum(int num) { _num = num; }
	void SetSuit(int suit) { _suit = suit; }

private:
	int _num;
	int _suit;
};



