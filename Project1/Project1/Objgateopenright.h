#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//#define MAPSIZE_X 19

//�I�u�W�F�N�g:�u���b�N
class CObjgateopenright :public CObj
{
public:
	CObjgateopenright();
	~CObjgateopenright() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[


private:
	//int m_map[MAPSIZE_X][400]; //�}�b�v���
};