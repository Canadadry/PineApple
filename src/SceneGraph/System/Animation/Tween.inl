
template<typename T>
Tween<T>::Tween(Property<T>& property,T start, T end, sf::Time duration,Easing easing, sf::Time startDelay)
: m_property(property)
, m_start(start)
, m_end(end)
, m_duration(duration)
, m_easing(easing)
, m_startDelay(startDelay)
, m_current_time(sf::seconds(0))
{}

template<typename T>
void Tween<T>::update(sf::Time elapsed_time)
{
	m_current_time += elapsed_time;
	float progress = ( m_current_time.asSeconds() - m_startDelay.asSeconds() ) / m_duration.asSeconds();

	compute(m_easing.ease(progress));
}

template<typename T>
bool Tween<T>::running() const
{
    return (( m_current_time + m_startDelay ) < m_duration) ;
}

template<typename T>
void Tween<T>::compute(float progress)
{
	m_property = (m_end - m_start) * progress + m_start;

}

