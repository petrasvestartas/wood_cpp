#pragma once

// [Win32] Our example includes a copy of glfw3.lib pre-compiled with VS2010 to maximize ease of testing and compatibility with old VS compilers.
// To link with VS2010-era libraries, VS2015+ requires linking with legacy_stdio_definitions.lib, which we do using this pragma.
// Your own project should not be affected, as you are likely to link with a newer binary of GLFW that is adequate for your version of Visual Studio.
#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif

inline void StyleColorsCustom()
{
	ImGuiStyle *style = &ImGui::GetStyle();
	ImVec4 *colors = style->Colors;

	colors[ImGuiCol_Text] = ImVec4(0.0f, 0.0f, 0.0f, 1.00f);
	colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
	colors[ImGuiCol_WindowBg] = ImVec4(0.98f, 0.98f, 0.98f, 0.85f);
	colors[ImGuiCol_ChildBg] = ImVec4(1.00f, 1.00f, 1.00f, 0.00f);
	colors[ImGuiCol_PopupBg] = ImVec4(1.00f, 1.00f, 1.00f, 0.92f);
	colors[ImGuiCol_Border] = ImVec4(0.50f, 0.50f, 0.50f, 0.50f);
	colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_FrameBg] = ImVec4(0.43f, 0.43f, 0.43f, 0.39f);
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.47f, 0.47f, 0.47f, 0.40f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.42f, 0.42f, 0.42f, 0.69f);
	colors[ImGuiCol_TitleBg] = ImVec4(0.9f, 0.9f, 0.9f, 0.83f);
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.9f, 0.9f, 0.9f, 0.87f);
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.9f, 0.9f, 0.9f, 0.20f);
	colors[ImGuiCol_MenuBarBg] = ImVec4(0.9f, 0.9f, 0.9f, 0.80f);
	colors[ImGuiCol_ScrollbarBg] = ImVec4(0.20f, 0.20f, 0.20f, 0.60f);
	colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.40f, 0.40f, 0.40f, 0.30f);
	colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.40f, 0.40f, 0.40f, 0.40f);
	colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.41f, 0.41f, 0.41f, 0.60f);
	colors[ImGuiCol_CheckMark] = ImVec4(0.0f, 0.0f, 0.0f, 0.50f);
	colors[ImGuiCol_SliderGrab] = ImVec4(1.00f, 1.00f, 1.00f, 0.30f);
	colors[ImGuiCol_SliderGrabActive] = ImVec4(0.41f, 0.41f, 0.41f, 0.60f);
	colors[ImGuiCol_Button] = ImVec4(0.7f, 0.7f, 0.7f, 0.62f);
	colors[ImGuiCol_ButtonHovered] = ImVec4(0.6f, 0.6f, 0.6f, 0.79f);
	colors[ImGuiCol_ButtonActive] = ImVec4(0.5f, 0.5f, 0.5f, 1.00f);
	colors[ImGuiCol_Header] = ImVec4(0.90f, 0.90f, 0.90f, 0.45f);
	colors[ImGuiCol_HeaderHovered] = ImVec4(0.6f, 0.6f, 0.6f, 0.80f);
	colors[ImGuiCol_HeaderActive] = ImVec4(0.53f, 0.53f, 0.53f, 0.80f);
	colors[ImGuiCol_Separator] = ImVec4(0.50f, 0.50f, 0.50f, 0.60f);
	colors[ImGuiCol_SeparatorHovered] = ImVec4(0.60f, 0.60f, 0.60f, 1.00f);
	colors[ImGuiCol_SeparatorActive] = ImVec4(0.70f, 0.70f, 0.70f, 1.00f);
	colors[ImGuiCol_ResizeGrip] = ImVec4(1.00f, 1.00f, 1.00f, 0.10f);
	colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.78f, 0.78f, 0.78f, 0.60f);
	colors[ImGuiCol_ResizeGripActive] = ImVec4(0.78f, 0.78f, 0.78f, 0.90f);
	colors[ImGuiCol_Tab] = colors[ImGuiCol_Header];
	colors[ImGuiCol_TabHovered] = colors[ImGuiCol_HeaderHovered];
	colors[ImGuiCol_TabActive] = colors[ImGuiCol_TitleBgActive];	  // ImLerp(colors[ImGuiCol_HeaderActive], colors[ImGuiCol_TitleBgActive], 0.60f);
	colors[ImGuiCol_TabUnfocused] = colors[ImGuiCol_TitleBg];		  // ImLerp(colors[ImGuiCol_Tab], colors[ImGuiCol_TitleBg], 0.80f);
	colors[ImGuiCol_TabUnfocusedActive] = colors[ImGuiCol_TabActive]; // ImLerp(colors[ImGuiCol_TabActive], colors[ImGuiCol_TitleBg], 0.40f);
	colors[ImGuiCol_PlotLines] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.90f, 0.90f, 0.90f, 1.00f);
	colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.90f, 0.90f, 1.00f);
	colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	colors[ImGuiCol_TableHeaderBg] = ImVec4(0.27f, 0.27f, 0.27f, 1.00f);
	colors[ImGuiCol_TableBorderStrong] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f); // Prefer using Alpha=1.0 here
	colors[ImGuiCol_TableBorderLight] = ImVec4(0.26f, 0.26f, 0.26f, 1.00f);	 // Prefer using Alpha=1.0 here
	colors[ImGuiCol_TableRowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.00f, 1.00f, 1.00f, 0.07f);
	colors[ImGuiCol_TextSelectedBg] = ImVec4(0.00f, 1.00f, 1.00f, 0.35f);
	colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
	colors[ImGuiCol_NavHighlight] = colors[ImGuiCol_HeaderHovered];
	colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
	colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
	colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.20f, 0.20f, 0.20f, 0.35f);
}

