project(hash_lib)

add_library(hash_lib
SHARED
hash.h
hash.c
)

add_executable(hash_test hash_test.c)

target_link_libraries(hash_test hash_lib)
