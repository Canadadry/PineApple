#ifndef TEXTNODE_H
#define TEXTNODE_H

#include <string>

#include <SceneGraph/Core/scenenode.h>
#include <SceneGraph/System/property.h>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>

class TextNode : public SceneNode
{
public:
    TextNode();

    Property<std::string>       text;
    Property<sf::Color>         color;
    Property<std::string>       fontName;
    Property<float>             fontlSize;
    Property<Geometry::Origin>  alignement;

    void updateFont();

private:
    virtual void    drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;

    mutable sf::Text        m_text;
    sf::Font        m_font;
};

#endif // TEXTNODE_H
