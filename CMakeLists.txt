cmake_minimum_required(VERSION 3.10)

project(Zapiekanka LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS})

set(INCLUDE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/tests
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Zapiekanki
    ${CMAKE_CURRENT_SOURCE_DIR}/include/ZapiekankaOptions
    ${CMAKE_CURRENT_SOURCE_DIR}/include/utilities
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Stores)

set(HEADERS
    include/Zapiekanka.hpp
    include/ZapiekankaStore.hpp
    include/ZapiekankaBuilder.hpp
    include/Director.hpp
    include/ZapiekankaFactory.hpp
    include/ZapiekankaOptions/Dough.hpp
    include/ZapiekankaOption.hpp
    include/ZapiekankaOptions/Topping.hpp
    include/ZapiekankaOptions/Cheese.hpp
    include/ZapiekankaOptions/Sauce.hpp
    include/Zapiekanki/ZakopaneZapiekanka.hpp
    include/Zapiekanki/CheeseZapiekanka.hpp
    include/Zapiekanki/CustomZapiekanka.hpp
    include/utilities/Memento.hpp
    include/utilities/MementoCaretaker.hpp
    include/Stores/WolnicaStore.hpp
    include/Stores/PlacNowyStore.hpp
    include/Stores/Zapiekantopia.hpp)

include_directories(${INCLUDE_DIRS})

add_executable(Zapiekanka src/main.cpp ${HEADERS})
add_executable(ZapiekankaTests tests/tests.cpp)

target_compile_features(Zapiekanka PRIVATE cxx_std_17)
target_compile_features(ZapiekankaTests PRIVATE cxx_std_17)

target_include_directories(Zapiekanka PRIVATE ${INCLUDE_DIRS})
target_include_directories(ZapiekankaTests PRIVATE ${INCLUDE_DIRS})

target_compile_options(Zapiekanka PRIVATE ${CMAKE_C_FLAGS})
target_compile_options(ZapiekankaTests PRIVATE -Wall)

find_package(GTest REQUIRED)
target_link_libraries(ZapiekankaTests GTest::GTest pthread)
