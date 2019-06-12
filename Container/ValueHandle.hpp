#ifndef CONTAINER_VALUEHANDLER_HPP
#define CONTAINER_VALUEHANDLER_HPP

#include <functional>
#include <vector>

namespace Container
{

template <typename T>
class ValueHandle
{
public:
	using ValueChangedCallback = std::function<void(const T&, const T&)>;

	ValueHandle(const T& initValue, const ValueChangedCallback& callback);
	ValueHandle(const T& initValue);

	ValueHandle(ValueHandle const& other) = default;
	ValueHandle& operator=(ValueHandle const& other) = default;

	ValueHandle(ValueHandle&& other) = default;
	ValueHandle& operator=(ValueHandle&& other) = default;

	const T& getValue() const;
	void setValue(const T& value);

private:
	ValueChangedCallback m_callback;
	T m_value{};
};

}

#include <Container\ValueHandle.inl>

#endif //CONTAINER_VALUEHANDLER_HPP
