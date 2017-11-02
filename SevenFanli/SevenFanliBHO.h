// SevenFanliBHO.h : CSevenFanliBHO 的声明

#pragma once
#include "resource.h"       // 主符号



#include "SevenFanli_i.h"
#include <shlguid.h>  
#include <exdispid.h>  


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
#endif

using namespace ATL;


// CSevenFanliBHO

class ATL_NO_VTABLE CSevenFanliBHO :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CSevenFanliBHO, &CLSID_SevenFanliBHO>,
	public IObjectWithSiteImpl<CSevenFanliBHO>,
	public IDispatchImpl<ISevenFanliBHO, &IID_ISevenFanliBHO, &LIBID_SevenFanliLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public IDispEventImpl<1, CSevenFanliBHO, &DIID_DWebBrowserEvents2, &LIBID_SHDocVw, 1, 1>  
{
public:
	CSevenFanliBHO();

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
	STDMETHOD(SetSite)(IUnknown *pUnkSite);  
	BEGIN_SINK_MAP(CSevenFanliBHO)  
		SINK_ENTRY_EX(1, DIID_DWebBrowserEvents2, DISPID_BEFORENAVIGATE2, OnBeforeNavigate2)
		SINK_ENTRY_EX(1, DIID_DWebBrowserEvents2, DISPID_DOCUMENTCOMPLETE, OnDocumentComplete) 
		SINK_ENTRY_EX(1, DIID_DWebBrowserEvents2, DISPID_DOWNLOADCOMPLETE, OnDownloadComplete)
	END_SINK_MAP()  

	void STDMETHODCALLTYPE OnBeforeNavigate2(IDispatch* pDisp, VARIANT* URL, 
		VARIANT* pvtFlags,
		VARIANT* pvtTargetFrameName, 
		VARIANT* pvtPostData, 
		VARIANT* pvtHeaders,
		VARIANT_BOOL* pvbCancel);
	void STDMETHODCALLTYPE OnDocumentComplete(IDispatch *pDisp, VARIANT *pvarURL);  
	void STDMETHODCALLTYPE OnDownloadComplete();
	bool isMainFrame(IDispatch *pDisp);
private:  
	CComPtr<IWebBrowser2>  m_spWebBrowser;  
	BOOL m_fAdvised;  
	BOOL m_isDocumentComplete;
};

OBJECT_ENTRY_AUTO(__uuidof(SevenFanliBHO), CSevenFanliBHO)
