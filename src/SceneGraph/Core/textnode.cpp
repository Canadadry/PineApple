#include <SceneGraph/Core/textnode.h>
#include <SFML/Graphics/RenderTarget.hpp>
#include <iostream>

TextNode::TextNode()
    : text("")
    , color(sf::Color::White)
    , fontName("/Library/Fonts/Arial.ttf")
    , fontlSize(16)
    , alignement(Geometry::Middle)
{
    fontName.onValueChanged.Connect(this,&TextNode::updateFont);
    updateFont();
}


void TextNode::updateFont()
{
    m_font.loadFromFile(fontName);
    m_text.setFont(m_font);
}

void TextNode:: updateCurrent(sf::Time dt)
{
    width = m_text.getLocalBounds().width;
    height = m_text.getLocalBounds().height;
    m_text.setPosition(sf::Vector2f(0.0f,-m_text.getLocalBounds().top));
}

void TextNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{

    m_text.setString(sf::String(text));
    m_text.setColor(color);
    m_text.setCharacterSize(fontlSize);
    target.draw(m_text, states);
}
