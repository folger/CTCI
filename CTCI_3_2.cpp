// 3.2 How would you design a stack which, in addition to push and pop,
// also has a function min which returns the minimum element?
// Push, pop and min should all operate in O(1) time.

#include <stack>
#include <climits>
#include <iostream>

template <typename T>
struct ValTraits
{
	enum
	{
		MAX = -1,
		MIN = -1,
	};
};

template <>
struct ValTraits<int>
{
	enum
	{
		MAX = INT_MAX,
		MIN = INT_MIN,
	};
};

template <typename T>
class StackWithMin
{
public:
	StackWithMin()
	{
	}

	void push(T val)
	{
		m_stack.push(val);
		if ( val <= min() )
			m_stackMin.push(val);
	}

	void pop()
	{
		if ( top() == min() )
			m_stackMin.pop();
		m_stack.pop();
	}

	T top()
	{
		return m_stack.top();
	}

	T min()
	{
		if ( m_stackMin.empty() )
			return ValTraits<T>::MAX;

		return m_stackMin.top();
	}

	bool empty()
	{
		return m_stack.empty();
	}

private:
	std::stack<T> m_stack;
	std::stack<T> m_stackMin;
};


int main()
{
	StackWithMin<int> s;

	s.push(2);
	s.push(1);
	s.push(3);
	s.push(-1);

	std::cout << s.min() << std::endl;
	s.pop();
	std::cout << s.min() << std::endl;
	s.pop();
	std::cout << s.min() << std::endl;
	s.pop();
	std::cout << s.min() << std::endl;

	return 0;
}

