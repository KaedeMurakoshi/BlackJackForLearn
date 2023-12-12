#pragma once
#include"Common.h"

class Card
{
public:
	Card();						// コンストラクタ
	virtual ~Card();			// デストラクタ

	bool operator==(const Card& other)const;	// ==比較に対応

	void ShowCard()const;		// カード情報表示

	// 読み取り、書き込み
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



