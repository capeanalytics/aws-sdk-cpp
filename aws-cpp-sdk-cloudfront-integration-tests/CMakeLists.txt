add_project(aws-cpp-sdk-cloudfront-tests 
    "Tests for the AWS Cloudfront C++ SDK" 
    aws-cpp-sdk-core 
    aws-cpp-sdk-cloudfront 
    testing-resources)

# Headers are included in the source so that they show up in Visual Studio.
# They are included elsewhere for consistency.

file(GLOB AWS_CLOUDFRONT_SRC
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

file(GLOB AWS_CLOUDFRONT_INTEGRATION_TESTS_SRC
    ${AWS_CLOUDFRONT_SRC}
)

set(AWS_CLOUDFRONT_INTEGRATION_TEST_APPLICATION_INCLUDES
    "${AWS_NATIVE_SDK_ROOT}/aws-cpp-sdk-core/include/"
    "${AWS_NATIVE_SDK_ROOT}/aws-cpp-sdk-cloudfront/include/"
    "${AWS_NATIVE_SDK_ROOT}/testing-resources/include/"
)

include_directories(${AWS_CLOUDFRONT_INTEGRATION_TEST_APPLICATION_INCLUDES})

if(MSVC AND BUILD_SHARED_LIBS)
    add_definitions(-DGTEST_LINKED_AS_SHARED_LIBRARY=1)
endif()

enable_testing()

if(PLATFORM_ANDROID AND BUILD_SHARED_LIBS)
    add_library(${PROJECT_NAME} ${LIBTYPE} ${AWS_CLOUDFRONT_INTEGRATION_TESTS_SRC})
else()
    add_executable(${PROJECT_NAME} ${AWS_CLOUDFRONT_INTEGRATION_TESTS_SRC})
endif()

target_link_libraries(${PROJECT_NAME} ${PROJECT_LIBS})
copyDlls(${PROJECT_NAME} ${PROJECT_LIBS})
list(APPEND AWS_INSTALLED_LIBS "${PROJECT_NAME}")
set(AWS_INSTALLED_LIBS "${AWS_INSTALLED_LIBS}" PARENT_SCOPE)

