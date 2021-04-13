#pragma once

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1617618064309) ENABLED START*/
// Add additional includes here
/*PROTECTED REGION END*/

namespace alica
{
class Go2RandomPosition : public DomainBehaviour
{
public:
    Go2RandomPosition();
    virtual ~Go2RandomPosition();
    virtual void run(void* msg);
    /*PROTECTED REGION ID(pub1617618064309) ENABLED START*/
    // Add additional protected methods here
    /*PROTECTED REGION END*/
protected:
    virtual void initialiseParameters();
    /*PROTECTED REGION ID(pro1617618064309) ENABLED START*/
    // Add additional protected methods here
    /*PROTECTED REGION END*/
private:
    /*PROTECTED REGION ID(prv1617618064309) ENABLED START*/
    // Add additional private methods here
    /*PROTECTED REGION END*/
};
} /* namespace alica */
