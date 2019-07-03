
#**************************************************************************************************
# Set variable ************************************************************************************
SET(SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/mashbot.cpp
)

add_executable("noops-mashbot" ${SOURCES})
target_compile_options("noops-mashbot" PRIVATE -O3)
target_link_libraries("noops-mashbot" PRIVATE -lstdc++fs)
