//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameL\UserData.h"

#include "GameHead.h"
#include "Objgateopenleft.h"
#include "Objhero.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjgateopenleft::CObjgateopenleft()
{
}

//�C�j�V�����C�Y
void CObjgateopenleft::Init()
{
}

//�A�N�V����
void CObjgateopenleft::Action()
{
}

//�h���[
void CObjgateopenleft::Draw()
{
	//�J���[���
	float c[4] = { 1.0f,1.0f,1.0f ,1.0f };

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`�挳�\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 128.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 224.0f;
	dst.m_right = 290.0f;
	dst.m_bottom = 180.0f;

	Draw::Draw(8, &src, &dst, c, 0.0f);
}
