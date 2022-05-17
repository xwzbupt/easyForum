#include <winsock2.h>
#pragma comment(lib, "WS2_32")
#include <iostream>

using namespace std;

int main()
{
	//1.启动SOCKET库，版本为2.0
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	wVersionRequested = MAKEWORD(2, 0);
	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0)
	{
		cout << "Socket2.0初始化失败，Exit!";
		return 0;
	}
	if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 0)
	{
		WSACleanup();
		return 0;
	}

	//2.创建socket，
	SOCKET sock;                   //socket
	sock = socket(
		AF_INET,           //internetwork: UDP, TCP, etc
		SOCK_STREAM,        //TCP
		0                  //protocol
	);
	if (sock == INVALID_SOCKET)
	{
		cout << "Socket 创建失败，Exit!";
		return 0;
	}

	//3.设置发往的地址
	SOCKADDR_IN addrto;            //发往的地址	
	memset(&addrto, 0, sizeof(addrto));
	addrto.sin_family = AF_INET;

	//去掉SDL检查。设置项目属性，将c/c++->SDL检查设置为“否”即可跳过检查，使用旧的函数可编译成功。
	addrto.sin_addr.S_un.S_addr = inet_addr("127.0.0.1"); //旧函数，不设置sdl检查会报错
							      //端口号必须和服务器绑定的端口号一致
	addrto.sin_port = htons(7861);
	//申请链接服务器
	connect(sock, (SOCKADDR*)&addrto, sizeof(SOCKADDR));
	char recvBuf[1024];
	char sendBuf[1024];
	int n = 0;

	while (true)
	{
		int i=recv(sock, recvBuf, 1024, 0);
		if (i == SOCKET_ERROR)
		{
			cout << "连接失败";
		}
		cout << recvBuf;

		Sleep(1000);

		cin >> sendBuf;
		i=send(sock, sendBuf, 1024, 0);
		if (i == SOCKET_ERROR)
		{
			cout << "连接失败";
		}
			
		memset(sendBuf, 0, sizeof(sendBuf));
		if (n > 10)
		{
			sprintf(sendBuf,"123");
			send(sock, sendBuf, 1024, 0);
			break;
		}
	}
	Sleep(5000);
	cout << "客户端关闭" << endl;
	closesocket(sock);
	WSACleanup();
	return 0;
}
