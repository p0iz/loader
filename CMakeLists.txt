cmake_minimum_required(VERSION 3.0)

project(loader)

enable_testing()

add_subdirectory(test)

# public includes
include_directories(include)
install(DIRECTORY include DESTINATION include)

# Ensure we use the correct OS calls
if (WIN32)
	set(OsSuffix "w32")
else()
	set(OsSuffix "posix")
endif()

add_library(loader src/library.cpp src/library_${OsSuffix}.cpp)
install(TARGETS loader DESTINATION lib)
