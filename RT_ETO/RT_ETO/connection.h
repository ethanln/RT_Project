#pragma once
#ifndef CONNECTION_H
#define CONNECTION_H

#include <string>
#include <WinSock2.h>
#include <Ws2tcpip.h>
#include <WinBase.h>
#include <minwinbase.h>
#include <Windows.h>
#include "ConnectionException.h"

using namespace std;

class connection {
	private:
		string port;

		struct addrinfo *result;

		struct addrinfo *ptr;

		struct addrinfo hints;

	public:

		connection(string _port);

		~connection();

		virtual void init() throw(ConnectionException);

		virtual void begin_listen() throw(ConnectionException);
};

#endif