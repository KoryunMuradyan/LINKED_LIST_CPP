#ifndef __LIST_DECLARATION_HPP__
#define __LIST_DECLARATION_HPP__

#include <iostream>
#include <cassert>

template <typename T>
class my_list
{
	private:
		struct node
		{
			T _node_data;
			node* next_node;
			node* prev_node;
		};

		size_t _size_init_list;
		node* _first = NULL;
		node* _last = NULL;

	public:

		class Iterator
		{
			public:
				node* _this_node;

				Iterator(node* new_node)
					: _this_node(new_node)
				{}

				T& operator* () { return _this_node->_node_data; }

				inline bool operator== (const Iterator& arg_iter) { 
					if (_this_node == arg_iter->_this_node) { 
						return true; 
					} else { 
						return false; 
					} 
				}

				inline bool operator!= (const Iterator& arg_iter) { 
					if (_this_node != arg_iter->_this_node) { 
						return true; 
					} else { 
						return false; 
					} 
				}

				inline bool operator= (const node& arg_node) { 
					this->_this_node == arg_node; 
					return this; 
				}

				//inline void operator++ () { node* tmp_node; tmp_node = this->_this_node; tmp_node->_this_node->next_node; } //assert( _this_node != _last );  TO BE ADDED TO THE DEFINITION OF THE METHOD !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

				inline void operator++ () { 
					_this_node = _this_node->next_node; 
					std::cout << _this_node->_node_data; 
				} //assert( _this_node != _last );  TO BE ADDED TO THE DEFINITION OF THE METHOD !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

				inline void operator-- () { 
					_this_node = _this_node->next_node; 
				} //assert( _this_node != _last ); TO BE ADDED TO THE DEFINITION OF THE METHOD !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

				inline Iterator operator+ (const int& iter_num) {
					assert(iter_num >= 0);
					Iterator new_iter = new Iterator;
					new_iter->_this_node = _this_node;
					for( int i = 0; i < iter_num; ++i ) {
						new_iter->_this_node = _this_node->next_node;
					}
					return new_iter; 
				}
					
		};

		my_list(const std::initializer_list<T>& init_list);

		inline T front() { return _first->_node_data; } // returns the _first element
			
		inline T back() { return _last->_node_data; } // returns the _last element

		inline void push_front(const T& t); // ads a new element to the begining of the list

		inline void push_back(const T& t); // ads a new element to the end of the list

		inline void pop_front(); // remmoves the _first element of the list and reduces it by 1

		inline void pop_back(); //removes the _last element of the list and reduces it by 1

		inline Iterator end() { 
			Iterator* tmp_Iter; 
			tmp_Iter->_this_node = this->_last; 
			return *(tmp_Iter); 
		} // returns an iterator pointing to the _last element of the list

		inline Iterator begin() 
		{ 
			Iterator* tmp_Iter; 
			tmp_Iter->_this_node = this->_first; 
			return *(tmp_Iter); 
		} // returns an iterator pointing to the _first ele//ment of the list 
		
		inline bool empty() 
		{ 
			if (_first == NULL && _last == NULL) 
				return true; 
			return false; 
		}  // returns true if the list is empty else returns false

		void insert(); // inserts new element in the list before the element at the specified position

		void erase(); // removes a single element or a range of elements from the list

		inline void display() 
		{ 
			node* tmp_node = _first; 
			while(tmp_node != _last) 
			{ 
				std::cout << tmp_node->_node_data << std::endl; 
				tmp_node = tmp_node->next_node; 
			}  
		}

		//my_list& operator= (const my_list& arg_my_list);

};

#endif  // my_list.hpp