static bool show_demo_window = true;
static bool show_another_window = false;
static ImVec4 clear_color = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
static std::array<std::string, 3> line_thickness_names = {"volumes", "joint_area", "joint_geometry"};
static std::array<int, 3> line_thickness = {1, 10, 10};
static float line_colors_0[4] = {0, 0, 0, 0};
static float line_colors_1[4] = {1.0f, 0.2f, 0.5f, 0.0f};
static float line_colors_2[4] = {0, 0.5, 1, 0};
static bool lock = 0, wf_mode = 0;
static int render_type = 0;

inline void start_imgui(const char *&glsl_version, GLFWwindow *&window);
inline void loop_start_imgui();
inline void loop_middle_imgui();
inline void loop_end_imgui(GLFWwindow *&window);
inline void end_imgui();

/**
 * @brief Initializes the Dear ImGui context, sets up the style, and prepares the rendering backends.
 *
 * This function sets up the Dear ImGui context, initializes the style by calling `StyleColorsCustom`, and
 * prepares the GLFW and OpenGL backends for use with ImGui. It also configures the font size based on the
 * current display's DPI scale to ensure consistent appearance across different screen resolutions.
 *
 * @param glsl_version A reference to a string containing the GLSL version used for the shaders.
 * @param window A pointer to the GLFWwindow structure that represents the current window context.
 */
inline void start_imgui(const char *&glsl_version, GLFWwindow *&window)
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO &io = ImGui::GetIO();

	StyleColorsCustom();

	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init(glsl_version);

	float dpiScale = io.DisplayFramebufferScale.x;
	float fontSize = 24.0f * dpiScale; // Adjust based on DPI scale

	ImFontConfig fontConfig;
	fontConfig.SizePixels = fontSize;
	io.Fonts->AddFontDefault(&fontConfig);

	io.Fonts->Build();

	float uiScaleFactor = 1.0f; // Adjust UI scale factor as needed
	ImGuiStyle &style = ImGui::GetStyle();
	style.ScaleAllSizes(uiScaleFactor);
}

/**
 * @brief Starts a new Dear ImGui frame.
 *
 * This function prepares the rendering backends for a new ImGui frame and starts a new frame.
 * It should be called at the beginning of each rendering loop to ensure that ImGui widgets and
 * elements can be drawn correctly for the current frame.
 */
