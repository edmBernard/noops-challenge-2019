
#**************************************************************************************************
# Set variable ************************************************************************************
SET(SAMPLES
  hexbot
  hexbot-basic
)

foreach (SAMPLE ${SAMPLES})
  add_executable("noops-${SAMPLE}" ${CMAKE_CURRENT_SOURCE_DIR}/${SAMPLE}.cpp)
  target_compile_options("noops-${SAMPLE}" PRIVATE -O3)
  target_link_libraries("noops-${SAMPLE}" PRIVATE -lstdc++fs ${OpenCV_LIBS} ${X11_LIBRARIES} ${CPR_LIBRARIES} ${CURL_LIBRARIES} ${OPENSSL_LIBRARIES} ZLIB::ZLIB -dl -pthread)
endforeach(SAMPLE)
