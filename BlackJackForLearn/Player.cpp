#include <iostream>
#include <algorithm>

#include"Player.h"
using namespace std;

// �R���X�g���N�^
Player::Player(const char* pName) : Person(pName)
{

}
// �f�X�g���N�^
Player::~Player()
{

}

// �^�[������
bool Player::Play(Shoe& shoe)
{
	//�o�[�X�g����܂Ń��[�v����
	while (CalcScore()) {
		cout << "hit or stand >> ";

		//����
		char str[16]; //������^
		cin >> str; //����������
		//hit�����͂��ꂽ�ꍇ
		if (strcmp(str, "hit") == 0) {
			//�J�[�h�̔z�z
			Hit(shoe);

			//��D�̕\��
			cout << "====================" << endl;
			cout << "player" << endl;
			ShowHand();
			cout << "====================" << endl;
		}
		else if (strcmp(str, "stand") == 0) {
			//�Ԃ�l��true�Ƃ��ďI��
			return true;
		}
	}
	//�o�[�X�g���Ă���̂�false��Ԃ��ďI��
	return false;
}