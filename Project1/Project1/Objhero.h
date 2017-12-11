#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F��l��
class CObjhero : public CObj
{
public:
	CObjhero() {};
	~CObjhero() {};
	void Init();   //�C�j�V�����C�Y
	void Action(); //�A�N�V����
	void Draw();   //�h���[

protected:
	float m_px;    //�ʒu
	float m_py; 
	float m_vx;    //�ړ��x�N�g��
	float m_vy;
	float m_posture; //����

	int m_ani_timex;  //�A�j���[�V�����t���[������Ԋux���p
	int m_ani_timey;  //�A�j���[�V�����t���[������Ԋuy���p
	int m_ani_framex; //�`��t���[��x���p
	int m_ani_framey; //�`��t���[��y���p
};