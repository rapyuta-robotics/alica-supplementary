#include "supplementary/WorldModel.h"

#include <engine/AlicaClock.h>
#include <engine/AlicaEngine.h>

namespace supplementary
{
WorldModel::WorldModel()
        : maySendMessages(true)
        , alicaContext(nullptr)
        , ownID(nullptr)
{
    essentials::SystemConfig& sc = essentials::SystemConfig::getInstance();
    this->maySendMessages = sc["WorldModel"]->get<bool>("WorldModel", "MaySendMessages", NULL);
}

WorldModel::~WorldModel() {}

void WorldModel::init() {}

bool WorldModel::setAlicaContext(alica::AlicaContext* alicaContext)
{
    std::cout << "WorldModel: setAlicaContext called!" << std::endl;
    if (this->alicaContext == nullptr) {
        this->alicaContext = alicaContext;
        return true;
    } else {
        return false;
    }
}

alica::AlicaContext* WorldModel::getAlicaContext()
{
    return this->alicaContext;
}

alica::AlicaTime WorldModel::getTime()
{
    if (this->alicaContext != nullptr) {
        return this->alicaContext->getAlicaClock().now();
    } else {
        return alica::AlicaTime::zero();
    }
}

bool WorldModel::isMaySendMessages() const
{
    return this->maySendMessages;
}

void WorldModel::setMaySendMessages(bool maySendMessages)
{
    this->maySendMessages = maySendMessages;
}

/**
 * The AlicaEngine must be set, before this method is called!
 */
const essentials::IdentifierConstPtr WorldModel::getOwnId()
{
    if (!this->ownID) {
        this->ownID = this->alicaContext->getLocalAgentId();
    }
    return this->ownID;
}

} // namespace supplementary
