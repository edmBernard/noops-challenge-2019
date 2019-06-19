
#**************************************************************************************************
# Set variable ************************************************************************************
SET(SAMPLES
  polybot
)

foreach (SAMPLE ${SAMPLES})
  add_executable("noops-${SAMPLE}" ${CMAKE_CURRENT_SOURCE_DIR}/${SAMPLE}.cpp)
  target_compile_options("noops-${SAMPLE}" PRIVATE -O3)
  target_link_libraries("noops-${SAMPLE}" PRIVATE -pthread)
endforeach(SAMPLE)
