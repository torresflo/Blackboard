namespace Container
{

template<typename T>
inline void BlackboardT<T>::declare(BlackboardID blackboardID, const T& initValue)
{
	m_Elements.emplace(blackboardID, initValue);
}

template<typename T>
inline bool BlackboardT<T>::exist(BlackboardID blackboardID) const
{
	return m_Elements.count(blackboardID) != 0;
}

template<typename T>
inline void BlackboardT<T>::setValue(BlackboardID blackboardID, const T& value)
{
	m_Elements.at(blackboardID) = value;
}

template<typename T>
inline const T& BlackboardT<T>::getValue(BlackboardID blackboardID) const
{
	return m_Elements.at(blackboardID);
}

template<typename T>
inline unsigned int BlackboardT<T>::getNbOfElements() const
{
	return m_Elements.size();
}

}
