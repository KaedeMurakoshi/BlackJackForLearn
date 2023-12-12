#pragma once
#include"Common.h"

class Card
{
public:
	Card();						// コンストラクタ
	virtual ~Card();			// デストラクタ

	bool operator==(const Card& other)const;	// ==比較に対応

	void ShowCard()const;

	// 読み取り、書き込み
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



