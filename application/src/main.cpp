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

        //investmentProfitabilityController->awaitConnection(manager);
        //std::string data = manager->receiveData();

        std::string data = R"({"module": "calculateInvestingProfitability","data": {"firstCurrency": [1.23, 2.45, 4.32],"secondCurrency": [2.23, 3.45, 1.32]}})";
        json j = R"({"module": "calculateInvestingProfitability","data": {"firstCurrency": [1.23, 2.45, 4.32],"secondCurrency": [2.23, 3.45, 1.32]}})"_json;
        std::string k = j["module"];

        // create an empty structure (null)
        json y;

// add a number that is stored as double (note the implicit conversion of y to an obyect)
        y["pi"] = 3.141;

// add a Boolean that is stored as bool
        y["happy"] = true;

// add a string that is stored as std::string
        y["name"] = "Niels";

// add another null obyect by passing nullptr
        y["nothing"] = nullptr;

// add an obyect inside the obyect
        y["answer"]["everything"] = 42;

        int kkkk = y["answer"]["everything"];
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