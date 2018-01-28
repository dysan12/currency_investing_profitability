//
// Created by Thomas on 2018-01-28.
//

#ifndef AET_INVESTMENTPROFITABILITYCONTROLLER_H
#define AET_INVESTMENTPROFITABILITYCONTROLLER_H


#include <functional>
#include <map>
#include "../InvestmentProfitabilityAbstractController.h"
#include "../../../../../utilities/ConnectionManager/Server/SocketManager.h"
#include "../../../../../utilities/JsonParser/include/rapidjson/document.h"
#include <iostream>


class InvestmentProfitabilityController : public InvestmentProfitabilityAbstractController{
private:

public:
    std::map<std::string, std::function<void()>> getActionsMap() override {
        using namespace std::string_literals;
        std::map<std::string, std::function<void()>> actionsMap = {
                {"calculateInvestingProfitability", std::bind(&calculateInvestingProfitability, this)},
                {"compareTrendLines", std::bind(&compareTrendLines, this)}};
        return actionsMap;
    };

    bool awaitConnection(Server::SocketManager) override ;

    double calculateInvestingProfitability();
    std::vector<double> compareTrendLines();
};


#endif //AET_INVESTMENTPROFITABILITYCONTROLLER_H
