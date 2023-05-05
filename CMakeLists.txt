cmake_minimum_required(VERSION 3.10)

project(Zapiekanka LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/tests)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/Zapiekanki)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/ZapiekankaOptions)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/utilities)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/Stores)


set(SOURCES src/main.cpp include/Zapiekanka.hpp
    include/ZapiekankaStore.hpp include/ZapiekankaBuilder.hpp include/Director.hpp include/ZapiekankaFactory.hpp
    include/ZapiekankaOptions/Dough.hpp include/ZapiekankaOption.hpp include/ZapiekankaOptions/Topping.hpp
    include/ZapiekankaOptions/Cheese.hpp include/ZapiekankaOptions/Sauce.hpp
    include/Zapiekanki/ZakopaneZapiekanka.hpp include/Zapiekanki/CheeseZapiekanka.hpp include/Zapiekanki/CustomZapiekanka.hpp
    include/utilities/Memento.hpp include/utilities/MementoCaretaker.hpp include/Stores/WolnicaStore.hpp
    include/Stores/PlacNowyStore.hpp include/Stores/CustomNameGenerator.hpp)


find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_executable(Zapiekanka ${SOURCES})
add_executable(ZapiekankaTests tests/tests.cpp)
target_link_libraries(ZapiekankaTests ${GTEST_LIBRARIES} pthread)



