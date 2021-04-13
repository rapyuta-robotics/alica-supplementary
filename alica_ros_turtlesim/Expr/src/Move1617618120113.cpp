#include "Move1617618120113.h"
/*PROTECTED REGION ID(eph1617618120113) ENABLED START*/
// Add additional options here
/*PROTECTED REGION END*/

namespace alica
{
// Plan:Move
// Check of RuntimeCondition - (Name): 1617618409499, (ConditionString): , (Comment) :

/**
 * Available Vars:
 */
bool RunTimeCondition1617618409499::evaluate(std::shared_ptr<RunningPlan> rp)
{
    /*PROTECTED REGION ID(1617618409499) ENABLED START*/
    // std::cout << "The RunTimeCondition 1617618409499 in Plan 'Move' is not implement yet!" << std::endl;
    return true;
    /*PROTECTED REGION END*/
}
/**
 * Task: FollowerTask  -> EntryPoint-ID: 1617618274891
 * Task: LeaderTask  -> EntryPoint-ID: 1617618291624
 */
std::shared_ptr<UtilityFunction> UtilityFunction1617618120113::getUtilityFunction(Plan* plan)
{
    /*PROTECTED REGION ID(1617618120113) ENABLED START*/
    std::shared_ptr<UtilityFunction> defaultFunction = std::make_shared<DefaultUtilityFunction>(plan);
    return defaultFunction;
    /*PROTECTED REGION END*/
}
} // namespace alica
