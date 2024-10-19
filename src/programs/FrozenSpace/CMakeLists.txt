
add_executable(FrozenSpace main.cpp)
target_link_libraries(FrozenSpace PRIVATE core)


set_property(TARGET FrozenSpace PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")