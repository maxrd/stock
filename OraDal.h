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
	//// ���������ַ�����Ϊ��BSTR�ͻ���_bstr_t���� 
	//_bstr_t strConnect,bstrSQL;	
	
	public:	
		bool   m_bInit;
		OraDal(void);		
	    ~OraDal(void);
		bool AddData(CString data);
		void conn(void);
		void Close(void);
	
};