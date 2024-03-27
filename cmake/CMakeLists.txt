########################################################################
# PROPERTIES
########################################################################
cmake_minimum_required(VERSION 3.24.2)

set(COMPILER_NINJA OFF)

if(WIN32)
  string(ASCII 27 Esc)
  set(ColourReset "${Esc}[m")
  set(ColourBold  "${Esc}[1m")
  set(Red         "${Esc}[31m")
  set(Green       "${Esc}[32m")
  set(Yellow      "${Esc}[33m")
  set(Blue        "${Esc}[34m")
  set(Magenta     "${Esc}[35m")
  set(Cyan        "${Esc}[36m")
  set(White       "${Esc}[37m")
  set(BoldRed     "${Esc}[1;31m")
  set(BoldGreen   "${Esc}[1;32m")
  set(BoldYellow  "${Esc}[1;33m")
  set(BoldBlue    "${Esc}[1;34m")
  set(BoldMagenta "${Esc}[1;35m")
  set(BoldCyan    "${Esc}[1;36m")
  set(BoldWhite   "${Esc}[1;37m")
endif()


if(COMPILER_NINJA)
 set(CMAKE_MAKE_PROGRAM "C:\\Ninja\\ninja.exe" CACHE FILEPATH "" FORCE)
endif()

project(wood LANGUAGES C CXX)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
cmake_policy(SET CMP0097 NEW)
# Set global property (all targets are impacted)
set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CMAKE_COMMAND} -E time")

# debug
set(RELEASE_DEBUG "" CACHE STRING "DEBUG to true ")
if(RELEASE_DEBUG)
  message("${BoldBlue} RELEASE IS BEING CONFIGURED ${ColourReset}" )
  set(CMAKE_BUILD_TYPE_INIT "Release")
else()
  message("${BoldBlue} AUTHOR_WARNING DEBUG IS BEING CONFIGURED ${ColourReset}" )
  set(CMAKE_C_FLAGS_DEBUG "-g -DDEBUG")
  set(CMAKE_CXX_FLAGS_DEBUG "-g -DDEBUG")
endif()





########################################################################
#
# START SUPERBUILD - DOWNLOAD LIBRARIES FROM GITHUB REPOSIROTRIES
#
########################################################################
#cmake_policy(SET CMP0097 NEW)
cmake_policy(SET CMP0135 NEW)
include(ExternalProject)



SET(GET_LIBS "" CACHE STRING "Set option to download dependencies")
if (GET_LIBS)
  message(AUTHOR_WARNING "GET_LIBS_" ${GET_LIBS})

  #######################################################################
  # CDT
  ####################################################################### 
  ExternalProject_Add(cdt
  GIT_REPOSITORY    https://github.com/artem-ogre/CDT.git
  GIT_TAG           master
      CMAKE_ARGS
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}
        #-DCMAKE_INSTALL_PREFIX:PATH="${CMAKE_BINARY_DIR}/install"
      SOURCE_DIR   "${CMAKE_BINARY_DIR}/install/cdt/"
        #INSTALL_DIR   "${CMAKE_INSTALL_PREFIX}/install"
      CONFIGURE_COMMAND "" #do not configure
      BUILD_COMMAND "" #do not buld
      INSTALL_COMMAND "" #installer for now is empty
  )

  #######################################################################
  # CLIPPER2
  ####################################################################### 
  ExternalProject_Add(clipper_2
      GIT_REPOSITORY https://github.com/AngusJohnson/Clipper2.git
      GIT_TAG main
      CMAKE_ARGS
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}
        #-DCMAKE_INSTALL_PREFIX:PATH="${CMAKE_BINARY_DIR}/install"
      SOURCE_DIR   "${CMAKE_BINARY_DIR}/install/clipper_2"
        #INSTALL_DIR   "${CMAKE_INSTALL_PREFIX}/install"
      CONFIGURE_COMMAND "" #do not configure
      BUILD_COMMAND "" #do not buld
      INSTALL_COMMAND "" #installer for now is empty
  )




########################################################################
# CGAL
######################################################################## 

ExternalProject_Add(cgal
  URL https://github.com/CGAL/cgal/releases/download/v5.5.1/CGAL-5.5.1-library.zip
  #GIT_REPOSITORY https://github.com/CGAL/cgal.git
  #GIT_TAG v5.4.1
  CMAKE_ARGS
    -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
    -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}
    #-DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_INSTALL_PREFIX}
  SOURCE_DIR   "${CMAKE_BINARY_DIR}/install/cgal"
  BUILD_ALWAYS "" #do not build
  INSTALL_COMMAND "" #installer for now is empty
)


