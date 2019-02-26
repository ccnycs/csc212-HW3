#ifndef MAIN_SAVITCH_LIST_H  
#define MAIN_SAVITCH_LIST_H

#include <cstdlib> // Provides size_t and NULL

#include <map>
#include <iostream>
#include "node.h"

namespace nodespace{
    class list{
	public:
        // functions modified from the linked list toolkit
        std::size_t length(const node* head_ptr){return length;};
        
        //add to end, insert at position P
        void append(const node::value_type& entry);
        void insert(std::size_t position, const node::value_type& entry);   
        
        //find first occurance
        node* search(const node::value_type& target);
        const node* search(const node::value_type& target);
        
        node* locate(std::size_t position);
        const node* locate(std::size_t position);
        
        //remove by position, value, remove all
        void remove(std::size_t position);
        void remove(const node::value_type& target);
        void clear();
        
        //returns new list
        list* copy();

        //additional functions to index into list and overwrite node
        node* operator[] (size_t ind);
        node& operator = (node::value_type i)

    private:
        node* head_ptr;
        node* tail_ptr;
        size_t length;
    };
}
#endif

		