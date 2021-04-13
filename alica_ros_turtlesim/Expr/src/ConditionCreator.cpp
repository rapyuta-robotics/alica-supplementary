#include "ConditionCreator.h"
#include "Go2RandomPosition1617618064309.h"
#include "GoTo1617618375823.h"
#include "Master1617617242750.h"
#include "Move1617618120113.h"

namespace alica
{

ConditionCreator::ConditionCreator() {}
ConditionCreator::~ConditionCreator() {}

std::shared_ptr<BasicCondition> ConditionCreator::createConditions(int64_t conditionConfId)
{
    switch (conditionConfId) {
    case 1617617417531:
        return std::make_shared<PreCondition1617617417531>();
        break;
    case 1617617440413:
        return std::make_shared<PreCondition1617617440413>();
        break;
    case 1617618409499:
        return std::make_shared<RunTimeCondition1617618409499>();
        break;
    default:
        std::cerr << "ConditionCreator: Unknown condition id requested: " << conditionConfId << std::endl;
        throw new std::exception();
        break;
    }
}
} // namespace alica
