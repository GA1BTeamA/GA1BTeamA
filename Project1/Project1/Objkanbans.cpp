//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameL\UserData.h"

#include "GameHead.h"
#include "Objkanbans.h"
#include "Objhero.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjkanbans::CObjkanbans()
{
}

//�C�j�V�����C�Y
void CObjkanbans::Init()
{
}

//�A�N�V����
void CObjkanbans::Action()
{
}

//�h���[
void CObjkanbans::Draw()
{
	//�J���[���
	float c[4] = { 1.0f,1.0f,1.0f ,1.0f };

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`�挳�\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 32.0f;
	src.m_bottom = 32.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 128.0f;
	dst.m_left = 128.0f;
	dst.m_right = 160.0f;
	dst.m_bottom = 160.0f;

	Draw::Draw(5, &src, &dst, c, 0.0f);
}
