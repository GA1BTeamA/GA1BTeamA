#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g:�u���b�N
class CObjBlock :public CObj
{
public:
	CObjBlock();
	~CObjBlock() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[
	

private:
	int m_map[18][400]; //�}�b�v���

	float m_block_scroll;  //�X�N���[���p
};