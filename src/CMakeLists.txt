#set sources
set(SOURCES main.cpp)

#add the executables
add_executable(${app_name} ${SOURCES})

#ncurses links libraries 
target_link_libraries(${app_name} ncurses tinfo) #form??
