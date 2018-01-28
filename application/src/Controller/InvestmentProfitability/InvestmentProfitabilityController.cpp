//
// Created by Thomas on 2018-01-28.
//

#include "InvestmentProfitabilityController.h"


bool InvestmentProfitabilityController::awaitConnection(Server::SocketManager manager) override {
    manager.prepareConnection();
    manager.listenForConnection();

    return true;
}

double InvestmentProfitabilityController::calculateInvestingProfitability() {
    return 0;
}

std::vector<double> InvestmentProfitabilityController::compareTrendLines() {
    return std::vector<double>();
}