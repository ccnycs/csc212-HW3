#include "llist.h"
#include "node.h"
#include <cassert>
#include<vector>
#include<tuple>
#include<list>
#include"node.cpp"

namespace nodespace
{

void LList::append(const node::value_type& entry)
{
    node* temp = new node(entry, NULL);

    if(list_length == 0)
    {
        head_ptr = temp;
        tail_ptr = temp;
        //std::cout<<head_ptr->data();
    }

    else
    {
        tail_ptr->set_link(temp);

        tail_ptr = temp;
    }

    list_length++;
}

void LList::insert(std::size_t position, const node::value_type& entry)
{

    if(position < 1 || position > list_length)
    {
        throw std::out_of_range("Invalid");
    }

    if(position == 1)
    {
        head_ptr = new node(entry, head_ptr);

        list_length++;

        return;
    }

    node* cursor = head_ptr;

    std::size_t cnt = 1;

    while(cursor != NULL)
    {
        if(cnt == position-1)
        {
            node* temp = new node(entry, cursor->link());
            cursor->set_link(temp);
            //std::cout << "Done\n";
        }

        cursor = cursor->link();

        cnt++;
    }

    list_length++;


}

//find first occurrence
const node* LList::search(const node::value_type& target)
{

    node* cursor = head_ptr;

    while(cursor != NULL)
    {
        if(cursor->data() == target)
        {
            return cursor;
        }

        std::cout << cursor->data() << std::endl;

        cursor = cursor->link();
    }
    //std::cout << "Reached\n";

    return NULL;
}

const node* LList::locate(std::size_t position)
{

    std::size_t cnt = 0;

    assert( 0 < position);

    node* cursor = head_ptr;

    while(cursor != NULL)
    {
        cnt++;

        if(cnt == position)
        {
            return cursor;
        }

        cursor = cursor->link();
    }

    return NULL;
}

//remove by value, remove all
bool LList::remove(const node::value_type& target)
{

    node* cursor = head_ptr;
    node* temp = head_ptr->link();

    while(temp != NULL)
    {
        if(temp->data() == target)
        {
            cursor->set_link(temp->link());

            delete temp;

            return true;
        }

        temp = temp->link();

        cursor = cursor->link();

    }

    return false;

}

void LList::clear()
{
    node* cursor = head_ptr;

    while(head_ptr != NULL)
    {
        head_ptr = head_ptr->link();

        delete cursor;

        cursor = head_ptr;
    }

    head_ptr = NULL;
    tail_ptr = NULL;
    list_length = 0;

}

//returns new list
LList* LList::copy()
{
    assert(list_length > 0);

    node* temp = new node(head_ptr->data());

    LList* linked_list = new LList(temp, temp, 1);

    node* cursor = head_ptr->link();

    while(cursor != NULL)
    {
        linked_list->append(cursor->data());

        cursor = cursor->link();

    }

    linked_list->list_length = this->list_length;

    /*
    node* c = linked_list->head_ptr;

    while(c!=NULL)
    {
        std::cout << "Linked " << c->data() << std::endl;
        c = c->link();
    }*/

    return linked_list;

}

//additional functions to index into list
node* LList::operator[] (size_t ind)
{
    node* temp = get_head_ptr();



    while(temp != NULL && ind > 0)
    {
        temp = temp->link();
        ind--;
        //std::cout <<"Found" << ind << std::endl;
    }

    return temp;
}

std::list<std::tuple<node::value_type, int>> frequency(LList data)
{

    std::tuple <node::value_type, int> tuplee;

    std::vector < node::value_type > v;

    std::list<std::tuple<node::value_type, int>> data_list;

    node *temp = data.get_head_ptr();
    node *head_ptr2 = data.get_head_ptr();

    size_t cnt_temp = 0;

    while(head_ptr2 != NULL)
    {
        temp = head_ptr2;

        cnt_temp = 0;

        while(temp!=NULL)
        {
            cnt_temp++;

            temp = nodespace::list_search(temp->link(), temp->data());
        }

        bool check = true;

        for(int i=0; i<v.size(); i++)
        {

            if(v[i] == head_ptr2->data())
            {
                check = false;
            }

        }

        if(check)
        {
            tuplee = std::make_tuple(head_ptr2->data(), cnt_temp);

            data_list.push_back(tuplee);

        }

        v.push_back(head_ptr2->data());

        head_ptr2 = head_ptr2->link();
    }

    return data_list;

}
}

