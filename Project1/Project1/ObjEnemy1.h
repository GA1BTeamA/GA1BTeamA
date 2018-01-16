#pragma once
class CObjEnemy1 : public CObj
{
public:
	CObjEnemy1(float x,float y);
	~CObjEnemy1() {};
	void Init();
	void Action();
	void Draw();

private:
	float m_px;    //�ʒu
	float m_py;
	float m_vx;    //�ړ��x�N�g��
	float m_vy;
	float m_posture; //����

	int m_ani_timex;  //�A�j���[�V�����t���[������Ԋux���p
	int m_ani_timey;
	int m_ani_framex; //�`��t���[��x���p
	int m_ani_framey;

	float m_speed_power; //�X�s�[�h�p���[
	float m_ani_max_time;//�A�j���[�V��������Ԋu�ő�l

	 //�ړ��̌�������p
	bool m_move;

};

