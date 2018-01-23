#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

#define MAPSIZE_X 19

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
	int GetMap(int x, int y) { return m_map[y][x]; }

	//�u���b�N�Ƃ̓����蔻��
	void BlockHit
	(
		float *x, float *y, bool scroll_on,
		bool*up, bool* down, bool* left, bool* right,
		float* vx, float*vy, int* bt
	);

	

private:
	int m_map[MAPSIZE_X][400]; //�}�b�v���

	//�`��J���[���
	float c[4];

	float m_block_scroll;  //�X�N���[���p

	////��l���ʒu
	//float hx;
	//float hy;

};