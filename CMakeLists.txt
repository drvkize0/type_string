cmake_minimum_required( VERSION 3.8 )

project( type_string_test )

set( TARGET_NAME test )

add_executable( ${TARGET_NAME} "main.cpp" )

set_target_properties( ${TARGET_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO

    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}
)

