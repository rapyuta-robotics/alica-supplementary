#include "Master1617617242750.h"
/*PROTECTED REGION ID(eph1617617242750) ENABLED START*/
// Add additional options here
#include <alica_ros_turtlesim/world_model.hpp>
/*PROTECTED REGION END*/

namespace alica
{
// Plan:Master
/**
 * Task: DefaultTask  -> EntryPoint-ID: 1617618015424
 */
std::shared_ptr<UtilityFunction> UtilityFunction1617617242750::getUtilityFunction(Plan* plan)
{
    /*PROTECTED REGION ID(1617617242750) ENABLED START*/
    std::shared_ptr<UtilityFunction> defaultFunction = std::make_shared<DefaultUtilityFunction>(plan);
    return defaultFunction;
    /*PROTECTED REGION END*/
}
/**
 * Outgoing transition:
 *   - Name: 1617617417531, ConditionString: , Comment: MISSING_COMMENT
 *
 * Abstract plans in current state:
 *   - Go2RandomPosition (1617618064309)
 *
 * Tasks in plan:
 *   - DefaultTask (1617616289767) (Entrypoint: 1617618015424)
 *
 * States in plan:
 *   - Init (1617617300343)
 *   - Move (1617617304997)
 *
 * Variables of precondition:
 */
bool PreCondition1617617417531::evaluate(std::shared_ptr<RunningPlan> rp)
{
    /*PROTECTED REGION ID(1617617417528) ENABLED START*/
    // std::cout << "The PreCondition 1617617417531 in Transition 'FromInitTo Move' is not implement yet!" << std::endl;
    return rp->isAnyChildStatus(PlanStatus::Success);
    /*PROTECTED REGION END*/
}
/**
 * Outgoing transition:
 *   - Name: 1617617440413, ConditionString: , Comment: MISSING_COMMENT
 *
 * Abstract plans in current state:
 *   - Move (1617618120113)
 *
 * Tasks in plan:
 *   - DefaultTask (1617616289767) (Entrypoint: 1617618015424)
 *
 * States in plan:
 *   - Init (1617617300343)
 *   - Move (1617617304997)
 *
 * Variables of precondition:
 */
bool PreCondition1617617440413::evaluate(std::shared_ptr<RunningPlan> rp)
{
    /*PROTECTED REGION ID(1617617440412) ENABLED START*/
    // std::cout << "The PreCondition 1617617440413 in Transition 'FromMoveTo Init' is not implement yet!" << std::endl;
    return turtlesim::ALICATurtleWorldModel::get()->getInit();
    /*PROTECTED REGION END*/
}
} // namespace alica
