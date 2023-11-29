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

void Dealer::PlayBase(Shoe& shoe)
{
	printf("\n～～～ディーラーのターン～～～\n\n");

	//スコアが16以下の場合hitを続ける
	while (0 < CalcScore() && CalcScore() < 17) 
	{
		//ヒットする
		Hit(shoe);
		cout << "hit" << endl;
		//手札の表示
		cout << "====================" << endl;
		cout << GetName() << endl;
		ShowHand();
		cout << "====================" << endl;
	}

	if (!CalcScore())
	{
		printf("バーストしてしまいました　＞＜\n");
	}
	else
	{
		printf("standします\n");
	}
	return;
}