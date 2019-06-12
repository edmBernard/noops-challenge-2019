
#**************************************************************************************************
# Set variable ************************************************************************************
SET(SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/vexbot.cpp
)

add_executable("moops-vexbot" ${SOURCES})
target_compile_options("moops-vexbot" PRIVATE -O3)
target_link_libraries("moops-vexbot" PRIVATE -lstdc++fs)
