//
// Created by Thomas on 2018-01-28.
//

#ifndef AET_INVESTMENTPROFITABILITYCONTROLLER_H
#define AET_INVESTMENTPROFITABILITYCONTROLLER_H


#include <functional>
#include <map>
#include "../InvestmentProfitabilityAbstractController.h"
#include "../../../../service/utilities/ConnectionManager/Server/SocketManager.h"
#include "../../../../service/utilities/JsonLib/include/rapidjson/document.h"
#include "../../InvestmentProfitability.h"
#include <iostream>


class InvestmentProfitabilityController : public InvestmentProfitabilityAbstractController{
private:
    InvestmentProfitability* investmentProfitability;
    std::vector<double> serverData;
public:
    const std::vector<double> &getServerData() const override;

    void setServerData(const std::vector<double> &serverData);

public:
    std::map<std::string, std::function<void()>> getActionsMap() override {
        using namespace std::string_literals;
        std::map<std::string, std::function<void()>> actionsMap = {
                {"calculateInvestingProfitability", std::bind(&calculateInvestingProfitability, this)},
                {"compareTrendLines", std::bind(&compareTrendLines, this)}};
        return actionsMap;
    };

    void setInvestmentModel(InvestmentProfitability*) override;

    void calculateInvestingProfitability();
    void compareTrendLines();
    ~InvestmentProfitabilityController() override = default;
};


#endif //AET_INVESTMENTPROFITABILITYCONTROLLER_H
