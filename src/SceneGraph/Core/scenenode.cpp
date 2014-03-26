#include <SceneGraph/Core/scenenode.h>

typedef std::vector<SceneNode*>::iterator SceneNodeIter;
typedef std::vector<SceneNode*>::const_iterator SceneNodeConstIter;

SceneNode::SceneNode(SceneNode* parent)
    : visible(true)
    , opacity(1.0)
    , m_trueOpacity(1.0)
    , m_children()
    , m_parent(nullptr)
{
    if(parent != nullptr)
	parent->attachChild(this);
}

SceneNode::~SceneNode()
{
    for(SceneNodeIter it = m_children.begin(); it != m_children.end(); it++)
    {
	delete *it;
    }
}


SceneNode* SceneNode::attachChild(SceneNode* child)
{
    child->m_parent = this;
    m_children.push_back(child);
    return child;
}

void SceneNode::detachChild(const SceneNode &node)
{
    SceneNodeIter it;
    for(it = m_children.begin(); it != m_children.end(); it++)
    {
	if(*it == &node) break;
    }

    if(it == m_children.end()) return;

    (*it)->m_parent = nullptr;
    m_children.erase(it);
}

void SceneNode::update(sf::Time dt)
{
    Animation::update(dt);
    updateCurrent(dt);
    updateChildren(dt);
}

void SceneNode::updateCurrent(sf::Time /*dt*/)
{

}

void SceneNode::updateChildren(sf::Time dt)
{
    for(SceneNodeIter child = m_children.begin(); child != m_children.end(); child++)
    {
	(*child)->update(dt);
    }
}

sf::Transform SceneNode::getWorldTransform() const
{
    sf::Transform transform = sf::Transform::Identity;

    for(const SceneNode* node = this; node != nullptr; node = node->m_parent)
    {
	transform = node->getTransform() * transform;
    }

    return transform;
}

sf::Vector2f SceneNode::getWorldPosition() const
{
    return getWorldTransform() * sf::Vector2f();
}

sf::FloatRect SceneNode::getBoundingRect() const
{
    return sf::FloatRect();
}

void SceneNode::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    if(visible.getValue()==false) return;
    if(m_parent != nullptr) m_trueOpacity = m_parent->m_trueOpacity.getValue()*opacity.getValue();
    else m_trueOpacity = opacity;
    states.transform *= getTransform();
    drawCurrent(target, states);
    drawChildren(target, states);
}

void SceneNode::drawCurrent(sf::RenderTarget &/*target*/, sf::RenderStates /*states*/) const
{

}

void SceneNode::drawChildren(sf::RenderTarget &target, sf::RenderStates states) const
{
    for(SceneNodeConstIter child = m_children.begin(); child != m_children.end(); child++)
    {
	(*child)->draw(target, states);
    }
}
