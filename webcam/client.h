#ifndef CLIENT_H_
#define CLIENT_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <iostream>

const unsigned char DELIMITER = 255;
const unsigned char TYPE_IMAGE = 1;
const unsigned char TYPE_POSITION = 2;
const unsigned char TYPE_ATTITUDE = 3;

using namespace std;

class Client
{

public: 
	Client(char* host, int port);
	virtual ~Client();
	int connectToServer();
	int unconnectToServer();
	int receive(char* c);
	unsigned char* getBytesLength(long value);
	unsigned char* getBytesFromInt(int value);
	long sendImage(unsigned char* image, long length, unsigned char id);
	int sendPosition(int x, int y, unsigned char id);
	int sendAttitude(int heading, unsigned char id);
private: 
	char* _host;
	int _socketfd, _port;
	struct sockaddr_in _serverAddress;
	struct hostent* _server;

};


#endif
