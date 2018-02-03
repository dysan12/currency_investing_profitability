//
// Created by Thomas on 2018-01-28.
//

#include "InvestmentProfitabilityController.h"


bool InvestmentProfitabilityController::awaitConnection(Server::SocketManager* manager) {
    manager->prepareConnection();
    manager->listenForConnection();

    return true;
}

void InvestmentProfitabilityController::calculateInvestingProfitability() {
    this->setServerData(this->investmentProfitability->calculateInvestingProfitability());
}

void InvestmentProfitabilityController::compareTrendLines() {
    this->setServerData(this->investmentProfitability->compareTrendLines());
}

void InvestmentProfitabilityController::setInvestmentModel(InvestmentProfitability *invest) {
    this->investmentProfitability = invest;
}

const std::vector<double> &InvestmentProfitabilityController::getServerData() const {
    return serverData;
}

void InvestmentProfitabilityController::setServerData(const std::vector<double> &serverData) {
    InvestmentProfitabilityController::serverData = serverData;
}
