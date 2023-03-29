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
}
void GameField::SetPhase(Phase phase) {
	m_phase = phase;
}
void GameField::Update(float deltaTime) {

	m_character->Update(deltaTime);
	for (auto a : m_listStage) {
		m_character->CheckCollision(a);
		a->Update(deltaTime);
	}
}

void GameField::Draw() {
	m_character->Draw();
	for (auto a : m_listStage) {
		a->Draw();
	}
}
