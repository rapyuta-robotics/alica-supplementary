#include "Go2RandomPosition.h"
#include <memory>

/*PROTECTED REGION ID(inccpp1617618064309) ENABLED START*/
// Add additional includes here
#include <alica_ros_turtlesim/world_model.hpp>
#include <random>
/*PROTECTED REGION END*/

namespace alica
{
/*PROTECTED REGION ID(staticVars1617618064309) ENABLED START*/
// initialise static variables here
/*PROTECTED REGION END*/

Go2RandomPosition::Go2RandomPosition()
        : DomainBehaviour("Go2RandomPosition")
{
    /*PROTECTED REGION ID(con1617618064309) ENABLED START*/
    // Add additional options here
    /*PROTECTED REGION END*/
}
Go2RandomPosition::~Go2RandomPosition()
{
    /*PROTECTED REGION ID(dcon1617618064309) ENABLED START*/
    // Add additional options here
    /*PROTECTED REGION END*/
}
void Go2RandomPosition::run(void* msg)
{
    /*PROTECTED REGION ID(run1617618064309) ENABLED START*/
    // Add additional options here
    if (isSuccess()) {
        return;
    }

    // code for generate random value between 0 and 10 which is default turtlesim area size
    std::random_device seed_gen;
    std::default_random_engine engine(seed_gen());
    std::uniform_real_distribution<> dist(0, 10.0);

    // teleport turtle to random place
    turtlesim::ALICATurtleWorldModel::get()->turtle.teleport(dist(engine), dist(engine));
    turtlesim::ALICATurtleWorldModel::get()->setInit(false);
    setSuccess();
    /*PROTECTED REGION END*/
}
void Go2RandomPosition::initialiseParameters()
{
    /*PROTECTED REGION ID(initialiseParameters1617618064309) ENABLED START*/
    // Add additional options here

    /*PROTECTED REGION END*/
}
/*PROTECTED REGION ID(methods1617618064309) ENABLED START*/
// Add additional options here
/*PROTECTED REGION END*/

} /* namespace alica */
