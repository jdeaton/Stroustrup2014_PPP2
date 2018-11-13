# Chapter 12. A Display Model.

find_package(FLTK)

# Section 12.1: Why graphics?
# Section 12.2: A display model.

# Section 12.3: A first example.
add_executable(ch12_ex1 ex1.cpp)
target_include_directories(ch12_ex1 ${FLTK_INCLUDE_DIR})
target_link_libraries(ch12_ex1 ${FLTK_LIBRARIES})

