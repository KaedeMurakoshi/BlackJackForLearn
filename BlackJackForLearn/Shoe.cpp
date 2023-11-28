#include <iostream>
#include"Shoe.h"

using namespace std;
// �R���X�g���N�^
Shoe::Shoe()
{
	// �J�[�h����������
	_cardNum = CARD_NUM;

	// �J�[�h������
	for (int i = 0; i < CARD_NUM; ++i)
	{
		_card[i] = i;
	}

	// �V���b�t��
	_Shuffle();
}

// �f�X�g���N�^
Shoe::~Shoe()
{

}

// �J�[�h���P�����
int Shoe::TakeCard()
{
	// �J�[�h�̎c�薇�����O��������[�P��Ԃ�
	if (_cardNum <= 0) return -1;

	// �R�D�̌�납������Ă���
	--_cardNum;
	int card = _card[_cardNum];

	// �������J�[�h�Ɂ|�P������
	_card[_cardNum] = -1;	// �f�o�b�O�p

	return card;
}

//�V���b�t���i�t�B�b�V���[�C�F�[�c�j
void Shoe::_Shuffle()
{
	for (int i = _cardNum; i > 1; --i) {
		int a = i - 1;
		int b = rand() % i;
		swap(_card[a], _card[b]);
	}
}