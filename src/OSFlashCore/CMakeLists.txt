set(SOURCES 
    downloader.h 
    downloader.cpp)

add_library(OSFlasherCore ${SOURCES})

set(OPENSSL_HEADER "D:/projects/devDependencies/OpenSSL/include")

set(OPENSSL_LIB "D:/projects/devDependencies/OpenSSL/lib/libssl.lib"
                "D:/projects/devDependencies/OpenSSL/lib/libcrypto.lib")

if(NOT TARGET spdlog)
    # Stand-alone build
    find_package(spdlog REQUIRED)
endif()

target_include_directories(OSFlasherCore PUBLIC  ${OPENSSL_HEADER})


target_link_libraries(OSFlasherCore PRIVATE spdlog::spdlog $<$<BOOL:${MINGW}>:ws2_32> ${OPENSSL_LIB})