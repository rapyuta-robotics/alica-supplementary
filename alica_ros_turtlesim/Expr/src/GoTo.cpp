#include "GoTo.h"
#include <memory>

/*PROTECTED REGION ID(inccpp1617618375823) ENABLED START*/
// Add additional includes here
#include <alica_ros_turtlesim/world_model.hpp>
#include <constraintsolver/CGSolver.h>
/*PROTECTED REGION END*/

namespace alica
{
/*PROTECTED REGION ID(staticVars1617618375823) ENABLED START*/
// initialise static variables here
/*PROTECTED REGION END*/

GoTo::GoTo()
        : DomainBehaviour("GoTo")
{
    /*PROTECTED REGION ID(con1617618375823) ENABLED START*/
    // Add additional options here
    /*PROTECTED REGION END*/
}
GoTo::~GoTo()
{
    /*PROTECTED REGION ID(dcon1617618375823) ENABLED START*/
    // Add additional options here
    /*PROTECTED REGION END*/
}
void GoTo::run(void* msg)
{
    /*PROTECTED REGION ID(run1617618375823) ENABLED START*/
    // Add additional options here
    if (!_query.getSolution<reasoner::CGSolver, double>(getPlanContext(), _results)) {
        std::cout << getName() << " - Solution to query not found." << std::endl;
        return;
    }
    // move turtle to goal
    if (turtlesim::ALICATurtleWorldModel::get()->turtle.move_toward_goal(_results[0], _results[1])) {
        setSuccess(); // set success if turtle reach goal
    }

    /*PROTECTED REGION END*/
}
void GoTo::initialiseParameters()
{
    /*PROTECTED REGION ID(initialiseParameters1617618375823) ENABLED START*/
    // Add additional options here
    _query.clearDomainVariables();
    _query.addDomainVariable(getEngine()->getTeamManager().getDomainVariable(getOwnId(), "x"));
    _query.addDomainVariable(getEngine()->getTeamManager().getDomainVariable(getOwnId(), "y"));

    /*PROTECTED REGION END*/
}
/*PROTECTED REGION ID(methods1617618375823) ENABLED START*/
// Add additional options here
/*PROTECTED REGION END*/

} /* namespace alica */
