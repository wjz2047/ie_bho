// dllmain.cpp : DllMain 的实现。

#include "stdafx.h"
#include "resource.h"
#include "SevenFanli_i.h"
#include "dllmain.h"

CSevenFanliModule _AtlModule;

HINSTANCE ghInstance=NULL;
//412A357C-CB48-48E1-91C1-EA9B7DEDB3A4
const CLSID CLSID_IEPlugin = { 0x412A357C, 0xCB48, 0x48E1, { 0x91, 0xC1, 0xEA, 0x9B, 0x7D, 0xED, 0xB3, 0xA4 } };
#define CLSID_IEPlugin_Str _T("{412A357C-CB48-48E1-91C1-EA9B7DEDB3A4}")

// DLL 入口点
extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)  
{  
	if (dwReason == DLL_PROCESS_ATTACH)  
	{  
		ghInstance = hInstance;
		DisableThreadLibraryCalls(ghInstance);  
	}  
	return _AtlModule.DllMain(dwReason, lpReserved);   
}  

HRESULT CSevenFanliModule::DllRegisterServer(_In_ BOOL bRegTypeLib)
{
	HKEY hk;
	TCHAR dllpath[1024];
	DWORD n;

	// Get the full path to this DLL's file so we can register it
	GetModuleFileName(ghInstance,dllpath,1024);
	// Create our key under HKCR\\CLSID
	if(RegCreateKeyEx(HKEY_CLASSES_ROOT,_T("CLSID\\") CLSID_IEPlugin_Str,0,NULL,0,KEY_ALL_ACCESS,NULL,&hk,NULL)!=ERROR_SUCCESS) return SELFREG_E_CLASS;
	// Set the name of our BHO
	RegSetValueEx(hk,NULL,0,REG_SZ,(const BYTE*)_T("SevenFanliBHO"),24*sizeof(TCHAR));
	RegCloseKey(hk);
	// Create the InProcServer32 key
	if(RegCreateKeyEx(HKEY_CLASSES_ROOT,_T("CLSID\\") CLSID_IEPlugin_Str _T("\\InProcServer32"),0,NULL,0,KEY_ALL_ACCESS,NULL,&hk,NULL)!=ERROR_SUCCESS) return SELFREG_E_CLASS;
	// Set the path to this DLL
	RegSetValueEx(hk,NULL,0,REG_SZ,(const BYTE*)dllpath,(_tcslen(dllpath)+1)*sizeof(TCHAR));
	// Set the ThreadingModel to Apartment
	RegSetValueEx(hk,_T("ThreadingModel"),0,REG_SZ,(const BYTE*)_T("Apartment"),10*sizeof(TCHAR));
	RegCloseKey(hk);
	// Now register the BHO with Internet Explorer
	if(RegCreateKeyEx(HKEY_LOCAL_MACHINE,_T("Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Browser Helper Objects\\") CLSID_IEPlugin_Str,0,NULL,0,KEY_ALL_ACCESS,NULL,&hk,NULL)!=ERROR_SUCCESS) return SELFREG_E_CLASS;
	// I believe the following tells explorer.exe not to load our BHO
	n=1;
	RegSetValueEx(hk,_T("NoExplorer"),0,REG_DWORD,(const BYTE*)&n,sizeof(DWORD));
	RegCloseKey(hk);
	return S_OK;
}

HRESULT CSevenFanliModule::DllUnregisterServer(_In_ BOOL bUnRegTypeLib)
{
	// Remove the Internet Explorer BHO registration
	RegDeleteKey(HKEY_LOCAL_MACHINE,_T("Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Browser Helper Objects\\") CLSID_IEPlugin_Str);
	// Remove the COM registration, starting with the deeper key first since RegDeleteKey is not recursive
	RegDeleteKey(HKEY_CLASSES_ROOT,_T("CLSID\\") CLSID_IEPlugin_Str _T("\\InProcServer32"));
	RegDeleteKey(HKEY_CLASSES_ROOT,_T("CLSID\\") CLSID_IEPlugin_Str);
	return S_OK;
}
