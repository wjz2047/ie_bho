// dllmain.h : 模块类的声明。

class CSevenFanliModule : public ATL::CAtlDllModuleT< CSevenFanliModule >
{
public :
	DECLARE_LIBID(LIBID_SevenFanliLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_SEVENFANLI, "{0DEE8D0C-1812-4D38-97B5-750559225FEA}")
	virtual HRESULT DllRegisterServer(_In_ BOOL bRegTypeLib = TRUE);
	virtual HRESULT DllUnregisterServer(_In_ BOOL bUnRegTypeLib = TRUE);
};

extern class CSevenFanliModule _AtlModule;