inline void loop_start_imgui()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

/**
 * @brief Renders the middle section of the ImGui interface, including camera controls, joint parameter adjustments, and output geometry selection.
 *
 * This function creates a side menu bar that adapts to different resolutions by using the display's DPI scale factor. It provides users with
 * controls for camera settings, allowing for the selection of different camera perspectives and orientations. Additionally, it offers sliders
 * for adjusting parameters related to joint properties and selecting the type of geometry to output. The function ensures that UI elements
 * are scaled appropriately for visibility across various display settings.
 */
inline void loop_middle_imgui()
{
	// Determine scale factor for consistent UI across different resolutions
	float dpiScale = ImGui::GetIO().DisplayFramebufferScale.x;

	// Calculate dimensions relative to screen size and DPI scale
	float menuWidth = 600 * dpiScale;				   // Set menu width to 200 pixels adjusted by DPI scale
	float windowHeight = ImGui::GetIO().DisplaySize.y; // Full height of the window

	// Set the position and size of the menu bar to be DPI-aware and screen size independent
	ImGui::SetNextWindowPos(ImVec2(ImGui::GetIO().DisplaySize.x - menuWidth, 0));
	ImGui::SetNextWindowSize(ImVec2(menuWidth, windowHeight));

	// Begin the ImGui window with DPI-aware flags
	bool my_tool_active;
	ImGui::Begin("UI", &my_tool_active, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_MenuBar);

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// CAMERA
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	ImGui::Text("%.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);

	if (ImGui::Button("pe", ImVec2(40, 40)))
	{
		opengl_cameras::cam_type = opengl_cameras::CAMERA_ARCBALL_PERSPECTIVE;
	}
	ImGui::SameLine();
	if (ImGui::Button("or", ImVec2(40, 40)))
	{
		opengl_cameras::cam_type = opengl_cameras::CAMERA_ARCBALL_ORTHO;
		ImGui::SameLine();
	}
	ImGui::SameLine();
	if (ImGui::Button("to", ImVec2(40, 40)))
	{
		opengl_cameras::cam_type = opengl_cameras::CAMERA_ARCBALL_ORTHO_TOP;
		opengl_cameras::set_camera();
	}
	ImGui::SameLine();
	if (ImGui::Button("bo", ImVec2(40, 40)))
	{
		opengl_cameras::cam_type = opengl_cameras::CAMERA_ARCBALL_ORTHO_BOTTOM;
		opengl_cameras::set_camera();
	}
	ImGui::SameLine();
	if (ImGui::Button("le", ImVec2(40, 40)))
	{
		opengl_cameras::cam_type = opengl_cameras::CAMERA_ARCBALL_ORTHO_LEFT;
		opengl_cameras::set_camera();
	}
	ImGui::SameLine();
	if (ImGui::Button("ri", ImVec2(40, 40)))
	{
		opengl_cameras::cam_type = opengl_cameras::CAMERA_ARCBALL_ORTHO_RIGHT;
		opengl_cameras::set_camera();
	}
	ImGui::SameLine();
	if (ImGui::Button("fr", ImVec2(40, 40)))
	{
		opengl_cameras::cam_type = opengl_cameras::CAMERA_ARCBALL_ORTHO_FRONT;
		opengl_cameras::set_camera();
	}
	ImGui::SameLine();
	if (ImGui::Button("ba", ImVec2(40, 40)))
	{
		opengl_cameras::cam_type = opengl_cameras::CAMERA_ARCBALL_ORTHO_BACK;
		opengl_cameras::set_camera();
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// JOINTS_PARAMETERS_AND_TYPES
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if (ImGui::CollapsingHeader("DIVISION LENGTH VALUES"))
	{

		// Set shift value
		ImGui::TextColored(ImVec4(0, 0, 0, 1), "\nSELECT DIVISION LENGTH VALUE");
		for (int i = 0; i < wood::globals::JOINT_NAMES.size(); i++)
		{
			float joint_type = (float)wood::globals::JOINTS_PARAMETERS_AND_TYPES[i * 3 + 0];
			ImGui::SliderFloat((wood::globals::JOINT_NAMES[i] + " division_length").c_str(), &joint_type, 0.1, 400);
			wood::globals::JOINTS_PARAMETERS_AND_TYPES[i * 3 + 0] = (double)joint_type;
		}
	}

	// IMGUI_DEMO_MARKER("Help");
	if (ImGui::CollapsingHeader("SHIFT VALUES"))
	{

		// Set shift value
		ImGui::TextColored(ImVec4(0, 0, 0, 1), "\nSELECT SHIFT VALUE");
		for (int i = 0; i < wood::globals::JOINT_NAMES.size(); i++)
		{
			float joint_type = (float)wood::globals::JOINTS_PARAMETERS_AND_TYPES[i * 3 + 1];
			ImGui::SliderFloat((wood::globals::JOINT_NAMES[i] + " shift").c_str(), &joint_type, 0.0, 1.0);
			wood::globals::JOINTS_PARAMETERS_AND_TYPES[i * 3 + 1] = (double)joint_type;
		}
	}
	// Select joint Types - Sliders
	ImGui::TextColored(ImVec4(0, 0, 0, 1), "\nSELECT JOINT TYPE");
	for (int i = 0; i < wood::globals::JOINT_NAMES.size(); i++)
	{
		int joint_type = (int)wood::globals::JOINTS_PARAMETERS_AND_TYPES[i * 3 + 2];
		ImGui::SliderInt(wood::globals::JOINT_NAMES[i].c_str(), &joint_type, i * 10, (i * 10 + 10) - 1);
		wood::globals::JOINTS_PARAMETERS_AND_TYPES[i * 3 + 2] = (double)joint_type;
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// OUTPUT_GEOMETRY_TYPE
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Run, the code below set the state_chaged bool so that the code is rerun inside render pipeline, by calling the function pointer
	ImGui::TextColored(ImVec4(0, 0, 0, 1), "\nJOINT GEOMETRY \n0 - joint area \n1 - joint lines \n2 - joint volumes \n3 - joint geometry \n4 - merge joints");

	// Search type
	ImGui::SliderInt("", &wood::globals::OUTPUT_GEOMETRY_TYPE, 0, 5);

	// wood::globals::RUN = ImGui::Button("run", ImVec2(100, 100)); // Buttons return true when clicked (most widgets return true when edited/activated)
	if (ImGui::Button("run", ImVec2(100, 100)))
	{
		opengl_globals::state_changed = true;
		wood::globals::RUN_COUNT++;
		std::cout << "imgui_render -> restart \n";
	}

	ImGui::End();
}

/**
 * @brief Renders the ImGui frame and updates the display.
 *
 * This function should be called at the end of each ImGui frame. It handles the rendering of ImGui draw data
 * to the OpenGL context and updates the display with the new frame. It also sets the OpenGL viewport
 * to match the current window size.
 *
 * @param window A pointer to the GLFWwindow structure that represents the current window context.
 */
inline void loop_end_imgui(GLFWwindow *&window)
{
	// Render ImGui draw data to the OpenGL context
	ImGui::Render();

	// Obtain the current framebuffer size
	int display_w, display_h;
	glfwGetFramebufferSize(window, &display_w, &display_h);

	// Set the OpenGL viewport to match the framebuffer size
	glViewport(0, 0, display_w, display_h);

	// Pass the ImGui draw data to the OpenGL3 renderer to render the ImGui frame
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

/**
 * @brief Cleans up ImGui resources upon application termination.
 *
 * This function releases all ImGui resources and properly shuts down ImGui, the ImGui GLFW backend,
 * and the ImGui OpenGL3 backend. It should be called before the application exits and after the
 * rendering loop has ended to ensure a clean exit and release of all allocated resources.
 */
inline void end_imgui()
{
	// Shut down ImGui OpenGL3 backend
	ImGui_ImplOpenGL3_Shutdown();

	// Shut down ImGui GLFW backend
	ImGui_ImplGlfw_Shutdown();

	// Destroy the ImGui context and free associated resources
	ImGui::DestroyContext();
}
