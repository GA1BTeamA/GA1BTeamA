//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameL\UserData.h"

#include "GameHead.h"
#include "Objgateopenright.h"
#include "Objhero.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjgateopenright::CObjgateopenright()
{
}

//�C�j�V�����C�Y
void CObjgateopenright::Init()
{
}

//�A�N�V����
void CObjgateopenright::Action()
{
}

//�h���[
void CObjgateopenright::Draw()
{
	//�J���[���
	float c[4] = { 1.0f,1.0f,1.0f ,1.0f };

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`�挳�\���ʒu

				//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 150.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 224.0f;
	dst.m_right = 256.0f;
	dst.m_bottom = 160.0f;

	Draw::Draw(9, &src, &dst, c, 0.0f);
}
