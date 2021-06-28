#include "UDP_Client.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT    4045
#define MAXLINE 1024
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
	int sockfd;
        char buffer[MAXLINE];
        char *hello = "Hello from client";
        struct sockaddr_in       servaddr;
        if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
                perror("socket creation failed");
                exit(EXIT_FAILURE);
        }
        else
                LOG_INFO(UDP_Client_i, "Socket created successfully");
        memset(&servaddr, 0, sizeof(servaddr));
        servaddr.sin_family = AF_INET;
        servaddr.sin_port = htons(PORT);
        servaddr.sin_addr.s_addr = INADDR_ANY;
        int n, len;
        sendto(sockfd, (const char *)hello, strlen(hello), MSG_CONFIRM, (const struct sockaddr *) &servaddr, sizeof(servaddr));
        LOG_INFO(UDP_Client_i, "Hello message sent");
        n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *) &servaddr, (socklen_t*)&len);
        buffer[n] = '\0';
        LOG_INFO(UDP_Client_i, "Data Recieved : " << buffer);
        close(sockfd);
	return 0;
}

