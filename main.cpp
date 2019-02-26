#include "node.h"
#include "dnode.h"

#include <iostream>

namespace nodespace
{

    int main()
    {
        node* tail = new node(1.0);
        node* second = new node(2.0, tail);
        node* third = new node(3.0, second);

        

        // Frequency left to implement

        return 0;
    }

}

int main()
{
    return nodespace::main();
}