#pragma once

#include"Sprite2D.h"
#include"Character.h"
#include"SpriteAnimation.h"
class GameField {
	enum class Phase {
		Idle,
		Attack,
		Die
	};
public:
	GameField();
	~GameField();
	void Init();
	void Update(float deltaTime);
	void Draw();
	void SetPhase(Phase phase);
private:
	std::shared_ptr<Character> m_character;
	Phase m_phase;
	std::list<std::shared_ptr<Sprite2D>> m_listStage;
	
};