#include "Node.h"

int Node::GetId()
{
    return id;
}

int Node::GetX()
{
    return x;
}

int Node::GetY()
{
    return y;
}

int Node::GetZ()
{
    return z;
}


Node::Node(int id, double x, double y, double z)
    :id{id}, x{x}, y{y}, z{z}{};

Node::~Node()
{

}