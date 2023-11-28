#pragma once

class Shoe;

class Person
{
public:
	Person(const char* pName);				// �R���X�g���N�^
	virtual ~Person();		// �f�X�g���N�^
	void Hit(Shoe& shoe);	// �q�b�g
	void ShowHand();		// ��D��\��
	int CalcScore();		// �X�R�A��\��
	const char* GetName()const;

private:
	char* _pName;			// ���O
	int _hand[16];			// ��D���
	int _handNum;			// ��D�̖���
};