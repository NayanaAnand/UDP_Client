#include "UDP_Client.h"
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#define MAX 80
#define PORT 4455
#define SA struct sockaddr

PREPARE_LOGGING(UDP_Client_i)

UDP_Client_i::UDP_Client_i(const char *uuid, const char *label) :
    UDP_Client_base(uuid, label)
{
    // Avoid placing constructor code here. Instead, use the "constructor" function.

}

UDP_Client_i::~UDP_Client_i()
{
}

void UDP_Client_i::constructor()
{
    /***********************************************************************************
     This is the RH constructor. All properties are properly initialized before this function is called 
    ***********************************************************************************/
}

int UDP_Client_i::serviceFunction()
{
    char buff[MAX];

        int sockfd;
        struct sockaddr_in servaddr;

        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1) {
                printf("socket creation failed...\n");
                exit(0);
        }
        else
                printf("Socket successfully created..\n");
        bzero(&servaddr, sizeof(servaddr));

        servaddr.sin_family = AF_INET;
        servaddr.sin_addr.s_addr = inet_addr("172.24.85.101");
        servaddr.sin_port = htons(PORT);

        if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) {
                printf("connection with the server failed...\n");
                exit(0);
        }
        else
                LOG_INFO(UDP_Client_i,"connected to the server..\n");


    while(1) {
            bzero(buff, sizeof(buff));
            //printf("Enter the string : ");
            strcpy(buff, "Hello, I am Client");
            write(sockfd, buff, sizeof(buff));
            bzero(buff, sizeof(buff));
            read(sockfd, buff, sizeof(buff));
            LOG_INFO(UDP_Client_i, "Data Recieved : " << buff);
            if ((strncmp(buff, "exit", 4)) == 0) {
                    printf("Client Exit...\n");
                    break;
            }
    }

        close(sockfd);

        return 0;
}