ExternalProject_Add(cgal_auxiliary
  URL https://github.com/CGAL/cgal/releases/download/v5.5/CGAL-5.5-win64-auxiliary-libraries-gmp-mpfr.zip
  CMAKE_ARGS
    -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
    -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}
    #-DCMAKE_INSTALL_PREFIX:PATH="${CMAKE_BINARY_DIR}/install"
  SOURCE_DIR   "${CMAKE_BINARY_DIR}/install/cgal/auxiliary"
    #INSTALL_DIR   "${CMAKE_INSTALL_PREFIX}/install"
  CONFIGURE_COMMAND "" #do not configure
  BUILD_COMMAND "" #do not build
  INSTALL_COMMAND "" #installer for now is empty
)
  message("${BoldBlue} ${CMAKE_BINARY_DIR}/install/cgal/auxiliary ${ColourReset}" )



########################################################################
# BOOST
########################################################################
ExternalProject_Add(boost
  URL https://boostorg.jfrog.io/artifactory/main/release/1.78.0/source/boost_1_78_0.tar.gz
  CONFIGURE_COMMAND ""
  BUILD_COMMAND ""
  INSTALL_COMMAND ${CMAKE_COMMAND} -E copy_directory <SOURCE_DIR>/boost ${CMAKE_BINARY_DIR}/install/boost/include/boost
)


########################################################################
# EIGEN
######################################################################## 
  ExternalProject_Add(eigen
    GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
    GIT_TAG 3.4.0
    CMAKE_ARGS
      -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
      -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}
      -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/install/eigen #has not effect
    SOURCE_DIR   "${CMAKE_BINARY_DIR}/install/eigen" #install directory is in build/install/eigen
    BUILD_COMMAND "" #do not build
    INSTALL_COMMAND "" #do not install
  )
########################################################################
# GOOGLETEST ///googletest/include
######################################################################## 
set(GOOGLE_TEST_OS "")
if (WIN32)
    set(GOOGLE_TEST_OS "$<$<PLATFORM_ID:Windows>:-Dgtest_force_shared_crt:BOOL=ON>")
endif (WIN32)

        unset(GTEST_ROOT CACHE)
         unset(GMOCK_ROOT CACHE)
         ExternalProject_Add(googletest
             GIT_REPOSITORY https://github.com/google/googletest.git
             GIT_TAG 58d77fa8070e8cec2dc1ed015d66b454c8d78850
             PREFIX ${CMAKE_BINARY_DIR}/install/googletest
             INSTALL_DIR ${CMAKE_BINARY_DIR}/install/googletest
             CMAKE_ARGS
                 -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
		 ${GOOGLE_TEST_OS} #$<$<PLATFORM_ID:Windows>:-Dgtest_force_shared_crt:BOOL=ON>
             BUILD_COMMAND
                 COMMAND ${CMAKE_COMMAND} --build <BINARY_DIR> --config Release --target install
                # COMMAND ${CMAKE_COMMAND} --build <BINARY_DIR> --config Debug --target install
             INSTALL_COMMAND  ""
             )
         set(GTEST_ROOT ${CMAKE_BINARY_DIR}/install/googletest CACHE PATH "" FORCE)
         set(GMOCK_ROOT ${CMAKE_BINARY_DIR}/install/googletest CACHE PATH "" FORCE)



endif ()



########################################################################
#
# CONFIGURE THE PROJECT
#
########################################################################

