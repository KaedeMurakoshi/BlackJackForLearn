#include <iostream>
#include <algorithm>

#include"Player.h"
using namespace std;

// コンストラクタ
Player::Player(const char* pName) : Person(pName)
{

}

// デストラクタ
Player::~Player()
{

}

// ターン処理
void Player::PlayBase(Shoe& shoe)
{
	//バーストするまでループ処理
	while (CalcScore()) {
		cout << "hit or stand >> ";

		//入力
		char str[16]; //文字列型
		cin >> str; //文字列を入力
		//hitが入力された場合
		if (strcmp(str, "hit") == 0) {
			//カードの配布
			Hit(shoe);

			//手札の表示
			cout << "====================" << endl;
			cout << GetName() << endl;
			ShowHand();
			cout << "====================" << endl;
			continue;
		}
		else if (strcmp(str, "stand") == 0) {
			// standしたので終了
			return;
		}
	}
	//バーストしているので終了
	return;
}