#ifndef TEXTNODE_H
#define TEXTNODE_H

#include <string>

#include <SceneGraph/Core/scenenode.h>
#include <SFML/Graphics/RectangleShape.hpp>

class RectangleNode : public SceneNode
{
public:
    RectangleNode(SceneNode* parent = nullptr);
    virtual ~RectangleNode(){}

    void onGeometryChange();
    Property<sf::Color> color;
    Property<sf::Color> borderColor;
    Property<float>     borderWidth;

private:
    virtual void    drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;
    mutable sf::RectangleShape m_shape;

};

#endif // TEXTNODE_H
