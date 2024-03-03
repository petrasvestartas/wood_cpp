
#include "../../../stdafx.h" //go up to the folder where the CMakeLists.txt is

#include "viewer_wood.h"
#include "cgal_mesh_boolean.h"

float viewer::viewer_wood::scale = 1000.0f;
float viewer::viewer_wood::line_thickness = 3;

void viewer::viewer_wood::add(std::vector<std::vector<CGAL_Polyline>> &polyline_groups, int color_type)
{

    std::vector<std::vector<float>> vertices;

    int count = 0;
    for (auto &polyline_group : polyline_groups)
        count += polyline_groups.size();

    float scale_inv = 1 / viewer::viewer_wood::scale;

    for (auto &polyline_group : polyline_groups)
        for (auto &polyline : polyline_group)
        {
            if (polyline.size() == 0)
                continue;

            vertices.emplace_back(std::vector<float>());
            vertices.back().reserve(polyline.size() * 3);
            for (auto &point : polyline)
            {
                vertices.back().emplace_back(static_cast<float>(point.x() * scale_inv));
                vertices.back().emplace_back(static_cast<float>(point.y() * scale_inv));
                vertices.back().emplace_back(static_cast<float>(point.z() * scale_inv));
            }
        }

    glm::vec4 c = colors::black;
    switch (color_type)
    {
    case (0):
        c = colors::red;
        break;
    case (1):
        c = colors::green;
        break;
    case (2):
        c = colors::blue;
        break;
    case (3):
        c = colors::black;
        break;
    case (4):
        c = colors::grey;
        break;
    case (5):
        c = colors::white;
        break;
    }

    opengl_globals_geometry::polylines.add(vertices, viewer::viewer_wood::line_thickness, c, "mesh_outlines_wood");
}

void viewer::viewer_wood::add(std::vector<std::array<IK::Point_3, 2>> &point_pairs)
{

    std::vector<std::vector<float>> vertices;
    vertices.reserve(point_pairs.size() * 2);
    float scale_inv = 1 / viewer::viewer_wood::scale;

    for (auto &point_pair : point_pairs)
    {
        vertices.emplace_back(std::vector<float>());
        vertices.back().reserve(6);
        vertices.back().emplace_back(static_cast<float>(point_pair[0].x() * scale_inv));
        vertices.back().emplace_back(static_cast<float>(point_pair[0].y() * scale_inv));
        vertices.back().emplace_back(static_cast<float>(point_pair[0].z() * scale_inv));
        vertices.back().emplace_back(static_cast<float>(point_pair[1].x() * scale_inv));
        vertices.back().emplace_back(static_cast<float>(point_pair[1].y() * scale_inv));
        vertices.back().emplace_back(static_cast<float>(point_pair[1].z() * scale_inv));
    }
    opengl_globals_geometry::polylines.add(vertices, viewer::viewer_wood::line_thickness, colors::red, "mesh_outlines_wood");
}

void viewer::viewer_wood::add(std::vector<std::vector<IK::Point_3>> &input_polyline_pairs)
{

    std::vector<std::vector<float>> vertices;
    vertices.reserve(input_polyline_pairs.size());
    float scale_inv = 1 / viewer::viewer_wood::scale;

    for (auto &polyline : input_polyline_pairs)
    {
        if (polyline.size() == 0)
            continue;
        vertices.emplace_back(std::vector<float>());
        vertices.back().reserve(polyline.size() * 3);
        for (auto &point : polyline)
        {
            vertices.back().emplace_back(static_cast<float>(point.x() * scale_inv));
            vertices.back().emplace_back(static_cast<float>(point.y() * scale_inv));
            vertices.back().emplace_back(static_cast<float>(point.z() * scale_inv));
        }
    }
    opengl_globals_geometry::polylines.add(vertices, viewer::viewer_wood::line_thickness, colors::grey, "mesh_outlines_wood");
}

void viewer::viewer_wood::add_areas(std::vector<CGAL_Polyline> &polylines)
{
    // std::cout << "Hi<<\n";
    std::vector<std::vector<glm::vec3>> vertices;
    vertices.reserve(polylines.size());
    float scale_inv = 1 / viewer::viewer_wood::scale;

    for (auto &polyline : polylines)
    {
        if (polyline.size() == 0)
            continue;

        vertices.emplace_back(std::vector<glm::vec3>());
        vertices.back().reserve(polyline.size() * 3);
        for (auto &point : polyline)
        {
            vertices.back().emplace_back(
                static_cast<float>(point.x() * scale_inv),
                static_cast<float>(point.y() * scale_inv),
                static_cast<float>(point.z() * scale_inv));
        }
    }
    // std::cout << "Hi<<\n";
    opengl_globals_geometry::meshes.add(vertices, colors::green, false, 0.001f, 1.0f, "mesh_outlines_wood");
    // opengl_globals_geometry::polylines.add(vertices, 5, colors::green, "mesh_outlines_wood");
}

void viewer::viewer_wood::add_areas(std::vector<std::vector<CGAL_Polyline>> &polylines)
{
    // std::cout << "Hi<<\n";
    std::vector<CGAL_Polyline> polylines_merged;
    polylines_merged.reserve(polylines.size() * 4);
    for (auto &lists : polylines)
        for (auto &polyline : lists)
        {
            if (polyline.size() == 0)
                continue;
            polylines_merged.emplace_back(polyline);
        }
    // std::cout << "Hi<<\n";
    add_areas(polylines_merged);
    // std::cout << "Hi<<\n";
    return;
}

