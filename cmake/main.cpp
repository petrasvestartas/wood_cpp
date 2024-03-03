#include "stdafx.h"
#include "wood_test.h" // test

int main(int argc, char **argv)
{

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// GoogleTest
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// wood::test::run_all_tests();

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Display
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	wood::globals::DISTANCE = 0.1;
	wood::globals::DISTANCE_SQUARED = 0.01;
	wood::globals::ANGLE = 0.11;
	wood::globals::OUTPUT_GEOMETRY_TYPE = 3;

	opengl_globals::shader_type_0default_1transparent_2shaded_3shadedwireframe_4wireframe_5normals_6explode = 2;
	opengl_render::render(wood::test::type_plates_name_side_to_side_edge_inplane_hilti);

	return 0;
}
