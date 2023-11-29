#pragma once

class Shoe;

class Person
{
public:
	Person(const char* pName);	// コンストラクタ
	virtual ~Person();			// デストラクタ
	void Hit(Shoe& shoe);		// ヒット
	bool Play(Person person);	// 派生クラスのPlayBaseを呼んで結果に応じでtrue,falseを返す
	void ShowHand();			// 手札を表示
	int CalcScore();			// スコアを表示
	const char* GetName()const;

private:
	char* _pName;				// 名前
	int _hand[16];				// 手札情報
	int _handNum;				// 手札の枚数
};