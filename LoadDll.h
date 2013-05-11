// STKDRV.h: interface for the CLoadDll class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STKDRV_H__4BE51F0E_A261_11D2_B30C_00C04FCCA334__INCLUDED_)
#define AFX_STKDRV_H__4BE51F0E_A261_11D2_B30C_00C04FCCA334__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SCStkDrv.h"
class CLoadDll  
{
public:
	CLoadDll();
	virtual ~CLoadDll();
public:
	BOOL Load();
	void Unload();
	
	BOOL SCInit(void *pInit, int nSize);
	void SCQuit();
	void SCAskData(void *pAsk, int nSize);
	UINT SCGetInfo(TSCInfo Info, void *pData, int *nSize);

protected:
	BOOL (WINAPI *	m_pfnSCInit)(void *pAsk, int nSize);
	void (WINAPI *	m_pfnSCAskData)(void *pAsk, int nSize);
	void (WINAPI *	m_pfnSCQuit)(void);
	UINT (WINAPI *	m_pfnSCGetInfo)(TSCInfo Info, void *pData, int *nSize);

private:
	void GetAdress();
	HINSTANCE	m_hSTKDrv;
};

#endif // !defined(AFX_STKDRV_H__4BE51F0E_A261_11D2_B30C_00C04FCCA334__INCLUDED_)
