#pragma once

#include <essentials/SystemConfig.h>
#include <essentials/IdentifierConstPtr.h>

namespace alica
{
    class AlicaContext;
    class AlicaTime;
} // namespace alica

namespace supplementary
{

    class WorldModel
    {
    public:
        WorldModel();
        virtual ~WorldModel();
        virtual void init();
        alica::AlicaTime getTime();
        bool isMaySendMessages() const;
        void setMaySendMessages(bool maySendMessages);
        const essentials::IdentifierConstPtr getOwnId();
        bool setAlicaContext(alica::AlicaContext* alicaContext);
        alica::AlicaContext* getAlicaContext();

    protected:
        alica::AlicaContext* alicaContext;
        bool maySendMessages;
        essentials::IdentifierConstPtr ownID;
    };
} // namespace supplementary