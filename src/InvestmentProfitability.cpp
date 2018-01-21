//
// Created by Thomas on 2018-01-18.
//

#include "InvestmentProfitability.h"

InvestingProfitability::InvestingProfitability(const std::vector<double> &mainCurrencyValues,
                                               const std::vector<double> &sideCurrencyValues) : mainCurrencyValues(
        mainCurrencyValues), sideCurrencyValues(sideCurrencyValues) {}

double InvestingProfitability::calculateInvestingProfitability() {
    double profitability = 0;
    double prevCurrencyValue = this->getMainCurrencyValues().front();
    bool first = true;

    for (auto &value: this->getMainCurrencyValues()) {
        if (first) {
            first = false;
            continue;
        } else {
            profitability += round((value / prevCurrencyValue - 1) * 100) / 100;
            prevCurrencyValue = value;
        }
    }

    return profitability * 100; //Zwraca w procentach zysk (ujemny lub dodatni)
}

const std::vector<double> &InvestingProfitability::getMainCurrencyValues() const {
    return mainCurrencyValues;
}

const std::vector<double> &InvestingProfitability::getSideCurrencyValues() const {
    return sideCurrencyValues;
}

std::vector<double> InvestingProfitability::compareTrendLines() {
    std::vector<double> trend = {};
    double mainCurrencyPreviousValue = this->getMainCurrencyValues().front();
    double sideCurrencyPreviousValue = this->getSideCurrencyValues().front();

    for (int index = 1; index < this->getMainCurrencyValues().size(); index++) {
        trend.push_back(
                round(
                        ((this->getMainCurrencyValues()[index] / mainCurrencyPreviousValue) -
                         (this->getSideCurrencyValues()[index] / sideCurrencyPreviousValue)
                        ) * 100) / 100
        );
        mainCurrencyPreviousValue = this->getMainCurrencyValues()[index];
        sideCurrencyPreviousValue = this->getSideCurrencyValues()[index];
    }

    return trend;
}