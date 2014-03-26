#ifndef __GEOMTRY_H_
#define __GEOMTRY_H_

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SceneGraph/System/property.h>

class Geometry :private sf::Transformable
{
public:
    Geometry();
    virtual ~Geometry();

    enum Origin{TopLeft = 0, Top, TopRight,Left, Middle, Right, BottomLeft, Bottom, BottomRigh };

    Property<float> x;
    Property<float> y;
    Property<float> width;
    Property<float> height;
    Property<float> scale;
    Property<float> rotation;
    Property<Origin> origin;

private: // those properties must be define before their ReadOnly version
    Property<float> m_horzontalCenter;
    Property<float> m_verticalCenter;
public:

    ReadOnlyProperty<float> horzontalCenter;
    ReadOnlyProperty<float> verticalCenter;

    sf::FloatRect getBoundingBox() const;
    sf::Transform getTransform()   const;

private:
    void updateTransform() const;
    mutable sf::Transformable m_tranformFacade;

    void updateInterals();

};


#endif // end of __GEOMTRY_H_
