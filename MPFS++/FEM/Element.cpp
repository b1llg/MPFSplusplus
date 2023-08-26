#include "Element.h"

Element::Element()
    :id{-1}, type{" "}, pid{-1}, nodes{NULL}
{
    std::cout << "Empty element defined" << std::endl;
}

Element::Element(int id, std::string type, int pid, int mid, std::vector<int> nodes)
    :id{ id }, type{ type }, pid{ pid }, mid{ mid }, nodes{nodes} 
{
};

void Element::AddNode(int nid)
{
    nodes.push_back(nid);
}

int Element::GetEid()
{
    return id;
}

std::string Element::GetType()
{
    return type;
}

int Element::GetPid()
{
    return pid;
}

std::vector<int> Element::GetNodes()
{
    return nodes;
}

void Element::SetProperty(Property prop)
{
    prop = prop;
}

Element::~Element()
{

}