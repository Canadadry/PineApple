#include <SceneGraph/Core/rectanglenode.h>
#include <SFML/Graphics/RenderTarget.hpp>

RectangleNode::RectangleNode(SceneNode* parent)
    : SceneNode(parent)
    , color(sf::Color::White)
    , borderWidth(0.0f)
    , borderColor(sf::Color::Black)
    , m_shape(sf::Vector2f(0,0))
{
    width.onValueChanged.Connect(this,&RectangleNode::onGeometryChange);
    height.onValueChanged.Connect(this,&RectangleNode::onGeometryChange);
}



void RectangleNode::onGeometryChange()
{
    m_shape.setSize(sf::Vector2f(width,height));
}

void RectangleNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    m_shape.setFillColor(color*sf::Color(255,255,255,255*opacity.getValue()));
    m_shape.setOutlineThickness(borderWidth);
    m_shape.setOutlineColor(borderColor*sf::Color(255,255,255,255*opacity.getValue()));

    target.draw(m_shape, states);
}
