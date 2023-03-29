#pragma once
#include"SpriteAnimation.h"
#include "Sprite2D.h"

#define g 10
class Character : public SpriteAnimation {
public:
	Character();
	Character(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture, GLint numFrames, GLint numActions, GLint currentAction, GLfloat frameTime) :
		SpriteAnimation(model, shader, texture, numFrames, numActions, currentAction, frameTime),m_isCollsion(false),vy(0),vx(0) {};

	~Character();
	void SetVx(float _vx);
	float GetVx();
	void SetVy(float _vy);
	float GetVy();
	void CheckCollision(std::shared_ptr<Sprite2D> stage);
	void Update(float deltaTime);
private:
	float vx;
	float vy;
	bool m_isCollsion;
};