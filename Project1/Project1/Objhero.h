#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "ObjBlock.h"
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

	//��l���̈ʒu�擾�p
	float GetX() { return m_px; }
	float GetY() { return m_py; }
	float GetVY() { return m_vy; }
	float GetVX() { return m_vx; }

	//��l���̈ʒu�ύX�p
	void SetX (float x ) { m_px =  x; }
	void SetY (float y ) { m_py =  y; }
	void SetVY(float vy) { m_vy = vy; }
	void SetVX(float vx) { m_vx = vx; }
	int GetBT() { return m_block_type; }

	//�u���b�N�Ƃ̏Փˏ�Ԋm�F
	void SetUp(bool b) { m_hit_up    = b; }
	void SetDown(bool b) { m_hit_down  = b; }
	void SetLeft(bool b) { m_hit_left  = b; }
	void SetRight(bool b) { m_hit_right = b; }
	void SetBT(int t) { m_block_type = t; }
	void SetGoalBlock(int goalblock) { goal_block = goalblock; }


protected:
	float m_px;    //�ʒu
	float m_py; 
	float m_vx;    //�ړ��x�N�g��
	float m_vy;
	float m_posture; //����

	int m_ani_timex;  //�A�j���[�V�����t���[������Ԋux���p
	int m_ani_timey;  //�A�j���[�V�����t���[������Ԋuy���p
	int m_ani_timea;  //�A�j���[�V�����t���[������Ԋu�A�N�V�����p
	int m_ani_framex; //�`��t���[��x���p
	int m_ani_framey; //�`��t���[��y���p
	int m_ani_framea; //�`��t���[���A�N�V�����p

	//�u���b�N�Ƃ̏Փˏ�Ԋm�F�p�ϐ�
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	//�W�����v�{�^���t���O
	bool button_flag_up;

	//�`�F���W�{�^���t���O
	bool button_flag_z;

	//�`��؂�ւ�
	bool Draw_flag;

	//�̗�
	int HP;

	//����ł���block�̎�ނ��m�F�p
	int m_block_type;

	int goal_block;
	int key_block;
	int shoes_block;
};