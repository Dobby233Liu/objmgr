cmake_minimum_required(VERSION 3.11)

project(objmgr LANGUAGES C)
enable_testing()

set(CMAKE_C_STANDARD 99)

add_library(objmgr OBJECT
  src/objmgr/objmgr.c
  src/objmgr/objapi.c
)
target_include_directories(objmgr PUBLIC
  include
)

add_executable(tester
  src/test/objdefs/objdefs.c
  src/test/objdefs/obj_loop_5_then_remove_self.c
  src/test/objdefs/obj_noop.c
  src/test/tests.c
  src/test/hash.c
  src/test/main.c
)
target_link_libraries(tester PUBLIC
  objmgr
)
target_include_directories(tester PUBLIC
  libs/uthash/src
)

add_test(
  NAME create_loop_and_destroy
  COMMAND $<TARGET_FILE:tester>
    create_loop_and_destroy
)
