add_library(core core.cpp)
target_link_libraries(core PUBLIC sfml-system sfml-network sfml-graphics sfml-window)
target_link_libraries(core PUBLIC ImGui-SFML::ImGui-SFML)
