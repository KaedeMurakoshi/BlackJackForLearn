#pragma once
#include"Person.h"

class Dealer : public Person
{
public:
	Dealer();				// �f�t�H���g�R���X�g���N�^�͎c���Ă���
	Dealer(const char* pName);
	virtual ~Dealer();
	void PlayBase(Shoe& shoe) override;	// �^�[������
};