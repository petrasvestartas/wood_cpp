# Introduction

Welcome to the timber joinery [library](https://github.com/petrasvestartas/wood_cpp)!

The library is designed to facilitate the generation of timber joinery. It includes a comprehensive collection of joint configurations intended for placement at the interface zone between a pair of elements. The connectivity between elements can be established through either a collision detection method or by providing the indices of elements where the joint is to be created. Additionally, users have the flexibility to define custom joint shapes, which can be configured for compatibility with CNC milling processes. The installation is described below. For more information check the examples and API.

Ready to start? The installation instructions are below!

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
- **Step 2:** Add sub-module for doxygen-awesome-css in the folder of docs:
```bash
    cd C:/brg/2_code/wood_cpp/docs
    git submodule add --force https://github.com/jothepro/doxygen-awesome-css.git
    cd doxygen-awesome-css
    git checkout v2.3.1
```

- **Step 2:** Run the doxygen using docs.bat file:
```bash
    cd C:/brg/2_code/wood_cpp/
    docs.bat
```