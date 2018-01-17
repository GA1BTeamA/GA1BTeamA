//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameL\UserData.h"

#include "GameHead.h"
#include "ObjBlock.h"
#include "Objhero.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjBlock::CObjBlock()
{
	m_block_scroll = 0.0f;

	//�}�b�v�f�[�^���R�s�[
	//memcpy(m_map, map, sizeof(int)*(18 * 400));
}

//�C�j�V�����C�Y
void CObjBlock::Init()
{

	//�}�b�v�f�[�^
	//�O���f�[�^�̓ǂݍ���(�X�e�[�W���)
	unique_ptr<wchar_t>p;  //�X�e�[�W���|�C���^�[
	int size;  //�X�e�[�W���̑傫��
	p = Save::ExternalDataOpen(L"mapdata.csv", &size);  //�O���f�[�^�ǂݍ���

	
	int count = 1;
	for (int i = 0; i < MAPSIZE_X; i++)
	{
		for (int j = 0; j < 400; j++)
		{
			int w = 0;
			swscanf_s(&p.get()[count], L"%d", &w);

			m_map[i][j] = w;
			if(w>=10)
				count += 3;
			else 
				count += 2;
		}
	}
	/*
	int block_data[20][25] =
	{
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0 },
		{ 0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },

	};
	*/
}

//�A�N�V����
void CObjBlock::Action()
{

	//��l���̈ʒu���擾
	CObjhero* hero = (CObjhero*)Objs::GetObj(OBJ_HERO);
	CObjhero2* hero2 = (CObjhero2*)Objs::GetObj(OBJ_HERO2);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//����X�N���[�����C��
	if (hx < 80)
	{
		hero->SetX(80);						//��l���̓��C���𒴂��Ȃ��悤�ɂ���
		m_block_scroll -= hero->GetVX();	//��l�����{�������ׂ����̒l��m_block_scroll�ɉ�����
	}

	//�O���X�N���[�����C��
	if (hx > 400)
	{
		hero->SetX(400);					//��l���̓��C���𒴂��Ȃ��悤�ɂ���
		m_block_scroll -= hero->GetVX();	//��l�����{�������ׂ����̒l��m_block_scroll�ɉ�����
	}

	//�G�o�����C��
	//��l���̈ʒu�{500��G�o�����C���ɂ���
	float line = hx + (-m_block_scroll) + 800;

	//�G�o�����C����v�f�ԍ���
	int ex = ((int)line) / 32;

	//�G�o�����C���̗������
	for (int i = 0; i < MAPSIZE_X; i++)
	{
		//��̒�����17��T��
		if (m_map[i][ex] == 17)
		{
			//17������΁A�G���o��
			CObjEnemy1* obje = new CObjEnemy1(ex*32.0f, i*32.0f);
			Objs::InsertObj(obje, OBJ_ENEMY1, 2);

			//�G�o���ꏊ�̒l��0�ɂ���
			m_map[i][ex] = 0;
		}
	}

	//��l���̏Փˊm�F��Ԋm�F�p�t���O�̏�����
	hero->SetUp(false);
	hero->SetDown(false);
	hero->SetLeft(false);
	hero->SetRight(false);

	//����ł���block�̎�ނ̏�����
	hero->SetBT(0);

	//m_map�̑S�v�f�ɃA�N�Z�X
	for (int i = 0; i < MAPSIZE_X; i++)
	{
		for (int j = 0; j < 400; j++)
		{
			if (m_map[i][j] > 0 && m_map[i][j] != 15 && m_map[i][j] != 11 && m_map[i][j] != 17 && m_map[i][j] != 18)
			{
				//�v�f�ԍ������W�ɕύX
				float x = j*32.0f;
				float y = i*32.0f;

				//��l���ƃu���b�N�̓��蔻��
				if ((hx+19.0f + (-m_block_scroll)+26.0f > x) && (hx+19.0+(-m_block_scroll) < x + 32.0f) && (hy + 64.0f > y) && (hy < y + 32.0f))
				{
					//�㉺���E����

					//vector�̍쐬
					float vx[2]; 
					float vy[2];

					vx[0]= (hx + (-m_block_scroll))+32 - x;
					vy[0]= hy+32  - y;

					vx[1] = (hx + (-m_block_scroll)+32) - x;
					vy[1] = hy  - y;
					//float vx = (hx+32+(-m_block_scroll)) - x;
					//float vy = hy + 32 - y;

					for (int k = 0; k < 2; k++)
					{
						//���������߂�
						float len = sqrt(vx[k]*vx[k] + vy[k]*vy[k]);

						//�p�x�����߂�
						float r = atan2(vy[k], vx[k]);
						r = r*180.0f / 3.14f;

						if (r <= 0.0f)
							r = abs(r);
						else
							r = 360.0f - abs(r);

						//len��������̒������Z���ꍇ����ɓ���
						if (len < 38)
						{

							//�p�x�ŏ㉺���E�𔻒�
							if ((r <= 45 && r>=0) || r >= 315)
							{
								//�E
								hero->SetRight(true);//��l�����������ɏՓ˂��Ă���
								hero->SetX(x + 10.0f + (m_block_scroll));//�u���b�N�̈ʒu�[��l���̕�
								hero->SetVX(-hero->GetVX()*0.1f);//-VX*�����W��
								hx = x + 10.0f + (m_block_scroll);

							}
							if (r >= 45 && r <= 135)
							{
								if (k == 0)
								{
									//��
									hero->SetDown(true);//��l���̉��̕������Փ˂��Ă���
									hero->SetY(y - 64.0f);//�u���b�N�ʒu�[��l���̕�
									hero->SetBT(m_map[i][j]);//�u���b�N�̗v�f(type)����l���ɓn��
									hero->SetVY(0.0f);
								}
							}
							if (r >= 135 && r <= 225)
							{
								//��
								hero->SetLeft(true);//��l�����E�̕����ɏՓ˂��Ă���
								hero->SetX(x - 52.0f + (m_block_scroll));//�u���b�N�̈ʒu�[��l���̕�
								hero->SetVX(-hero->GetVX()*0.1f);//-VX*�����W��
								hx = x - 55.0f  + (m_block_scroll);
							}
							if (r >= 225 && r <= 315)
							{
								//��
								if (k == 1)
								{
									hero->SetUp(true);//��l���̏�̕������Փ˂��Ă���
									hero->SetBT(m_map[i][j]);//�u���b�N�̗v�f(type)����l���ɓn��
									//hero->SetY(y + 64.0f);//�u���b�N�̈ʒu+��l���̕�
									if (hero->GetVY() < 0)
									{
										hero->SetVY(0.0f);
									}
								}
						
							}
							
						}
					}
				}
			}
		}
	}



}

