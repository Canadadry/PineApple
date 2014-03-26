#ifndef _Animation_H_
#define _Animation_H_

#include <vector>
#include <SFML/System/Time.hpp>
#include <SceneGraph/System/property.h>
#include "Tween.h"
#include "Easing.h"

template <typename T>
class Animation
{
public:
	Animation();
	~Animation();

	void update(sf::Time dt);

	void animate  (Property<T>& property, T start, T end,sf::Time duration = sf::milliseconds(300), Easing easing = Easing(), sf::Time start_delay = sf::seconds(0.0f));
	void animateTo(Property<T>& property,         T end ,sf::Time duration = sf::milliseconds(300), Easing easing = Easing(), sf::Time start_delay = sf::seconds(0.0f));
	void animateOf(Property<T>& property, T offset      ,sf::Time duration = sf::milliseconds(300), Easing easing = Easing(), sf::Time start_delay = sf::seconds(0.0f));

private:
	void animate(Tween<T>* tween);

	std::vector<Tween<T>*> m_anim;
};

#include <SceneGraph/System/Animation/Animation.inl>






#endif //end of Animation
