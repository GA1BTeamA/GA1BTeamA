//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameL\UserData.h"

#include "GameHead.h"
#include "Objkanbans.h"
#include "Objhero.h"

extern CObjBlock* g_objb;

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

	for (int i = 0; i < MAPSIZE_Y; i++)
	{
		for (int j = 0; j < MAPSIZE_X; j++)
		{
			if (g_objb->GetMap(j,i) == 19)
			{
				//�\���ʒu�̐ݒ�
				dst.m_top = i*32.0f;
				dst.m_left = j*32.0f + g_objb->GetScroll();
				dst.m_right = dst.m_left + 32.0f;
				dst.m_bottom = dst.m_top + 32.0f;
				
				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 32.0f;
				src.m_bottom = 32.0f;

				Draw::Draw(5, &src, &dst, c, 0.0f);
			}
		}
	}
}
