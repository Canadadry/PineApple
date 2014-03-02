#ifndef TEXTNODE_H
#define TEXTNODE_H

#include <string>

#include <SceneGraph/scenenode.h>
#include <SFML/Graphics/RectangleShape.hpp>

class RectangleNode : public SceneNode
{
public:
    RectangleNode(SceneNode* parent = nullptr);
    virtual ~RectangleNode(){}

private:
    virtual void    drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;
    sf::RectangleShape m_shape;

};

#endif // TEXTNODE_H
