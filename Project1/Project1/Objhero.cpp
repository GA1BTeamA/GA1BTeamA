//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "Objhero.h"
#include "ObjBlock.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�u���b�N����l���؂�ւ� false=���p true=�Z�p
extern  bool g_hero_change;

extern float g_px;

//�Z���̉�ʐ؂�ւ��t���O
extern bool screen_change_flag;

extern bool armor_block;
bool damage_flag;
bool enemy_flag;

//��l�����S�[���O�ɂ��邩�ǂ���
extern bool brother_goal;
extern bool sister_goal;

//�C�j�V�����C�Y
void CObjhero::Init()
{
	m_px = 300.0f;    //�ʒu
	m_py = 512.0f;
	m_vx = 0.0f;    //�ړ��x�N�g��
	m_vy = 0.0f;
	m_posture = 1.0f; //�E����0.0���@������1.0��

	m_ani_timex = 0;    //�A�j���[�V�����t���[������Ԋux��
	m_ani_timey = 0;    //�A�j���[�V�����t���[������Ԋuy��
	m_ani_timea = 0;    //�A�j���[�V�����t���[������Ԋu�A�N�V����
	m_ani_framex = 1; //�`��t���[��x��
	m_ani_framey = 1; //�`��t���[������
	m_ani_framea = 1; //�`��t���[���A�N�V����

	//�u���b�N�Ƃ̏Փˏ�Ԋm�F�p
	m_hit_up=false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	d = 0;
	t = 0;

	damage_flag = false;
	enemy_flag = false;

	//�W�����v�{�^���t���O
	button_flag_up = false;

	//�`�F���W�{�^���t���O
	button_flag_z = false;

	//�`��؂�ւ�
	Draw_flag=true;

	//�̗�
	HP = 1;

	m_block_type = 15;

	//�S�[���u���b�N
	goal_block = 0;

	brother_goal = false;

	muteki = 0;
	muteki_e = 0;
	muteki_t = 0;

	Hits::SetHitBox(this, m_px, m_py, 32, 64, ELEMENT_PLAYER, OBJ_HERO, 1);

}

//�A�N�V����
void  CObjhero::Action()
{

	if (g_hero_change == true)
	{

		//�u���b�N�Ƃ̓����蔻����s
		CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
		pb->BlockHit(&m_px, &m_py, true,
			&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
			&m_block_type
		);

		//�u���b�N���������Ă���
		CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

		//HitBox�̈ʒu�̕ύX
		CHitBox* hit = Hits::GetHitBox(this);

		//�G�Ɠ������Ă��邩�m�F
		/*if (hit->CheckObjNameHit(OBJ_ENEMY1) != nullptr&& muteki == 0)
		{
			//��l�����G�Ƃǂ̊p�x�œ������Ă��邩�m�F
			HIT_DATA** hit_data;							//�����������ׂ̍��ȏ������邽�߂̍\����
			hit_data = hit->SearchObjNameHit(OBJ_ENEMY1);	//hit_data�Ɏ�l���Ɠ������Ă��鑼�S�Ă�HitBox�Ƃ̏�������

			//�G�̍��E�ɓ���������
			float r = hit_data[0]->r;
			//�E
			if ((r <= 45 && r >= 0) || r >= 315)
			{
				HP -= 1;
				hit->SetStatus(ELEMENT_ENEMY, OBJ_HERO, 1);
				if (enemy_flag == false)
				{
					enemy_flag = true;
					muteki = 1;
				}				
			}
			//��
			if (r >= 45 && r <= 135)
			{
				HP -= 1;
				hit->SetStatus(ELEMENT_ENEMY, OBJ_HERO, 1);
				if (enemy_flag == false)
				{
					enemy_flag = true;
					muteki = 1;
				}
			}
			//��
			if (r >= 135 && r <= 225)
			{
				HP -= 1;
				hit->SetStatus(ELEMENT_ENEMY, OBJ_HERO, 1);
				if (enemy_flag == false)
				{
					enemy_flag = true;
					muteki = 1;
				}
			}
			if (r >= 225 && r <= 315)
			{
				HP -= 1;
				hit->SetStatus(ELEMENT_ENEMY, OBJ_HERO, 1);
				if (enemy_flag == false)
				{
					enemy_flag = true;
					muteki = 1;
				}
			}
			if (armor_block == true)
			{
				armor_block = false;
			}
			
		}*/

		//��l���؂�ւ�
		if (Input::GetVKey('Z') == true)
		{
			if (button_flag_z == true && m_hit_down == true)
			{

				g_hero_change = false;

				//�u���b�N���������Ă���
				CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

				g_px = block->GetgbScroll();

				screen_change_flag = true;

				button_flag_z = false;
			}
		}

		else
		{
			button_flag_z = true;
		}

		//�L�[�����̓��͕���
		//x���ړ��p
		if (Input::GetVKey(VK_RIGHT) == true)
		{
			m_vx += 0.4f;
			m_posture = 1.0f;
			m_ani_timex += 2;

		}
		else if (Input::GetVKey(VK_LEFT) == true)
		{
			m_vx -= 0.4f;
			m_posture = 0.0f;
			m_ani_timex += 2;
		}
		else
		{
			m_ani_framex = 1;  //�L�[���͂������ꍇ�͐Î~�t���[���ɂ���
			m_ani_timex = 0;
		}

		if (m_ani_timex > 8)
		{
			m_ani_framex += 1;
			m_ani_timex = 0;
		}

		if (m_ani_framex == 8)
		{
			m_ani_framex = 0;
		}

		//y���ړ��p
		if (Input::GetVKey(VK_UP) == true)
		{
			if (button_flag_up == true && m_hit_down == true)
			{
				m_vy -= 12.0f;
				button_flag_up = false;
			}
		}
		else
		{
			button_flag_up = true;
		}

		//�󒆂ɂ��邩�̊m�F
		if (m_hit_down == false)
		{
			Draw_flag = false;

			m_ani_timey += 1;

			if (m_ani_timey > 8)
			{
				m_ani_framey += 1;
				m_ani_timey = 0;
			}
			if (m_ani_framey == 8)
			{
				m_ani_framey = 0;
			}
		}
		else
		{
			Draw_flag = true;
			m_ani_timey = 0;
			m_ani_framey = 0;
		}

		//���C
		m_vx += -(m_vx*0.098);

		//���R����
		m_vy += 9 / (16.0f);

		//�ʒu�̍X�V
		m_px += m_vx;
		m_py += m_vy;

		if (m_py > 850 || HP == 0)
		{
			g_px = 0.0f;
			brother_goal = false;
			goal_block = 0;
			HP = 0;
			Scene::SetScene(new CSceneGameOver());
		}

		if (armor_block == true && HP<2)
		{
			HP = 2;
		}

		if (GetBT() == 3 || GetBT() == 12 || GetBT() == 6)
		{
			
			if (HP>0&&d == 0 && damage_flag == false && muteki == 0)
			{
				muteki = 1;
				HP -= 1;
				damage_flag = true;
			}
		}


		if (goal_block == 11)
		{
			goal_block = 0;
			if (brother_goal == true && sister_goal == true)
			{
				g_px = 0.0f;
				brother_goal = false;
				Scene::SetScene(new CSceneClear());
			}
		}

		
		//�������݂ƐڐG�������̖��G
		if (enemy_flag == true && muteki == 0)
		{
			t++;
		}
		else
		{
			t = 0;
		}
		if (t > 60 * 1)
		{
			hit->SetStatus(ELEMENT_PLAYER, OBJ_HERO, 1);
			enemy_flag = false;
		}
		//�Ƃ����񂾎��̖��G
		if (damage_flag == true && muteki == 0)
		{
			d++;
		}
		else
		{
			d = 0;
		}
		if (d > 60 * 1)
		{
			damage_flag = false;
		}

		if (g_hero_change == true)
			hit->SetPos(m_px + 16, m_py);

		if (muteki == 1)
		{
			muteki_t++;
			if (muteki_t == 60)
			{
				muteki = 0;
				muteki_t = 0;
			}

			if (muteki_t % 2 == 1)
			{
				muteki_e = 1;
			}

			if (muteki_t % 2 == 0)
			{
				muteki_e = 0;
			}

		}
	}

}

