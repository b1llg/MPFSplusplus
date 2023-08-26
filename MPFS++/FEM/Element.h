#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Node.h"
#include "Property.h"

class Element
{
protected:
    int id;                             // Element id
    std::string type;                   // Element type
    int pid;                            // Property id
    int mid;                            // Material id

    Property prop;                     // Element property

    std::vector<int> nodes;             // Nodes vector

public:
    // Constructors
    Element();
    Element(int id, std::string type, int pid, int mid, std::vector<int> nodes);

    // Method
    void AddNode(int nid);
    int GetEid();
    std::string GetType();
    int GetPid();
    std::vector<int> GetNodes();
    void SetProperty(Property prop);

    // Destructor
    ~Element();
};
