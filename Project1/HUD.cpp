#include "HUD.h"

HUD::HUD()
{
	if (Load())
	{
		m_HudOrangeRect.setSize(sf::Vector2f(200, 200));
		m_HudOrangeRect.setTexture(&m_HudOrangeTexture);
		m_HudOrangeRect.setPosition(sf::Vector2f(0, 200));

		m_orangeEle1Rect.setSize(sf::Vector2f(50, 50));
		m_orangeEle1Rect.setTexture(&m_orangeEle1Texture);
		m_orangeEle1Rect.setPosition(sf::Vector2f(20, 210));

		m_orangeEle2Rect.setSize(sf::Vector2f(50, 50));
		m_orangeEle2Rect.setTexture(&m_orangeEle2Texture);
		m_orangeEle2Rect.setPosition(sf::Vector2f(20, 270));

		m_orangeEle3Rect.setSize(sf::Vector2f(50, 50));
		m_orangeEle3Rect.setTexture(&m_orangeEle3Texture);
		m_orangeEle3Rect.setPosition(sf::Vector2f(20, 330));
	}
}

HUD::~HUD()
{
}


bool HUD::Load()
{
	if (!m_HudOrangeTexture.loadFromFile("Assets/orange.png"))
		return false;

	if (!m_orangeEle1Texture.loadFromFile("Assets/orangeEle1.png"))
		return false;

	if (!m_orangeEle2Texture.loadFromFile("Assets/orangeEle2.png"))
		return false;

	if (!m_orangeEle3Texture.loadFromFile("Assets/orangeEle3.png"))
		return false;

	return true;
}

void HUD::Draw(sf::RenderWindow& window)
{
	window.draw(m_HudOrangeRect);

	window.draw(m_orangeEle1Rect);
	window.draw(m_orangeEle2Rect);
	window.draw(m_orangeEle3Rect);
}