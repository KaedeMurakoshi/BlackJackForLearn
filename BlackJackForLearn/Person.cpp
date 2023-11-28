#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>

#include"Player.h"
#include"Dealer.h"
#include"Shoe.h"
#include"Person.h"
#include"Common.h"

using namespace std;

// コンストラクタ
Person::Person(const char* pName)
{
	// 初期化
	fill_n(_hand, HAND_NUM, -1);

	_handNum = 0;

	_pName = new char[strlen(pName) + 1];
	strcpy(_pName, pName);
}

// デストラクタ
Person::~Person()
{
	if (_pName == nullptr)
	{
		delete _pName;
		_pName = nullptr;
	}
}

const char* Person::GetName()const
{
	return _pName;
}
// ヒット
void Person::Hit(Shoe& shoe)
{
	// カードを１枚引く
	int card = shoe.TakeCard();

	// 正しい情報が渡されていたら
	if (card >= 0)
	{
		// 手札の枚数が１５枚以下なら
		if (_handNum < HAND_NUM)
		{
			//手札に書き込む
			_hand[_handNum] = card;
			// 手札枚数更新
			++_handNum;
		}
		else
		{
			printf("手札がいっぱいです\n");
		}
	}
	else
	{
		printf("カードが引けませんでした\n");
	}
}

void Person::ShowHand()
{
	//標準出力
	cout << "hand: ";
	//配列の最初から最後までを順に表示
	for (int i = 0; i < _handNum; ++i)
	{
		//カードの種類(スペード,ハート,ダイヤ,クラブ)を探索
		int type = _hand[i] / 13; //13で割った数(0-3)で4種類を分割

		//標準出力
		const char* strType[] = { "s", "h", "d", "c" };
		cout << strType[type];
		// １～１３
		cout << _hand[i] % 13 + 1 << ' ';
	}
	//改行
	cout << endl;
	//スコアの表示
	cout << "score: " << CalcScore() << endl;
}

int Person::CalcScore()
{
	// 手札がなかったら
	if (_handNum <= 0)
	{
		printf("エラー：手札がありません\n");
		return 0;
	}

	int* data = NULL; //スコア計算用配列用ポインタ

	data = new(nothrow) int[_handNum]; //手札枚数確保

	if (data == NULL)
	{
		// メモリ不足は今回はバーストとして終了する。
		cout << "メモリの確保に失敗しました。再起動してください。" << endl;
		return 0;
	}

	//手札配列からデータを取得,1-10の値として格納
	for (int i = 0; i < _handNum; i++) {
		if (_hand[i] % 13 < 10) {
			//配列の値が10以下(0-9)であれば1を加えて格納
			*(data + i) = _hand[i] % 13 + 1;
		}
		else {
			//ここで10を格納しているのは,11-13のカードのこと
			*(data + i) = 10;
		}
	}

	//ソート（Aをあぶりだすため）
	sort(data, data + _handNum);

	//返り値用変数(計算結果)
	int score = 0;
	//2番目から順にスコアを足していく
	//1番目が0の場合(つまりAである。2枚続く可能性はあるが2枚目のAは必ず1としてカウントする
	//ので先頭だけ調べればよい
	for (int i = 1; i < _handNum; i++) {
		//スコアにデータを加える
		score = score + (*(data + i));
	}

	//先頭が1(A)であるか判定し状況によって1 or 11として計算
	if (*data == 1) {
		if (score + 11 < 22) { //11として扱ってもバーストしない場合
			//11を加える
			score += 11;
		}
		else {
			//11として扱うとバーストする場合
			//スコアに1を加える
			score += 1;
		}
	}
	else {
		//先頭が1でないなら,スコアにデータをそのまま加える
		score += data[0];
	}

	//バーストである場合は0を返す
	if (score > 21) {
		score = 0;
	}

	// 解放
	if (data != NULL)
	{
		delete[] data;
		data = NULL;
	}

	return score;
}