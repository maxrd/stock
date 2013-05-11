#pragma once
#include "SCStkDrv.h"
#include <winsock.h>
#include <string>
using namespace std;
class CKBridge
{
private:
	SOCKET m_socket;
	bool   m_bInit;
   bool    m_bConnect;
public:
	CKBridge(void);
	~CKBridge(void);
    
	void Init(void);
    void Release(void);
	bool ConnectToHost(int PortNo, char* IPAddress); 
	CString SendMsg(CString data);
};
