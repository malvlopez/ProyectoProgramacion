# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ProyectoProgramacion_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ProyectoProgramacion_autogen.dir\\ParseCache.txt"
  "ProyectoProgramacion_autogen"
  )
endif()
