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

//�g�p����l�[���X�y�[�X
using namespace GameL;

//----------------------------------------------

//��u���b�N

//�u���b�N����l���؂�ւ� false=���p true=�Z�p
extern bool g_hero_change;

CObjGateBlock::CObjGateBlock()
{
}
//�C�j�V�����C�Y
void CObjGateBlock::Init()
{
}
//�A�N�V����
void CObjGateBlock::Action()
{
	//�Z��l���̈ʒu���擾
	CObjhero* hero = (CObjhero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//����l���̈ʒu���擾
	CObjhero2* hero2 = (CObjhero2*)Objs::GetObj(OBJ_HERO2);
	float hx2 = hero2->GetX();
	float hy2 = hero2->GetY();

	/*if (g_hero_change == true)
	{
		//�Z����X�N���[�����C��
		if (hx < 80)
		{
			hero->SetX(80);						//��l���̓��C���𒴂��Ȃ��悤�ɂ���
			m_block_scroll -= hero->GetVX();	//��l�����{�������ׂ����̒l��m_block_scroll�ɉ�����
		}

		//�Z�O���X�N���[�����C��
		if (hx > 400)
		{
			hero->SetX(400);					//��l���̓��C���𒴂��Ȃ��悤�ɂ���
			m_block_scroll -= hero->GetVX();	//��l�����{�������ׂ����̒l��m_block_scroll�ɉ�����
		}
	}

	else
	{
		//������X�N���[�����C��
		if (hx2 < 80)
		{
			hero2->SetX(80);						//��l���̓��C���𒴂��Ȃ��悤�ɂ���
			m_block_scroll -= hero2->GetVX();	//��l�����{�������ׂ����̒l��m_block_scroll�ɉ�����
		}

		//���O���X�N���[�����C��
		if (hx2 > 400)
		{
			hero2->SetX(400);					//��l���̓��C���𒴂��Ȃ��悤�ɂ���
			m_block_scroll -= hero2->GetVX();	//��l�����{�������ׂ����̒l��m_block_scroll�ɉ�����
		}
	}*/
}
//�h���[
void CObjGateBlock::Draw()
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
	dst.m_top = 448.0f;
	dst.m_left = 320.0f;
	dst.m_right = 384.0f;
	dst.m_bottom = 512.0f;

	Draw::Draw(15, &src, &dst, c, 0.0f);
}

//----------------------------------------------

//�J�� ��

CObjGateOpenLeft::CObjGateOpenLeft()
{
}
//�C�j�V�����C�Y
void CObjGateOpenLeft::Init()
{
}
//�A�N�V����
void CObjGateOpenLeft::Action()
{
}
//�h���[
void CObjGateOpenLeft::Draw()
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
	dst.m_top = 512.0f;
	dst.m_left = 320.0f;
	dst.m_right = 384.0f;
	dst.m_bottom = 576.0f;

	Draw::Draw(8, &src, &dst, c, 0.0f);
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
	dst.m_top = 512.0f;
	dst.m_left = 320.0f;
	dst.m_right = 384.0f;
	dst.m_bottom = 576.0f;

	Draw::Draw(9, &src, &dst, c, 0.0f);
}
