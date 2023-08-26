#include <vector>
#include <string>
#include <sstream>
#include "../FEM/Element.h"
#include "../FEM/Node.h"
#include "../FEM/Property.h"
#include "../FEM/PropertyTruss.h"

bool Builder_Node(std::vector<Node>* grid, std::string line)
{
    int id;
    double x, y, z;

    static_cast<std::stringstream>(line) >> id >> x >> y >> z;

    Node temp{ id, x, y,z };
    grid->push_back(temp);


    return true;
}

bool Builder_Element(std::vector<Element>* elems, std::string line)
{
    std::string type;

    int id, pid, mid;

    std::vector<int> Nodes;

    static_cast<std::stringstream>(line) >> type;

    if (type == "E1TR2")
    {
         int n1, n2;

        static_cast<std::stringstream>(line) >> type >> id >> pid >> mid >> n1 >> n2;

        Nodes.push_back(n1);
        Nodes.push_back(n2);
    }

    Element temp{ id, type, pid, mid, Nodes };


    elems->push_back(temp);






    return true;
}

bool Builder_Property(std::vector<Property*>* props, std::string physic, std::string eltype)
{
    std::string line;
    if (physic == "SLD")
    {
        if (eltype == "TRUSS")
        {
            Property* prop = new PropertyTruss{};
            props->push_back(prop);
        }
        else
        {
            std::cerr << "Error in Builder_Property: eltype(" << eltype << ") not defined" << std::endl;
        }
    }
    else
    {
        std::cerr << "Error in Builder_Property: physic(" << physic << ") not defined" << std::endl;
    }

    return true;
}

bool Assign_Property(std::vector<Element>* elems, std::vector<Property*>* props)
{
    for (Element el : *elems)
    {
        el.SetProperty(props);
    }
    return false;
}
