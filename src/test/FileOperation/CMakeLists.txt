set(HEADER_FILE ../../OSFlashCore)
add_executable(fileTest FileOp.cpp)

target_include_directories(fileTest PUBLIC ${HEADER_FILE})
target_link_libraries(fileTest PRIVATE OSFlasherCore)