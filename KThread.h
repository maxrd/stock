#pragma once
#include "SCStkDrv.h"
#include <vector>
#include <string>
#include ".\kbridge.h"
//#include ".\OraDal.h"
using namespace std;
class CKThread
{
private:
	//Ԥ�账����RCV_NOW_STRUCTEx ������Լ��������ͱ�
	
	HANDLE                    m_SomeThingThread;
	bool                      m_SomeThingRun;
	CKBridge                  m_CKbirdge;
	//OraDal                    m_OraDal;
	bool					  test_flage,m_bInit; 
	CRITICAL_SECTION          m_guard;
	int sort;
	int sendCount;
	int restartCount;
public:
	CKThread(void);
	~CKThread(void);
    
	void  Init(void);
	void  Release(void);
	void  SomeThing(void);
	void  AddData(CString data);
	static DWORD WINAPI SomeThingFunc(LPVOID pDt);
	void  SetTestFlage(bool flage);
	void  SetSort(int num);
	void DoEvents(void);
	vector<CString>			  m_vpArray;
	
};
