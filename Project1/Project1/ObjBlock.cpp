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


//�u���b�N����l���؂�ւ� false=���p true=�Z�p
bool g_hero_change;

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


//BlockHit�֐�
//����1  float* x          ;������s��object��x�ʒu
//����2  float* y          ;������s��object��y�ʒu
//����3  bool   scroll_on  ;������s��object�̓X�N���[���̉e���^���邩�ǂ����itrue=�^���� false=�^���Ȃ��j
//����4  bool*  up         ;�㉺���E����̏㕔���ɓ������Ă��邩�ǂ�����Ԃ�
//����5  bool*  down       ;�㉺���E����̉������ɓ������Ă��邩�ǂ�����Ԃ�
//����6  bool*  left       ;�㉺���E����̍������ɓ������Ă��邩�ǂ�����Ԃ�
//����7  bool*  right      ;�㉺���E����̉E�����ɓ������Ă��邩�ǂ�����Ԃ�
//����8  float* vx         ;���E���莞�̔����ɂ��ړ������E�͂̒l�ς��ĕԂ�
//����9  float* vy         ;�㉺���莞�ɂ�鎩�R�����^���̈ړ������E�͂̒l�ς��ĕԂ�
//����10 int*   bt         ;���������莞�A����ȃu���b�N�̃^�C�v��Ԃ�
//������s��object�ƃu���b�N64��64����ŁA�����蔻��Ə㉺���E������s��
//���̌��ʂ͈���4�`10�ɕԂ�
void CObjBlock::BlockHit
(
	float* x, float* y, bool scroll_on,
	bool*up, bool* down, bool* left, bool* right,
	float *vx, float *vy, int* bt
)
{
	//��l���̏Փˊm�F��Ԋm�F�p�t���O�̏�����
	*up = false;
	*down = false;
	*left = false;
	*right = false;

	//����ł���block�̎�ނ̏�����
	*bt = 0;

	//m_map�̑S�v�f�ɃA�N�Z�X
	for (int i = 0; i < MAPSIZE_X; i++)
	{
		for (int j = 0; j < 400; j++)
		{
			if (m_map[i][j] > 0 && m_map[i][j] != 15 && m_map[i][j] != 11 && m_map[i][j] != 17 && m_map[i][j] != 18 && m_map[i][j] != 19)
			{
				//�v�f�ԍ������W�ɕύX
				float bx = j*32.0f;
				float by = i*32.0f;

				//�X�N���[���̉e��
				float scroll = scroll_on ? m_block_scroll : 0;

				//��l���ƃu���b�N�̓��蔻��
				if ((*x + 19.0f + (-m_block_scroll) + 26.0f > bx) && (*x + 19.0 + (-m_block_scroll) < bx + 32.0f) && (*y + 64.0f > by) && (*y < by + 32.0f))
				{
					//�㉺���E����

					//vector�̍쐬
					float rvx[2];
					float rvy[2];

					rvx[0] = (*x + (-m_block_scroll)) + 32 - bx;
					rvy[0] = *y + 32 - by;

					rvx[1] = (*x + (-m_block_scroll) + 32) - bx;
					rvy[1] = *y - by;
					//float vx = (hx+32+(-m_block_scroll)) - x;
					//float vy = hy + 32 - y;

					for (int k = 0; k < 2; k++)
					{
						//���������߂�
						float len = sqrt(rvx[k] * rvx[k] + rvy[k] * rvy[k]);

						//�p�x�����߂�
						float r = atan2(rvy[k],rvx[k]);
						r = r*180.0f / 3.14f;

						if (r <= 0.0f)
							r = abs(r);
						else
							r = 360.0f - abs(r);

						//len��������̒������Z���ꍇ����ɓ���
						if (len < 38)
						{

							//�p�x�ŏ㉺���E�𔻒�
							if ((r <= 45 && r >= 0) || r >= 315)
							{
								//�E
								*right = true;//��l�����������ɏՓ˂��Ă���
								*x=(bx + 10.0f + (m_block_scroll));//�u���b�N�̈ʒu�[��l���̕�
								*vx=-(*vx)*0.1f;//-VX*�����W��
								*x = bx + 10.0f + (m_block_scroll);

							}
							if (r >= 45 && r <= 135)
							{
								if (k == 0)
								{
									//��
									*down=true;//��l���̉��̕������Փ˂��Ă���
									*y=by - 64.0f;//�u���b�N�ʒu�[��l���̕�
									*bt=m_map[i][j];//�u���b�N�̗v�f(type)����l���ɓn��
									*vy = 0.0f;
								}
							}
							if (r >= 135 && r <= 225)
							{
								//��
								*left=true;//��l�����E�̕����ɏՓ˂��Ă���
								*x=bx - 50.0f + (m_block_scroll);//�u���b�N�̈ʒu�[��l���̕�
								*vx=-(*vx)*0.1f;//-VX*�����W��
								*x = bx - 55.0f + (m_block_scroll);
							}
							if (r >= 225 && r <= 315)
							{
								//��
								if (k == 1)
								{
									*up=true;//��l���̏�̕������Փ˂��Ă���
									*bt=m_map[i][j];//�u���b�N�̗v�f(type)����l���ɓn��
									//*y=by + 64.0f;//�u���b�N�̈ʒu+��l���̕�
									if (*vy < 0)
									{
										*vy=0.0f;
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