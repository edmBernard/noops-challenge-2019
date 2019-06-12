
#**************************************************************************************************
# Set variable ************************************************************************************
SET(SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/vexbot.cpp
)

add_executable("noops-vexbot" ${SOURCES})
target_compile_options("noops-vexbot" PRIVATE -O3)
target_link_libraries("noops-vexbot" PRIVATE -lstdc++fs)
