#pragma once
class Node
{
protected:
    int id;
    double x, y, z;

public:
    int GetId();
    int GetX();
    int GetY();
    int GetZ();
    Node(int id, double x, double y, double z);
    ~Node();

};