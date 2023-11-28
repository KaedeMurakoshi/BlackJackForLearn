#include <iostream>
#include"Shoe.h"

using namespace std;
// コンストラクタ
Shoe::Shoe()
{
	// カード枚数初期化
	_cardNum = CARD_NUM;

	// カード初期化
	for (int i = 0; i < CARD_NUM; ++i)
	{
		_card[i] = i;
	}

	// シャッフル
	_Shuffle();
}

// デストラクタ
Shoe::~Shoe()
{

}

// カードを１枚取る
int Shoe::TakeCard()
{
	// カードの残り枚数が０だったらー１を返す
	if (_cardNum <= 0) return -1;

	// 山札の後ろから引いていく
	--_cardNum;
	int card = _card[_cardNum];

	// 引いたカードに－１を入れる
	_card[_cardNum] = -1;	// デバッグ用

	return card;
}

//シャッフル（フィッシャーイェーツ）
void Shoe::_Shuffle()
{
	for (int i = _cardNum; i > 1; --i) {
		int a = i - 1;
		int b = rand() % i;
		swap(_card[a], _card[b]);
	}
}