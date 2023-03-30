#pragma once

#include"Sprite2D.h"
#include"Character.h"
#include"SpriteAnimation.h"
	enum Phase {
		Idle,
		Holding,
		Jumping,
		Die
	};
class GameField {
public:
	GameField();
	~GameField();

	float power;

	void Init();
	void Update(float deltaTime);
	void Draw();
	void SetPhase(Phase phase);
	bool IsIdle();
	std::shared_ptr<Character> m_character;
private:
	Phase m_phase;
	std::list<std::shared_ptr<Sprite2D>> m_listStage;
	
};