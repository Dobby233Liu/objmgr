cmake_minimum_required(VERSION 3.11)

project(objmgr)

add_library(objmgr OBJECT
  src/objects/object01.c
  src/objects.c
  src/objmgr.c
)
target_include_directories(objmgr PUBLIC
  include
)
set_property(TARGET objmgr
  PROPERTY C_STANDARD_REQUIRED
  99
)

add_executable(objmgr_demo
  src/demo.c
)
target_link_libraries(objmgr_demo PUBLIC objmgr)
set_property(TARGET objmgr_demo
  PROPERTY C_STANDARD_REQUIRED
  99
)
