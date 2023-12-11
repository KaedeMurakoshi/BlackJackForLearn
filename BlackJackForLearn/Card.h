#pragma once
#include"Common.h"

class Card
{
public:
	Card();						// コンストラクタ
	Card(const Card& other);	// コピーコンストラクタ（初期化時の代入に対応）
	virtual ~Card();			// デストラクタ

	bool operator==(const Card& other)const;	// ==比較に対応
	Card& operator=(Card& other);				// 代入に対応

	void ShowCard()const;

	// 読み取り、書き込み
	int GetNum() const{ return _num; }const
	int GetSuit() const{ return _suit; }const
	void SetNum(int num) { _num = num; }
	void SetSuit(int suit) { _suit = suit; }

private:
	int _num;
	int _suit;
};