###############################################################################
#EXECUTABLE LINK HEADER ONLY DIRECTORY
###############################################################################
SET(BUILD_MY_PROJECTS "" CACHE STRING "Build Project")
if (BUILD_MY_PROJECTS)
  message("${BoldBlue} BUILD_MY_PROJECTS_ ${BUILD_MY_PROJECTS} ${ColourReset}" )

  ###############################################################################
  # CREATE EXE
  ###############################################################################
  add_executable(${PROJECT_NAME} main.cpp 
  "${CMAKE_SOURCE_DIR}/src/wood/include/wood_globals.cpp"
  "${CMAKE_SOURCE_DIR}/src/wood/include/cgal_box_util.cpp"
  "${CMAKE_SOURCE_DIR}/src/wood/include/rtree_util.cpp"
  "${CMAKE_SOURCE_DIR}/src/wood/include/cgal_inscribe_util.cpp"
  "${CMAKE_SOURCE_DIR}/src/wood/include/cgal_intersection_util.cpp"
  "${CMAKE_SOURCE_DIR}/src/wood/include/cgal_xform_util.cpp"
  "${CMAKE_SOURCE_DIR}/src/wood/include/cgal_math_util.cpp"
  "${CMAKE_SOURCE_DIR}/src/wood/include/cgal_plane_util.cpp"
  "${CMAKE_SOURCE_DIR}/src/wood/include/cgal_polyline_mesh_util.cpp"
  "${CMAKE_SOURCE_DIR}/src/wood/include/cgal_polyline_util.cpp"
  "${CMAKE_SOURCE_DIR}/src/wood/include/cgal_rectangle_util.cpp"
  "${CMAKE_SOURCE_DIR}/src/wood/include/cgal_vector_util.cpp"
  "${CMAKE_SOURCE_DIR}/src/wood/include/clipper_util.cpp"
  "${CMAKE_SOURCE_DIR}/src/wood/include/wood_element.cpp"
  "${CMAKE_SOURCE_DIR}/src/wood/include/wood_joint.cpp"
  "${CMAKE_SOURCE_DIR}/src/wood/include/wood_joint_lib.cpp"
  "${CMAKE_SOURCE_DIR}/src/wood/include/wood_test.cpp"
  "${CMAKE_SOURCE_DIR}/src/wood/include/wood_main.cpp"
  "${CMAKE_SOURCE_DIR}/src/wood/include/wood_xml.cpp"
  "${CMAKE_SOURCE_DIR}/src/wood/include/cgal_mesh_boolean.cpp"
  "${CMAKE_SOURCE_DIR}/src/wood/include/database_writer.cpp"
  ) 
  
  ###############################################################################
  # PCH support
  ###############################################################################
  message("${BoldBlue}  PRECOMPILED HEADER ${ColourReset}")
  target_precompile_headers(${PROJECT_NAME} PRIVATE  stdafx.h) # With PUBLIC they will be used by targets using this target
  #target_precompile_headers(${PROJECT_NAME} PRIVATE   "C:/IBOIS57/_Code/Software/CPP/CMAKE/super_build/compas_wood/build_win/CMakeFiles/compas_wood.dir/Release/cmake_pch.hxx")
  set(CMAKE_PCH_INSTANTIATE_TEMPLATES ON)

  ###############################################################################
  # LIBRARIES
  ###############################################################################

  ###############################################################################
  # OPENGL
  ###############################################################################
  find_package(OpenGL REQUIRED)

  ###############################################################################
  # LINK HEADERS TO EXE
  # check path:
  # message(AUTHOR_WARNING "${CMAKE_SOURCE_DIR}/viewer/include/stb")
  ###############################################################################

  list(APPEND petras_include_paths 
  #my_code
  "${CMAKE_SOURCE_DIR}/src/wood/include/"
  #cdt
  "${CMAKE_BINARY_DIR}/install/cdt/CDT/include/"
  #clipper
  "${CMAKE_BINARY_DIR}/install/clipper_2/CPP/Clipper2Lib/include/"
  #boost
  "${CMAKE_BINARY_DIR}/install/boost/include/"
  #eigen
  "${CMAKE_BINARY_DIR}/install/eigen/"
  #cgal
  "${CMAKE_BINARY_DIR}/install/cgal/include"
  "${CMAKE_BINARY_DIR}/install/cgal/auxiliary/gmp/include"
  #"C:/msys64/mingw64/lib/" #GCC
  #googletest
  "${CMAKE_BINARY_DIR}/install/googletest/include/"
  # SQLite
  "${CMAKE_SOURCE_DIR}/src/sqlite/"
  )

  message("${BoldBlue} Include directories: ${petras_include_paths}")

  target_include_directories(${PROJECT_NAME} PUBLIC "$<BUILD_INTERFACE:${petras_include_paths}>") #header for the library

  ###############################################################################
  # LINK LIBRARIES TO EXE, STATIC LIBRARIES PATHS MUST BE AT THE END
  ###############################################################################
  if(COMPILER_NINJA)
      message("${BoldBlue} COMPILER_NINJA ${ColourReset}")
      target_link_libraries(${PROJECT_NAME} PUBLIC 
      Clipper2 
      gmp
      mpfr
      gtest
      gmock
      sqlite3
      ) 

  else()
    message("${BoldBlue} COMPILER_MSVC ${ColourReset}")
    target_link_libraries(${PROJECT_NAME} PUBLIC 
      Clipper2 
      libgmp-10
      libmpfr-4
      gtest
      gmock
      sqlite3
    ) 


  endif()



  ###############################################################################
  # CGAL
  ###############################################################################
  #target_link_libraries(${PROJECT_NAME} PUBLIC "${CMAKE_BINARY_DIR}/install/cgal/auxiliary/gmp/lib/" ) # WINDOWS
  if(COMPILER_NINJA)
    target_link_directories(${PROJECT_NAME} PUBLIC "C:/msys64/mingw64/lib/" )
  else()
    target_link_directories(${PROJECT_NAME} PUBLIC "${CMAKE_BINARY_DIR}/install/cgal/auxiliary/gmp/lib/" )
  endif()

  ###############################################################################
  # GOOGLETEST
  ###############################################################################
  target_link_directories(${PROJECT_NAME} PUBLIC "${CMAKE_BINARY_DIR}/install/googletest/lib/" )

  ###############################################################################
  # All the build libraries such as Clipper2
  ###############################################################################
  target_link_directories(${PROJECT_NAME} PUBLIC "${CMAKE_BINARY_DIR}/Release/" )




