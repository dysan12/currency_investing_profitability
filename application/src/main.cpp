//
// Created by Thomas on 2018-01-28.
//

#include "Controller/InvestmentProfitabilityAbstractController.h"
#include "Controller/InvestmentProfitability/InvestmentProfitabilityController.h"
#include "../../config/config.h"
#include "../../service/utilities/JsonParser/JsonReader.h"
#include "../../service/utilities/JsonParser/JsonWriter.h"

int main(int argc, char const *argv[]) {
    while (1) {
        Server::SocketManager *manager = new Server::SocketManager(CurrencyInvestingProfitability::serverAddress.port,
                                                                   CurrencyInvestingProfitability::serverAddress.address);
        InvestmentProfitabilityAbstractController *investmentProfitabilityController = new InvestmentProfitabilityController();

        //investmentProfitabilityController->awaitConnection(manager);
        //std::string data = manager->receiveData();
        std::string data = R"({"module": "calculateInvestingProfitability","data": {"firstCurrency": [1.23, 2.45, 4.32],"secondCurrency": [2.23, 3.45, 1.32]}})";

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