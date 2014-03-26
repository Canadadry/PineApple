#ifndef SCENENODE_H
#define SCENENODE_H

#include <vector>

#include <SceneGraph/Core/geometry.h>
#include <SceneGraph/System/Animation/Animation.h>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>


class SceneNode : public Geometry, public sf::Drawable, private sf::NonCopyable, public Animation<float>
{

public:
    explicit SceneNode(SceneNode* parent = nullptr);
    virtual ~SceneNode();

    SceneNode*              attachChild(SceneNode* child);
    void                    detachChild(const SceneNode& node);

    void                    update(sf::Time dt);

    sf::Transform           getWorldTransform() const;
    sf::Vector2f            getWorldPosition() const;
    virtual sf::FloatRect   getBoundingRect() const;

    Property<bool>  visible;
    Property<float> opacity;

protected:
    mutable Property<float>         m_trueOpacity;

private:
    virtual void    updateCurrent(sf::Time dt);
    virtual void    updateChildren(sf::Time dt);

    virtual void    draw(sf::RenderTarget &target, sf::RenderStates states) const;
    virtual void    drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;
    virtual void    drawChildren(sf::RenderTarget &target, sf::RenderStates states) const;


    std::vector<SceneNode*> m_children;
    SceneNode*              m_parent;

};

#endif // SCENENODE_H
