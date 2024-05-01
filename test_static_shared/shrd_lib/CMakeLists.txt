add_library(shrd_lib SHARED shrd_lib.cpp shrd_lib.h)
target_link_libraries(shrd_lib PRIVATE log_facade)