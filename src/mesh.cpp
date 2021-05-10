#include <iostream>
#include <string>

#define TINYOBJLOADER_IMPLEMENTATION
#include <tiny_obj_loader.h>
#include <GL/gl3w.h>
#include <glm/mat4x4.hpp>


#include "mesh.h"

Mesh::Mesh(std::string path) : model(glm::mat4x4(1.0f))
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
		return;
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
}

auto Mesh::set_color(glm::vec3 col) -> void
{
	if (has_texture)
	{
		std::cerr << "Tried of set a color for a mesh that already has a texture" << std::endl;
	}
	else
	{
		color = col;
	}
}


auto Mesh::gen_vao() -> void
{

	auto num_vertices = vertices.size();
	auto num_normals = normals.size();
	glCreateVertexArrays(1, &vao);

    // Get the names (video card pointers)
    glCreateBuffers(1, &vbo);

    // Alloc video memory and initialize it with vertices
    glNamedBufferStorage(vbo,
			 (num_vertices + num_normals) * 3 * sizeof(float),
			 NULL,
			 GL_MAP_WRITE_BIT);

    float* mapped_vbo = (float *) glMapNamedBuffer(vbo, GL_WRITE_ONLY);
    std::memcpy(mapped_vbo, vertices.data(), num_vertices * 3 * sizeof(float));
    std::memcpy(mapped_vbo + num_vertices * 3, normals.data(), num_normals * 3 * sizeof(float));

    glUnmapNamedBuffer(vbo);

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*) (num_vertices * sizeof(glm::vec3)));
    glEnableVertexAttribArray(1);
}


auto Mesh::draw() -> void
{
	glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, vertices.size());


}