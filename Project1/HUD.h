#include "ExtraIncludes.h"

class HUD
{
public:
	HUD();
	~HUD();
	void Draw(sf::RenderWindow& window);
	bool Load();
private:
	sf::Texture m_HudOrangeTexture;
	sf::RectangleShape m_HudOrangeRect;

	sf::Texture m_orangeEle1Texture, m_orangeEle2Texture, m_orangeEle3Texture;
	sf::RectangleShape m_orangeEle1Rect, m_orangeEle2Rect, m_orangeEle3Rect;
};

