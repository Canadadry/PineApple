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
    , horzontalCenter(m_horzontalCenter)
    , verticalCenter(m_verticalCenter)
    , m_horzontalCenter(0.0)
    , m_verticalCenter(0.0)
{
    width.onValueChanged.Connect(this,&Geometry::updateInterals);
    height.onValueChanged.Connect(this,&Geometry::updateInterals);
}

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

void Geometry::updateInterals()
{
    m_horzontalCenter = width/2;
    m_verticalCenter = height/2;
}

void Geometry::updateTransform() const
{
    m_tranformFacade.setOrigin(cornerPositionX[origin]*width,cornerPositionY[origin]*height);
    m_tranformFacade.setPosition(x,y);
    m_tranformFacade.setScale(scale,scale);
    m_tranformFacade.setRotation(rotation);
}

