#include "ConstraintCreator.h"

#include "constraints/Go2RandomPosition1617618064309Constraints.h"
#include "constraints/GoTo1617618375823Constraints.h"
#include "constraints/Master1617617242750Constraints.h"
#include "constraints/Move1617618120113Constraints.h"

#include <iostream>

namespace alica
{

ConstraintCreator::ConstraintCreator() {}

ConstraintCreator::~ConstraintCreator() {}

std::shared_ptr<BasicConstraint> ConstraintCreator::createConstraint(int64_t constraintConfId)
{
    switch (constraintConfId) {
    case 1617618409499:
        return std::make_shared<Constraint1617618409499>();
        break;
    default:
        std::cerr << "ConstraintCreator: Unknown constraint requested: " << constraintConfId << std::endl;
        throw new std::exception();
        break;
    }
}

} // namespace alica
