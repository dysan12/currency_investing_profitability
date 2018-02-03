cmake_minimum_required(VERSION 3.9)
project(CURR_INV_PROFIT)

set(CMAKE_CXX_STANDARD 17)
link_libraries(ws2_32 wsock32)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(
        CURR_INV_PROFIT
        application/src/main.cpp
        application/src/InvestmentProfitability.cpp
        application/src/InvestmentProfitability.h
        config/config.h
        application/src/Controller/InvestmentProfitability/InvestmentProfitabilityController.cpp
        application/src/Controller/InvestmentProfitability/InvestmentProfitabilityController.h
        application/src/Controller/InvestmentProfitabilityAbstractController.h
        service/utilities/ConnectionManager/Server/SocketManager.h
        service/utilities/ConnectionManager/Server/SocketManager.cpp
        service/utilities/JsonParser/JsonReader.cpp
        service/utilities/JsonParser/JsonReader.h
        service/utilities/JsonParser/JsonWriter.cpp
        service/utilities/JsonParser/JsonWriter.h service/utilities/JsonParser/Json.h)