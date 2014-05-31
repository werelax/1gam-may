#include "Config.h"

Config::Config(const char* filename) : fileContents(readFileContents(filename)) {
    json_error_t error;
    root = json_loads(fileContents.c_str(), 0, &error);
    if (!root) {
        std::cout << "Unable to load JSON from: " << filename << std::endl;
    } else {
        std::cout << "JSON read succesfully!!" << std::endl;
    }
}

Config::~Config() {
    json_decref(root);
}

std::string Config::getOptionAsString(std::string optionName) {
    std::string optionNameCopy = optionName;
    json_t* option = getPathReference(root, optionNameCopy);
    if (option) {
        return std::string(json_string_value(option));
    } else {
        return "";
    }
}

void Config::getOptionList(const char* optionName) {
}

wall_list Config::getWallList(const char* optionName) {
    wall_list walls;
    json_t* reference = getPathReference(root, optionName);
    int x; int y; int w; int h;
    for (size_t i = 0; i < json_array_size(reference); i += 4) {
        x = json_integer_value(json_array_get(reference, i));
        y = json_integer_value(json_array_get(reference, i+1));
        w = json_integer_value(json_array_get(reference, i+2));
        h = json_integer_value(json_array_get(reference, i+3));
        walls.push_back(new Wall(x, y, w, h));
    }
    return walls;
}

json_t* Config::getPathReference(json_t* root, std::string path) {
    size_t prev = 0;
    size_t next = 0;
    json_t* reference = root;
    while ((next = path.find_first_of(".", prev)) != std::string::npos &&
           reference != NULL) {
        reference = json_object_get(reference,
                                    path.substr(prev, next - prev).c_str());
        prev = next + 1;
    }
    return json_object_get(reference, path.substr(prev).c_str());
}

std::string Config::readFileContents(const char* filename) {
    std::ifstream in(filename, std::ios::in | std::ios::binary);
    if (in) {
        std::string contents;
        in.seekg(0, std::ios::end);
        contents.resize(in.tellg());
        in.seekg(0, std::ios::beg);
        in.read(&contents[0], contents.size());
        in.close();
        return contents;
    } else {
        std::cout << "Unable to open file: " << filename << std::endl;
        return NULL;
    }
}
