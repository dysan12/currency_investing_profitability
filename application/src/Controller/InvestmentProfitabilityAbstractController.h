//
// Created by Thomas on 2018-01-28.
//

#ifndef AET_INVESTMENTPROFITABILITYABSTRACTCONTROLLER_H
#define AET_INVESTMENTPROFITABILITYABSTRACTCONTROLLER_H

#include <functional>
#include <map>
#include "../Exceptions/NotSupportedException.h"
#include "../../../service/utilities/ConnectionManager/Server/SocketManager.h"
#include "../InvestmentProfitability.h"

class InvestmentProfitabilityAbstractController {
public:
    void dispatchAction(const std::string &actionName)
    {
        std::map <std::string, std::function<void()>> actionMap = this->getActionsMap();

        auto action = actionMap.find(actionName);
        if(action != actionMap.end()) {
            try {
                actionMap[actionName]();
            } catch (...) {
                throw; // pass exception further
            }
        } else {
            throw NotSupportedException("Requested action is not supported by controller!");
        }
    }

    virtual void setInvestmentModel(InvestmentProfitability*) = 0;
    virtual std::map<std::string, std::function<void()>> getActionsMap() = 0;
    virtual bool awaitConnection(Server::SocketManager*) = 0;
    virtual const std::vector<double> &getServerData() const = 0;
};
#endif //AET_INVESTMENTPROFITABILITYABSTRACTCONTROLLER_H
