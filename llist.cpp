#include "llist.h"
#include <map>
#include <cassert>    // Provides assert
#include <cstdlib>    // Provides NULL and size_t
using namespace std;

namespace nodespace{
	
	void LList::append(const node::value_type& entry){
		node *temp = new node(entry,NULL);
		if(head_ptr=NULL){
			head_ptr = NULL;
			tail_ptr = NULL;
		}
		tail_ptr->set_link(temp);
		tail_ptr = temp;
	};
	
	void LList::insert(std::size_t position, const node::value_type& entry){
		node *pre = new node;
		node *cur = new node;
		node *temp = new node;
		if(position<1 || position>list_length){
			throw::std::out_of_range("non-existent position");
		}
		for(int i =1; i<position; i++){
			pre = cur;
			cur=cur->link();
		}
		temp->set_data(entry);
		pre->set_link(temp);
		temp->set_link(cur);
	};   

	//find first occurrence
	const node* LList::search(const node::value_type& target){
		const node *cursor = head_ptr;
		for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( )){
	    	if (cursor->data() == target){
				return cursor;
			}
		}
		return NULL;
	};
	
	const node* LList::locate(std::size_t position){
		const node *cursor = head_ptr;
		assert (0 < position);
		for (size_t i = 1; (i < position) && (cursor != NULL); i++){
	    	cursor = cursor->link( );
		}
		return cursor;
	};

	//remove by value, remove all
	bool LList::remove(const node::value_type& target){
		node *remove_ptr;
		node *pre;
		for(remove_ptr = head_ptr; remove_ptr!=NULL; remove_ptr=remove_ptr->link()){
			if(remove_ptr->data()==target){
				pre = remove_ptr;
				remove_ptr = remove_ptr->link();
				pre ->set_link(remove_ptr->link());
				delete remove_ptr;
				return true;
			}
		}
		return false;
	};


	void LList::clear(){
		node *temp = head_ptr;
		while(head_ptr!=NULL){
			head_ptr = head_ptr->link();
			delete temp;
			head_ptr = temp;
		}
		head_ptr = NULL;
	};

	//returns new list
	LList* LList::copy(){
		LList* new_list = new LList();
		new_list->append(head_ptr->data());
		node *cursor;
		for(cursor = head_ptr; cursor != NULL; cursor = cursor->link()){
			new_list->append(cursor->data());
		}
		return new_list;
	};

	//additional functions to index into list
	node* LList::operator[] (size_t ind){
		if(ind<1 || ind>list_length){
			throw::std::out_of_range("index does not exist");
		}
		node *temp;
		for(temp=head_ptr; temp!=NULL; temp=temp->link()){
			if(temp->data()==ind){
				return temp;
			}
		}
	};

	std::list<std::tuple<node::value_type, int>> frequency(LList data){
		 std::list<std::tuple<node::value_type, int>> count;
		 std::map<int,int> store; 
		 node* cursor = data.head_ptr;
		 while(cursor!=NULL){
			 int key = cursor->data();
			if (store.count(key) <= 0) {
				store[key] = 1;
			}
			else {
				store[key]++;
			}
			cursor->link();
		}
		 
	}
}