//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawTexture.h"
#include "GameHead.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�u���b�N����l���؂�ւ� false=���p true=�Z�p
extern  bool g_hero_change;

//�C�j�V�����C�Y
void CObjBackground::Init()
{
	m_scroll = 0.0f;
	m_x1 = 0.0f;
	m_x2 = 800.0f;
	m_key_flag = false;

	
}

//�A�N�V����
void CObjBackground::Action()
{
	//��l���̈ʒu���擾
	CObjhero* hero = (CObjhero*)Objs::GetObj(OBJ_HERO);
	CObjhero2* hero2 = (CObjhero2*)Objs::GetObj(OBJ_HERO2);

	if (g_hero_change == false)
	{
		hx = hero2->GetX();
		hy = hero2->GetY();
		//�w�i1�E2�̓���
		if (hx > 400)
		{
			m_x1 -= hero2->GetVX();
			m_x2 -= hero2->GetVX();
		}
		else if (hx < 80)
		{
			m_x1 -= hero2->GetVX();
			m_x2 -= hero2->GetVX();
		}
	}
	else
	{
		hx = hero->GetX();
		hy = hero->GetY();

		//�w�i1�E2�̓���
		if (hx > 400)
		{
			m_x1 -= hero->GetVX();
			m_x2 -= hero->GetVX();
		}
		else if (hx < 80)
		{
			m_x1 -= hero->GetVX();
			m_x2 -= hero->GetVX();
		}
	}


	
	
	if (m_x1 < -800.0f)
	{
		m_x1 = m_x2 + 800;
	}
	if (m_x1 > 800.0f)
	{
		m_x1 = m_x2 - 800;
	}
	
	if (m_x2 < -800.0f)
	{
		m_x2 = m_x1 + 800;
	}
	if (m_x2 > 800.0f)
	{
		m_x2 = m_x1 - 800;
	}

	//�|�[�Y��ʂɈړ�(�̔w�i�\��)
	if (Input::GetVKey('C') == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CScenePause);

			m_key_flag == false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//�h���[
void CObjBackground::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f, 1.0f, 1.0f, 1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 800.0f;
	src.m_bottom = 400.0f;

	//�w�i1�ʒu�ݒ肵�`��
	dst.m_top = 0.0f;
	dst.m_left = 0.0f + m_x1;
	dst.m_right = 800.0f + m_x1;
	dst.m_bottom = 600.0f;
	Draw::Draw(0, &src, &dst, c, 0.0f);

	//�w�i2�ʒu�ݒ肵�`��
	dst.m_top = 0.0f;
	dst.m_left = 0.0f + m_x2;
	dst.m_right = 800.0f + m_x2;
	dst.m_bottom = 600.0f;
	Draw::Draw(0, &src, &dst, c, 0.0f);
}