void viewer::viewer_wood::add(std::vector<std::array<CGAL_Polyline, 4>> &volume_pairs)
{
    // std::cout << "Hi\n";

    std::vector<std::vector<float>> vertices;
    vertices.reserve(volume_pairs.size() * 4);
    float scale_inv = 1 / viewer::viewer_wood::scale;

    for (auto &polyline_array : volume_pairs)
    {

        for (auto &polyline : polyline_array)
        {
            vertices.emplace_back(std::vector<float>());
            vertices.back().reserve(polyline.size() * 3);

            for (auto &point : polyline)
            {
                vertices.back().emplace_back(static_cast<float>(point.x() * scale_inv));
                vertices.back().emplace_back(static_cast<float>(point.y() * scale_inv));
                vertices.back().emplace_back(static_cast<float>(point.z() * scale_inv));
            }
        }
    }
    opengl_globals_geometry::polylines.add(vertices, viewer::viewer_wood::line_thickness, colors::blue, "mesh_outlines_wood");
}

void viewer::viewer_wood::add_loft(std::vector<std::vector<CGAL_Polyline>> &output_plines)
{
    std::vector<float> out_vertices;
    std::vector<float> out_normals;
    std::vector<int> out_triangles;

    for (auto &polylines : output_plines)
        cgal::polyline_mesh_util::closed_mesh_from_polylines_vnf(polylines, out_vertices, out_normals, out_triangles, viewer::viewer_wood::scale);

    if (out_vertices.size() > 2 && out_normals.size() > 2 && out_triangles.size() > 2)
        opengl_globals_geometry::meshes.add(out_vertices, out_normals, out_triangles, colors::white);
}

void viewer::viewer_wood::add_mesh_boolean_difference(std::vector<CGAL_Polyline> &input_plines, std::vector<std::vector<CGAL_Polyline>> &output_plines)
{

    for (int i = 0; i < input_plines.size(); i += 2)
    {

        std::vector<CGAL_Polyline> input_plines_pair = {input_plines[i], input_plines[i + 1]};

        // create mesh list for boolean difference
        std::vector<CGAL::Surface_mesh<CGAL::Exact_predicates_inexact_constructions_kernel::Point_3>> mesh_list;

        // create mesh from outlines
        mesh_list.emplace_back(CGAL::Surface_mesh<CGAL::Exact_predicates_inexact_constructions_kernel::Point_3>());
        cgal::polyline_mesh_util::closed_mesh_from_polylines(input_plines_pair, mesh_list[0], 1000);

        // create mesh from genereated joints - output_plines
        // std::cout << "output_plines.size(): " << output_plines[(size_t)(i * 0.5)].size() << std::endl;
        for (int j = 0; j < output_plines[(size_t)(i * 0.5)].size(); j += 2)
        {
            mesh_list.emplace_back(CGAL::Surface_mesh<CGAL::Exact_predicates_inexact_constructions_kernel::Point_3>());
            std::vector<CGAL_Polyline> polylines_single = {output_plines[(size_t)(i * 0.5)][j], output_plines[(size_t)(i * 0.5)][j + 1]};
            cgal::polyline_mesh_util::closed_mesh_from_polylines(polylines_single, mesh_list.back(), 1000);
        }

        for (size_t i = 0; i < mesh_list.size(); i++)
        {
            if (!CGAL::is_closed(mesh_list[i]))
                std::cerr << "mesh is not closed." << i << std::endl;

            if (CGAL::Polygon_mesh_processing::does_self_intersect(mesh_list[i]))
                std::cerr << "mesh has self-intersections." << i << std::endl;
        }

        // create boolean difference
        std::vector<float> out_vertices;
        std::vector<float> out_normals;
        std::vector<int> out_triangles;
        // std::cout << "mesh_list.size(): " << mesh_list.size() << std::endl;
        cgal::mesh_boolean::mesh_boolean_difference_to_viewer(mesh_list, 0, out_vertices, out_normals, out_triangles);

        // add to viewer
        opengl_globals_geometry::meshes.add(out_vertices, out_normals, out_triangles, colors::white);

        // print vertices and triangles
        // std::cout << "vertices: " << out_vertices.size() << " triangles: " << out_triangles.size() << " normals: " << out_normals.size() << std::endl;
        // for (size_t i = 0; i < out_vertices.size(); i += 3)
        //     std::cout << out_vertices[i] << "\n"
        //               << out_vertices[i + 1] << "\n"
        //               << out_vertices[i + 2] << std::endl;
        // for (size_t i = 0; i < out_triangles.size(); i += 3)
        //     std::cout << out_triangles[i] << "\n"
        //               << out_triangles[i + 1] << "\n"
        //               << out_triangles[i + 2] << std::endl;
    }
}

void viewer::viewer_wood::add(std::vector<IK::Point_3> &points)
{

    std::vector<float> vertices;
    std::vector<float> vertices_colors;
    vertices.reserve(vertices.size() * 3);
    vertices.reserve(vertices_colors.size() * 3);
    for (auto &point : points)
    {
        vertices.emplace_back(static_cast<float>(point.hx() / scale));
        vertices.emplace_back(static_cast<float>(point.hy() / scale));
        vertices.emplace_back(static_cast<float>(point.hz() / scale));

        vertices_colors.emplace_back(0.0f);
        vertices_colors.emplace_back(0.0f);
        vertices_colors.emplace_back(0.0f);
    }

    opengl_globals_geometry::pointclouds.add(vertices, vertices_colors, line_thickness, "points_wood");
}
