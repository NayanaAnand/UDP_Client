#ifndef UDP_CLIENT_BASE_IMPL_BASE_H
#define UDP_CLIENT_BASE_IMPL_BASE_H

#include <boost/thread.hpp>
#include <ossie/Component.h>
#include <ossie/ThreadedComponent.h>


class UDP_Client_base : public Component, protected ThreadedComponent
{
    public:
        UDP_Client_base(const char *uuid, const char *label);
        ~UDP_Client_base();

        void start() throw (CF::Resource::StartError, CORBA::SystemException);

        void stop() throw (CF::Resource::StopError, CORBA::SystemException);

        void releaseObject() throw (CF::LifeCycle::ReleaseError, CORBA::SystemException);

        void loadProperties();

    protected:

    private:
};
#endif // UDP_CLIENT_BASE_IMPL_BASE_H
