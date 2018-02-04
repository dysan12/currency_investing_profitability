//
// Created by Thomas on 2018-01-28.
//

#include "Controller/InvestmentProfitabilityAbstractController.h"
#include "Controller/InvestmentProfitability/InvestmentProfitabilityController.h"
#include "../../config/config.h"
#include "../../service/utilities/JsonParser/JsonReader.h"
#include "../../service/utilities/JsonParser/JsonWriter.h"
#include "../../service/utilities/JsonParser/Json.h"
using json = nlohmann::json;

int main(int argc, char const *argv[]) {
    Server::SocketManager *manager = new Server::SocketManager(CurrencyInvestingProfitability::serverAddress.port,
                                                               CurrencyInvestingProfitability::serverAddress.address);
    manager->prepareConnection();

    JsonReader *reader = new JsonReader();
    JsonWriter *writer = new JsonWriter();

    while (1) {
        InvestmentProfitabilityAbstractController *investmentProfitabilityController = new InvestmentProfitabilityController();

        manager->listenForConnection();

        std::string data = manager->receiveData();
        std::cout << "Input data: " << data << std::endl;

        std::string actionName = reader->parseAction(data);
        investmentProfitabilityController->setInvestmentModel(
                new InvestmentProfitability(reader->parseFirstCurrency(data), reader->parseSecondCurrency(data)));

        investmentProfitabilityController->dispatchAction(actionName);

        std::string preparedData = writer->parseToJson(investmentProfitabilityController->getServerData());

        manager->sendData(preparedData.c_str());

        std::cout << "Output data: " << preparedData << std::endl;

        manager->destroyConnectedSocket();
        delete investmentProfitabilityController;
    }
}