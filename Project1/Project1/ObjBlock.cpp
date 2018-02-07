//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameL\UserData.h"

#include "GameHead.h"
#include "ObjBlock.h"
#include "Objhero.h"

extern CObjhero* objh;
extern CObjhero2* objh2;

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�u���b�N����l���؂�ւ� false=���p true=�Z�p
bool g_hero_change;

//��l���������������Ă��邩�̃t���O
bool brother_key;
bool sister_key;
bool armor_block;
bool shose_block;
//��l��������J����Ƃ��̃t���O
bool brother_gateopen;
bool sister_gateopen;
bool brother_gateopen2;
bool sister_gateopen2;
//�X�C�b�`�𓥂�ł���Ƃ��̃t���O
bool switch_flag;
bool switch_flag2;

//�O���[�o���ʒu
extern float g_px;

//��l�����S�[���O�ɂ��邩�ǂ���
bool brother_goal;
bool sister_goal;

//�Z���̉�ʐ؂�ւ��t���O
bool screen_change_flag;

CObjBlock::CObjBlock()
{
	m_block_scroll = 0.0f;

	gb_block_scroll = 0.0f;

	gs_block_scroll = 0.0f;

	scroll_change_b = 0.0f;

	scroll_change_s = 0.0f;

	scroll_change_keep = 0.0f;

	screen_change_flag = false;

	button_flag = true;

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
	for (int i = 0; i < MAPSIZE_Y; i++)
	{
		for (int j = 0; j < MAPSIZE_X; j++)
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

	armor_block = false;
	shose_block = false;
	brother_key = false;
	sister_key = false;
	brother_gateopen = false;
	sister_gateopen = false;
	switch_flag = false;
}

//�A�N�V����
void CObjBlock::Action()
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
	
	//��l����ʐ؂�ւ�
	if (screen_change_flag == true)
	{

		if (g_hero_change == false)
		{
			scroll_change_keep = m_block_scroll;
			m_block_scroll = scroll_change_s;
			scroll_change_b = scroll_change_keep;
			g_hero_change = true;
		}
		else
		{
			scroll_change_keep = m_block_scroll;
			m_block_scroll = scroll_change_b;
			scroll_change_s = scroll_change_keep;
			g_hero_change = false;
		}

		screen_change_flag = false;

	}

	if (g_hero_change == true)
	{
		//�Z����X�N���[�����C��
		if (hx < 250)
		{

			hero->SetX(250);						//��l���̓��C���𒴂��Ȃ��悤�ɂ���
			m_block_scroll -= hero->GetVX();//��l�����{�������ׂ����̒l��m_block_scroll�ɉ�����
			gb_block_scroll -= hero->GetVX();//��l�����{�������ׂ����̒l��m_block_scroll�ɉ�����

		}

		//�Z�O���X�N���[�����C��
		if (hx > 380)
		{
			hero->SetX(380);					//��l���̓��C���𒴂��Ȃ��悤�ɂ���
			m_block_scroll -= hero->GetVX();	//��l�����{�������ׂ����̒l��m_block_scroll�ɉ�����
			gb_block_scroll -= hero->GetVX();//��l�����{�������ׂ����̒l��m_block_scroll�ɉ�����
		}
	}

	else
	{
		//������X�N���[�����C��
		if (hx2 < 250)
		{
			hero2->SetX(250);						//��l���̓��C���𒴂��Ȃ��悤�ɂ���
			m_block_scroll -= hero2->GetVX();	//��l�����{�������ׂ����̒l��m_block_scroll�ɉ�����
			gs_block_scroll -= hero2->GetVX();//��l�����{�������ׂ����̒l��m_block_scroll�ɉ�����
		}

		//���O���X�N���[�����C��
		if (hx2 > 380)
		{
			hero2->SetX(380);					//��l���̓��C���𒴂��Ȃ��悤�ɂ���
			m_block_scroll -= hero2->GetVX();	//��l�����{�������ׂ����̒l��m_block_scroll�ɉ�����
			gs_block_scroll -= hero2->GetVX();	//��l�����{�������ׂ����̒l��m_block_scroll�ɉ�����
		}
	}


	

	//�G�o�����C��
	//��l���̈ʒu�{500��G�o�����C���ɂ���
	float line = hx + (-m_block_scroll) + 1000;

	//�G�o�����C����v�f�ԍ���
	int ex = ((int)line) / 32;

	//�G�o�����C���̗������
	for (int i = 0; i < MAPSIZE_Y; i++)
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

	//�L�����؂�ւ��ɍۂ�����M�~�b�N�̉摜�Ɠ����蔻��؂�ւ�
	if (g_hero_change == true)
	{
		if (brother_gateopen == false)
		{
			for (int i = 0; i < MAPSIZE_Y; i++)
			{
				for (int j = 0; j < MAPSIZE_X; j++)
				{
					if (m_map[i][j] == 99)
					{
						m_map[i][j] = 21;
					}
				}
			}
		}
		else
		{
			for (int i = 0; i < MAPSIZE_Y; i++)
			{
				for (int j = 0; j < MAPSIZE_X; j++)
				{
					if (m_map[i][j] == 21)
					{
						m_map[i][j] = 99;
					}
				}
			}
		}
	}
	else
	{
		if (sister_gateopen == false)
		{
			for (int i = 0; i < MAPSIZE_Y; i++)
			{
				for (int j = 0; j < MAPSIZE_X; j++)
				{
					if (m_map[i][j] == 99)
					{
						m_map[i][j] = 21;
					}
				}
			}
		}
		else
		{
			for (int i = 0; i < MAPSIZE_Y; i++)
			{
				for (int j = 0; j < MAPSIZE_X; j++)
				{
					if (m_map[i][j] == 21)
					{
						m_map[i][j] = 99;
					}
				}
			}
		}
	}

	//��l�����X�C�b�`�𓥂�ł���ԁA���X�C�b�`�ƃu���b�N��p�ӂ���
	if (switch_flag == true||switch_flag2==true)
	{
		for (int i = 0; i < MAPSIZE_Y; i++)
		{
			for (int j = 0; j < MAPSIZE_X; j++)
			{
				if (m_map[i][j] == 27)
				{
					m_map[i][j] = 29;
					m_map[i + 1][j] = 30;
				}
				if (m_map[i][j] == 28)
				{
					m_map[i][j] = 31;
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < MAPSIZE_Y; i++)
		{
			for (int j = 0; j < MAPSIZE_X; j++)
			{
				if (m_map[i][j] == 29)
				{
					m_map[i][j] = 27;
					m_map[i + 1][j] = 1;
				}
				if (m_map[i][j] == 31)
				{
					m_map[i][j] = 28;
				}
			}
		}
	}
}

//�h���[
void CObjBlock::Draw()
{

	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f};

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	for (int i = 0; i < MAPSIZE_Y; i++)
	{
		for (int j = 0; j < MAPSIZE_X; j++)
		{
			if (m_map[i][j] > 0)
			{
				
				//�\���ʒu
				//�S�[����64*64�ŕ\��
				if (m_map[i][j] == 11)
				{
					dst.m_top = i*32.0f;
					dst.m_left = j*32.0f + m_block_scroll;
					dst.m_right = dst.m_left + 64.0f;
					dst.m_bottom = dst.m_top + 64.0f;
				}
				//����ȊO��32*32�ŕ\��
				else
				{
					dst.m_top = i*32.0f;
					dst.m_left = j*32.0f + m_block_scroll;
					dst.m_right = dst.m_left + 32.0f;
					dst.m_bottom = dst.m_top + 32.0f;
				}

			//�`��
				
					//���u���b�N(��)
			if (m_map[i][j] == 4)
			{
						//�؂���ʒu
						src.m_top = 0.0f;
						src.m_left = 64.0f;
						src.m_right = 96.0f;
						src.m_bottom = 32.0f;

						if (g_hero_change == true)
							c[3] = 0.5f;

						Draw::Draw(1, &src, &dst, c, 0.0f);

						c[3] = 1.0f;

						
			}

			//���u���b�N(��)
			else if (m_map[i][j] == 13)
			{
				//�؂���ʒu
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 32.0f;
				src.m_bottom = 32.0f;

				if (g_hero_change == true)
					c[3] = 0.5f;

				Draw::Draw(1, &src, &dst, c, 0.0f);

				c[3] = 1.0f;

			}
					//���u���b�N(�y)
			else if (m_map[i][j] == 16)
			{
				//�؂���ʒu
				src.m_top = 0.0f;
				src.m_left = 32.0f;
				src.m_right = 64.0f;
				src.m_bottom = 32.0f;

				if (g_hero_change == true)
					c[3] = 0.5f;

				Draw::Draw(1, &src, &dst, c, 0.0f);

				c[3] = 1.0f;
			}
				
				
				//�Z�u���b�N(��)
			else if (m_map[i][j] == 5)
			{
				//�؂���ʒu
				src.m_top = 0.0f;
				src.m_left = 64.0f;
				src.m_right = 96.0f;
				src.m_bottom = 32.0f;

				if (g_hero_change == false)
					c[3] = 0.5f;

				Draw::Draw(1, &src, &dst, c, 0.0f);

				c[3] = 1.0f;
			}

				//���u���b�N
				if (m_map[i][j] == 1|| m_map[i][j] == 26||m_map[i][j]==30)
				{
					//�؂���ʒu
					src.m_top = 0.0f;
					src.m_left = 0.0f;
					src.m_right = 32.0f;
					src.m_bottom = 32.0f;

					Draw::Draw(1, &src, &dst, c, 0.0f);
				}

				//�؃u���b�N
				else if (m_map[i][j] == 2 || m_map[i][j] == 31)
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
				else if (m_map[i][j] == 8)
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
				//�S�[��
				else if (m_map[i][j] == 11)
				{
					//�؂���ʒu�̐ݒ�
					src.m_top = 32.0f;
					src.m_left = 0.0f;
					src.m_right = 64.0f;
					src.m_bottom = 96.0f;

					Draw::Draw(1, &src, &dst, c, 0.0f);
				}
				//�J�M(�Z)
				else if (m_map[i][j] == 18)
				{
					//�؂���ʒu�̐ݒ�
					src.m_top = 32.0f;
					src.m_left = 128.0f;
					src.m_right = 160.0f;
					src.m_bottom = 63.0f;

					if (g_hero_change == false)
						c[3] = 0.5f;

					Draw::Draw(1, &src, &dst, c, 0.0f);

					c[3] = 1.0f;
				}
				//�J�M(��)
				else if (m_map[i][j] == 23)
				{
					//�؂���ʒu�̐ݒ�
					src.m_top = 32.0f;
					src.m_left = 161.0f;
					src.m_right = 192.0f;
					src.m_bottom = 63.0f;

					if (g_hero_change == true)
						c[3] = 0.5f;

					Draw::Draw(1, &src, &dst, c, 0.0f);

					c[3] = 1.0f;
				}
				//����
				else if (m_map[i][j] == 19)
				{
					//�؂���ʒu�̐ݒ�
					src.m_top = 32.0f;
					src.m_left = 64.0f;
					src.m_right = 95.0f;
					src.m_bottom = 63.0f;

					if (g_hero_change == true)
						c[3] = 0.5f;

					Draw::Draw(1, &src, &dst, c, 0.0f);

					c[3] = 1.0f;
				}
				//��낢
				else if (m_map[i][j] == 20)
				{
					//�؂���ʒu�̐ݒ�
					src.m_top = 32.0f;
					src.m_left = 96.0f;
					src.m_right = 127.0f;
					src.m_bottom = 63.0f;

					if (g_hero_change == false)
						c[3] = 0.5f;

					Draw::Draw(1, &src, &dst, c, 0.0f);

					c[3] = 1.0f;
				}
				//�X�C�b�`��
				else if (m_map[i][j] == 29)
				{
					//�؂���ʒu�̐ݒ�
					src.m_top = 64.0f;
					src.m_left = 128.0f;
					src.m_right = 160.0f;
					src.m_bottom = 96.0f;

					Draw::Draw(1, &src, &dst, c, 0.0f);
				}
				//�X�C�b�`����(�Z)
				else if (g_hero_change == true && m_map[i][j] == 27)
				{
					//�؂���ʒu�̐ݒ�
					src.m_top = 64.0f;
					src.m_left = 64.0f;
					src.m_right = 96.0f;
					src.m_bottom = 96.0f;

					Draw::Draw(1, &src, &dst, c, 0.0f);
				}
				//�X�C�b�`����(��)
				else if (g_hero_change == false && m_map[i][j] == 27)
				{
					//�؂���ʒu�̐ݒ�
					src.m_top = 64.0f;
					src.m_left = 96.0f;
					src.m_right = 128.0f;
					src.m_bottom = 96.0f;

					Draw::Draw(1, &src, &dst, c, 0.0f);
				}
			}
		}
	}

	//���擾���A�A�C�e�����ɕ\��

	if (g_hero_change == true && brother_key == true)
	{
		dst.m_top = 16.0f;
		dst.m_left = 16.0f;
		dst.m_right = 48.0f;
		dst.m_bottom = 48.0f;

		//�؂���ʒu�̐ݒ�
		src.m_top = 32.0f;
		src.m_left = 128.0f;
		src.m_right = 160.0f;
		src.m_bottom = 64.0f;
		Draw::Draw(1, &src, &dst, c, 0.0f);
	}
	
	else if (g_hero_change == false && sister_key == true)
	{
		dst.m_top = 16.0f;
		dst.m_left = 16.0f;
		dst.m_right = 48.0f;
		dst.m_bottom = 48.0f;

		//�؂���ʒu�̐ݒ�
		src.m_top = 32.0f;
		src.m_left = 160.0f;
		src.m_right = 192.0f;
		src.m_bottom = 64.0f;
		Draw::Draw(1, &src, &dst, c, 0.0f);
	}

	//��낢�擾���A�A�C�e�����ɕ\��

	if (g_hero_change == true && armor_block == true)
	{
		dst.m_top = 16.0f;
		dst.m_left = 82.0f;
		dst.m_right = 114.0f;
		dst.m_bottom = 48.0f;

		//�؂���ʒu�̐ݒ�
		src.m_top = 32.0f;
		src.m_left = 96.0f;
		src.m_right = 127.0f;
		src.m_bottom = 63.0f;
		Draw::Draw(1, &src, &dst, c, 0.0f);
	}


	//���擾���A�A�C�e�����ɕ\��

	if (g_hero_change == false && shose_block == true)
	{
		dst.m_top = 16.0f;
		dst.m_left = 82.0f;
		dst.m_right = 114.0f;
		dst.m_bottom = 48.0f;

		//�؂���ʒu�̐ݒ�
		src.m_top = 32.0f;
		src.m_left = 64.0f;
		src.m_right = 95.0f;
		src.m_bottom = 63.0f;
		Draw::Draw(1, &src, &dst, c, 0.0f);
	}

}


//��l���p-----------------------------------------------------------------------------------------------------------------------------------------
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
	for (int i = 0; i < MAPSIZE_Y; i++)
	{
		for (int j = 0; j < MAPSIZE_X; j++)
		{
			if (m_map[i][j] >   0 && 
				m_map[i][j] != 15 && 
				m_map[i][j] != 17 && 
				m_map[i][j] != 99 && 
				m_map[i][j] != 28 &&
				m_map[i][j] != 29 )
			{
				//�v�f�ԍ������W�ɕύX
				float bx = j*32.0f;
				float by = i*32.0f;

				//�X�N���[���̉e��
				float scroll = scroll_on ? m_block_scroll : 0;

				//��l���ƃu���b�N�̓��蔻��
				if ((*x + 41.0f + (-m_block_scroll) > bx) && (*x + 19.0 + (-m_block_scroll) < bx + 32.0f) && (*y + 64.0f > by) && (*y < by + 32.0f))
				{
					//�㉺���E����

					//vector�̍쐬
					float rvx[2];
					float rvy[2];

					rvx[0] = (*x + (-m_block_scroll)) + 16 - bx;
					rvy[0] = *y + 32 - by;

					rvx[1] = (*x + (-m_block_scroll) + 16) - bx;
					rvy[1] = *y  - by;
					//float vx = (hx+32+(-m_block_scroll)) - x;
					//float vy = hy + 32 - y;

					for (int k = 0; k < 2; k++)
					{
						//���������߂�
						float len = sqrt(rvx[k] * rvx[k] + rvy[k] * rvy[k]);

						//�p�x�����߂�
						float r = atan2(rvy[k], rvx[k]);
						r = r*180.0f / 3.14f;

						if (r <= 0.0f)
							r = abs(r);
						else
							r = 360.0f - abs(r);

						//len��������̒������Z���ꍇ����ɓ���
						if (len < 38)
						{

							//��l����p�u���b�N����
							//�Z 5=�؃u���b�N 18=�Z�� 20=�Z
							if (g_hero_change == false && m_map[i][j] == 5 || g_hero_change == false && m_map[i][j] == 18 || g_hero_change == false && m_map[i][j] == 20)
								;
							//�� 4=�؃u���b�N 13=���u���b�N 16=�y�u���b�N 23=���� 19=�C
							else if (g_hero_change == true && m_map[i][j] == 4 || g_hero_change == true && m_map[i][j] == 13 || g_hero_change == true && m_map[i][j] == 16 ||
								g_hero_change == true && m_map[i][j] == 23 || g_hero_change == true && m_map[i][j] == 19)
								;
							//���̑�
							else
							{
								//�p�x�ŏ㉺���E�𔻒�
								if ((r <= 45 && r >= 0) || r >= 315)
								{
									//�E
									*right = true;//��l�����������ɏՓ˂��Ă���
									*x = (bx + 13.0f + (m_block_scroll));//�u���b�N�̈ʒu�[��l���̕�
									*vx = -(*vx)*0.1f;//-VX*�����W��
									*bt = m_map[i][j];//�u���b�N�̗v�f(type)����l���ɓn��

								}
								if (r >= 45 && r <= 135)
								{
									if (k == 0)
									{
										//��
										*down = true;//��l���̉��̕������Փ˂��Ă���
										*y = by - 64.0f;//�u���b�N�ʒu�[��l���̕�
										*bt = m_map[i][j];//�u���b�N�̗v�f(type)����l���ɓn��
										*vy = 0.0f;

										if (*bt==26)
										{
											if (g_hero_change == true)
												brother_goal = true;
											else
												sister_goal = true;
										}
										else
										{
											if(g_hero_change == true)
												brother_goal = false;
											else
												sister_goal = false;
										}
									}
								}
								if (r >= 135 && r <= 225)
								{
									//��
									*left = true;//��l�����E�̕����ɏՓ˂��Ă���
									*x = bx - 41.0f + (m_block_scroll);//�u���b�N�̈ʒu�[��l���̕�
									*vx = -(*vx)*0.1f;//-VX*�����W��

									*bt = m_map[i][j];//�u���b�N�̗v�f(type)����l���ɓn��


									if (m_map[i][j] == 11 && g_hero_change == false)
									{
										objh2->SetGoalBlock(11);
									}
									else if (m_map[i][j] == 11 && g_hero_change == true)
									{
										objh->SetGoalBlock(11);
									}
									
								}
								if (r >= 225 && r <= 315)
								{
									//��
									if (k == 1)
									{
										*up = true;//��l���̏�̕������Փ˂��Ă���
										*bt = m_map[i][j];//�u���b�N�̗v�f(type)����l���ɓn��
										//*y=by + 64.0f;//�u���b�N�̈ʒu+��l���̕�

										if (*vy < 0)
										{
											*vy = 0.0f;
										}
									}

								}

								if (g_hero_change == true)
								{
									//�Z�����ɐG�ꂽ��t���O�𗧂Ă�
									if (m_map[i][j] == 18)
									{
										brother_key = true;
										m_map[i][j] = 0;
									}
									//brother_key��true�ŐG�ꂽ�Ƃ��u��v���J��
									if (m_map[i][j] == 21)
									{
										if (brother_key == true)
										{
											brother_gateopen = true;
											brother_key = false;

											m_map[i][j] = 99;
										}
									}
									//brother_key��true�ŐG�ꂽ�Ƃ��u��2�v���J��
									if (m_map[i][j] == 32)
									{
										if (brother_key == true)
										{
											brother_gateopen2 = true;
											brother_key = false;
											if (brother_gateopen2 == true && sister_gateopen2 == true)
											{
												m_map[i][j] = 99;
											}
										}
									}
								}
								else
								{
									//�������ɐG�ꂽ��t���O�𗧂Ă�
									if (m_map[i][j] == 23)
									{
										sister_key = true;
										m_map[i][j] = 0;
									}
									//sister_key��true�ŐG�ꂽ�Ƃ�����J��
									if (m_map[i][j] == 21)
									{
										if (sister_key == true)
										{
											sister_gateopen = true;
											sister_key = false;

											m_map[i][j] = 99;
										}
									}
									//sister_key��true�ŐG�ꂽ�Ƃ���2���J��
									if (m_map[i][j] == 32)
									{
										if (sister_key == true)
										{
											sister_gateopen2 = true;
											sister_key = false;
											if (brother_gateopen2 == true && sister_gateopen2 == true)
											{
												m_map[i][j] = 99;
											}
										}
									}
								}

								if (g_hero_change == true)
								{
									//�Z����낢�ɐG�ꂽ��t���O�𗧂Ă�
									if (m_map[i][j] == 20)
									{
										armor_block = true;
										m_map[i][j] = 0;
									}
								}
								else
								{
									//�������ɐG�ꂽ��t���O�𗧂Ă�
									if (m_map[i][j] == 19)
									{
										shose_block = true;
										m_map[i][j] = 0;
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

//�I�I�J�~�p-----------------------------------------------------------------------------------------------------------------------------------------
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
void CObjBlock::BlockEnemyHit
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
	for (int i = 0; i < MAPSIZE_Y; i++)
	{
		for (int j = 0; j < MAPSIZE_X; j++)
		{
			if (m_map[i][j] > 0 &&
				m_map[i][j] != 15 &&
				m_map[i][j] != 17 &&
				m_map[i][j] != 99 &&
				m_map[i][j] != 28 &&
				m_map[i][j] != 29)
			{
				//�v�f�ԍ������W�ɕύX
				float bx = j*32.0f;
				float by = i*32.0f;

				//�X�N���[���̉e��
				float scroll = scroll_on ? m_block_scroll : 0;

				//��l���ƃu���b�N�̓��蔻��
				if ((*x+58.0+ (-m_block_scroll) > bx) && (*x+4.0f + (-m_block_scroll) < bx + 32.0f) && (*y + 64.0f > by) && (*y < by + 32.0f))
				{
					//�㉺���E����

					//vector�̍쐬
					float rvx[2];
					float rvy[2];

					rvx[0] = (*x + (-m_block_scroll))+16 - bx;
					rvy[0] = *y + 32 - by;

					rvx[1] = (*x + (-m_block_scroll)+16) - bx;
					rvy[1] = *y - by;
					//float vx = (hx+32+(-m_block_scroll)) - x;
					//float vy = hy + 32 - y;

					for (int k = 0; k < 2; k++)
					{
						//���������߂�
						float len = sqrt(rvx[k] * rvx[k] + rvy[k] * rvy[k]);

						//�p�x�����߂�
						float r = atan2(rvy[k], rvx[k]);
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
								*x = (bx + 58.0f + (m_block_scroll));//�u���b�N�̈ʒu�[��l���̕�
								*vx = -(*vx)*0.1f;//-VX*�����W��
								*bt = m_map[i][j];//�u���b�N�̗v�f(type)����l���ɓn��

							}
							if (r >= 45 && r <= 135)
							{
								if (k == 0)
								{
									//��
									*down = true;//��l���̉��̕������Փ˂��Ă���
									*y = by - 64.0f;//�u���b�N�ʒu�[��l���̕�
									*bt = m_map[i][j];//�u���b�N�̗v�f(type)����l���ɓn��
									*vy = 0.0f;
								}
							}
							if (r >= 135 && r <= 225)
							{
								//��
								*left = true;//��l�����E�̕����ɏՓ˂��Ă���
								*x = bx - 64.0f + (m_block_scroll);//�u���b�N�̈ʒu�[��l���̕�
								*vx = -(*vx)*0.1f;//-VX*�����W��
								*bt = m_map[i][j];//�u���b�N�̗v�f(type)����l���ɓn��

							}
							if (r >= 225 && r <= 315)
							{
								//��
								if (k == 1)
								{
									*up = true;//��l���̏�̕������Փ˂��Ă���
									*bt = m_map[i][j];//�u���b�N�̗v�f(type)����l���ɓn��
									//*y=by + 64.0f;//�u���b�N�̈ʒu+��l���̕�

									if (*vy < 0)
									{
										*vy = 0.0f;
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