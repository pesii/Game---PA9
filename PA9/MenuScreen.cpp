#include "MenuScreen.h"

void MenuState::Update()
{

	do
	{
		Draw();

		HandleInput();

	} while (menu_selection == 0);

}

void MenuState::HandleInput()
{
	int select_positions[] = { 2, 3, 6 };

	while (gameStates->window.isOpen())
	{
		sf::Event event;
		while (gameStates->window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				gameStates->window.close();

			if (event.type == sf::Event::KeyPressed)
			{
				cout << "button pressed" << endl;

				// If Up is pushed and not at top of menu, Move selector box up one
				if (select_pos < 2 && event.key.code == sf::Keyboard::Up)
				{
					select_box.setPosition(select_box.getPosition().x, SCREEN_HEIGHT / select_positions[++select_pos]);
					Draw();
				}
				// If Down is pushed and not at Bottom of menu, Move selector box down one
				else if (select_pos > 0 && event.key.code == sf::Keyboard::Down)
				{
					select_box.setPosition(select_box.getPosition().x, SCREEN_HEIGHT / select_positions[--select_pos]);
					Draw();
				}
				else if (event.key.code == sf::Keyboard::Return)
				{
					menu_selection = select_pos + 1;

					if (menu_selection == 3)
					{
						// enter game
						menu_selection = 0;
					}
					else if (menu_selection == 2)
					{
						// display instructions
						gameStates->AddState(new InstructionsState(gameStates), false);
					}
					else if (menu_selection == 1)
					{
						// display credits
						gameStates->AddState(new CreditsState(gameStates), false);
					}
					else
					{
						menu_selection = 0;
					}
				}

			}
		}
	}

	cin >> menu_selection;
}

void MenuState::Draw()
{

	cout << "In the menu" << endl;
	cout << "1. Start" << endl;
	cout << "2. Credits" << endl;


	// Update Window
	gameStates->window.clear(sf::Color::Black);

	gameStates->window.draw(mBackground);
	gameStates->window.draw(option1);
	gameStates->window.draw(option2);
	gameStates->window.draw(option3);
	gameStates->window.draw(select_box);

	gameStates->window.display();
}
