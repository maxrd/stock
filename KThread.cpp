#include "stdafx.h"
#include ".\kthread.h"

CKThread::CKThread(void)
{
	m_SomeThingRun = false;
	m_SomeThingThread = NULL;
	m_bInit = false;
	sendCount =0;
	restartCount=0;
	
}

CKThread::~CKThread(void)
{
}
DWORD WINAPI CKThread::SomeThingFunc(LPVOID pDt)
{
	CKThread *p = (CKThread*)pDt;
	p->SomeThing();
	return 0;
}
//处里THREAD的函式
void CKThread::SomeThing(void)
{
	do
	{
        CTime time = CTime::GetCurrentTime(); 
		int m_nYear = time.GetYear(); ///年 
        int m_nMonth = time.GetMonth(); ///月
        int m_nDay = time.GetDay(); ///日
		int m_nhour = time.GetHour();
		int m_nmin = time.GetMinute();

		int m_nsec = time.GetSecond();
        
		if(m_vpArray.size() > 0 )
		{					
			/*EnterCriticalSection(&m_guard);
			for(UINT i = 0; i < m_vpArray.size();i++)
			{	
				CString str1 = m_vpArray[0];
				CString str = m_CKbirdge.SendMsg(str1);
				if(!str.Compare("ok")) 
				{

					m_vpArray.erase( m_vpArray.begin( ) );  

				}
				Sleep(30);
			}
			LeaveCriticalSection(&m_guard);*/
			if(sort == 3) {
				string bb = "xxx";
			}
			int sendflag=0;
			CString SendStr="";
			int start1 = 25;
			int start2 = 24;
			if(m_vpArray.size() < start1) {
				sendflag=m_vpArray.size()-1;		  
			}
			else
			{
				sendflag =start2;
			}
			bool rtn = false;
			EnterCriticalSection(&m_guard);
			try {							
					//m_OraDal.AddData(m_vpArray[0]);
                    //m_vpArray.erase( m_vpArray.begin( ));
					for(UINT i = 0; i <= sendflag;i++)
					{	
						SendStr +=  m_vpArray[i];
						if(i< sendflag) 	 SendStr += "$";						
						if(i == sendflag) {
							SendStr = "Stock$"+SendStr ;
							CString str = m_CKbirdge.SendMsg(SendStr);
				            if(!str.Compare("ok"))
							{
								for(UINT j = 0; j <= sendflag;j++) {
								m_vpArray.erase( m_vpArray.begin( ) );  
								}
							}

							
						}
						
						
					}	
					restartCount++;
							
				
			}
			catch(...) {
				//Release();
				//Init();

			}
            LeaveCriticalSection(&m_guard);
			if(sendCount >=10) {
				Sleep(100);
			}
			else {
			    Sleep(5);
			}
			if(sendCount > 100000) sendCount = 10;
			
			if(restartCount>=500) {				
                m_CKbirdge.Release();
				m_CKbirdge.Init();
				restartCount=0;
			}
			
		}
		else {
			//restartCount++;
   //         if(restartCount>=60) {				
   //             //m_CKbirdge.Release();
			//	//m_CKbirdge.Init();
			//	restartCount=0;
			//}
			//if(m_bInit) {
			//	AddData("$ok");
			//}			
			Sleep(300);

		}
		
		//DoEvents();	
	}while(m_SomeThingRun);
	CloseHandle( m_SomeThingThread);
	m_SomeThingThread = 0;
}
void  CKThread::AddData(CString data)
{
	if(m_bInit)
	{
			EnterCriticalSection(&m_guard);
			m_vpArray.push_back(data);
			LeaveCriticalSection(&m_guard);		
	}
}
//初始化 THREAD
void  CKThread::Init(void)
{
	
	m_SomeThingRun = true;
	InitializeCriticalSection(&m_guard);
	//开始跑THREAD
	m_SomeThingThread = CreateThread( 
	NULL,                        // default security attributes 
	0,                           // use default stack size  
	SomeThingFunc,                  // thread function 
	this,                        // argument to thread function 
	0,                           // use default creation flags 
	NULL);
	m_CKbirdge.Init();
	m_bInit = true;
	//m_OraDal.conn();
}
//结束的处里
void  CKThread::Release(void)
{

    do
	{	
	    m_SomeThingRun = false;
		CloseHandle(m_SomeThingThread);
		m_SomeThingThread =0;
		Sleep(50);
	}while(m_SomeThingThread);

	if(m_vpArray.size() > 0)
		m_vpArray.clear();
	m_CKbirdge.Release();
	if(m_bInit)
	DeleteCriticalSection(&m_guard);
	//m_OraDal.Close();
	m_bInit = false;
}
void CKThread::SetTestFlage(bool flage) {
	test_flage = flage;
}
void CKThread::SetSort(int num) {
	sort = num;

}
void CKThread::DoEvents () {

    MSG msg;

   while   (   PeekMessage (   &msg,   NULL,   0,  0,  PM_REMOVE))
           {
               DispatchMessage     (   &msg);
           }
}