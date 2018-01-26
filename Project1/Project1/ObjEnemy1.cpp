//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjEnemy1.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjEnemy1::CObjEnemy1(float x, float y)
{
	//�ʒu
	m_px = x;
	m_py = y;
}

//�C�j�V�����C�Y
void CObjEnemy1::Init()
{
	//m_px = 0.0f;		//�ʒu
	//m_py = 0.0f;
	m_vx = 0.0f;		//�ړ��x�N�g��
	m_vy = 0.0f;
	m_posture = 1.0f;	//�E����0.0���@������1.0��

	m_ani_timex = 0;    //�A�j���[�V�����t���[������Ԋux��
	m_ani_timey = 0;	//�A�j���[�V�����t���[������Ԋuy��
	m_ani_framex = 1;   //�`��t���[��x��
	m_ani_framey = 1;	//�`��t���[��y��

	m_speed_power = 0.5f;
	m_ani_max_time = 4;

	m_move = false; //true=�E�@false=��

	Hits::SetHitBox(this, m_px, m_py, 64, 50, ELEMENT_ENEMY, OBJ_ENEMY1, 1);
}

//�A�N�V����
void CObjEnemy1::Action()
{


	//����
	if (m_py > 1000.0f)
	{
		;
	}

	//�ʏ푬�x
	m_speed_power = 0.35f;
	m_ani_max_time = 6;
	/*
	//�u���b�N�Փ˂Ō����ύX
	if (m_hit_left == true)
	{
		m_move = true;
	}
	if (m_hit_right == true)
	{
		m_move = false;
	}
	*/
	//����
	/*if (m_move == true)
	{
		m_vx += m_speed_power;
		m_posture = 1.0f;
		m_ani_timex += 1;
	}
	else if (m_move == false)
	{
		m_vx -= m_speed_power;
		m_posture = 0.0f;
		m_ani_timex += 1;
	}

	if (m_ani_timex > m_ani_max_time)
	{
		m_ani_framex += 1;
		m_ani_timex = 0;
	}

	if (m_ani_framex == 4)
	{
		m_ani_framex = 0;
	}*/

	//���C
	m_vx += -(m_vx * 0.098);

	//���R�����^��
	m_vy += 9.8/(16.0f);
	
	//�u���b�N�^�C�v���m�p�̕ϐ����Ȃ����߂̃_�~�[
	int d;
	//�u���b�N�Ƃ̓����蔻����s
	CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	float x = pb->GetScroll() + m_px;

	pb->BlockHit(&x, &m_py, false,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&d);

	//�u���b�N���������Ă���
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//HitBox�̈ʒu�̕ύX
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_px + block->GetScroll(), m_py+12);

	if (m_px < 0 || m_px > 2500 || m_py < 0 || m_py > 600)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
		
	//�ʒu�̍X�V
	m_px += m_vx;
	m_py += m_vy;
	
}

//�h���[
void CObjEnemy1::Draw()
{
	int AniDatax[4] =
	{
		0, 1, 2, 1,
	};

	//�J���[���
	float c[4] = { 1.0f,1.0f,1.0f ,1.0f };

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`�挳�\���ʒu

	//�u���b�N���������Ă���
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f + AniDatax[m_ani_framex] * 64;
	src.m_right = 64.0f + AniDatax[m_ani_framex] * 64;
	src.m_bottom = 64.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = m_py;
	dst.m_left = (64.0f * m_posture) + m_px + block->GetScroll();
	dst.m_right = (64 - 64.0f * m_posture) + m_px + block->GetScroll();
	dst.m_bottom = m_py+64.0f;

	Draw::Draw(2, &src, &dst, c, 0.0f);
}