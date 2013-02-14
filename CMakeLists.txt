project(monopoly)
include_directories(src/ rapidxml/)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -g")
file(GLOB_RECURSE
		source_files
		src/*)

add_executable(
		monopoly
		${source_files}
		)
target_link_libraries(
		monopoly
		sfml-system
		sfml-window
		sfml-graphics
		sfml-audio
		)
