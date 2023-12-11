#pragma once
#include"Common.h"
#include"Card.h"

class Card;

class Shoe 
{
public:
	Shoe();					// コンストラクタ
	virtual ~Shoe();		// デストラクタはvirtualをつける
	Card TakeCard();		// カードを１枚返す	

private:
	Card _card[CARD_NUM];	// 山札
	int _cardNum;			// カードが何枚残っているか
	void _Shuffle();		// シャッフル
	void InitShoe();		// 山札の初期化
};