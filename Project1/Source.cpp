#include "ExtraIncludes.h"
#include "HUD.h"
#include "BoundedBuffer.h"

using namespace std;

BoundedBuffer boundedBuffer = BoundedBuffer();


void* Producer()
{
	int i = 1;
	while (true)
	{
		boundedBuffer.Produce(i);
		i++;
	}
}

void* Consumer()
{
	while (true)
	{
		boundedBuffer.Consume();
	}
}

int main()
{
	// Create the main window 
	sf::RenderWindow window(sf::VideoMode(1280, 720, 32), "Monitors");
	sf::Time frameTime;
	sf::Clock frameClock;
	//load a font
	sf::Font font;
	font.loadFromFile("C:\\Windows\\Fonts\\GARA.TTF");
	HUD hud = HUD();

	sf::Thread producerThread(&Producer);
	sf::Thread consumerThread(&Consumer);

	//producerThread.launch();
	//consumerThread.launch();
	

	//Chest chest = Chest(sf::Vector2f(300, 300), 3);
	while (window.isOpen())
	{
		// Start game loop 
		sf::Event Event;
		while (window.pollEvent(Event))
		{
			//Make a new thing
			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Q))
			{		
				boundedBuffer.AddNewItem();
			}

			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::W))
			{
				boundedBuffer.RemoveItem();
			}

			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::A))
			{
				producerThread.launch();
			}

			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::S))
			{
				consumerThread.launch();
			}
		}

		//prepare frame
		window.clear();

		hud.Draw(window);

		// Finally, display rendered frame on screen 
		window.display();
	}
}