#include "llist.h"

namespace nodespace{
	
	void LList::append(const node::value_type& entry){
		node* new_tail;
		new_tail = new node(entry);
		tail_ptr -> set_link(new_tail);
		tail_ptr = new_tail;
		delete new_tail;
		++list_length;
	};
	
	void LList::insert(std::size_t position, const node::value_type& entry){
		node* previous_ptr;
		previous_ptr = list_locate(head_ptr, position);
		list_insert(previous_ptr, entry);
		++list_length;
	};   

	//find first occurrence
	const node* LList::search(const node::value_type& target){
		return list_search(head_ptr, target);
	};
	
	const node* LList::locate(std::size_t position){
		return list_locate(head_ptr, position);
	};

	//remove by value
	bool LList::remove(const node::value_type& target){
		node* previous_ptr;
		previous_ptr = list_search(head_ptr, target);
		if (previous_ptr != NULL) {
			list_remove(previous_ptr);
			return 1;
		}
		else return 0;
	};
	
	//remove all
	void LList::clear(){
		list_clear(head_ptr);
	};

	//returns new list
	LList* LList::copy(){
		node* new_list_head;
		new_list_head = new node(head_ptr -> data());
		list_copy(head_ptr, new_list_head.head_ptr, new_list_head.tail_ptr);
	};

	//additional functions to index into list
	node* LList::operator[] (size_t ind){

	};

	std::list<std::tuple<node::value_type, int>> frequency(LList data);
}
