#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

#define MAPSIZE_X 300
#define MAPSIZE_Y 19

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

	float GetScroll() { return m_block_scroll; }
	int GetMap(int x, int y) { return m_map[y][x]; }

private:
	int m_map[MAPSIZE_Y][MAPSIZE_X]; //�}�b�v���

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

	float GetScroll() { return m_block_scroll; }
	int GetMap(int x, int y) { return m_map[y][x]; }

private:
	int m_map[MAPSIZE_Y][MAPSIZE_X]; //�}�b�v���

	float m_block_scroll;  //�X�N���[���p
	
};