# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\pelicula_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\pelicula_autogen.dir\\ParseCache.txt"
  "pelicula_autogen"
  )
endif()
