#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
#include "../MPFS++/Core.h"
#include "Builders.h"
#include "StringManipulators.h"


void PreProcessor(std::string file_name, std::vector<Node>* grid, std::vector<Element>* elems, std::vector<Property*>* props)
{
    // Open input file
    std::ifstream file(file_name);

    if (!file)
    {
        std::cerr << "Unable to open the file: " << file_name << std::endl;
    }


    // Initialize line string to read input file
    std::string line;
    // read the first line
    std::getline(file, line);

    while (true)
    {

        // If end of input file, break loop
        if (file.eof()) break;

        // if line is empty -> do nothing (prevents warning)
        if (line.empty());

        // Check if its end of file
        
        if (String_Contains(line, "*END")) break;

  
        if (String_Contains(line, "*NODES"))
        {
            std::getline(file, line);

            while (line[0] == '?')
            {
                std::getline(file, line); // skip input comments
            }

            while (line[0] != '*' && line[0] != '?') // means line has node content and is not a card definition
            {
                Builder_Node(grid, line);
                std::getline(file, line);
            }
        }

        if (String_Contains(line, "*ELEMENTS"))
        {
            std::getline(file, line);
            while (line[0] == '?')
            {
                std::getline(file, line); // skip input comments
            }

            while (line[0] != '*' && line[0] != '?') // means line has node content and is not a card definition
            {
                Builder_Element(elems, line);
                std::getline(file, line);
            }
        }

        if (String_Contains(line, "*PROP"))
        {
            std::vector<std::string> property_definition{};

            property_definition = String_Split(line);

            Builder_Property(props, property_definition[1], property_definition[2], file);
        }
        // last resort, read next line
        std::getline(file, line);
    }

    file.close();
}