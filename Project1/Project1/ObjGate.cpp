//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameL\UserData.h"

#include "GameHead.h"
#include "ObjBlock.h"
#include "Objhero.h"
#include "ObjGate.h"

extern CObjhero* objh;

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�u���b�N����l���؂�ւ� false=���p true=�Z�p
extern bool g_hero_change;

//��l��������J����Ƃ��̃t���O
extern bool brother_gateopen;
extern bool sister_gateopen;

//----------------------------------------------

//��u���b�N

CObjGate::CObjGate()
{
	m_block_scroll = 0.0f;
}
//�C�j�V�����C�Y
void CObjGate::Init()
{
	//�}�b�v�f�[�^
	//�O���f�[�^�̓ǂݍ���(�X�e�[�W���)
	unique_ptr<wchar_t>p;  //�X�e�[�W���|�C���^�[
	int size;  //�X�e�[�W���̑傫��
	p = Save::ExternalDataOpen(L"mapdata.csv", &size);  //�O���f�[�^�ǂݍ���


	int count = 1;
	for (int i = 0; i < MAPSIZE_Y; i++)
	{
		for (int j = 0; j < MAPSIZE_X; j++)
		{
			int w = 0;
			swscanf_s(&p.get()[count], L"%d", &w);

			m_map[i][j] = w;
			if (w >= 10)
				count += 3;
			else
				count += 2;
		}
	}
}
//�A�N�V����
void CObjGate::Action()
{
	//�u���b�N���������Ă���
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//�Z��l���̈ʒu���擾
	CObjhero* hero = (CObjhero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//����l���̈ʒu���擾
	CObjhero2* hero2 = (CObjhero2*)Objs::GetObj(OBJ_HERO2);
	float hx2 = hero2->GetX();
	float hy2 = hero2->GetY();

	if (g_hero_change == true)
	{
		m_block_scroll = block->GetgbScroll();
		//�Z����}�b�v�X�N���[��
		if (hx < 80)
		{
			//m_block_scroll -= hero->GetVX();	//��l�����{�������ׂ����̒l��m_block_scroll�ɉ�����
			m_block_scroll = block->GetgbScroll();
		}

		//�Z�O���}�b�v�X�N���[��
		if (hx > MAPSIZE_X)
		{
			//m_block_scroll -= hero->GetVX();	//��l�����{�������ׂ����̒l��m_block_scroll�ɉ�����
			m_block_scroll = block->GetgbScroll();
		}
	}
	else
	{
		m_block_scroll = block->GetgsScroll();
		//������}�b�v�X�N���[��
		if (hx2 < 80)
		{
			//m_block_scroll -= hero2->GetVX();	//��l�����{�������ׂ����̒l��m_block_scroll�ɉ�����
			m_block_scroll = block->GetgsScroll();
		}

		//���O���}�b�v�X�N���[��
		if (hx2 > MAPSIZE_X)
		{
			//m_block_scroll -= hero2->GetVX();	//��l�����{�������ׂ����̒l��m_block_scroll�ɉ�����
			m_block_scroll = block->GetgsScroll();
		}
	}
}

//�h���[
void CObjGate::Draw()
{
	//�J���[���
	float c[4] = { 1.0f,1.0f,1.0f ,1.0f };

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`�挳�\���ʒu

	for (int i = 0; i < MAPSIZE_Y; i++)
	{
		for (int j = 0; j < MAPSIZE_X; j++)
		{
			if (m_map[i][j] > 0)
			{
				//�\���ʒu
				//64*64�ŕ\��
				dst.m_top = i*32.0f;
				dst.m_left = j*32.0f + m_block_scroll;
				dst.m_right = dst.m_left + 64.0f;
				dst.m_bottom = dst.m_top + 64.0f;

				//�`��

				//�Z��u���b�N
				if (g_hero_change == true)
				{
					if (m_map[i][j] == 21)
					{
						if (brother_gateopen == false)
						{
							//�؂���ʒu�̐ݒ�
							src.m_top = 0.0f;
							src.m_left = 64.0f;
							src.m_right = 128.0f;
							src.m_bottom = 64.0f;

							Draw::Draw(8, &src, &dst, c, 0.0f);
						}
					}
				}
				//����u���b�N
				if (g_hero_change == false)
				{
					if (m_map[i][j] == 21)
					{
						if (sister_gateopen == false)
						{
							//�؂���ʒu�̐ݒ�
							src.m_top = 0.0f;
							src.m_left = 128.0f;
							src.m_right = 192.0f;
							src.m_bottom = 64.0f;
							
							Draw::Draw(8, &src, &dst, c, 0.0f);
						}
					}
				}
				
				//��u���b�N
				if (m_map[i][j] == 22)
				{
					//�؂���ʒu�̐ݒ�
					src.m_top = 0.0f;
					src.m_left = 0.0f;
					src.m_right = 64.0f;
					src.m_bottom = 64.0f;

					Draw::Draw(8, &src, &dst, c, 0.0f);
				}

				//�J��u���b�N��
				if (m_map[i][j] == 21)
				{
					if (brother_gateopen == true && g_hero_change == true || sister_gateopen == true && g_hero_change == false)
					{
						//�؂���ʒu�̐ݒ�
						src.m_top = 0.0f;
						src.m_left = 192.0f;
						src.m_right = 256.0f;
						src.m_bottom = 64.0f;
						Draw::Draw(8, &src, &dst, c, 0.0f);
					}

					
				}
			}
		}
	}
	
		

}

