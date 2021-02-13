
add_library(stock_buy_sell main.cpp)

target_link_libraries(stock_buy_sell
    project_options 
    project_warnings 
    CONAN_PKG::ms-gsl)

add_executable(test_stock_buy_sell main.cpp)
target_link_libraries(test_stock_buy_sell PRIVATE stock_buy_sell)