// dllmain.h : ģ�����������

class CSevenFanliModule : public ATL::CAtlDllModuleT< CSevenFanliModule >
{
public :
	DECLARE_LIBID(LIBID_SevenFanliLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_SEVENFANLI, "{0DEE8D0C-1812-4D38-97B5-750559225FEA}")
};

extern class CSevenFanliModule _AtlModule;
