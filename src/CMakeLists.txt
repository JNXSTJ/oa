# for each "src/x.cpp", generate target "x"
file(GLOB_RECURSE all_srcs *.cpp)
foreach(v ${all_srcs})
    string(REGEX MATCH "src/.*" relative_path ${v})
    message(${relative_path})
    message(${v})
    string(REGEX REPLACE "src/leetcode/[0-9]*/" "" target_name ${relative_path})
    string(REGEX REPLACE "src/" "" target_name ${target_name})
    string(REGEX REPLACE ".cpp" "" target_name ${target_name})

    message(${relative_path})
    message(${target_name})
    add_executable(${target_name} ${v})
endforeach()
