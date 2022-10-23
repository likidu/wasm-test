cmake_minimum_required (VERSION 3.11)

add_subdirectory(smk)

project(kaines
  LANGUAGES CXX
  VERSION 0.1.0
)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/Emulator.cpp
)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Werror)

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME} PRIVATE smk)

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)

# Detect emscripten is used.
if(CMAKE_CXX_COMPILER MATCHES "/em\\+\\+(-[a-zA-Z0-9.])?$") 
  set_property(TARGET ${PROJECT_NAME} APPEND_STRING PROPERTY LINK_FLAGS " -s DEMANGLE_SUPPORT=1")
  set_property(TARGET ${PROJECT_NAME} APPEND_STRING PROPERTY LINK_FLAGS " -s DISABLE_EXCEPTION_CATCHING=2")
  set_property(TARGET ${PROJECT_NAME} APPEND_STRING PROPERTY LINK_FLAGS " -s WASM=1")
  set_property(TARGET ${PROJECT_NAME} APPEND_STRING PROPERTY LINK_FLAGS " -s TOTAL_MEMORY=134217728")

  # Release flags
  # set_property(TARGET ${PROJECT_NAME} APPEND_STRING PROPERTY LINK_FLAGS " --closure 1")
  # set_property(TARGET ${PROJECT_NAME} APPEND_STRING PROPERTY LINK_FLAGS " --js-opts 3")
  # set_property(TARGET ${PROJECT_NAME} APPEND_STRING PROPERTY LINK_FLAGS " --llvm-lto 3")
  # set_property(TARGET ${PROJECT_NAME} APPEND_STRING PROPERTY LINK_FLAGS " --llvm-opts 3")
  set_property(TARGET ${PROJECT_NAME} APPEND_STRING PROPERTY LINK_FLAGS " -O3")
  set_property(TARGET ${PROJECT_NAME} APPEND_STRING PROPERTY LINK_FLAGS " -flto")

  # Copy the index.html file.
  configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/src/index.html
    ${CMAKE_CURRENT_BINARY_DIR}/index.html
  )

  configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/src/style.css
    ${CMAKE_CURRENT_BINARY_DIR}/style.css
  )
endif()

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)