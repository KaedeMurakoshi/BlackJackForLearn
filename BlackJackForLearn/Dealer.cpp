#include<iostream>
#include<algorithm>

#include"Dealer.h"
using namespace std;

// コンストラクタ
Dealer::Dealer() : Person("Dealer")			// 基底クラスの引数付きコンストラクタを明示的に呼び出す(名前をDealerにする)
{
	
}

// 引数付きコンストラクタ
Dealer::Dealer(const char* pName) : Person(pName)	// 自分で名前を入力
{

}

// デストラクタ
Dealer::~Dealer()
{

}

bool Dealer::Play(Shoe& shoe)
{
	//スコアが16以下の場合hitを続ける
	while (CalcScore() < 17 && CalcScore() > 0) {
		//ヒットする
		Hit(shoe);
		cout << "hit" << endl;
		//手札の表示
		cout << "====================" << endl;
		cout << "dealer" << endl;
		ShowHand();
		cout << "====================" << endl;
	}
	// バーストしていたら
	if (CalcScore() <= 0) return false;
	return true;
}