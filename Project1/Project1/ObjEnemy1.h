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
	float m_px;    //位置
	float m_py;
	float m_vx;    //移動ベクトル
	float m_vy;
	float m_posture; //向き

	int m_ani_timex;  //アニメーションフレーム動作間隔x軸用
	int m_ani_timey;
	int m_ani_framex; //描画フレームx軸用
	int m_ani_framey;

	float m_speed_power; //スピードパワー
	float m_ani_max_time;//アニメーション動作間隔最大値

	 //移動の向き制御用
	bool m_move;

};

