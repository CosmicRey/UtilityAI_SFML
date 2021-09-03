
#include "UtilityAI/BlackBoard.hpp"
#include "UtilityAI/GameLoop.hpp"
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

class UtilityTestScenerio : public uai::IGameLoop
{
public:
	// Inherited via IGameLoop
	virtual void Startup() override
	{
	}
	virtual bool Tick() override
	{
		return true;
	}
	virtual void Shutdown() override
	{
	}
};

int main(int argc, char** argv)
{
	RegisterBlackboardVariable(VariableName);
	sf::RenderWindow window(sf::VideoMode(), "SFML works!");

	std::unique_ptr<uai::IGameLoop> gameLoop = std::make_unique<UtilityTestScenerio>();

	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	gameLoop->Startup();

	while (window.isOpen() && gameLoop->Tick()) 
	{
		window.clear();
		window.draw(shape);
		window.display();
	};

	gameLoop->Shutdown();

	std::cout << VariableName.GetString() << "\n";
}