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
    src/BookSystem.cpp
    src/Bundle.cpp
    src/Librarian.cpp
    src/LibrarySystem.cpp
    src/LoginSystem.cpp
    src/User.cpp
    src/UserSystem.cpp
    # src/AlphabeticalSort.cpp
    # src/DisplaySystem.cpp
    # src/FrequencySort.cpp
    # src/GenreSearch.cpp
    # src/ISBNSearch.cpp
    # src/KeyWordSearch.cpp
)

TARGET_LINK_LIBRARIES(test gtest)