//----------------------------------------------

//�J�� �E

CObjGateOpenRight::CObjGateOpenRight()
{
	m_block_scroll = 0.0f;
}

//�C�j�V�����C�Y
void CObjGateOpenRight::Init()
{
	

	//�}�b�v�f�[�^
	//�O���f�[�^�̓ǂݍ���(�X�e�[�W���)
	unique_ptr<wchar_t>p;  //�X�e�[�W���|�C���^�[
	int size;  //�X�e�[�W���̑傫��
	p = Save::ExternalDataOpen(L"mapdata.csv", &size);  //�O���f�[�^�ǂݍ���


	int count = 1;
	for (int i = 0; i < MAPSIZE_Y; i++)
	{
		for (int j = 0; j < MAPSIZE_X; j++)
		{
			int w = 0;
			swscanf_s(&p.get()[count], L"%d", &w);

			m_map[i][j] = w;
			if (w >= 10)
				count += 3;
			else
				count += 2;
		}
	}
}

//�A�N�V����
void CObjGateOpenRight::Action()
{
	//�u���b�N���������Ă���
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//�Z��l���̈ʒu���擾
	CObjhero* hero = (CObjhero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//����l���̈ʒu���擾
	CObjhero2* hero2 = (CObjhero2*)Objs::GetObj(OBJ_HERO2);
	float hx2 = hero2->GetX();
	float hy2 = hero2->GetY();

	if (g_hero_change == true)
	{
		m_block_scroll = block->GetgbScroll();
		//�Z����}�b�v�X�N���[��
		if (hx < 80)
		{
			//m_block_scroll -= hero->GetVX();	//��l�����{�������ׂ����̒l��m_block_scroll�ɉ�����
			m_block_scroll = block->GetgbScroll();
		}

		//�Z�O���}�b�v�X�N���[��
		if (hx > MAPSIZE_X)
		{
			//m_block_scroll -= hero->GetVX();	//��l�����{�������ׂ����̒l��m_block_scroll�ɉ�����
			m_block_scroll = block->GetgbScroll();
		}
	}

	else
	{
		m_block_scroll = block->GetgsScroll();
		//������}�b�v�X�N���[��
		if (hx2 < 80)
		{
			//m_block_scroll -= hero2->GetVX();	//��l�����{�������ׂ����̒l��m_block_scroll�ɉ�����
			m_block_scroll = block->GetgsScroll();
		}

		//���O���}�b�v�X�N���[��
		if (hx2 > MAPSIZE_X)
		{
			//m_block_scroll -= hero2->GetVX();	//��l�����{�������ׂ����̒l��m_block_scroll�ɉ�����
			m_block_scroll = block->GetgsScroll();
		}
	}
}

//�h���[
void CObjGateOpenRight::Draw()
{
	//�J���[���
	float c[4] = { 1.0f,1.0f,1.0f ,1.0f };

	RECT_F src;	//�`�挳�؂���ʒu
	RECT_F dst;	//�`�挳�\���ʒu

	//�\���ʒu�̐ݒ�
	for (int i = 0; i < MAPSIZE_Y; i++)
	{
		for (int j = 0; j < MAPSIZE_X; j++)
		{
			if (m_map[i][j] > 0)
			{
				//64*64�ŕ\��
				dst.m_top = i*32.0f;
				dst.m_left = j*32.0f + m_block_scroll;
				dst.m_right = dst.m_left + 64.0f;
				dst.m_bottom = dst.m_top + 64.0f;

				if (m_map[i][j] == 21)
				{
					if (brother_gateopen == true && 
						g_hero_change == true || 
						sister_gateopen == true && 
						g_hero_change == false)
					{
						//�؂���ʒu�̐ݒ�
						src.m_top = 0.0f;
						src.m_left = 0.0f;
						src.m_right = 64.0f;
						src.m_bottom = 64.0f;
						Draw::Draw(9, &src, &dst, c, 0.0f);
					}

					
				}
			}
		}
	}
}
