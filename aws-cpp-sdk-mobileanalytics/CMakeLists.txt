add_project(aws-cpp-sdk-mobileanalytics "C++ SDK for the AWS mobileanalytics service" aws-cpp-sdk-core)

file(GLOB AWS_MOBILEANALYTICS_HEADERS
    "include/aws/mobileanalytics/*.h"
)

file(GLOB AWS_MOBILEANALYTICS_MODEL_HEADERS
    "include/aws/mobileanalytics/model/*.h"
)

file(GLOB AWS_MOBILEANALYTICS_SOURCE
    "source/*.cpp"
)

file(GLOB AWS_MOBILEANALYTICS_MODEL_SOURCE
    "source/model/*.cpp"
)

file(GLOB MOBILEANALYTICS_UNIFIED_HEADERS
    ${AWS_MOBILEANALYTICS_HEADERS}
    ${AWS_MOBILEANALYTICS_MODEL_HEADERS}
)

file(GLOB MOBILEANALYTICS_UNITY_SRC
    ${AWS_MOBILEANALYTICS_SOURCE}
    ${AWS_MOBILEANALYTICS_MODEL_SOURCE}
)

if(ENABLE_UNITY_BUILD)
    enable_unity_build("MOBILEANALYTICS" MOBILEANALYTICS_UNITY_SRC)
endif()

file(GLOB MOBILEANALYTICS_SRC
    ${MOBILEANALYTICS_UNIFIED_HEADERS}
    ${MOBILEANALYTICS_UNITY_SRC}
)

if(WIN32)
    #if we are compiling for visual studio, create a sane directory tree.
    if(MSVC)
        source_group("Header Files\\aws\\mobileanalytics" FILES ${AWS_MOBILEANALYTICS_HEADERS})
        source_group("Header Files\\aws\\mobileanalytics\\model" FILES ${AWS_MOBILEANALYTICS_MODEL_HEADERS})
        source_group("Source Files" FILES ${AWS_MOBILEANALYTICS_SOURCE})
        source_group("Source Files\\model" FILES ${AWS_MOBILEANALYTICS_MODEL_SOURCE})
    endif(MSVC)
endif()

set(MOBILEANALYTICS_INCLUDES
    "${CMAKE_CURRENT_SOURCE_DIR}/include/"
)

include_directories(${MOBILEANALYTICS_INCLUDES})

if(USE_WINDOWS_DLL_SEMANTICS AND BUILD_SHARED_LIBS)
    add_definitions("-DAWS_MOBILEANALYTICS_EXPORTS")
endif()

add_library(${PROJECT_NAME} ${LIBTYPE} ${MOBILEANALYTICS_SRC})
add_library(AWS::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
list(APPEND AWS_INSTALLED_LIBS "${PROJECT_NAME}")
set(AWS_INSTALLED_LIBS "${AWS_INSTALLED_LIBS}" PARENT_SCOPE)


target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)
  
target_link_libraries(${PROJECT_NAME} ${PROJECT_LIBS})

setup_install()

install (FILES ${AWS_MOBILEANALYTICS_HEADERS} DESTINATION ${INCLUDE_DIRECTORY}/aws/mobileanalytics)
install (FILES ${AWS_MOBILEANALYTICS_MODEL_HEADERS} DESTINATION ${INCLUDE_DIRECTORY}/aws/mobileanalytics/model)

if(PLATFORM_WINDOWS AND MSVC)
    install (FILES nuget/${PROJECT_NAME}.autopkg DESTINATION nuget)
endif()

do_packaging()


