CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(LibrarySystem)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

# ADD_EXECUTABLE(main
#   main.cpp
# )

ADD_EXECUTABLE(test
    tests/tests.cpp
    src/Book.cpp
    src/User.cpp
    src/Librarian.cpp
    src/LibrarySystem.cpp
    src/BookSystem.cpp
    src/Bundle.cpp
)

TARGET_LINK_LIBRARIES(test gtest)