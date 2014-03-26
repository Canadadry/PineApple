#include "spritenode.h"
#include <SFML/Graphics/RenderTarget.hpp>

SpriteNode::SpriteNode(const sf::Texture &texture)
: m_array(sf::TrianglesFan,4)
, m_texture(texture)
{
    sf::Vector2u textureSize = m_texture.getSize();
    m_array[0].texCoords = sf::Vector2f(0             , 0);
    m_array[1].texCoords = sf::Vector2f(textureSize.x , 0);
    m_array[2].texCoords = sf::Vector2f(textureSize.x , textureSize.y);
    m_array[3].texCoords = sf::Vector2f(0             , textureSize.y);

    width  = textureSize.x;
    height = textureSize.y;
}


void SpriteNode::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
{
    sf::Color alpha(255,255,255,255*m_trueOpacity.getValue());
    m_array[0].color = alpha;
    m_array[1].color = alpha;
    m_array[2].color = alpha;
    m_array[3].color = alpha;

    m_array[0].position = sf::Vector2f(0     , 0);
    m_array[1].position = sf::Vector2f(width , 0);
    m_array[2].position = sf::Vector2f(width , height);
    m_array[3].position = sf::Vector2f(0     , height);

    states.texture = &m_texture;
    target.draw(m_array, states);
}
