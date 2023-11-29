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

void Dealer::PlayBase(Shoe& shoe)
{
	printf("\n�`�`�`�f�B�[���[�̃^�[���`�`�`\n\n");

	//�X�R�A��16�ȉ��̏ꍇhit�𑱂���
	while (0 < CalcScore() && CalcScore() < 17) 
	{
		//�q�b�g����
		Hit(shoe);
		cout << "hit" << endl;
		//��D�̕\��
		cout << "====================" << endl;
		cout << GetName() << endl;
		ShowHand();
		cout << "====================" << endl;
	}

	if (!CalcScore())
	{
		printf("�o�[�X�g���Ă��܂��܂����@����\n");
	}
	else
	{
		printf("stand���܂�\n");
	}
	return;
}