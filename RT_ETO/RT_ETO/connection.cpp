#include "stdafx.h"
#include "connection.h"

connection::connection(string _port) 
{
	this->port = sizeof(_port) > 0 ? _port : "8080";
	this->result = NULL;
	this->ptr = NULL;
	
}

connection::~connection()
{

}

void connection::init()
{
	/*// Setup address specifications.
	ZeroMemory(&this->hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;

	// Resolve the local address and port to be used by the server.
	int iResult = getaddrinfo(NULL, this->port.c_str(), &this->hints, &this->result);
	if (iResult != 0) {
		printf("getaddrinfo failed: %d\n", iResult);
		WSACleanup();
		throw new ConnectionException("Could not get info address");
	}

	// Instantiate socket instance.
	SOCKET listen_socket = INVALID_SOCKET;

	// Create a SOCKET for the server to listen for client connections.
	listen_socket = socket(this->result->ai_family, this->result->ai_socktype, this->result->ai_protocol);

	// If socket is error, throw exception.
	if (listen_socket == INVALID_SOCKET) {
		printf("Error at socket(): %ld\n", WSAGetLastError());
		freeaddrinfo(this->result);
		WSACleanup();
		throw new ConnectionException("Could not create socket instance.");
	}

	// Setup the TCP listening socket.
	iResult = bind(listen_socket, this->result->ai_addr, (int)result->ai_addrlen);

	// If result in error.
	if (iResult == SOCKET_ERROR) {
		printf("bind failed with error: %d\n", WSAGetLastError());
		freeaddrinfo(result);
		closesocket(listen_socket);
		WSACleanup();
		throw new ConnectionException("Could not create socket instance.");
	}

	// Delete address info.
	freeaddrinfo(result);

	// Initiate listening process on socket.
	if (listen(listen_socket, SOMAXCONN) == SOCKET_ERROR) {
		printf("Listen failed with error: %ld\n", WSAGetLastError());
		closesocket(listen_socket);
		WSACleanup();
		throw new ConnectionException("Could not conduct listening process.");
	}

	// Client socket.
	SOCKET client_socket = INVALID_SOCKET;

	// Accept a client socket
	client_socket = accept(listen_socket, NULL, NULL);
	if (client_socket == INVALID_SOCKET) {
		printf("accept failed: %d\n", WSAGetLastError());
		closesocket(listen_socket);
		WSACleanup();
		throw new ConnectionException("Could not recieve client socket.");
	}*/
}

void connection::begin_listen()
{

}