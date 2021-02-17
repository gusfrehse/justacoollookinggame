#include <iostream>
#include <string>

#define TINYOBJLOADER_IMPLEMENTATION
#include <tiny_obj_loader.h>


#include "mesh.h"

auto Mesh::open(std::string path) -> void
{
    tinyobj::ObjReaderConfig config;
    config.mtl_search_path = "";

    tinyobj::ObjReader reader;

    if (!reader.ParseFromFile(path, config))
    {
	std::cerr << "Could not parse from file '" << path << "'" << std::endl;
	if (!reader.Error().empty())
	{
	    std::cerr << "TinyObjReader error: " << reader.Error();
	}
    }

    // TODO
}
