add_executable(tests)

target_sources(tests
PUBLIC
   test_01.cpp
)

target_link_libraries(tests
PRIVATE
       rule
)

target_compile_features(tests
PRIVATE
       cxx_std_20
)

set_target_properties(tests
PROPERTIES
       DEBUG_POSTFIX "d"
)

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

list(APPEND CMAKE_MODULE_PATH ${FETCHCONTENT_BASE_DIR}/catch2-src/extras)
include(CTest)
include(Catch)

catch_discover_tests(tests)
