//
// Created by Thomas on 2018-01-28.
//

#include "Controller/InvestmentProfitabilityAbstractController.h"
#include "Controller/InvestmentProfitability/InvestmentProfitabilityController.h"
#include "../../../utilities/ConnectionManager/Server/SocketManager.h"
#include "../../config/config.h"
#include "../../service/utilities/JsonReader.h"

int main(int argc, char const *argv[]) {
    while (1) {
        InvestmentProfitabilityAbstractController *investmentProfitabilityController = new InvestmentProfitabilityController();
        Server::SocketManager manager(CurrencyInvestingProfitability::serverAddress.port,
                                      CurrencyInvestingProfitability::serverAddress.address);
        investmentProfitabilityController->awaitConnection(manager);
        std::string data = manager.receiveData();

        JsonReader *reader = new JsonReader();
        std::string actionName = reader->parseAction(data);

        investmentProfitabilityController->dispatchAction(actionName);
    }
}