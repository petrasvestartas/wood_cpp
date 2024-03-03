#ifndef VIEWER_WOOD_H
#define VIEWER_WOOD_H

namespace viewer
{
    namespace viewer_wood
    {

        extern float scale;

        extern float line_thickness;

        void add(std::vector<std::vector<CGAL_Polyline>> &polyline_groups, int color_type = 0);

        void add(std::vector<std::array<IK::Point_3, 2>> &point_pairs);

        void add(std::vector<std::vector<IK::Point_3>> &input_polyline_pairs);

        void add_areas(std::vector<CGAL_Polyline> &polylines);

        void add_areas(std::vector<std::vector<CGAL_Polyline>> &polylines);

        void add(std::vector<std::array<CGAL_Polyline, 4>> &volume_pairs);

        void add_loft(std::vector<std::vector<CGAL_Polyline>> &output_plines);

        void add_mesh_boolean_difference(std::vector<CGAL_Polyline> &input_plines, std::vector<std::vector<CGAL_Polyline>> &output_plines);

        void add(std::vector<IK::Point_3> &points);
    }
} // namespace viewer

#endif // VIEWER_WOOD_H