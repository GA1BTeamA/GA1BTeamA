#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�w�i
class CObjBackground : public CObj
{
public:
	CObjBackground() {};
	~CObjBackground() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[
private:
	float m_scroll;  //���E�X�N���[���p
	float bm_x1;  //�Z�w�i1�̈ʒu���
	float bm_x2;  //�Z�w�i2�̈ʒu���
	float sm_x1;  //���w�i1�̈ʒu���
	float sm_x2;  //���w�i2�̈ʒu���
	bool m_key_flag;

	//��l���̈ʒu���擾
	float hx;
	float hy;
};

