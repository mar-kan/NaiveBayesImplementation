cmake_minimum_required(VERSION 3.21)
project(NaiveBayesImplementation)

include(GNUInstallDirs)
set(PACKAGE_NAME matplotlib_cpp)
set(INSTALL_CONFIGDIR ${CMAKE_INSTALL_LIBDIR}/${PACKAGE_NAME}/cmake)


# Library target
add_library(matplotlib_cpp INTERFACE)
target_include_directories(matplotlib_cpp
        INTERFACE
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/examples>
        $<INSTALL_INTERFACE:include>
        )
target_compile_features(matplotlib_cpp INTERFACE
        cxx_std_11
        )
# TODO: Use `Development.Embed` component when requiring cmake >= 3.18
find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
target_link_libraries(matplotlib_cpp INTERFACE
        Python3::Python
        Python3::Module
        )
find_package(Python3 COMPONENTS NumPy)
if(Python3_NumPy_FOUND)
    target_link_libraries(matplotlib_cpp INTERFACE
            Python3::NumPy
            )
else()
    target_compile_definitions(matplotlib_cpp INTERFACE WITHOUT_NUMPY)
endif()
install(
        TARGETS matplotlib_cpp
        EXPORT install_targets
)




add_executable(NaiveBayesImplementation main.cpp WordList.cpp WordList.h NaiveBayes.cpp NaiveBayes.h Utils.cpp Utils.h Preprocess.cpp Preprocess.h Plot.cpp Plot.h Metrics.cpp Metrics.h)
target_link_libraries(NaiveBayesImplementation PRIVATE matplotlib_cpp)
set_target_properties(NaiveBayesImplementation PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
