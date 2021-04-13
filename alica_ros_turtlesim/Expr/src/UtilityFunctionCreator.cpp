#include "UtilityFunctionCreator.h"
#include "Master1617617242750.h"
#include "Move1617618120113.h"
#include <iostream>

namespace alica
{

UtilityFunctionCreator::~UtilityFunctionCreator() {}

UtilityFunctionCreator::UtilityFunctionCreator() {}

std::shared_ptr<BasicUtilityFunction> UtilityFunctionCreator::createUtility(int64_t utilityfunctionConfId)
{
    switch (utilityfunctionConfId) {
    case 1617617242750:
        return std::make_shared<UtilityFunction1617617242750>();
        break;
    case 1617618120113:
        return std::make_shared<UtilityFunction1617618120113>();
        break;
    default:
        std::cerr << "UtilityFunctionCreator: Unknown utility requested: " << utilityfunctionConfId << std::endl;
        throw new std::exception();
        break;
    }
}

} // namespace alica
