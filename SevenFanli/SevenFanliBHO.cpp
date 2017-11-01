// SevenFanliBHO.cpp : CSevenFanliBHO µÄÊµÏÖ

#include "stdafx.h"
#include "SevenFanliBHO.h"


// CSevenFanliBHO

CSevenFanliBHO::CSevenFanliBHO()
{
	m_isRefresh = TRUE;
}

STDMETHODIMP CSevenFanliBHO::SetSite(IUnknown* pUnkSite)  
{  
	if (pUnkSite != NULL)  
	{  
		// Cache the pointer to IWebBrowser2.  
		HRESULT hr = pUnkSite->QueryInterface(IID_IWebBrowser2, (void **)&m_spWebBrowser);  
		if (SUCCEEDED(hr))  
		{  
			// Register to sink events from DWebBrowserEvents2.  
			hr = DispEventAdvise(m_spWebBrowser);  
			if (SUCCEEDED(hr))  
			{  
				m_fAdvised = TRUE;  
			}  
		}  
	}  
	else  
	{  
		// Unregister event sink.  
		if (m_fAdvised)  
		{  
			DispEventUnadvise(m_spWebBrowser);  
			m_fAdvised = FALSE;  
		}  

		// Release cached pointers and other resources here.  
		m_spWebBrowser.Release();  
	}  

	// Call base class implementation.  
	return IObjectWithSiteImpl<CSevenFanliBHO>::SetSite(pUnkSite);  
}  

void STDMETHODCALLTYPE CSevenFanliBHO::OnBeforeNavigate2(IDispatch* pDisp, VARIANT* URL, VARIANT* pvtFlags, VARIANT* pvtTargetFrameName, 
	VARIANT* pvtPostData, VARIANT* pvtHeaders, VARIANT_BOOL* pvbCancel)
{
	m_isRefresh = FALSE;
}

void STDMETHODCALLTYPE CSevenFanliBHO::OnDocumentComplete(IDispatch *pDisp, VARIANT *pvarURL)  
{  
	CComQIPtr<IWebBrowser2> spTempWebBrowser = pDisp;
	if (spTempWebBrowser && m_spWebBrowser && m_spWebBrowser.IsEqualObject(spTempWebBrowser)) {
		m_isRefresh = TRUE;

		CComPtr<IDispatch> spDispDoc;
		HRESULT hr = m_spWebBrowser->get_Document(&spDispDoc);
		if (SUCCEEDED(hr)) { 
			CComQIPtr<IHTMLDocument2> spHTMLDoc = spDispDoc;
			if (spHTMLDoc != NULL) {
				IHTMLWindow2 *spWindow;
				if (SUCCEEDED(spHTMLDoc->get_parentWindow(&spWindow))) {
					VARIANT vEmpty = {0};
					CComBSTR js_code = L"alert(111)";
					CComBSTR bstrLanguage = L"javascript";
					spWindow->execScript(js_code, bstrLanguage, &vEmpty);
				}
			}
		}
	} 
}  

void STDMETHODCALLTYPE CSevenFanliBHO::OnDownloadComplete()
{
	if (m_isRefresh) {
		CComPtr<IDispatch> spDispDoc;
		HRESULT hr = m_spWebBrowser->get_Document(&spDispDoc);
		if (SUCCEEDED(hr)) { 
			CComQIPtr<IHTMLDocument2> spHTMLDoc = spDispDoc;
			if (spHTMLDoc != NULL) {
				IHTMLWindow2 *spWindow;
				if (SUCCEEDED(spHTMLDoc->get_parentWindow(&spWindow))) {
					VARIANT vEmpty = {0};
					CComBSTR js_code = L"alert(222)";
					CComBSTR bstrLanguage = L"javascript";
					spWindow->execScript(js_code, bstrLanguage, &vEmpty);
				}
			}
		}
	} 
}