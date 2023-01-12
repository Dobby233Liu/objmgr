cmake_minimum_required(VERSION 3.11)

project(objmgr)

add_library(objmgr OBJECT
  src/objmgr/objmgr.c
  src/objmgr/objapi.c
)
target_include_directories(objmgr PUBLIC include)

add_executable(test
  src/test/objdefs/objdefs.c
  src/test/objdefs/obj_loop_5_then_remove_self.c
  src/test/objdefs/obj_noop.c
  src/test/tests.c
  src/test/hash.c
  src/test/main.c
)
target_link_libraries(test PUBLIC objmgr)
target_include_directories(test PUBLIC libs/uthash/src)

set_property(
  TARGET objmgr test
  PROPERTY C_STANDARD_REQUIRED 99
)

add_test(NAME l5trs_single COMMAND test l5trs_single)
