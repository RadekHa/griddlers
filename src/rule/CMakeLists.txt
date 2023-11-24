add_library (rule STATIC)

target_sources (rule
PRIVATE
       Rule.cpp
)

target_include_directories(rule
PUBLIC
       $<INSTALL_INTERFACE:include>
       $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
PRIVATE
       ${CMAKE_CURRENT_SOURCE_DIR}
)

set_target_properties (rule
PROPERTIES
    DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX}
)

target_compile_features (rule PRIVATE
    cxx_std_20
)
