
#**************************************************************************************************
# Set variable ************************************************************************************
SET(SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/pathbot.cpp
)

add_executable("noops-pathbot" ${SOURCES})
target_compile_options("noops-pathbot" PRIVATE -O3)
target_link_libraries("noops-pathbot" PRIVATE -lstdc++fs)
