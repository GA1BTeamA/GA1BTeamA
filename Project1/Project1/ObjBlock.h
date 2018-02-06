#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

#define MAPSIZE_X 289
#define MAPSIZE_Y 19

//�I�u�W�F�N�g:�u���b�N
class CObjBlock :public CObj
{
public:
	CObjBlock();
	~CObjBlock() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[

	float GetScroll() { return m_block_scroll; }
	float GetgbScroll() { return gb_block_scroll; }
	float GetgsScroll() { return gs_block_scroll; }
	int GetMap(int x, int y) { return m_map[y][x]; }



	//�u���b�N�Ƃ̓����蔻��
	void BlockHit
	(
		float *x, float *y, bool scroll_on,
		bool*up, bool* down, bool* left, bool* right,
		float* vx, float*vy, int* bt
	);

private:
	int m_map[MAPSIZE_Y][MAPSIZE_X]; //�}�b�v���

	//�`��J���[���
	float c[4];

	float m_block_scroll;  //�X�N���[���p

	float gb_block_scroll;  //�Z�̃X�N���[���p

	float gs_block_scroll;  //���̃X�N���[���p

	float scroll_change_b;//��l���X�N���[���ʒu�L��

	float scroll_change_s;//��l���X�N���[���ʒu�L��

	float scroll_change_keep;//��l���X�N���[���ꎞ�ۑ��p

	bool button_flag;//���{�^���t���O

	////��l���ʒu
	//float hx;
	//float hy;
};