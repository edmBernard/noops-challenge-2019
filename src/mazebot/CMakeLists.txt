
#**************************************************************************************************
# Set variable ************************************************************************************
SET(SAMPLES
  mazebot
  mazebot-basic
)

foreach (SAMPLE ${SAMPLES})
  add_executable("noops-${SAMPLE}" ${CMAKE_CURRENT_SOURCE_DIR}/${SAMPLE}.cpp)
  target_compile_options("noops-${SAMPLE}" PRIVATE -O3)
  target_link_libraries("noops-${SAMPLE}" PRIVATE ${CPR_LIBRARIES} ${CURL_LIBRARIES} ${OPENSSL_LIBRARIES} ZLIB::ZLIB fmt::fmt -dl -pthread)
endforeach(SAMPLE)
