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

    sf::FloatRect getBoundingBox() const;
    sf::Transform getTransform()   const;

private:
    void updateTransform() const;
    mutable sf::Transformable m_tranformFacade;
};


#endif // end of __GEOMTRY_H_
