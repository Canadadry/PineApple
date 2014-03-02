#include <SceneGraph/rectanglenode.h>
#include <SFML/Graphics/RenderTarget.hpp>

RectangleNode::RectangleNode(SceneNode* parent)
    : SceneNode(parent)
    , m_shape(sf::Vector2f(100,100))
{
    m_shape.setFillColor(sf::Color::Red);
    m_shape.setOutlineThickness(5.0);
    m_shape.setOutlineColor(sf::Color::Yellow);
}


void RectangleNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_shape, states);
}
