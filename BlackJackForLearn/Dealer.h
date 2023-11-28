#pragma once
#include"Person.h"

class Dealer : public Person
{
public:
	Dealer();				// デフォルトコンストラクタは残しておく
	Dealer(const char* pName);
	virtual ~Dealer();
	bool Play(Shoe& shoe);	// ターン処理
};