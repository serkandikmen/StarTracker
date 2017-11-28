#include "client.h"

Client::Client(char* host, int port)
{	
	_host = host;
	_port = port;
}

Client::~Client()
{
}

int Client::connectToServer()
{
	_socketfd = socket(AF_INET, SOCK_STREAM, 0);
	if(_socketfd < 0) 
	{
		printf("Error opening socket\n");
		return -1;
	}
	
	//init connection

	_server = gethostbyname(_host);
	bzero((char*) &_serverAddress, sizeof(_serverAddress));
	_serverAddress.sin_family = AF_INET;
	bcopy((char*) _server->h_addr, (char*) &_serverAddress.sin_addr.s_addr, _server->h_length);
	_serverAddress.sin_port = htons(_port);
	if(!connect(_socketfd, (struct sockaddr*) &_serverAddress, sizeof(_serverAddress)))
	{
		printf("Error connecting to server");
		return -1;	
	}

	return 1;
}

int Client::unconnectToServer()
{
	return close(_socketfd);
}

int Client::receive(char* c)
{
	return read(_socketfd, c, 1024);
}

unsigned char* Client::getBytesLength(long value)
{
	unsigned char* temp = new unsigned char[4];
	temp[0] = (long)((value>>24) & 0xFF);
	temp[1] = (long)((value>>16) & 0xFF);
	temp[2] = (long)((value>>8) & 0xFF);
	temp[3] = (long)((value) & 0xFF);
	return temp;
}

unsigned char* Client::getBytesFromInt(int value)
{
	unsigned char* temp = new unsigned char[4];
	temp[0] = (int)((value>>24) & 0xFF);
	temp[1] = (int)((value>>16) & 0xFF);
	temp[2] = (int)((value>>8) & 0xFF);
	temp[3] = (int)((value) & 0xFF);
	return temp;
}

long Client::sendImage(unsigned char* image, long length, unsigned char id)
{
	unsigned char* lengthBytes = getBytesLength(length);
	unsigned char* temp = new unsigned char[7];
	temp[0] = DELIMITER;
	temp[1] = id;
	temp[2] = *lengthBytes++;
	temp[3] = *lengthBytes++;
	temp[4] = *lengthBytes++;
	temp[5] = *lengthBytes++;
	temp[6] = TYPE_IMAGE;
	write(_socketfd, temp, 7);
	return write(_socketfd, image, length);
}

int Client::sendPosition(int x, int y, unsigned char id)
{
	unsigned char* lengthBytes = getBytesLength((long)8); // int = 4bytes, 2 int variables for each x and y
	unsigned char* temp = new unsigned char[7];
	temp[0] = DELIMITER;
	temp[1] = id;
	temp[2] = *lengthBytes++;
	temp[3] = *lengthBytes++;
	temp[4] = *lengthBytes++;
	temp[5] = *lengthBytes++;
	temp[6] = TYPE_POSITION;
	write(_socketfd, temp, 7);

	int n = 0;
	unsigned char tempPos[4];
	unsigned char* posX = getBytesFromInt(x);
	unsigned char* posY = getBytesFromInt(y);
	tempPos[0] = *posX++;
	tempPos[1] = *posX++;
	tempPos[2] = *posX++;
	tempPos[3] = *posX++;
	n = write(_socketfd, tempPos, 4);

	tempPos[0] = *posY++;
	tempPos[1] = *posY++;
	tempPos[2] = *posY++;
	tempPos[3] = *posY++;
	n += write(_socketfd, tempPos, 4);
	return n;
}

int Client::sendAttitude(int heading, unsigned char id)
{
	unsigned char* lengthBytes = getBytesLength((long)4); // int = 4bytes
	unsigned char* temp = new unsigned char[7];
	temp[0] = DELIMITER;
	temp[1] = id;
	temp[2] = *lengthBytes++;
	temp[3] = *lengthBytes++;
	temp[4] = *lengthBytes++;
	temp[5] = *lengthBytes++;
	temp[6] = TYPE_ATTITUDE;
	write(_socketfd, temp, 7);

	unsigned char tempAtt[4];
	unsigned char* att = getBytesFromInt(heading);
	tempAtt[0] = *att++;
	tempAtt[1] = *att++;
	tempAtt[2] = *att++;
	tempAtt[3] = *att++;
	return write(_socketfd, tempAtt, 4);
}
