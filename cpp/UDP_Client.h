#ifndef UDP_CLIENT_I_IMPL_H
#define UDP_CLIENT_I_IMPL_H

#include "UDP_Client_base.h"

class UDP_Client_i : public UDP_Client_base
{
    ENABLE_LOGGING
    public:
        UDP_Client_i(const char *uuid, const char *label);
        ~UDP_Client_i();

        void constructor();

        int serviceFunction();

    protected:
};

#endif // UDP_CLIENT_I_IMPL_H
