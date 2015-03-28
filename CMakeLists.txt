
set(PROJECT_NAME "GA_KGrahp")
project(${PROJECT_NAME} C CXX)
cmake_minimum_required(VERSION 2.8)


# --------------
# Build settings
# --------------

set(CMAKE_POSITION_INDEPENDENT_CODE ON)


# Install destinations
set( CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/_install CACHE PATH "Installation Destination" FORCE)
set( INSTALL_DES ./ CACHE PATH "Where to install to." )

# Warnings for Debug mode
option( USE_STRICT_COMPILE_WARNINGS "Use strict compilation warnings in debug mode." ON )
if( USE_STRICT_COMPILE_WARNINGS )
    if( CMAKE_COMPILER_IS_GNUCXX )
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
        message("CMAKE_CXX_FLAGS: " ${CMAKE_CXX_FLAGS})
        #set( CMAKE_CXX_FLAGS_DEBUG "-Wall -Wextra -Werror" )
        #set( CMAKE_CXX_FLAGS_DEBUG "-pedantic -Wall -Wextra -Wwrite-strings -Winit-self -Wcast-align -Wcast-qual -Wpointer-arith -Wstrict-aliasing -Wformat=2 -Wmissing-declarations -Wmissing-include-dirs -Wuninitialized -Werror-implicit-function-declaration -Wfloat-equal -Wundef -Wstrict-overflow=5 -Wswitch-default -Wswitch-enum -Wconversion -Wunreachable-code -Wno-unused-parameter" )
        # use to suppress unused stuff: -Wno-unused-parameter -Wno-unused-result
    endif()
endif()

# Debug is default
#if( NOT CMAKE_BUILD_TYPE )
#    set( CMAKE_BUILD_TYPE "Debug" CACHE STRING "" FORCE ) #MinSizeRel
#endif()
message("CMAKE_BUILD_TYPE ::" ${CMAKE_BUILD_TYPE})

add_definitions(
    -fPIC
#    -std=c++11
)


# ------------
# Dependencies
# ------------

### Qt5
set(CMAKE_AUTOMOC ON)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5PrintSupport REQUIRED)

# ------------
# Source files
# ------------

file(GLOB SRC_DET "src/*.cpp")
set(SRC ${SRC_DET})

file(GLOB INCL_DET "include/*.h")
set(INCL ${INCL_DET})


message("SRC ::" ${SRC})
message("INCL ::" ${INCL})

include_directories(${CMAKE_CURRENT_BINARY_DIR}
                    ${CMAKE_CURRENT_SOURCE_DIR}
                    ${CMAKE_CURRENT_SOURCE_DIR}/include
                    )

# --------------
# Build and link
# --------------

message("add_executable of ::" ${PROJECT_NAME})


#add_library( libqcustomplot SHARED IMPORTED )
#set_target_properties( libqcustomplot PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/res/libqcustomplot.so )


add_executable( ${PROJECT_NAME}  ${INCL} ${SRC})

target_link_libraries( ${PROJECT_NAME}
                        Qt5::Widgets
#                        libqcustomplot
                        )



# -------
# Install
# -------
install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION ${INSTALL_DES}
        COMPONENT Runtime )











