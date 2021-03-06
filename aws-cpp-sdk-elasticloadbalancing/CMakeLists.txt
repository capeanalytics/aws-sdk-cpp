add_project(aws-cpp-sdk-elasticloadbalancing "C++ SDK for the AWS elasticloadbalancing service" aws-cpp-sdk-core)

file(GLOB AWS_ELASTICLOADBALANCING_HEADERS
    "include/aws/elasticloadbalancing/*.h"
)

file(GLOB AWS_ELASTICLOADBALANCING_MODEL_HEADERS
    "include/aws/elasticloadbalancing/model/*.h"
)

file(GLOB AWS_ELASTICLOADBALANCING_SOURCE
    "source/*.cpp"
)

file(GLOB AWS_ELASTICLOADBALANCING_MODEL_SOURCE
    "source/model/*.cpp"
)

file(GLOB ELASTICLOADBALANCING_UNIFIED_HEADERS
    ${AWS_ELASTICLOADBALANCING_HEADERS}
    ${AWS_ELASTICLOADBALANCING_MODEL_HEADERS}
)

file(GLOB ELASTICLOADBALANCING_UNITY_SRC
    ${AWS_ELASTICLOADBALANCING_SOURCE}
    ${AWS_ELASTICLOADBALANCING_MODEL_SOURCE}
)

if(ENABLE_UNITY_BUILD)
    enable_unity_build("ELASTICLOADBALANCING" ELASTICLOADBALANCING_UNITY_SRC)
endif()

file(GLOB ELASTICLOADBALANCING_SRC
    ${ELASTICLOADBALANCING_UNIFIED_HEADERS}
    ${ELASTICLOADBALANCING_UNITY_SRC}
)

if(WIN32)
    #if we are compiling for visual studio, create a sane directory tree.
    if(MSVC)
        source_group("Header Files\\aws\\elasticloadbalancing" FILES ${AWS_ELASTICLOADBALANCING_HEADERS})
        source_group("Header Files\\aws\\elasticloadbalancing\\model" FILES ${AWS_ELASTICLOADBALANCING_MODEL_HEADERS})
        source_group("Source Files" FILES ${AWS_ELASTICLOADBALANCING_SOURCE})
        source_group("Source Files\\model" FILES ${AWS_ELASTICLOADBALANCING_MODEL_SOURCE})
    endif(MSVC)
endif()

set(ELASTICLOADBALANCING_INCLUDES
    "${CMAKE_CURRENT_SOURCE_DIR}/include/"
)

include_directories(${ELASTICLOADBALANCING_INCLUDES})

if(USE_WINDOWS_DLL_SEMANTICS AND BUILD_SHARED_LIBS)
    add_definitions("-DAWS_ELASTICLOADBALANCING_EXPORTS")
endif()

add_library(${PROJECT_NAME} ${LIBTYPE} ${ELASTICLOADBALANCING_SRC})
add_library(AWS::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
list(APPEND AWS_INSTALLED_LIBS "${PROJECT_NAME}")
set(AWS_INSTALLED_LIBS "${AWS_INSTALLED_LIBS}" PARENT_SCOPE)

target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)
  
target_link_libraries(${PROJECT_NAME} ${PROJECT_LIBS})

setup_install()

install (FILES ${AWS_ELASTICLOADBALANCING_HEADERS} DESTINATION ${INCLUDE_DIRECTORY}/aws/elasticloadbalancing)
install (FILES ${AWS_ELASTICLOADBALANCING_MODEL_HEADERS} DESTINATION ${INCLUDE_DIRECTORY}/aws/elasticloadbalancing/model)

if(PLATFORM_WINDOWS AND MSVC)
    install (FILES nuget/${PROJECT_NAME}.autopkg DESTINATION nuget)
endif()

do_packaging()


