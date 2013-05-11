#import "c:\Program Files\Common Files\System\ADO\msado15.dll" no_namespace rename("EOF", "EndOfFile")
#include <iostream>
#include "stdio.h"
#include <iomanip>
#include <string>
using namespace std;
class OraDal
{
	private:
     
	//_CommandPtr m_pCmd;	
	//_ConnectionPtr m_pConnection;
	//// 设置连接字符串，为是BSTR型或者_bstr_t类型 
	//_bstr_t strConnect,bstrSQL;	
	
	public:	
		bool   m_bInit;
		OraDal(void);		
	    ~OraDal(void);
		bool AddData(CString data);
		void conn(void);
		void Close(void);
	
};