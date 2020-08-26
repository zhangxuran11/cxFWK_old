include_directories(include)

file(GLOB tmp_SRCS "*.cpp")
list(APPEND cxFWK_SRCS ${tmp_SRCS})
list(APPEND cxFWK_INCS ${CMAKE_CURRENT_SOURCE_DIR}/include)
SET(cxFWK_SRCS "${cxFWK_SRCS}" CACHE INTERNAL "cxFWK lib source files" )
SET(cxFWK_INCS "${cxFWK_INCS}" CACHE INTERNAL "cxFWK lib include dictory")
