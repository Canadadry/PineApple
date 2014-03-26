#ifndef __PROPERTY__
#define __PROPERTY__

#include <SceneGraph/System/Signal/Signal.h>
#include <functional>

template<typename T>
class Property
{
public:
    Property(const T& value):m_value(value){}
    void setValue(const T& value)
    {
	if(m_value != value)
	{
	    m_value = value;
	    m_valueChanged.Emit(value);
	    onValueChanged.Emit();
	}

    }
    const T& operator=(const T& value)
    {
	setValue(value);
	return value;
    }
    operator T() const { return m_value;}

    T getValue() const { return m_value;}

    void bindTo(Property<T>& p)
    {
	if(m_bindedTo != NULL) m_bindedTo->m_valueChanged.Disconnect(this,&Property::setValue);
	m_bindedTo = &p;
	m_bindedTo->m_valueChanged.Connect(this,&Property::setValue);
	setValue(*m_bindedTo);
    }

    void clear()
    {
	if(m_bindedTo != NULL) m_bindedTo->m_valueChanged.Disconnect(this,&Property::setValue);
	m_bindedTo = NULL;
    }

    Signal0<> onValueChanged;

private:
    T m_value;
    Signal1<const T&> m_valueChanged;
    Property<T>* m_bindedTo;
};

#endif //end of __PROPERTY__
