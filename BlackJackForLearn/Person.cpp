#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>

#include"Player.h"
#include"Dealer.h"
#include"Shoe.h"
#include"Person.h"
#include"Common.h"

using namespace std;

// �R���X�g���N�^
Person::Person(const char* pName)
{
	// ������
	fill_n(_hand, HAND_NUM, -1);

	_handNum = 0;

	_pName = new char[strlen(pName) + 1];
	strcpy(_pName, pName);
}

// �f�X�g���N�^
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
// �q�b�g
void Person::Hit(Shoe& shoe)
{
	// �J�[�h���P������
	int card = shoe.TakeCard();

	// ��������񂪓n����Ă�����
	if (card >= 0)
	{
		// ��D�̖������P�T���ȉ��Ȃ�
		if (_handNum < HAND_NUM)
		{
			//��D�ɏ�������
			_hand[_handNum] = card;
			// ��D�����X�V
			++_handNum;
		}
		else
		{
			printf("��D�������ς��ł�\n");
		}
	}
	else
	{
		printf("�J�[�h�������܂���ł���\n");
	}
}

void Person::ShowHand()
{
	//�W���o��
	cout << "hand: ";
	//�z��̍ŏ�����Ō�܂ł����ɕ\��
	for (int i = 0; i < _handNum; ++i)
	{
		//�J�[�h�̎��(�X�y�[�h,�n�[�g,�_�C��,�N���u)��T��
		int type = _hand[i] / 13; //13�Ŋ�������(0-3)��4��ނ𕪊�

		//�W���o��
		const char* strType[] = { "s", "h", "d", "c" };
		cout << strType[type];
		// �P�`�P�R
		cout << _hand[i] % 13 + 1 << ' ';
	}
	//���s
	cout << endl;
	//�X�R�A�̕\��
	cout << "score: " << CalcScore() << endl;
}

int Person::CalcScore()
{
	// ��D���Ȃ�������
	if (_handNum <= 0)
	{
		printf("�G���[�F��D������܂���\n");
		return 0;
	}

	int* data = NULL; //�X�R�A�v�Z�p�z��p�|�C���^

	data = new(nothrow) int[_handNum]; //��D�����m��

	if (data == NULL)
	{
		// �������s���͍���̓o�[�X�g�Ƃ��ďI������B
		cout << "�������̊m�ۂɎ��s���܂����B�ċN�����Ă��������B" << endl;
		return 0;
	}

	//��D�z�񂩂�f�[�^���擾,1-10�̒l�Ƃ��Ċi�[
	for (int i = 0; i < _handNum; i++) {
		if (_hand[i] % 13 < 10) {
			//�z��̒l��10�ȉ�(0-9)�ł����1�������Ċi�[
			*(data + i) = _hand[i] % 13 + 1;
		}
		else {
			//������10���i�[���Ă���̂�,11-13�̃J�[�h�̂���
			*(data + i) = 10;
		}
	}

	//�\�[�g�iA�����Ԃ肾�����߁j
	sort(data, data + _handNum);

	//�Ԃ�l�p�ϐ�(�v�Z����)
	int score = 0;
	//2�Ԗڂ��珇�ɃX�R�A�𑫂��Ă���
	//1�Ԗڂ�0�̏ꍇ(�܂�A�ł���B2�������\���͂��邪2���ڂ�A�͕K��1�Ƃ��ăJ�E���g����
	//�̂Ő擪�������ׂ�΂悢
	for (int i = 1; i < _handNum; i++) {
		//�X�R�A�Ƀf�[�^��������
		score = score + (*(data + i));
	}

	//�擪��1(A)�ł��邩���肵�󋵂ɂ����1 or 11�Ƃ��Čv�Z
	if (*data == 1) {
		if (score + 11 < 22) { //11�Ƃ��Ĉ����Ă��o�[�X�g���Ȃ��ꍇ
			//11��������
			score += 11;
		}
		else {
			//11�Ƃ��Ĉ����ƃo�[�X�g����ꍇ
			//�X�R�A��1��������
			score += 1;
		}
	}
	else {
		//�擪��1�łȂ��Ȃ�,�X�R�A�Ƀf�[�^�����̂܂܉�����
		score += data[0];
	}

	//�o�[�X�g�ł���ꍇ��0��Ԃ�
	if (score > 21) {
		score = 0;
	}

	// ���
	if (data != NULL)
	{
		delete[] data;
		data = NULL;
	}

	return score;
}