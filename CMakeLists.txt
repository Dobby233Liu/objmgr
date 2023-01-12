cmake_minimum_required(VERSION 3.11)

project(objmgr)

add_library(objmgr OBJECT
  src/objmgr/objmgr.c
  src/objmgr/objapi.c
)
target_include_directories(objmgr PUBLIC include)

add_library(objects OBJECT
  src/objdefs/objdefs.c
  src/objdefs/object01.c
)
target_link_libraries(objects PUBLIC objmgr)

add_executable(objmgr_demo
  src/demo.c
)
target_link_libraries(objmgr_demo PUBLIC objmgr objects)

set_property(
  TARGET objmgr objects objmgr_demo
  PROPERTY C_STANDARD_REQUIRED 99
)
