#include "BehaviourCreator.h"
#include "Go2RandomPosition.h"
#include "GoTo.h"
#include "engine/BasicBehaviour.h"

namespace alica
{

BehaviourCreator::BehaviourCreator() {}

BehaviourCreator::~BehaviourCreator() {}

std::shared_ptr<BasicBehaviour> BehaviourCreator::createBehaviour(int64_t behaviourId)
{
    switch (behaviourId) {
    case 1617618064309:
        return std::make_shared<Go2RandomPosition>();
        break;
    case 1617618375823:
        return std::make_shared<GoTo>();
        break;
    default:
        std::cerr << "BehaviourCreator: Unknown behaviour requested: " << behaviourId << std::endl;
        throw new std::exception();
        break;
    }
}
} // namespace alica
