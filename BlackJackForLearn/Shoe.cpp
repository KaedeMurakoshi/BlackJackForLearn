#include <iostream>
#include"Shoe.h"

using namespace std;

void Shoe::InitShoe()
{
	//Card _card[CARD_NUM];

	// カード初期化
	for (int i = 0; i < CARD_NUM; ++i)
	{
		_card[i].SetNum(i % 13);	//０～１２で初期化
		_card[i].SetSuit(i % 4);	//０～３で初期化
	}

	// シャッフル
	_Shuffle();
}

// コンストラクタ
Shoe::Shoe()
{
	InitShoe();

	// カード枚数初期化
	_cardNum = CARD_NUM;
}

// デストラクタ
Shoe::~Shoe()
{

}

// カードを１枚取る
Card Shoe::TakeCard()
{
	// カードの残り枚数が０だったら山札を初期化
	if (_cardNum <= 0) 
	{
		InitShoe();
		_cardNum = CARD_NUM;
	}

	// 山札の後ろから引いていく
	--_cardNum;
	Card card =_card[_cardNum];

	// デバッグ用
	// 引いたカードに－１を入れる
	_card[_cardNum].SetNum(-1);	
	_card[_cardNum].SetSuit(-1);

	return card;
}

//シャッフル（フィッシャーイェーツ）
void Shoe::_Shuffle()
{
	for (int i = CARD_NUM; i > 0; --i) {
		int a = i - 1;
		int b = rand() % i;

		int tempNum = _card[a].GetNum();
		int tempSuit = _card[a].GetSuit();
		_card[a].SetNum(_card[b].GetNum());
		_card[a].SetSuit(_card[b].GetSuit());
		_card[b].SetNum(tempNum);
		_card[b].SetSuit(tempSuit);
	}
}