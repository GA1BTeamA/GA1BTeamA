//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameL\UserData.h"

#include "GameHead.h"
#include "ObjBlock.h"
#include "ObjGate.h"
#include "Objhero.h"

//extern CObjhero* objh;

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�u���b�N����l���؂�ւ� false=���p true=�Z�p
extern bool g_hero_change;

//----------------------------------------------

//��u���b�N

CObjGate::CObjGate()
{
}
//�C�j�V�����C�Y
void CObjGate::Init()
{
	gb_map_x = /*246*/0;
	gb_x = 0.0f;
}
//�A�N�V����
void CObjGate::Action()
{
	//�Z��l���̈ʒu���擾
	CObjhero* hero = (CObjhero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//����l���̈ʒu���擾
	CObjhero2* hero2 = (CObjhero2*)Objs::GetObj(OBJ_HERO2);
	float hx2 = hero2->GetX();
	float hy2 = hero2->GetY();

	//��l�����C��
	if (g_hero_change == true)
	{
		//�Z���C��
		if (hx < 80|| hx > MAPSIZE_X)
		{
			gb_x -= hero->GetVX();
		}
	}
	else
	{
		//�����C��
		if (hx2 < 80|| hx2 > MAPSIZE_X)
		{
			gb_x -= hero2->GetVX();
		}
	}

	//�����蔻��-------------------------------------------

	//�v�f�ԍ������W�ɕύX
	float x = gb_map_x * 64;

	//��l���ƃu���b�N�̓����蔻��
	

}
//�h���[
void CObjGate::Draw()
{
	//�J���[���
	float c[4] = { 1.0f,1.0f,1.0f ,1.0f };

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`�挳�\���ʒu

	int i;

	//��u���b�N----------------------------------------------------
	for (i = 0; i < 8; i++)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 64.0f;
		src.m_bottom = 64.0f;
		//�\���ʒu�̐ݒ�
		dst.m_top    = ((i * 2) * 32.0f);
		dst.m_left   =  (gb_map_x            * 32.0f)       + gb_x;
		dst.m_right  = ((gb_map_x            * 32.0f) + 64) + gb_x;
		dst.m_bottom = ((i * 2) * 32.0f) + 64;

		Draw::Draw(8, &src, &dst, c, 0.0f);
	}

	//�Z��u���b�N------------------------------------------------
	if (g_hero_change == true)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 64.0f;
		src.m_right = 128.0f;
		src.m_bottom = 64.0f;
		//�\���ʒu�̐ݒ�
		dst.m_top = ((i * 2) * 32.0f);
		dst.m_left = (gb_map_x * 32.0f) + gb_x;
		dst.m_right = ((gb_map_x * 32.0f) + 64) + gb_x;
		dst.m_bottom = ((i * 2) * 32.0f) + 64;

		Draw::Draw(8, &src, &dst, c, 0.0f);
	}
	//����u���b�N------------------------------------------------
	else
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 128.0f;
		src.m_right = 192.0f;
		src.m_bottom = 64.0f;
		//�\���ʒu�̐ݒ�
		dst.m_top = ((i * 2) * 32.0f);
		dst.m_left = (gb_map_x * 32.0f) + gb_x;
		dst.m_right = ((gb_map_x * 32.0f) + 64) + gb_x;
		dst.m_bottom = ((i * 2) * 32.0f) + 64;

		Draw::Draw(8, &src, &dst, c, 0.0f);
	}
}

//----------------------------------------------

//�J�� �E

CObjGateOpenRight::CObjGateOpenRight()
{
}

//�C�j�V�����C�Y
void CObjGateOpenRight::Init()
{
}

//�A�N�V����
void CObjGateOpenRight::Action()
{
}

//�h���[
void CObjGateOpenRight::Draw()
{
	//�J���[���
	float c[4] = { 1.0f,1.0f,1.0f ,1.0f };

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`�挳�\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	//�\���ʒu�̐ݒ�
	/*dst.m_top = 512.0f;
	dst.m_left = 320.0f;
	dst.m_right = 384.0f;
	dst.m_bottom = 576.0f;*/

	Draw::Draw(9, &src, &dst, c, 0.0f);
}
