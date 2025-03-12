cmake_minimum_required(VERSION 3.16)
project(sdkmanager 
        LANGUAGES CXX
        VERSION 0.0.1.1001
        DESCRIPTION "Seeed JetPack Imager"
        HOMEPAGE_URL "")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")



include(FetchContent)

FetchContent_Declare(
    webview
    GIT_REPOSITORY https://github.com/webview/webview
    GIT_TAG 0.12.0)
FetchContent_MakeAvailable(webview)



if(WIN32)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/platform/win/winicon.rc.in winicon.rc)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/platform/win/resource.h resource.h COPYONLY)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/platform/win/icon_win.ico icon_win.ico COPYONLY)
    add_executable(${CMAKE_PROJECT_NAME} WIN32)
    set(RC_FILE ${CMAKE_CURRENT_BINARY_DIR}/winicon.rc) # use the generated rc file
    target_sources(${CMAKE_PROJECT_NAME} PRIVATE src/main.cc resource.h ${RC_FILE})

    # Packing a installer using NSIS
    include(cmake/nsis_install.cmake)


elseif(UNIX)
    add_executable(${CMAKE_PROJECT_NAME})
    target_sources(${CMAKE_PROJECT_NAME} PRIVATE src/main.cc)
endif()

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE webview::core)


add_subdirectory(src/OSFlashCore)

# Install operations



include(CPack)

include(CTest)

add_subdirectory(src/test/FileOperation)

