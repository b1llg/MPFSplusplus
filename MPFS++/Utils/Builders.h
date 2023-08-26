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

    static_cast<std::stringstream>(line) >> type;

    if (type == "E1TR2")
    {
        int id, pid, mid, n1, n2;

        static_cast<std::stringstream>(line) >> type >> id >> pid >> mid >> n1 >> n2;

        std::vector<int> Node{ n1, n2 };

        Element temp{ id, type, pid, mid, Node };

        elems->push_back(temp);
    }




    return true;
}

bool Builder_Property(std::vector<Property*>* props, std::string physic, std::string eltype, std::ifstream& file)
{
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

}
