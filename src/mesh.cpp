#include <iostream>
#include <string>

#define TINYOBJLOADER_IMPLEMENTATION
#include <tiny_obj_loader.h>


#include "mesh.h"

auto Mesh::open(std::string path) -> int
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
	return -1;
    }

    if (!reader.Warning().empty())
    {
	std::cerr << "TinyObjReader warning: " << reader.Warning();
    }

    auto& attrib = reader.GetAttrib();
    auto& shapes = reader.GetShapes();
    auto& materials = reader.GetMaterials();

    for (const auto& shape : shapes)
    {
	for (const auto& index : shape.mesh.indices)
	{
	    auto vertex = glm::vec3(
		attrib.vertices[3 * index.vertex_index + 0],
		attrib.vertices[3 * index.vertex_index + 1],
		attrib.vertices[3 * index.vertex_index + 2]);
	    vertices.push_back(vertex);
	    // indices.push_back(indices.size());
	}
    }

    return 0;
}
