#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

#define MAPSIZE_X 289
#define MAPSIZE_Y 19

//�I�u�W�F�N�g:�S�[��
class CObjkey :public CObj
{
public:
	CObjkey();
	~CObjkey() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[


private:
	int m_map[MAPSIZE_Y][MAPSIZE_X]; //�}�b�v���
};