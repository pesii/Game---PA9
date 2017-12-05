/*
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
	StateManager();
	~StateManager() {}

	void AddState(State * newState, bool isReplacing = true);
	void RemoveState();
	State * GetActiveState();
	sf::RenderWindow window;
	AssetManager assets;

private:
	std::stack<State*> allStates;


	bool isAdding;
	bool isReplacing;
	bool isRemoving;
};
*/