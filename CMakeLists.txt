cmake_minimum_required(VERSION 3.1...3.23)
project(vector)

set(
  SOURCES
  src/main.c
  src/vector.c
)

add_executable(vector ${SOURCES})

# target_include_directories(
#   vector
#   PRIVATE
#   ${PROJECT_SOURCE_DIR}/include
# )

target_include_directories(
  vector
  PRIVATE
  ${PROJECT_SOURCE_DIR}/src
)
