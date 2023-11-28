#include<iostream>
#include<algorithm>

#include"Dealer.h"
using namespace std;

// �R���X�g���N�^
Dealer::Dealer() : Person("Dealer")			// ���N���X�̈����t���R���X�g���N�^�𖾎��I�ɌĂяo��(���O��Dealer�ɂ���)
{
	
}

// �����t���R���X�g���N�^
Dealer::Dealer(const char* pName) : Person(pName)	// �����Ŗ��O�����
{

}

// �f�X�g���N�^
Dealer::~Dealer()
{

}

bool Dealer::Play(Shoe& shoe)
{
	//�X�R�A��16�ȉ��̏ꍇhit�𑱂���
	while (CalcScore() < 17 && CalcScore() > 0) {
		//�q�b�g����
		Hit(shoe);
		cout << "hit" << endl;
		//��D�̕\��
		cout << "====================" << endl;
		cout << "dealer" << endl;
		ShowHand();
		cout << "====================" << endl;
	}
	// �o�[�X�g���Ă�����
	if (CalcScore() <= 0) return false;
	return true;
}