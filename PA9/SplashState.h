#pragma once

#include "standard_dependency.h"

class State
{
public:

	virtual void Init() = 0;
	virtual void Draw() = 0;
	virtual void Update() = 0;
	virtual void HandleInput() = 0;
	//void Pause();
	//void Resume();

};
class AssetManager
{
public:
	void loadTexture(std::string name, std::string filepath);
	sf::Texture & getTexture(std::string name);

	void loadFont(std::string name, std::string filepath);
	sf::Font & getFont(std::string name);

private:
	std::map<std::string, sf::Texture> Textures;
	std::map<std::string, sf::Font> Fonts;

};

class StateManager
{
public:
	StateManager() {
		window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Menu", sf::Style::Close | sf::Style::Titlebar);
	};
	~StateManager() {}

	void AddState(State * newState, bool isReplacing = true) {
		this->isAdding = true;

		if (isReplacing && !allStates.empty())
		{
			allStates.pop();
		}

		if (isAdding)
		{
			allStates.push(newState);
		}

		allStates.top()->Init();
		allStates.top()->Update();
	};
	void RemoveState() {
		if (!allStates.empty())
		{
			//State * delState = allStates.top();
			allStates.pop();
			//delete delState;
		}

		if (!allStates.empty())
		{
			allStates.top()->Update();
		}
	};
	State * GetActiveState() {
		return allStates.top();
	};

	sf::RenderWindow window;
	AssetManager assets;

private:
	std::stack<State*> allStates;


	bool isAdding;
	bool isReplacing;
	bool isRemoving;
};

class MenuState : public State
{
public:
	MenuState(StateManager * gameStateManager) {
		this->gameStates = gameStateManager;
	};
	~MenuState() {}

	void Init() {};
	void Update();
	void HandleInput();
	void Draw();

private:
	int menu_selection;
	StateManager * gameStates;
	sf::Sprite mBackground;
	sf::Font mFont;
	//sf::Music mMusic;

	sf::Text option1, option2, option3;
	sf::RectangleShape select_box;
	int select_pos;
	int select_positions[3];

};

class SplashState : public State
{
public:
	SplashState(StateManager * gameStates);
	~SplashState() {}

	void Init();
	void Update();
	void HandleInput();
	void Draw();

private:

	StateManager * gameStates;
	sf::Sprite mBackground;
	sf::Font mFont;

	sf::Text SplashText1, SplashText2, SplashText3, SplashText4;

};