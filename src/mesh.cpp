#include <iostream>
#include <string>

#define TINYOBJLOADER_IMPLEMENTATION
#include <tiny_obj_loader.h>


#include "mesh.h"

auto Mesh::open(std::string path) -> int
{
    tinyobj::ObjReaderConfig config;
    config.triangulate = true;
    config.vertex_color = false;
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
	    auto normal = glm::vec3(
		attrib.normals[3 * index.normal_index + 0],
		attrib.normals[3 * index.normal_index + 1],
		attrib.normals[3 * index.normal_index + 2]);
	    normals.push_back(normal);
	}
    }

    return 0;
}
