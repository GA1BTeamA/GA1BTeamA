//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\DrawTexture.h"
#include "GameL\Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneMain.h"
#include "GameHead.h"
#include "SceneGameOver.h"

//�R���X�g���N�^
CSceneGameOver::CSceneGameOver()
{

}

//�f�X�g���N�^
CSceneGameOver::~CSceneGameOver()
{

}

//�Q�[�����C�����������\�b�h
void CSceneGameOver::InitScene()
{
	//�o�͂����镶���̃O���t�B�b�N���쐬
	Font::SetStrTex(L"GameOver");

	//�^�C�g���I�u�W�F�N�g�쐬
	CObjGameOver* obj = new CObjGameOver(); //�^�C�g���I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_GAME_OVER, 1); //��l���I�u�W�F�N�g�o�^


}

//�Q�[�����C�����s�����\�b�h
void CSceneGameOver::Scene()
{

}