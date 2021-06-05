#include <iostream>
#include "ossie/ossieSupport.h"

#include "UDP_Client.h"
int main(int argc, char* argv[])
{
    UDP_Client_i* UDP_Client_servant;
    Component::start_component(UDP_Client_servant, argc, argv);
    return 0;
}

