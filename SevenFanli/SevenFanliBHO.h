// SevenFanliBHO.h : CSevenFanliBHO ������

#pragma once
#include "resource.h"       // ������



#include "SevenFanli_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif

using namespace ATL;


// CSevenFanliBHO

class ATL_NO_VTABLE CSevenFanliBHO :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CSevenFanliBHO, &CLSID_SevenFanliBHO>,
	public IObjectWithSiteImpl<CSevenFanliBHO>,
	public IDispatchImpl<ISevenFanliBHO, &IID_ISevenFanliBHO, &LIBID_SevenFanliLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CSevenFanliBHO()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_SEVENFANLIBHO)

DECLARE_NOT_AGGREGATABLE(CSevenFanliBHO)

BEGIN_COM_MAP(CSevenFanliBHO)
	COM_INTERFACE_ENTRY(ISevenFanliBHO)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IObjectWithSite)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:



};

OBJECT_ENTRY_AUTO(__uuidof(SevenFanliBHO), CSevenFanliBHO)
