cmake_minimum_required(VERSION 3.14)

set(WARNING_FLAGS
  $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Werror -Wundef>
  $<$<CXX_COMPILER_ID:GNU>:-Wuseless-cast -Wmaybe-uninitialized>
  $<$<CXX_COMPILER_ID:MSVC>:/W4 /permissive->
)

set(PROJECT_NAME
  # TODO: Name project
  tmp_project_name
)

project(${PROJECT_NAME} LANGUAGES C CXX)

# TODO: Replace all tmp_exe with new name
add_executable(tmp_exe
  # TODO: Add exe source files
)

# TODO: Replace all tmp_lib with new name
add_library(tmp_lib
  SHARED
  # TODO: Add lib source files
)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  # TODO: Update git tag
  GIT_TAG        52eb8108c5bdec04579160ae17225d66034bd723
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

FetchContent_Declare(
  googlebenchmark
  GIT_REPOSITORY https://github.com/google/benchmark.git
  # TODO: Update git tag
  GIT_TAG        192ef10025eb2c4cdd392bc502f0c852196baa48
)
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "" FORCE)
set(BENCHMARK_ENABLE_GTEST_TESTS OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googlebenchmark)

enable_testing()

add_executable(tmp_test
  # TODO: Add test source files
)

target_link_libraries(tmp_test
  PRIVATE
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(tmp_test)

# TODO: Replace all tmp_benchmark with new name
add_executable(tmp_benchmark
  # TODO: Add benchmark source files
)

target_link_libraries(tmp_benchmark
  PRIVATE
  benchmark::benchmark
  benchmark::benchmark_main
)

set(SAN_FLAGS
  -fsanitize=address,undefined
  -fno-omit-frame-pointer
  # (optional) -fsanitize=thread
  -g
)

add_library(project_defaults INTERFACE)

target_include_directories(tmp_lib
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

target_link_libraries(tmp_exe PRIVATE project_defaults tmp_lib)
target_link_libraries(tmp_lib PRIVATE project_defaults)
target_link_libraries(tmp_test PRIVATE project_defaults tmp_lib)
target_link_libraries(tmp_benchmark PRIVATE project_defaults tmp_lib)
