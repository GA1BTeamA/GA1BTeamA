//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "Objhero.h"
#include "ObjBlock.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjhero::Init()
{
	m_px = 500.0f;    //�ʒu
	m_py = 0.0f;
	m_vx = 0.0f;    //�ړ��x�N�g��
	m_vy = 0.0f;
	m_posture = 1.0f; //�E����0.0���@������1.0��

	m_ani_timex = 0;    //�A�j���[�V�����t���[������Ԋux��
	m_ani_timey = 0;    //�A�j���[�V�����t���[������Ԋuy��
	m_ani_framex = 1; //�`��t���[��x��
	m_ani_framey = 1; //�`��t���[������

	//�u���b�N�Ƃ̏Փˏ�Ԋm�F�p
	m_hit_up=false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	//�{�^���t���O
	button_flag = false;

	//�`��؂�ւ�
	Draw_flag=true;


}

//�A�N�V����
void  CObjhero::Action()
{
	

	//�L�[�����̓��͕���
	//x���ړ��p
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_vx += 0.4f;
		m_posture = 1.0f;
		m_ani_timex+=1;

	}
	else if (Input::GetVKey(VK_LEFT) == true)
	{
		m_vx -= 0.4f;
		m_posture = 0.0f;
		m_ani_timex+=1;
	}
	else
	{
		m_ani_framex=1;  //�L�[���͂������ꍇ�͐Î~�t���[���ɂ���
		m_ani_timex=0;
	}

	if (m_ani_timex > 8)
	{
		m_ani_framex +=1;
		m_ani_timex = 0;
	}
	if (m_ani_framex == 8)
	{
		m_ani_framex = 0;
	}

	//y���ړ��p
	if (Input::GetVKey(VK_UP) == true)
	{
	
		if (button_flag== true&&m_hit_down==true)
		{
			m_vy -= 12.0f;
			button_flag = false;
		}
	
	}
	else
	{
		button_flag = true;
	}


	//�󒆂ɂ��邩�̊m�F
	if (m_hit_down == false)
	{
		Draw_flag = false;

		m_ani_timey += 1;

		if (m_ani_timey > 8)
		{
			m_ani_framey += 1;
			m_ani_timey = 0;
		}
		if (m_ani_framey == 8)
		{
			m_ani_framey = 0;
		}
	}
	else
	{

		Draw_flag = true;
		m_ani_timey = 0;
		m_ani_framey = 0;
	}

	//���C
	m_vx += -(m_vx*0.098);

	//���R����
	m_vy += 9.8 / (16.0f);

	//�ʒu�̍X�V
	m_px += m_vx;
	m_py += m_vy;
}

//�h���[
void  CObjhero::Draw()
{

	//�����`��p
	int AniDatax[8] =
	{
		-1,0,1,2,3,4,5,6,
	};

	int AniDatay[9] =
	{
		1,1,2,2,2,2,2,2,0,
	};

	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;  //�`��؂���ʒu
	RECT_F dst;  //�`���\���ʒu
	if (Draw_flag == true)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 64.0f;
		src.m_left = 0.0f + AniDatax[m_ani_framex] * 64;
		src.m_right = 64.0f + AniDatax[m_ani_framex] * 64;
		src.m_bottom = 128.0f;
	}
	else
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 128.0f;
		src.m_left = 0.0f + AniDatay[m_ani_framey] * 64;
		src.m_right = 64.0f + AniDatay[m_ani_framey] * 64;
		src.m_bottom = 192.0f;
	}

	//�\���ʒu�̐ݒ�
	dst.m_top    = 0.0f+m_py;
	dst.m_left   = (   64.0f*m_posture)+m_px;
	dst.m_right  = (64- 64.0f*m_posture)+m_px;
	dst.m_bottom = 64.0f+m_py;

	//�`��
	Draw::Draw(3, &src, &dst, c, 0.0f);
}