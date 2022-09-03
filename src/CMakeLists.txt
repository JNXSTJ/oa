# for each "src/x.cpp", generate target "x"
file(GLOB_RECURSE all_srcs *.cpp)
foreach(v ${all_srcs})
    string(REGEX MATCH "src/.*" relative_path ${v})
    message(${relative_path})
    message(${v})
    string(REGEX REPLACE "src/leetcode/[0-9]*/" "" target_name ${relative_path})
    string(REGEX REPLACE "src/leetcode/" "" target_name ${target_name})
    string(REGEX REPLACE "src/" "" target_name ${target_name})
    string(REGEX REPLACE ".cpp" "" target_name ${target_name})

    string(REGEX REPLACE "/[a-zA-Z0-9].cpp" "" relative_path ${relative_path})

    message(${relative_path})
    message(${target_name})
    SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY build/${relative_path})
    message(${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
    add_executable(${target_name} ${v})
endforeach()
