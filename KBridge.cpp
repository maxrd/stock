#include "stdafx.h"
#include ".\kbridge.h"

CKBridge::CKBridge(void)
{
	m_socket = 0;
	m_bInit = false;
    m_bConnect = false;
}

CKBridge::~CKBridge(void)
{
}
//送资料的函式
CString CKBridge::SendMsg(CString  data)
{
   CString str = "NO";
   if(m_bInit)
   {
	   try {
			if(!m_bConnect)
				m_bConnect = ConnectToHost(83,"127.0.0.1");
			if(m_bConnect)
			{
				//预设处里是RCV_NOW_STRUCTEx 你可以自己改资料型别
				//if(strchr(data,'$'))
				//{
					UINT size = data.GetLength();
					int err= send(m_socket,data,size,0);
					char strText[1024];
					sprintf(strText,"%d",::WSAGetLastError());					                    
					//if(strText.GetLength()>=1) {					
					//   str = "error";
					//} 
					//else {
                       if(err != SOCKET_ERROR) str = "ok";
					//}
				//}
				//else {
					  //Release();
		              //Init();
				//}
			}
	   }
	   catch(...) {
		   //Release();
		   //Init();

	   }
   }
   return str;
}
//连结到SERVER的函式
bool CKBridge::ConnectToHost(int PortNo, char* IPAddress)
{
    SOCKADDR_IN target; //Socket address information


    target.sin_family = AF_INET; // address family Internet

    target.sin_port = htons (PortNo); //Port to connect on

    target.sin_addr.s_addr = inet_addr (IPAddress); //Target IP

    if(m_socket != 0)
        closesocket(m_socket);
	m_socket = 0;
    m_socket = socket (AF_INET, SOCK_STREAM, IPPROTO_TCP); //Create socket

    if (m_socket == INVALID_SOCKET)
        return false; //Couldn't create the socket
    //Try connecting...
    if (connect(m_socket, (SOCKADDR *)&target, sizeof(target)) == SOCKET_ERROR)
        return false; //Couldn't connect
    else
        return true; //Success
}
//初始化 WINSOCK
void CKBridge::Init(void)
{
    WSADATA wsadata;

    int error = WSAStartup(0x0202, &wsadata);

    if (error)
	{
        return;
	}

    if(wsadata.wVersion != 0x0202)
    {
        WSACleanup(); //Clean up Winsock
        return ;
    }
	m_bInit = true;
	m_bConnect = ConnectToHost(83,"127.0.0.1");
}
//结束处里WINSOCKET
void  CKBridge::Release(void)
{
    if (m_socket)
        closesocket(m_socket);
	WSACleanup(); //Clean up Winsock
}