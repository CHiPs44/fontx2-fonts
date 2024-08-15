# message(STATUS "fontx2-fonts PROJECT_NAME=${PROJECT_NAME}")
# target_include_directories(${PROJECT_NAME} INTERFACE 
# add_library(fontx2_fonts INTERFACE)
# target_include_directories(fontx2_fonts INTERFACE 
#   ${CMAKE_CURRENT_LIST_DIR}/include
# )
# target_link_libraries(fontx2_fonts INTERFACE)
# This will do for now...
target_include_directories(${PROJECT_NAME} PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/include
)
