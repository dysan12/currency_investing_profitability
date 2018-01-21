//
// Created by Thomas on 2018-01-15.
//

#ifndef MATHMODELS_INVESTINGPROFITABILITY_H
#define MATHMODELS_INVESTINGPROFITABILITY_H


#include <vector>
#include <cmath>

class InvestingProfitability {
private:
    std::vector<double> mainCurrencyValues;

    std::vector<double> sideCurrencyValues;

public:
    InvestingProfitability(const std::vector<double> &mainCurrencyValues,
                           const std::vector<double> &sideCurrencyValues);

    const std::vector<double> &getMainCurrencyValues() const;

    const std::vector<double> &getSideCurrencyValues() const;

public:
    double calculateInvestingProfitability();
    std::vector<double> compareTrendLines();
};


#endif //MATHMODELS_INVESTINGPROFITABILITY_H
