#pragma once
#include <winsock.h>
#include <iostream>
using namespace std;

void InitSocketTest()
{
	WSADATA wsaData;

	if (WSAStartup(MAKEWORD(1, 1), &wsaData) == 0)
	{
		cout << "Success";
	}
	else
	{
		cout << "Fail";
	}
}