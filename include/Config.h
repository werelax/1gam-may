#ifndef __Config__
#define __Config__

#include <fstream>
#include <iostream>
#include <cstring>
#include <jansson.h>
#include <list>
#include "Wall.h"

typedef std::list<Wall*> wall_list;

class Config
{
public:
    Config(const char* filename);

    ~Config();

    std::string getOptionAsString(std::string optionName);

    void getOptionList(const char* optionName);

    wall_list getWallList(const char* optionName);

private:

    json_t* getPathReference(json_t* root, std::string path);

    std::string readFileContents(const char* filename);

    std::string fileContents;
    json_t* root;
};

#endif
