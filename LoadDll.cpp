// STKDRV.cpp: implementation of the CLoadDll class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "LoadDll.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLoadDll::CLoadDll()
{
	m_hSTKDrv = NULL;

	m_pfnSCQuit = NULL;
	m_pfnSCAskData = NULL;
	m_pfnSCInit = NULL;
	m_pfnSCGetInfo = NULL;
}

CLoadDll::~CLoadDll()
{
	Unload();
}

void CLoadDll::Unload()
{
	if( m_hSTKDrv )  {
		FreeLibrary(m_hSTKDrv);
		m_hSTKDrv = NULL;
	}
}

BOOL CLoadDll::Load()
{
	m_hSTKDrv = LoadLibrary("SCStock.dll");
	if( !m_hSTKDrv ) {
		AfxMessageBox("cannot load library: SCStock.dll", MB_OK);
		return FALSE;
	}

	m_pfnSCInit = \
			(BOOL (WINAPI *)(void *, int ))GetProcAddress(m_hSTKDrv,"SCInit");
	m_pfnSCAskData = \
			(void (WINAPI *)(void *, int))GetProcAddress(m_hSTKDrv,"SCAskData");
	m_pfnSCQuit = (void (WINAPI *)(void)) GetProcAddress(m_hSTKDrv,"SCQuit");
	m_pfnSCGetInfo = \
			(UINT (WINAPI *)(TSCInfo, void *, int *))GetProcAddress(m_hSTKDrv,"SCGetInfo");

	return TRUE;
}

BOOL CLoadDll::SCInit(void *pInit, int nSize)
{
	if( m_pfnSCInit ) 
		return (*m_pfnSCInit)(pInit, nSize);

	return FALSE;
}


void CLoadDll::SCQuit()
{
	if( m_pfnSCQuit )
		(*m_pfnSCQuit)();
}

void CLoadDll::SCAskData(void *pAsk, int nSize)
{
	if( m_pfnSCAskData ) 
		(*m_pfnSCAskData)(pAsk, nSize);
}


UINT CLoadDll::SCGetInfo(TSCInfo Info, void *pData, int *nSize)
{
	if( m_pfnSCGetInfo ) 
		return (*m_pfnSCGetInfo)(Info, pData, nSize);

	return 0;
}


