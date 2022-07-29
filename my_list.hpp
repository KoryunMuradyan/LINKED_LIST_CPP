#ifndef __MY_LIST_HPP__
#define __MY_LIST_HPP__

#include "list_declaration.hpp"

template <typename T>
my_list<T>::my_list(const std::initializer_list<T>& init_list)
	: _size_init_list(init_list.size())
{
	_first = new node;
	_first->next_node = NULL;
	_first->prev_node = NULL;
	_first->_node_data = *(init_list.begin());
	_last = _first;
	for(size_t i = 1; i < init_list.size(); ++i) 
	{
		node* new_node = new node;
		new_node->prev_node = _last;
		new_node->next_node = NULL;
		new_node->_node_data = *(init_list.begin() + i);
		_last = new_node;
	}
}

template <typename T>
inline void 
my_list<T>::push_front(const T& t) // ads a new element to the begining of the list
{
	node* new_node = new node;
	new_node->prev_node = NULL;
	new_node->next_node = _first;
	new_node->_node_data = t;
	_first = new_node;
}

template <typename T>
inline void 
my_list<T>::push_back(const T& t) // ads a new element to the end of the list
{
	node* new_node = new node;
	new_node->prev_node = NULL;
	new_node->next_node = _first;
	new_node->_node_data = t;
	_first = new_node;
}

template <typename T>
inline void 
my_list<T>::pop_front() // remmoves the _first element of the list and reduces it by 1
{
	node* tmp = _first->next_node;
	_first = tmp;
	tmp = tmp->prev_node;
	delete tmp;
	_first->prev_node = NULL;
}

template <typename T>
inline void 
my_list<T>::pop_back() //removes the _last element of the list and reduces it by 1
{
	node* tmp = _last->prev_node;
	_last = tmp;
	tmp = tmp->next_node;
	delete tmp;
	_last->next_node = NULL;
}

/*
template <typename T>
my_list& my_list<T>::operator= (const my_list& arg_my_list)
{
	arg_my_list._first = this->_first;
	arg_my_list._last = this->_last;
	arg_my_list._size_init_list;
}
*/

#endif // my_list_methods_definitions.hpp
