project(TP_TESTS)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG ff233bdd4cac0a0bf6e5cd45bda3406814cb2796
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

enable_testing()

add_executable(TP_TESTS
        MegatronTest.cpp
        OptimusPrimeTest.cpp
)

target_link_libraries(TP_TESTS
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(TP_TESTS)