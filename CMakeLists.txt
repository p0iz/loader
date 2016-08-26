cmake_minimum_required(VERSION 3.0)

project(loader)

enable_testing()

add_subdirectory(test)

# public includes
include_directories(include)
install(DIRECTORY include DESTINATION include)

# Ensure we use the correct OS calls
if(WIN32)
	set(OsSuffix "w32")
elseif(UNIX)
	set(OsSuffix "posix")
else()
	message(FATAL_ERROR "Unsupported OS.")
endif()

add_library(loader src/library.cpp src/library_${OsSuffix}.cpp)
if(UNIX)
	target_link_libraries(loader dl)
endif()

install(TARGETS loader DESTINATION lib)
