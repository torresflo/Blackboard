#include "ValueHandle.hpp"
namespace Container
{

template<typename T>
inline ValueHandle<T>::ValueHandle(const T & initValue, const ValueHandle<T>::ValueChangedCallback & callback)
	:m_callback(callback), m_value(initValue)
{}

template<typename T>
inline ValueHandle<T>::ValueHandle(const T & initValue)
	: m_value(initValue)
{}

template<typename T>
const T& ValueHandle<T>::getValue() const
{
	return m_value;
}

template<typename T>
void ValueHandle<T>::setValue(const T& value)
{
	if (m_callback)
	{
		m_callback(m_value, value);
	}

	m_value = value;
}

}
