
template<typename T>
Animation<T>::Animation()
{
}

template<typename T>
Animation<T>::~Animation()
{
}

template<typename T>
void Animation<T>::animate(Tween<T>* tween)
{
    m_anim.push_back(tween);
}


template<typename T>
void Animation<T>::update(sf::Time dt)
{
    for (typename std::vector< Tween<T>*>::iterator it = m_anim.begin(); it != m_anim.end(); )
    {
	Tween<T>* tween = *it;
	tween->update(dt);
	if(tween->running()) it++;
	else
	{
	    delete tween;
	    it = m_anim.erase(it);
	}

    }
}

template<typename T>
void Animation<T>::animate  (Property<T>& property,  T start, T end,sf::Time duration , Easing easing , sf::Time start_delay)
{
    animate(new Tween<T>(property,start,end,duration,easing,start_delay));
}

template<typename T>
void Animation<T>::animateTo(Property<T>& property,   T end,sf::Time duration, Easing easing , sf::Time start_delay )
{
    animate(new Tween<T>(property,property,end,duration,easing,start_delay));
}

template<typename T>
void Animation<T>::animateOf(Property<T>& property, T offset      ,sf::Time duration , Easing easing , sf::Time start_delay)
{
    animate(new Tween<T>(property,property,property+offset,duration,easing,start_delay));
}
