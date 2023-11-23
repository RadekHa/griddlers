cmake_minimum_required(VERSION 3.18)

project(griddlers
  LANGUAGES CXX
  VERSION 0.1.0
)

if(NOT CMAKE_DEBUG_POSTFIX)
   set(CMAKE_DEBUG_POSTFIX d)
endif()

add_subdirectory(extern)
add_subdirectory(src)
add_subdirectory(tests)

# Copy DLLs needed for runtime on Windows
if(WIN32)
  if (BUILD_SHARED_LIBS)
    add_custom_command(TARGET tests POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy_if_different
          $<TARGET_FILE:Catch2::Catch2WithMain>
          $<TARGET_FILE:Catch2::Catch2>
          $<TARGET_FILE_DIR:tests>)
  endif()
endif()