endif ()


########################################################################
#
# COMPILE LIBRARIES TO REDUCE BUILD TIME
#
########################################################################
SET(COMPILE_LIBS "" CACHE STRING "Set option to compile dependencies")
if (COMPILE_LIBS)


  ###############################################################################
  # CLIPPER
  ###############################################################################
  set(CLIPPER2_INC
  "${CMAKE_BINARY_DIR}/install/clipper_2/CPP/Clipper2Lib/include/clipper2/clipper.core.h"
  "${CMAKE_BINARY_DIR}/install/clipper_2/CPP/Clipper2Lib/include/clipper2/clipper.engine.h"
  "${CMAKE_BINARY_DIR}/install/clipper_2/CPP/Clipper2Lib/include/clipper2/clipper.h"
  "${CMAKE_BINARY_DIR}/install/clipper_2/CPP/Clipper2Lib/include/clipper2/clipper.minkowski.h"
  "${CMAKE_BINARY_DIR}/install/clipper_2/CPP/Clipper2Lib/include/clipper2/clipper.offset.h"
 )

  set(CLIPPER2_SRC
  "${CMAKE_BINARY_DIR}/install/clipper_2/CPP/Clipper2Lib/src/clipper.engine.cpp"
  "${CMAKE_BINARY_DIR}/install/clipper_2/CPP/Clipper2Lib/src/clipper.offset.cpp"
  )

  add_library(Clipper2 STATIC ${CLIPPER2_INC} ${CLIPPER2_SRC}  )
  target_include_directories(Clipper2  PUBLIC "${CMAKE_BINARY_DIR}/install/clipper_2/CPP/Clipper2Lib/include/") #link headers to clipper library



  ###############################################################################
  # CGAL
  ###############################################################################
  #target_link_libraries(${PROJECT_NAME} PUBLIC "${CMAKE_BINARY_DIR}/install/cgal/auxiliary/gmp/lib/" ) # WINDOWS
  if(COMPILER_NINJA)
    target_link_directories(${PROJECT_NAME} PUBLIC "C:/msys64/mingw64/lib/" )
  else()
    target_link_directories(${PROJECT_NAME} PUBLIC "${CMAKE_BINARY_DIR}/install/cgal/auxiliary/gmp/lib/" )
  endif()

  
  if(NOT COMPILER_NINJA)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD        # Adds a post-build event to MyTest
      COMMAND ${CMAKE_COMMAND} -E copy_if_different  # which executes "cmake - E copy_if_different..."
          "${CMAKE_BINARY_DIR}/install/cgal/auxiliary/gmp/lib/libgmp-10.dll"      # <--this is in-file
          "${CMAKE_BINARY_DIR}/Release")                 # <--this is out-file path

    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD        # Adds a post-build event to MyTest
      COMMAND ${CMAKE_COMMAND} -E copy_if_different  # which executes "cmake - E copy_if_different..."
          "${CMAKE_BINARY_DIR}/install/cgal/auxiliary/gmp/lib/libmpfr-4.dll"      # <--this is in-file
          "${CMAKE_BINARY_DIR}/Release")                 # <--this is out-file path
  endif()


  ###############################################################################
  # SQLITE
  ###############################################################################
  message( "${CMAKE_SOURCE_DIR}/src/sqlite/sqlite3.c")
  add_library(sqlite3 STATIC "${CMAKE_SOURCE_DIR}/src/sqlite/sqlite3.c"  )
  target_include_directories(sqlite3 PUBLIC "${CMAKE_SOURCE_DIR}/src/sqlite/") #link headers to sqlite library


endif ()


