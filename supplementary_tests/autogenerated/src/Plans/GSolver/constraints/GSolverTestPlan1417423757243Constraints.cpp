#include "Plans/GSolver/constraints/GSolverTestPlan1417423757243Constraints.h"
using namespace std;
using namespace alica;
/*PROTECTED REGION ID(ch1417423757243) ENABLED START*/
#include <autodiff/AutoDiff.h>
#include <engine/constraintmodul/ProblemDescriptor.h>
#include <iostream>

using namespace autodiff;
/*PROTECTED REGION END*/

namespace alicaAutogenerated
{
// Plan:GSolverTestPlan

/*
 * Tasks:
 * - EP:1417423777546 : DefaultTask (1225112227903)
 *
 * States:
 * - SolverState (1417423777544)
 *
 * Vars:
 * - X (1417424527157)
 * - Y (1417424531712)
 */

/*
 * RuntimeCondition - (Name): NewRuntimeCondition
 * (ConditionString):
 * Static Variables: [X, Y]
 * Domain Variables:

 */
void Constraint1417424512343::getConstraint(shared_ptr<ProblemDescriptor> c, shared_ptr<RunningPlan>)
{
    /*PROTECTED REGION ID(cc1417424512343) ENABLED START*/
    // Proteced
    autodiff::Variable* xv = dynamic_cast<autodiff::Variable*>(c->getStaticVars()[0]);
    if (xv == nullptr) {
        cout << "Constraint1417424512343::getConstraint !!!!!!!!!!!!!!!!!!!!! error" << endl;
        return;
    }
    xv->editRange().intersect(0.0, 10000.0);

    autodiff::Variable* yv = dynamic_cast<autodiff::Variable*>(c->getStaticVars()[1]);
    if (yv == nullptr) {
        cout << "Constraint1417424512343::getConstraint !!!!!!!!!!!!!!!!!!!!! error" << endl;
        return;
    }
    yv->editRange().intersect(0.0, 10000.0);

    TermPtr x = xv;
    TermPtr y = yv;

    TermPtr constraint = x->getOwner()->trueConstant();
    constraint = constraint & (x->getOwner()->constant(5000) > x);
    constraint = constraint & (x->getOwner()->constant(4000) < x);

    constraint = constraint & (x->getOwner()->constant(8000) > y);
    constraint = constraint & (x->getOwner()->constant(7000) < y);
    c->setConstraint(constraint);

    TermPtr utility = x->getOwner()->constant(1.0);
    c->setUtility(utility);
    c->setUtilitySufficiencyThreshold(1.0);

    /*PROTECTED REGION END*/
}

// State: SolverState

// State: SolverState

} // namespace alicaAutogenerated