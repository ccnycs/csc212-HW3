# csc212-HW3
Linked Lists Assignment

In this assignment, implement a linked list object using the singly linked list toolkit([node.h](node.h), [node.cpp](node.cpp)). Then implement frequency function to count the occurrence of each element in the list. 


## Task 1: Add = operator to node
Implement the assignment operator for the node such that setting a node `=` overwrites the value in the node with the value. This should be implemented in [node.h](node.h)

This is the prototype:
```c++
nodespace::node& operator = (value_type value);
```

 And the function is called as:
 ```c++
 nodespace::node A(2);
 A = 5;
 ```

## Task 2: Linked List Class
Implement the methods of the linked list in [llist.cpp](llist.cpp)

The class declaration can be found in [list.h](list.h):
```c++
class LList{
	public:
        // functions modified from the linked list toolkit
        std::size_t length(const node* head_ptr){return list_length;}
        
        //add to end, insert at position P
        void append(const node::value_type& entry);
        void insert(std::size_t position, const node::value_type& entry);   
        
        //find first occurrence
        const node* search(const node::value_type& target);
        const node* locate(std::size_t position);
        
        //remove by value, remove all
        bool remove(const node::value_type& target);
        void clear();
        
        //returns new list
        LList* copy();

        //additional functions to index into list
        node* operator[] (size_t ind);

    private:
        node* head_ptr;
        node* tail_ptr;
        size_t list_length;
    };
```


### insert
If trying to insert into a non-existent position, this function should throw an out of range exception. 

### search and locate
If the target or position is not in the list, these functions should return the `NULL` pointer.

### remove
return `true` if value is removed, `false` if value is not in LList.

### node * operator[]
The subscript/indexing operator is used to obtain a modifiable value in the list. It is used as follows:
```c++
LList mylist();
mylist.append(1);
mylist.append(2);
mylist[0] = 2;
mylist[-1] = 3;
std::cout<<mylist[1]<<std::endl;
```
An out of range exception should be thrown if the index does not exist. 


## Task 3: Frequency
Create a function that counts how many times each element occurs in the linked list. The function should return a standard library linked list [std::list](https://devdocs.io/cpp/container/list) of (element, count) tuples. If LList is empty, the function should return an empty list. 

This function should be implemented in [llist.cpp](llist.cpp). 

Here is the function prototype:
```c++
std::list<std::tuple<const node::value_type&, int>> frequency(LList data);

```
And this is how the function is called:
```c++
LList numbers();
numbers.append(2);
numbers.append(4);
numbers.append(2);
 
std::list<std::tuple<node::value_type, int> count;
count = frequency(numbers);
```
Count should return a list containing something like `[(2,2), (4,1)]`
