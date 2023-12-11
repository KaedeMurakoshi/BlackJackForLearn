#pragma once
#include "Common.h"
#include "Card.h"
class Shoe;
class Card;

class Person
{
public:
	virtual void PlayBase(Shoe& shoe) = 0;	// �������z�֐�	

	Person(const char* pName);	// �R���X�g���N�^
	virtual ~Person();			// �f�X�g���N�^
	void Hit(Shoe& shoe);		// �q�b�g
	bool Play(Shoe& shoe);	// �h���N���X��PlayBase���Ă�Ō��ʂɉ�����true,false��Ԃ�
	void ShowHand();			// ��D��\��
	int CalcScore();			// �X�R�A��\��
	const char* GetName()const;

private:
	char* _pName;				// ���O
	Card _hand[HAND_NUM];				// ��D���
	int _cardNum;				// ��D�̖���
};