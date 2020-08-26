file(GLOB test_SRCS "*.cpp") 
ADD_EXECUTABLE(test_top ${test_SRCS}  )

set_target_properties(
    test_top
    PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/out/bin
    )

set_target_properties(
    test_top
    PROPERTIES EXE_LINKER_FLAGS -lm
    )
target_link_libraries(test_top cxFWK)