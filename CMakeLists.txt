cmake_minimum_required(VERSION 3.28)
project(tree)

set(CMAKE_CXX_STANDARD 20)
find_package(SFML 2.5 COMPONENTS graphics)

add_executable(tree Main_File.cpp
        AVL.h
        Boxed.h
        KeyBoard.h
        Trees_Building.h
        VERTEX.h
        Node_DD.h
        Node_Options.h
        Random.h
        TREE_OPTIONS.h
        Node_AVL.h
        Main_Window.cpp
        Main_Window.h
        Drawer.cpp
        Drawer.h
        ErrorWindow.cpp
        ErrorWindow.h
        First_Extra_Window.cpp
        First_Extra_Window.h
        Second_Extra_Window.cpp
        Second_Extra_Window.h
        Info_Extra_Window.cpp
        Info_Extra_Window.h
        PRINT_TREE_OPTIONS.h
        Control.cpp
        Control.h
        BigInteger.h
        BigInteger.cpp
        DD.h
        SPLAY.h
        Node_SPLAY.h
)

target_link_libraries(tree sfml-graphics)