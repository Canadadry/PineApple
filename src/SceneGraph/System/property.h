#ifndef __PROPERTY__
#define __PROPERTY__

#include <SceneGraph/System/Signal/Signal.h>
#include <functional>

template <typename T>
class ReadOnlyProperty;

template<typename T>
class Property
{
public:
    Property(const T& value)
    :m_value(value)
    , m_bindedTo(NULL)
    {}
    ~Property()
    {
	// TODO : fix this, but this is more complicated than just this line
	//clear();
    }

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

    void bindTo(ReadOnlyProperty<T>& p)
    {
	if(m_bindedTo != NULL) m_bindedTo->m_valueChanged.Disconnect(this,&Property::setValue);
	m_bindedTo = &p.m_trueProperty;
	m_bindedTo->m_valueChanged.Connect(this,&Property::setValue);
	setValue(*m_bindedTo);
    }


    void clear()
    {
	if(m_bindedTo != NULL) m_bindedTo->m_valueChanged.Disconnect(this,&Property::setValue);
	m_bindedTo = NULL;
    }

    mutable Signal0<> onValueChanged;

private:
    T m_value;
    mutable Signal1<const T&> m_valueChanged;
    Property<T>* m_bindedTo;
};

template<typename T>
class ReadOnlyProperty
{
public:
    friend class Property<T>;

    ReadOnlyProperty(Property<T>& property)
	:m_trueProperty(property)
    {
	m_trueProperty.onValueChanged.Connect(this,&ReadOnlyProperty<T>::forwardUpdate);
    }
    ~ReadOnlyProperty()
    {
	m_trueProperty.onValueChanged.Disconnect(this,&ReadOnlyProperty<T>::forwardUpdate);
    }

    operator T() const { return m_trueProperty.getValue();}
    T getValue() const { return m_trueProperty.getValue();}

    Signal0<> onValueChanged;

private:
    void forwardUpdate()
    {
	onValueChanged.Emit();
    }

    Property<T>& m_trueProperty;
};

#endif //end of __PROPERTY__
