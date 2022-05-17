#include <winsock2.h>
#pragma comment(lib, "WS2_32")
#include <iostream>

using namespace std;

int main()
{
	//1.����SOCKET�⣬�汾Ϊ2.0
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	wVersionRequested = MAKEWORD(2, 0);
	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0)
	{
		cout << "Socket2.0��ʼ��ʧ�ܣ�Exit!";
		return 0;
	}
	if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 0)
	{
		WSACleanup();
		return 0;
	}

	//2.����socket��
	SOCKET sock;                   //socket
	sock = socket(
		AF_INET,           //internetwork: UDP, TCP, etc
		SOCK_STREAM,        //TCP
		0                  //protocol
	);
	if (sock == INVALID_SOCKET)
	{
		cout << "Socket ����ʧ�ܣ�Exit!";
		return 0;
	}

	//3.���÷����ĵ�ַ
	SOCKADDR_IN addrto;            //�����ĵ�ַ	
	memset(&addrto, 0, sizeof(addrto));
	addrto.sin_family = AF_INET;

	//ȥ��SDL��顣������Ŀ���ԣ���c/c++->SDL�������Ϊ���񡱼���������飬ʹ�þɵĺ����ɱ���ɹ���
	addrto.sin_addr.S_un.S_addr = inet_addr("127.0.0.1"); //�ɺ�����������sdl���ᱨ��
							      //�˿ںű���ͷ������󶨵Ķ˿ں�һ��
	addrto.sin_port = htons(7861);
	//�������ӷ�����
	connect(sock, (SOCKADDR*)&addrto, sizeof(SOCKADDR));
	char recvBuf[1024];
	char sendBuf[1024];
	int n = 0;

	while (true)
	{
		int i=recv(sock, recvBuf, 1024, 0);
		if (i == SOCKET_ERROR)
		{
			cout << "����ʧ��";
		}
		cout << recvBuf;

		Sleep(1000);

		cin >> sendBuf;
		i=send(sock, sendBuf, 1024, 0);
		if (i == SOCKET_ERROR)
		{
			cout << "����ʧ��";
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
	cout << "�ͻ��˹ر�" << endl;
	closesocket(sock);
	WSACleanup();
	return 0;
}
