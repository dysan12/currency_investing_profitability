//
// Created by Thomas on 2018-01-18.
//

#ifndef AET_INVESTMENTPROFITABILITY_H
#define AET_INVESTMENTPROFITABILITY_H


#include <vector>
#include <cmath>

class InvestmentProfitability {
private:
    std::vector<double> mainCurrencyValues;

    std::vector<double> sideCurrencyValues;

public:
    InvestmentProfitability(const std::vector<double> &mainCurrencyValues,
                           const std::vector<double> &sideCurrencyValues);

    const std::vector<double> &getMainCurrencyValues() const;

    const std::vector<double> &getSideCurrencyValues() const;

public:
    std::vector<double> calculateInvestingProfitability();
    std::vector<double> compareTrendLines();
};


#endif //AET_INVESTMENTPROFITABILITY_H
