cmake_minimum_required(VERSION 3.4.1)

# configure import libs
set(distribution_DIR ${CMAKE_SOURCE_DIR}/../../../../distribution)

# shared lib will also be tucked into APK and sent to target
# refer to app/build.gradle, jniLibs section for that purpose.
# ${ANDROID_ABI} is handy for our purpose here. Probably this ${ANDROID_ABI} is
# the most valuable thing of this sample, the rest are pretty much normal cmake
add_library(lib_face SHARED IMPORTED)
set_target_properties(lib_face PROPERTIES IMPORTED_LOCATION
    C:/Users/asus/desktop/hello-libs/distribution/gperf/lib/${ANDROID_ABI}/libface.so)

add_library(lib_caffe SHARED IMPORTED)
set_target_properties(lib_caffe PROPERTIES IMPORTED_LOCATION
    C:/Users/asus/desktop/hello-libs/distribution/gperf/lib/${ANDROID_ABI}/libcaffe.so)

# build application's shared lib
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

add_library(hello-libs SHARED
            hello-libs.cpp)

target_include_directories(hello-libs PRIVATE
                           ${distribution_DIR}/gperf/include)

target_link_libraries(hello-libs
                      android
                      lib_face
                      lib_caffe
                      log)
