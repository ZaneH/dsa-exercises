cmake_minimum_required(VERSION 3.14)

set(WARNING_FLAGS
  $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Werror -Wundef>
  $<$<CXX_COMPILER_ID:GNU>:-Wuseless-cast -Wmaybe-uninitialized>
  $<$<CXX_COMPILER_ID:MSVC>:/W4 /permissive->
)

set(PROJECT_NAME
  dsa_exercises
)

project(${PROJECT_NAME} LANGUAGES C CXX)

add_library(dsa_lib
  INTERFACE
)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        52eb8108c5bdec04579160ae17225d66034bd723
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# FetchContent_Declare(
#   googlebenchmark
#   GIT_REPOSITORY https://github.com/google/benchmark.git
#   GIT_TAG        192ef10025eb2c4cdd392bc502f0c852196baa48
# )
# set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "" FORCE)
# set(BENCHMARK_ENABLE_GTEST_TESTS OFF CACHE BOOL "" FORCE)
# FetchContent_MakeAvailable(googlebenchmark)

enable_testing()

add_executable(dsa_test
  tests/ring_buffer/ring_buffer_test.cc
)

target_link_libraries(dsa_test
  PRIVATE
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(dsa_test)

# add_executable(dsa_benchmark
#   # TODO: Add benchmark source files
# )

# target_link_libraries(dsa_benchmark
#   PRIVATE
#   benchmark::benchmark
#   benchmark::benchmark_main
# )

set(SAN_FLAGS
  -fsanitize=address,undefined
  -fno-omit-frame-pointer
  # (optional) -fsanitize=thread
  -g
)

add_library(project_defaults INTERFACE)

target_include_directories(dsa_lib
  INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(project_defaults
  INTERFACE
  cxx_std_20
)
target_compile_options(project_defaults
  INTERFACE
  ${WARNING_FLAGS}
  $<$<CONFIG:Debug>:${SAN_FLAGS}>
)
target_link_options(project_defaults
  INTERFACE
  $<$<CONFIG:Debug>:${SAN_FLAGS}>
)

target_link_libraries(dsa_lib INTERFACE project_defaults)
target_link_libraries(dsa_test PRIVATE project_defaults dsa_lib)
# target_link_libraries(dsa_benchmark PRIVATE project_defaults dsa_lib)
