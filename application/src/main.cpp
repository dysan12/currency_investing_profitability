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
    while (1) {
        Server::SocketManager *manager = new Server::SocketManager(CurrencyInvestingProfitability::serverAddress.port,
                                                                   CurrencyInvestingProfitability::serverAddress.address);
        InvestmentProfitabilityAbstractController *investmentProfitabilityController = new InvestmentProfitabilityController();

        investmentProfitabilityController->awaitConnection(manager);
        std::string data = manager->receiveData();

        JsonReader *reader = new JsonReader();
        std::string actionName = reader->parseAction(data);
        investmentProfitabilityController->setInvestmentModel(
                new InvestmentProfitability(reader->parseFirstCurrency(data), reader->parseSecondCurrency(data)));

        investmentProfitabilityController->dispatchAction(actionName);

        JsonWriter *writer = new JsonWriter();
        std::string preparedData = writer->parseToJson(investmentProfitabilityController->getServerData());

        manager->sendData(preparedData.c_str());
    }
}