#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//-----------------------------------------------------

//�I�u�W�F�N�g:��u���b�N
class CObjGate :public CObj
{
public:
	CObjGate();
	~CObjGate() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[

	//�u���b�N�Ƃ̓����蔻��
	/*void BlockHit
	(
		float *x, float *y, bool scroll_on,
		bool*up, bool* down, bool* left, bool* right,
		float* vx, float*vy, int* bt
	);*/

private:
	//int m_map[MAPSIZE_X][400]; //�}�b�v���

	int gb_map_x; //��u���b�N�̃}�b�v���
	float gb_x;   //��u���b�N�̈ʒu���

	float m_block_scroll;  //�X�N���[���p

};

//-----------------------------------------------------

//�I�u�W�F�N�g:�J�� �E
class CObjGateOpenRight :public CObj
{
public:
	CObjGateOpenRight();
	~CObjGateOpenRight() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[

private:
	
};