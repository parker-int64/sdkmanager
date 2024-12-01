install(TARGETS ${CMAKE_PROJECT_NAME}
    LIBRARY DESTINATION .
    RUNTIME DESTINATION .
)
set(CPACK_GENERATOR "NSIS")
set(CPACK_PACKAGE_FILE_NAME "Seeed JetPack Imager")
set(CPACK_NSIS_MODIFY_PATH "OFF")  # Set this to OFF and don't add to PATH
set(CPACK_NSIS_DISPLAY_NAME "Seeed JetPack Imager")  # Installer name
set(CPACK_NSIS_PACKAGE_NAME "Seeed JetPack Imager")  # Installer package name
set(CPACK_NSIS_INSTALL_ROOT "$PROGRAMFILES64")  # Default installation location