//�h���[
void  CObjhero::Draw()
{

	//�����`��p
	int AniDatax[8] =
	{
		6,-1,0,1,2,3,4,5,
	};

	//�W�����v�p
	int AniDatay[9] =
	{
		1,1,2,2,2,2,2,2,0,
	};

	//���x
	float m;

	if (g_hero_change == true)
		m = 1.0f;
	else
		m = 0.5f;

	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,m};

	RECT_F src;  //�`��؂���ʒu
	RECT_F dst;  //�`���\���ʒu
	if (Draw_flag == true)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 64.0f-64.0f*muteki_e;
		src.m_left = 0.0f + AniDatax[m_ani_framex] * 64- AniDatax[m_ani_framex] * 64*muteki_e;
		src.m_right = 64.0f + AniDatax[m_ani_framex] * 64 - AniDatax[m_ani_framex] * 64 * muteki_e;
		src.m_bottom = 128.0f - 64.0f*muteki_e;
	}
	else
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 128.0f - 128.0f*muteki_e;
		src.m_left = 0.0f + AniDatay[m_ani_framey] * 64 - AniDatax[m_ani_framex] * 64 * muteki_e;
		src.m_right = 64.0f + AniDatay[m_ani_framey] * 64 - AniDatax[m_ani_framex] * 64 * muteki_e;
		src.m_bottom = 192.0f - 128.0f*muteki_e;
	}

	//�u���b�N���������Ă���
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	if (g_hero_change == true)
	{
		//�\���ʒu�̐ݒ�
		dst.m_top = 0.0f + m_py;
		dst.m_left = (64.0f*m_posture) + m_px ;
		dst.m_right = (64 - 64.0f*m_posture) + m_px ;
		dst.m_bottom = 64.0f + m_py;
	}
	else
	{
		//�\���ʒu�̐ݒ�
		dst.m_top = 0.0f + m_py;
		dst.m_left = (64.0f*m_posture) + m_px -g_px+block->GetScroll();
		dst.m_right = (64 - 64.0f*m_posture) + m_px - g_px +block->GetScroll();
		dst.m_bottom = 64.0f + m_py;
	}

	//�`��
	Draw::Draw(3, &src, &dst, c, 1.0f);
}