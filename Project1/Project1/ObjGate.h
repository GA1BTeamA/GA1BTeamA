#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//-----------------------------------------------------

//�I�u�W�F�N�g:��u���b�N
class CObjGateBlock :public CObj
{
public:
	CObjGateBlock();
	~CObjGateBlock() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[

private:

	float m_block_scroll;  //�X�N���[���p

};

//-----------------------------------------------------

//�I�u�W�F�N�g:�J�� ��
class CObjGateOpenLeft :public CObj
{
public:
	CObjGateOpenLeft();
	~CObjGateOpenLeft() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[

private:
	
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