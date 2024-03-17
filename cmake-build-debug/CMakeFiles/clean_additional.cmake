# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Catch-the-ball_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Catch-the-ball_autogen.dir/ParseCache.txt"
  "Catch-the-ball_autogen"
  )
endif()
