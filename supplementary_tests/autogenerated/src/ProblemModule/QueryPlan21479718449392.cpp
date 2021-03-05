#include "ProblemModule/QueryPlan21479718449392.h"
/*PROTECTED REGION ID(eph1479718449392) ENABLED START*/
// Add additional using directives here
/*PROTECTED REGION END*/

namespace alica
{
// Plan:QueryPlan21479718449392
QueryPlan21479718449392::QueryPlan21479718449392()
        : DomainPlan("QueryPlan21479718449392")
{
    /*PROTECTED REGION ID(con1479718449392) ENABLED START*/
    // Add additional options here
    /*PROTECTED REGION END*/
}
QueryPlan21479718449392::~QueryPlan21479718449392()
{
    /*PROTECTED REGION ID(dcon1479718449392) ENABLED START*/
    // Add additional options here
    /*PROTECTED REGION END*/
}
/**
 * Task: DefaultTask  -> EntryPoint-ID: 1479718449394
 */
std::shared_ptr<UtilityFunction> UtilityFunction1479718449392::getUtilityFunction(Plan* plan)
{
    /*PROTECTED REGION ID(1479718449392) ENABLED START*/

    shared_ptr<UtilityFunction> defaultFunction = make_shared<DefaultUtilityFunction>(plan);
    return defaultFunction;

    /*PROTECTED REGION END*/
}

/*PROTECTED REGION ID(methods1479718449392) ENABLED START*/
// Add additional options here
/*PROTECTED REGION END*/
} // namespace alica
