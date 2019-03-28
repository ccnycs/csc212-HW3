#include "llist.h"

namespace nodespace{
	
	void LList::append(const node::value_type& entry){

	};
	
	void LList::insert(std::size_t position, const node::value_type& entry){

	};   

	//find first occurrence
	const node* LList::search(const node::value_type& target){

	};
	
	const node* LList::locate(std::size_t position){

	};

	//remove by value, remove all
	bool LList::remove(const node::value_type& target){

	};

	void LList::clear(){

	};

	//returns new list
	LList* LList::copy(){

	};

	//additional functions to index into list
	node* LList::operator[] (size_t ind){

	};

	std::list<std::tuple<node::value_type, int>> frequency(LList data);
}