
#**************************************************************************************************
# Set variable ************************************************************************************
SET(SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/hexbot.cpp
)

add_executable("noops-hexbot" ${SOURCES})
target_compile_options("noops-hexbot" PRIVATE -O3)
target_link_libraries("noops-hexbot" PRIVATE -lstdc++fs ${CPR_LIBRARIES} ${CURL_LIBRARIES} ${OPENSSL_LIBRARIES} ZLIB::ZLIB -dl -pthread)
