#ifndef SPRITENODE_H
#define SPRITENODE_H

#include <SceneGraph/Core/scenenode.h>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Texture.hpp>

class SpriteNode : public SceneNode
{
public:
    explicit SpriteNode(const sf::Texture& texture);

private:
    virtual void    drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;


    mutable sf::VertexArray m_array;
    sf::Texture     m_texture;
};

#endif // SPRITENODE_H
