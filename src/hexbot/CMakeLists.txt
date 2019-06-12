
#**************************************************************************************************
# Set variable ************************************************************************************
SET(SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/hexbot.cpp
)

add_executable("moops-hexbot" ${SOURCES})
target_compile_options("moops-hexbot" PRIVATE -O3)
target_link_libraries("moops-hexbot" PRIVATE -lstdc++fs)