//�h���[
void CObjBlock::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	for (int i = 0; i < MAPSIZE_X; i++)
	{
		for (int j = 0; j < 400; j++)
		{
			if (m_map[i][j] > 0)
			{
				//�\���ʒu
				dst.m_top    = i*32.0f;
				dst.m_left = j*32.0f + m_block_scroll;
				dst.m_right = dst.m_left + 32.0f;
				dst.m_bottom =  dst.m_top+32.0f;

				//�`��
				//���u���b�N
				if (m_map[i][j] == 1|| m_map[i][j] == 13)
				{
					//�؂���ʒu
					src.m_top = 0.0f;
					src.m_left = 0.0f;
					src.m_right = 32.0f;
					src.m_bottom = 32.0f;

					Draw::Draw(1, &src, &dst, c, 0.0f);
				}

				//�؃u���b�N
				else if (m_map[i][j] == 2)
				{
					//�؂���ʒu
					src.m_top = 0.0f;
					src.m_left = 64.0f;
					src.m_right = 96.0f;
					src.m_bottom = 32.0f;

					Draw::Draw(1, &src, &dst, c, 0.0f);
				}

				//���u���b�N(��)
				else if (m_map[i][j] == 4)
				{
					//�؂���ʒu
					src.m_top = 0.0f;
					src.m_left = 64.0f;
					src.m_right = 96.0f;
					src.m_bottom = 32.0f;

					Draw::Draw(1, &src, &dst, c, 0.0f);
				}

				////���u���b�N(��)
				//else if (m_map[i][j] == 13)
				//{
				//	//�؂���ʒu
				//	src.m_top = 0.0f;
				//	src.m_left = 0.0f;
				//	src.m_right = 32.0f;
				//	src.m_bottom = 32.0f;

				//	Draw::Draw(1, &src, &dst, c, 0.0f);
				//}

				//�Z�u���b�N(��)
				else if (m_map[i][j] == 5)
				{
					//�؂���ʒu
					src.m_top = 0.0f;
					src.m_left = 64.0f;
					src.m_right = 96.0f;
					src.m_bottom = 32.0f;

					Draw::Draw(1, &src, &dst, c, 0.0f);
				}

				//��u���b�N
				else if (m_map[i][j] == 3)
				{
					//�؂���ʒu
					src.m_top = 0.0f;
					src.m_left = 96.0f;
					src.m_right = 128.0f;
					src.m_bottom = 32.0f;

					Draw::Draw(1, &src, &dst, c, 0.0f);
				}

				//�y�u���b�N
				else if (m_map[i][j] == 8|| m_map[i][j] == 16)
				{
					//�؂���ʒu
					src.m_top = 0.0f;
					src.m_left = 32.0f;
					src.m_right = 64.0f;
					src.m_bottom = 32.0f;

					Draw::Draw(1, &src, &dst, c, 0.0f);
				}

				//��u���b�N(�㕔��)
				else if (m_map[i][j] == 15)
				{
					//�؂���ʒu
					src.m_top = 0.0f;
					src.m_left = 128.0f;
					src.m_right = 162.0f;
					src.m_bottom = 32.0f;

					Draw::Draw(1, &src, &dst, c, 0.0f);
				}
				//�j�u���b�N
				else if (m_map[i][j] == 6)
				{
					//�؂���ʒu
					src.m_top = 0.0f;
					src.m_left = 160.0f;
					src.m_right = 192.0f;
					src.m_bottom = 32.0f;

					Draw::Draw(1, &src, &dst, c, 0.0f);
				}
				//�j�u���b�N�i�t���܁j
				else if (m_map[i][j] == 12)
				{
					//�؂���ʒu
					src.m_top = 32.0f;
					src.m_left = 160.0f;
					src.m_right = 192.0f;
					src.m_bottom = 0.0f;

					Draw::Draw(1, &src, &dst, c, 0.0f);
				}
			}
		}
	}

}
