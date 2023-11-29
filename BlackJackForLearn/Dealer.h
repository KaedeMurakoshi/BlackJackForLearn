#pragma once
#include"Person.h"

class Dealer : public Person
{
public:
	Dealer();				// デフォルトコンストラクタは残しておく
	Dealer(const char* pName);
	virtual ~Dealer();
	void PlayBase(Shoe& shoe) override;	// ターン処理
};