#ifndef _Tween_H_
#define _Tween_H_

#include "Easing.h"
#include <SceneGraph/System/property.h>
#include <SFML/System/Time.hpp>

template<typename T>
class Tween
{
public:

	Tween(Property<T>& property,T start, T end, sf::Time duration,Easing easing, sf::Time startDelay);
	void update(sf::Time elapsed_time);
	bool running() const;

protected:
	void compute(float progress) ;

	Property<T>& m_property;

	sf::Time m_duration;
	Easing m_easing;
	sf::Time m_startDelay;
	sf::Time m_current_time;

	T m_start;
	T m_end;

};

#include <SceneGraph/System/Animation/Tween.inl>
#endif //end of Tween
