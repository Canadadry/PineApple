#include <SceneGraph/Core/geometry.h>

float cornerPositionX[9] = {0.0f, 0.5f, 1.0f , 0.0f, 0.5f, 1.0f , 0.0f, 0.5f, 1.0f };
float cornerPositionY[9] = {0.0f, 0.0f, 0.0f , 0.5f, 0.5f, 0.5f , 1.0f, 1.0f, 1.0f };

Geometry::Geometry()
: x        (0.0f)
, y        (0.0f)
, width    (0.0f)
, height   (0.0f)
, scale    (1.0)
, rotation (0.0f)
, origin   (Geometry::Middle)
{}

Geometry::~Geometry(){}

sf::FloatRect Geometry::getBoundingBox() const
{
    return sf::FloatRect();
}

sf::Transform Geometry::getTransform() const
{
    updateTransform();
    return m_tranformFacade.getTransform();
}

void Geometry::updateTransform() const
{
    m_tranformFacade.setOrigin(cornerPositionX[origin]*width,cornerPositionY[origin]*height);
    m_tranformFacade.setPosition(x,y);
    m_tranformFacade.setScale(scale,scale);
    m_tranformFacade.setRotation(rotation);
}

