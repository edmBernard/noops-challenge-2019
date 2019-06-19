
#**************************************************************************************************
# Set variable ************************************************************************************
SET(SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/golfbot.cpp
)

add_executable("noops-golfbot" ${SOURCES})
target_compile_options("noops-golfbot" PRIVATE -O3)
target_link_libraries("noops-golfbot" PRIVATE -lstdc++fs)
