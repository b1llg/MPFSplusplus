#include "MPFS++/Core.h"
#include <iostream>
#include <fstream>
#include <iomanip>

int main()

{
     //Define common variable
    std::vector<Node>* grid = new std::vector<Node>;
    std::vector<Element>* elems = new std::vector<Element>;
    std::vector<Property*>* props = new std::vector<Property*>;

    PreProcessor("input.dat", grid, elems, props);

    for (auto node : *grid)
    {
        std::cout << "Node #" << node.GetId() << " at (x): " << std::fixed << std::setprecision(2) << node.GetX() << std::endl;
    }

    for (auto el : *elems)
    {
        std::cout << "Element #" << el.GetEid() << " is an element of type: " << el.GetType() << std::endl;
    }

    std::cout << "test" << std::endl;

    delete grid;
    delete elems;



    return 0;
}