#ifndef CONTAINER_BLACKBOARDT_HPP
#define CONTAINER_BLACKBOARDT_HPP

#include <unordered_map>

#include <Container\BlackboardID.hpp>

namespace Container
{

template <typename T>
class BlackboardT
{
public:
	void declare(BlackboardID blackboardID, const T& initValue = T());
	bool exist(BlackboardID blackboardID) const;

	void setValue(BlackboardID blackboardID, const T& value);
	const T& getValue(BlackboardID blackboardID) const;

	unsigned int getNbOfElements() const;

private:
	std::unordered_map<BlackboardID, T> m_Elements;
};

}

#include <Container\BlackboardT.inl>

#endif //CONTAINER_BLACKBOARDT_HPP
