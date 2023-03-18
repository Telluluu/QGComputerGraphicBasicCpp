#pragma once
#include <iterator>

//可以考虑让这个类的使用更优雅一点
//不想折腾的删除这个定义
#define LL_ITERATOR_FEATURE ///可选 [迭代器]

template<class T>
class LinkedList
{
	//...
public:
#ifdef LL_ITERATOR_FEATURE
	class iterator
	{
	private:
		//...
	public:
		using iterator_concept = std::bidirectional_iterator_tag;
		using difference_type = std::ptrdiff_t;
		using value_type = T;
		using pointer = T*;
		using reference = T&;
		reference operator*() const;
		pointer operator->() const;
		iterator& operator++();
		iterator operator++(int);
		iterator& operator--();
		iterator operator--(int);
		bool operator==(const iterator& other) const;
		bool operator!=(const iterator& other) const;
		reference operator[](difference_type  i) const;
		auto operator<=>(const iterator&) const = default;
	};

	iterator begin();
	iterator end();
	iterator rbegin();
	iterator rend();
#endif

public:
	LinkedList();
	~LinkedList();

	T& operator[](int i);
#ifdef LL_ITERATOR_FEATURE
	//default insert after iter
	void Insert(const T& val, const iterator& iter, bool insert_prev = false);
	iterator Remove(const iterator& iter);
#else
	//default insert after node
	void Insert(const T& val, T* node, bool insert_prev = false);
	T* Remove(T* node);
#endif

	T& Front();
	T& Back();

	size_t Count();
	bool Empty();

	void Clear();

	//... other methods
};