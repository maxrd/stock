#include "stdafx.h"
#include ".\OraDal.h"
OraDal::OraDal(void)
{
	//this->conn();

}
void OraDal::conn(void)
{
	 
	//try 
	//{
	//	if(m_pConnection == NULL) {		
	//		::CoInitialize(NULL); // ��ʼ��OLE/COM�⻷�� ��Ϊ����ADO�ӿ���׼��
	//		strConnect= "Provider=MSDAORA.1;Persist Security Info=TRUE;Data Source=stock;User ID=info;Password=info;Min Pool Size=10;Connection Lifetime=120;Connection Timeout=60;Incr Pool Size=10;Decr Pool Size=10;";

	//		// ����Connection����
	//		m_pConnection.CreateInstance(__uuidof(Connection));
	//		

	//		m_pConnection->CursorLocation = adUseClient;
	//		m_pConnection->Mode = adModeReadWrite;
	//		m_pConnection->ConnectionTimeout = 3;
	//		m_pConnection->CommandTimeout = 3;
	//		m_pConnection->ConnectionString = strConnect;
	//		//�����ݿ�����
	//		m_pConnection->Open("","","",adModeUnknown);
	//		if(m_pConnection==NULL) {
	//			cerr<<"Lind data ERROR!\n";
	//			m_bInit = false;
	//		}
	//		else  {
	//			m_bInit = true;
	//			cout <<"�������ݿ�ɹ���"<<endl;
	//		}
	//		CString bb = "";		
	//		::CoUninitialize();
	//	}
	//}
	//catch(_com_error e)
	//{
	//	m_bInit = false;
	//}
		
		
	
	
	
}

