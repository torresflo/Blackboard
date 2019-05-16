#ifndef CONTAINER_BLACKBOARD_HPP
#define CONTAINER_BLACKBOARD_HPP

#include <tuple>
#include <type_traits>

#include <Container\BlackboardT.hpp>
#include <Container\BlackboardID.hpp>

namespace Container
{

template <typename... Types>
class Blackboard
{
public:
	template <typename T>
	void declare(BlackboardID blackboardID, const T& initValue = T())
	{
		getBlackboardT<T>().declare(blackboardID, initValue);
	}

	template <typename T>
	bool exist(BlackboardID blackboardID) const
	{
		return getBlackboardT<T>().exist(blackboardID);
	}

	template <typename T>
	void setValue(BlackboardID blackboardID, const T& value)
	{
		getBlackboardT<T>().setValue(blackboardID, value);
	}

	template <typename T>
	const T& getValue(BlackboardID blackboardID) const
	{
		return getBlackboardT<T>().getValue(blackboardID);
	}

	template <typename T>
	unsigned int getNbOfElements() const
	{
		return getBlackboardT<T>().getNbOfElements();
	}

private:
	std::tuple<BlackboardT<Types>...> m_Elements;

	template <unsigned int Index>
	using getTypeOfElement = typename std::tuple_element<Index, decltype(m_Elements)>::type;

	template<typename T, unsigned int Index>
	using isRightElement = std::is_same<getTypeOfElement<Index>, T>;

	template<typename T, unsigned int Index = 0>
	struct FindElement : public std::conditional_t<
		isRightElement<T, Index>::value,
		std::integral_constant<decltype(Index), Index>,
		FindElement<T, Index + 1>>
	{};

	template <typename T>
	BlackboardT<T>& getBlackboardT()
	{ 
		constexpr unsigned int index = FindElement<BlackboardT<T>>::value;
		return std::get<index>(m_Elements);
	}

	template <typename T>
	const BlackboardT<T>& getBlackboardT() const
	{
		return const_cast<Blackboard*>(this)->getBlackboardT<T>();
	}
};

}

#endif //CONTAINER_BLACKBOARD_HPP
