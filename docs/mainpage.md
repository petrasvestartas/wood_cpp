# Introduction

The timber joinery generation library offers an innovative approach to creating timber joints, catering to both automated collision detection methods and user-defined element connectivity. It provides a versatile platform for generating joints from a catalog of predefined types, with the added flexibility for users to introduce custom joint designs. This capability enables a wide range of applications, from architectural designs to bespoke furniture making, facilitating both simplicity and creativity in timber construction projects.

![Example Image](type_plates_name_side_to_side_edge_inplane_hexshell.png "Example of fingers joints in a hexagonal shell made of plates.")

```cpp
    #include "stdafx.h"
    #include "wood_test.h"

    int main(int argc, char **argv)
    {

        wood_globals::DISTANCE = 0.1;
        wood_globals::DISTANCE_SQUARED = 0.01;
        wood_globals::ANGLE = 0.11;
        wood_globals::OUTPUT_GEOMETRY_TYPE = 4;

        opengl_globals::shader_type_0default_1transparent_2shaded_3shadedwireframe_4wireframe_5normals_6explode = 2;
        opengl_render::render(wood_test::type_plates_name_side_to_side_edge_inplane_hexshell);

        return 0;
    }

```

## Installation

The library is written using C++ and is built using CMake. The following instructions are for Windows, but the library can be built on other platforms as well.

- **Step 1:** Clone the repository: download and install [git](https://git-scm.com/downloads), [cmake](https://cmake.org/download/), and a C++ compiler like [Visual Studio](https://visualstudio.microsoft.com/vs/community/).
- **Step 2:** Open the terminal and move to the directory where you want to install the library, for example:
```bash
    cd C:/brg/2_code/
```
- **Step 3:** Clone the repository
```bash
    git clone https://github.com/petrasvestartas/wood_cpp.git
```

- **Step 4:** Run the install_windows.bat file
```bash
    cd C:/brg/2_code/wood_cpp/
    install_windows.bat
```

## Documentation

The documentation is built using [Doxygen](http://www.doxygen.nl/) and [Doxygen Awesome CSS](https://github.com/jothepro/doxygen-awesome-css). You can find the documentation in the `docs` folder. To build the documentation, execute the following command in the terminal::
- **Step 1:** Download doxygen from [doxygen](https://www.doxygen.nl/download.html) and install it.
- **Step 2:** Run the doxygen using docs.bat file:
```bash
    cd C:/brg/2_code/wood_cpp/
    docs.bat
```
