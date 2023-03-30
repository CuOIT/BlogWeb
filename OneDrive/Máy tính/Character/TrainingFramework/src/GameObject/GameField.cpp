#include"GameField.h"
#include"Character.h"
#include"Sprite2D.h"
#include"ResourceManagers.h"
#include "Stage.h"

GameField::GameField() {
	Init();
};


GameField::~GameField() {

};

void GameField::Init() {
	power = 0;
	SetPhase(Phase::Jumping);
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("Actor1_2.tga");
	auto shader = ResourceManagers::GetInstance()->GetShader("Animation");

	m_character = std::make_shared<Character>(model, shader, texture, 9, 6, 3, 0.1f);
	m_character->Set2DPosition(240.0f, 200.0f);
	m_character->SetSize(30, 40);

	shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	texture = ResourceManagers::GetInstance()->GetTexture("stage.tga");
	std::shared_ptr<Sprite2D> stage = std::make_shared<Sprite2D>(model, shader, texture);
	stage->Set2DPosition(240.0f, 400.0f);
	stage->SetSize(300, 40);
	m_listStage.push_back(stage);

	for (int i = 0; i < 5; i++) {

	stage = std::make_shared<Sprite2D>(model, shader, texture);
	stage->Set2DPosition(400+120*i, 400.0f);
	stage->SetSize(100, 50);
	m_listStage.push_back(stage);
	}
}
void GameField::SetPhase(Phase phase) {
	m_phase = phase;
}
void GameField::Update(float deltaTime) {

	m_character->Update(deltaTime);
	std::cout << m_character->Get2DPosition().y;
	for (auto a : m_listStage) {
		a->Update(deltaTime);
	}
	switch (m_phase) {
	case Phase::Idle:{
		std::cout << "Idle" << std::endl;

		m_character->SetVx(20+power/4);
		m_character->SetVy(-power);
		break;
		}
	case Phase::Jumping: {
		std::cout << "Jumping" << std::endl;
		m_character->Move(deltaTime);

		for(auto a:m_listStage)
		m_character->CheckCollision(a);
		if (m_character->GetCollision() && m_character->GetVy()>0) {
			m_character->SetVx(0);
			m_character->SetVy(0);
			SetPhase(Phase::Idle);
		}
		break;
		}
	}
}

bool GameField::IsIdle() {
	if (m_phase == Phase::Idle) {
		return true;
	}
	else return false;
}
void GameField::Draw() {
	m_character->Draw();
	for (auto a : m_listStage) {
		a->Draw();
	}
}
