//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "Objitem2.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�u���b�N����l���؂�ւ� false=���p true=�Z�p
extern  bool g_hero_change;

//�Z�̃A�C�e���|�[�`[0]=�Z[1]=��
extern int Bitem_porch[2];

//���̃A�C�e���|�[�`[0]=�C[1]=��
extern int Sitem_porch[2];

//�C�j�V�����C�Y
void CObjitem2::Init()
{

}

//�A�N�V����
void CObjitem2::Action()
{

}

//�h���[
void CObjitem2::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 66.0f;
	dst.m_right = 130.0f;
	dst.m_bottom = 64.0f;

	//�`��
	Draw::Draw(4, &src, &dst, c, 0.0f);
}