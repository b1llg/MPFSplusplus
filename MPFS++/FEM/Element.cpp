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

int Element::GetMid()
{
    return mid;
}

std::vector<int> Element::GetNodes()
{
    return nodes;
}

bool Element::SetProperty(std::vector<Property*>* props)
{
    prop = (*props)[mid-1];
    return true;
}

Element::~Element()
{

}