include(GenerateExportHeader)

include_directories(${CMAKE_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

add_library(testlib SHARED testlib.cpp)
generate_export_header(testlib)

add_executable(LibraryLoadTest catchmain.cpp loadtest.cpp)
target_link_libraries(LibraryLoadTest loader)

add_test(Test1 LibraryLoadTest)
