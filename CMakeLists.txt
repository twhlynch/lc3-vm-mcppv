cmake_minimum_required(VERSION 3.10)
project(lc3 C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options(-Wall)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)
find_library(MCPP_LIBRARY
			 NAMES mcpp
			 REQUIRED)

include_directories(
	${OPENGL_INCLUDE_DIR}
	${glfw3_INCLUDE_DIR}
	${GLM_INCLUDE_DIRS}
	vendor/glad/include
	vendor/stb_image/include
	/usr/local/include
	/opt/homebrew/include
)

set_source_files_properties(vendor/glad/src/glad.c PROPERTIES LANGUAGE C)
add_library(glad_c STATIC vendor/glad/src/glad.c)

file(GLOB_RECURSE SOURCES
	src/*.cpp
	src/*.c
	src/*.hpp
	src/*.h
)

add_executable(lc3
	${SOURCES}
)

install(TARGETS lc3
	RUNTIME DESTINATION /usr/local/bin
)
install(DIRECTORY assets/
	DESTINATION /usr/local/share/mcppv/assets
)

target_link_libraries(lc3
	${OPENGL_LIBRARIES}
	glfw
	glm::glm
	glad_c
	${MCPP_LIBRARY}
)

# assets
add_custom_command(TARGET lc3 POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E make_directory $<TARGET_FILE_DIR:lc3>/assets
	COMMAND ${CMAKE_COMMAND} -E copy_directory
			${CMAKE_SOURCE_DIR}/assets
			$<TARGET_FILE_DIR:lc3>/assets
)