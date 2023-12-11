#pragma once
#include "Common.h"
#include "Card.h"
class Shoe;
class Card;

class Person
{
public:
	virtual void PlayBase(Shoe& shoe) = 0;	// 純粋仮想関数	

	Person(const char* pName);	// コンストラクタ
	virtual ~Person();			// デストラクタ
	void Hit(Shoe& shoe);		// ヒット
	bool Play(Shoe& shoe);	// 派生クラスのPlayBaseを呼んで結果に応じでtrue,falseを返す
	void ShowHand();			// 手札を表示
	int CalcScore();			// スコアを表示
	const char* GetName()const;

private:
	char* _pName;				// 名前
	Card _hand[HAND_NUM];				// 手札情報
	int _cardNum;				// 手札の枚数
};