bool  OraDal::AddData(CString data)
{
	/*if(!m_pConnection->State) {
		this->conn();
	}*/
    try {  
	if(m_bInit) {
		    _CommandPtr m_pCmd;	
			_ConnectionPtr m_pConnection;
			// ���������ַ�����Ϊ��BSTR�ͻ���_bstr_t���� 
			_bstr_t strConnect,bstrSQL;


			::CoInitialize(NULL); // ��ʼ��OLE/COM�⻷�� ��Ϊ����ADO�ӿ���׼��
			strConnect= "Provider=MSDAORA.1;Persist Security Info=TRUE;Data Source=stock;User ID=info;Password=info;Min Pool Size=10;Connection Lifetime=120;Connection Timeout=60;Incr Pool Size=10;Decr Pool Size=10;";

			// ����Connection����
			m_pConnection.CreateInstance(__uuidof(Connection));
			

			m_pConnection->CursorLocation = adUseClient;
			m_pConnection->Mode = adModeReadWrite;
			m_pConnection->ConnectionTimeout = 3;
			m_pConnection->CommandTimeout = 3;
			m_pConnection->ConnectionString = strConnect;
			//�����ݿ�����
			m_pConnection->Open("","","",adModeUnknown);
			if(m_pConnection==NULL) {
				cerr<<"Lind data ERROR!\n";
				m_bInit = false;
			}
			else  {
				m_bInit = true;
				cout <<"�������ݿ�ɹ���"<<endl;
			}		
		

			m_pCmd.CreateInstance(__uuidof(Command));
			_ParameterPtr lPara0= m_pCmd->CreateParameter(_bstr_t("v_str"),adVarChar,adParamInput,80000);
			lPara0->PutValue(_variant_t(data));
			m_pCmd->Parameters->Append(lPara0);
	        
			////��Ʊ����
			//_ParameterPtr lPara1= m_pCmd->CreateParameter(_bstr_t("v_producname"),adVarChar,adParamInput,40);
			//lPara1->PutValue(_variant_t("��̩�Ƽ�"));
			//m_pCmd->Parameters->Append(lPara1);
	  //      
			////����ʱ��
			//_ParameterPtr lPara2= m_pCmd->CreateParameter(_bstr_t("v_productime"),adVarChar,adParamInput,15);
			//lPara2->PutValue(_variant_t("12:00:01"));
			//m_pCmd->Parameters->Append(lPara2);

			////�������̼�
			//_ParameterPtr lPara3= m_pCmd->CreateParameter(_bstr_t("v_zuorishoupan"),adNumeric,adParamInput,10);
			//lPara3->PutValue(_variant_t(10.1));
			//m_pCmd->Parameters->Append(lPara3);
	  //      
			////���̼�
			//_ParameterPtr lPara4= m_pCmd->CreateParameter(_bstr_t("v_kaipanjian"),adNumeric,adParamInput,10);
			//lPara4->PutValue(_variant_t(10.2));
			//m_pCmd->Parameters->Append(lPara4);

			////��߼�
			//_ParameterPtr lPara5= m_pCmd->CreateParameter(_bstr_t("v_zuigaojia"),adNumeric,adParamInput,10);
			//lPara5->PutValue(_variant_t(10.3));
			//m_pCmd->Parameters->Append(lPara5);

			////��ͼ�
			//_ParameterPtr lPara6= m_pCmd->CreateParameter(_bstr_t("v_zuidijia"),adNumeric,adParamInput,10);
			//lPara6->PutValue(_variant_t(10.4));
			//m_pCmd->Parameters->Append(lPara6);
	  //      
			////���̼�
			//_ParameterPtr lPara7= m_pCmd->CreateParameter(_bstr_t("v_shoupanjia"),adNumeric,adParamInput,10);
			//lPara7->PutValue(_variant_t(10.5));
			//m_pCmd->Parameters->Append(lPara7);

			////�ǵ�
			//_ParameterPtr lPara8= m_pCmd->CreateParameter(_bstr_t("v_zhangdie"),adNumeric,adParamInput,10);
			//lPara8->PutValue(_variant_t(10.6));
			//m_pCmd->Parameters->Append(lPara8);

			////���ճɽ�����
			//_ParameterPtr lPara9= m_pCmd->CreateParameter(_bstr_t("v_chengjiaoliang"),adNumeric,adParamInput,15);
			//lPara9->PutValue(_variant_t(123456));
			//m_pCmd->Parameters->Append(lPara9);

			////���ճɽ��� 
			//_ParameterPtr lPara10= m_pCmd->CreateParameter(_bstr_t("v_chengjiaoe"),adNumeric,adParamInput,15);
			//lPara10->PutValue(_variant_t(123456));
			//m_pCmd->Parameters->Append(lPara10);
	  //      
			////���1
			//_ParameterPtr lPara11= m_pCmd->CreateParameter(_bstr_t("v_buy1"),adNumeric,adParamInput,10);
			//lPara11->PutValue(_variant_t(10.8));
			//m_pCmd->Parameters->Append(lPara11);

			////����1
			//_ParameterPtr lPara12= m_pCmd->CreateParameter(_bstr_t("v_buy1liang"),adNumeric,adParamInput,12);
			//lPara12->PutValue(_variant_t(123456));
			//m_pCmd->Parameters->Append(lPara12);	
	  //      
			////���2
			//_ParameterPtr lPara13= m_pCmd->CreateParameter(_bstr_t("v_buy2"),adNumeric,adParamInput,10);
			//lPara13->PutValue(_variant_t(10.8));
			//m_pCmd->Parameters->Append(lPara13);

			////����2
			//_ParameterPtr lPara14= m_pCmd->CreateParameter(_bstr_t("v_buy1liang"),adNumeric,adParamInput,12);
			//lPara14->PutValue(_variant_t(123456));
			//m_pCmd->Parameters->Append(lPara14);

			//
			////���3
			//_ParameterPtr lPara15= m_pCmd->CreateParameter(_bstr_t("v_buy3"),adNumeric,adParamInput,10);
			//lPara15->PutValue(_variant_t(10.10));
			//m_pCmd->Parameters->Append(lPara15);


			////����3
			//_ParameterPtr lPara16= m_pCmd->CreateParameter(_bstr_t("v_buy3liang"),adNumeric,adParamInput,12);
			//lPara16->PutValue(_variant_t(123456));
			//m_pCmd->Parameters->Append(lPara16);
	  //      
			//
			////���4
			//_ParameterPtr lPara17= m_pCmd->CreateParameter(_bstr_t("v_buy4"),adNumeric,adParamInput,10);
			//lPara17->PutValue(_variant_t(10.12));
			//m_pCmd->Parameters->Append(lPara17);


			////����4
			//_ParameterPtr lPara18= m_pCmd->CreateParameter(_bstr_t("v_buy4liang"),adNumeric,adParamInput,12);
			//lPara18->PutValue(_variant_t(123456));
			//m_pCmd->Parameters->Append(lPara18);
	  //      
		 //   
			////���5
			//_ParameterPtr lPara19= m_pCmd->CreateParameter(_bstr_t("v_buy5"),adNumeric,adParamInput,10);
			//lPara19->PutValue(_variant_t(10.14));
			//m_pCmd->Parameters->Append(lPara19);

			////����5
			//_ParameterPtr lPara20= m_pCmd->CreateParameter(_bstr_t("v_buy5liang"),adNumeric,adParamInput,12);
			//lPara20->PutValue(_variant_t(123456));
			//m_pCmd->Parameters->Append(lPara20);


			////����1
			//_ParameterPtr lPara21= m_pCmd->CreateParameter(_bstr_t("v_sell1"),adNumeric,adParamInput,10);
			//lPara21->PutValue(_variant_t(10.8));
			//m_pCmd->Parameters->Append(lPara21);

			////����1
			//_ParameterPtr lPara22= m_pCmd->CreateParameter(_bstr_t("v_sell1liang"),adNumeric,adParamInput,12);
			//lPara22->PutValue(_variant_t(123456));
			//m_pCmd->Parameters->Append(lPara22);	


			////����1
			//_ParameterPtr lPara23= m_pCmd->CreateParameter(_bstr_t("v_sell2"),adNumeric,adParamInput,10);
			//lPara23->PutValue(_variant_t(10.8));
			//m_pCmd->Parameters->Append(lPara23);

			////����1
			//_ParameterPtr lPara24= m_pCmd->CreateParameter(_bstr_t("v_sell2liang"),adNumeric,adParamInput,12);
			//lPara24->PutValue(_variant_t(123456));
			//m_pCmd->Parameters->Append(lPara24);	

			////����1
			//_ParameterPtr lPara25= m_pCmd->CreateParameter(_bstr_t("v_sell3"),adNumeric,adParamInput,10);
			//lPara25->PutValue(_variant_t(10.8));
			//m_pCmd->Parameters->Append(lPara25);

			////����1
			//_ParameterPtr lPara26= m_pCmd->CreateParameter(_bstr_t("v_sell3liang"),adNumeric,adParamInput,12);
			//lPara26->PutValue(_variant_t(123456));
			//m_pCmd->Parameters->Append(lPara26);	

			////����1
			//_ParameterPtr lPara27= m_pCmd->CreateParameter(_bstr_t("v_sell4"),adNumeric,adParamInput,10);
			//lPara27->PutValue(_variant_t(10.8));
			//m_pCmd->Parameters->Append(lPara27);

			////����1
			//_ParameterPtr lPara28= m_pCmd->CreateParameter(_bstr_t("v_sell4liang"),adNumeric,adParamInput,12);
			//lPara28->PutValue(_variant_t(123456));
			//m_pCmd->Parameters->Append(lPara28);	

			////����1
			//_ParameterPtr lPara29= m_pCmd->CreateParameter(_bstr_t("v_sell5"),adNumeric,adParamInput,10);
			//lPara29->PutValue(_variant_t(10.8));
			//m_pCmd->Parameters->Append(lPara29);

			////����1
			//_ParameterPtr lPara30= m_pCmd->CreateParameter(_bstr_t("v_sell5liang"),adNumeric,adParamInput,12);
			//lPara30->PutValue(_variant_t(123456));
			//m_pCmd->Parameters->Append(lPara30);

			m_pCmd->CommandText=_bstr_t("UPDATEFUTURES_INFO2");
	  
			m_pCmd->ActiveConnection = m_pConnection;//��Ҫʹ�õ�ADO����       
			m_pCmd->CommandType=adCmdStoredProc;       
			m_pCmd->Execute(NULL,NULL, adCmdStoredProc); 
			::CoUninitialize();
			return true;
	   }
	}
	catch(_com_error e)
	{
	// ��ʾ������Ϣ
	   cerr << "\nERROR:" << (char*)e.Description();//�׳��쳣
	   return false;
	}
	
	
}
void OraDal::Close(void)
{
  /* if(m_pConnection->State)
    m_pConnection->Close();*/
}

OraDal::~OraDal(void)
{
	this->Close();
}