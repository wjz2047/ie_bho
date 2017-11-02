

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Thu Nov 02 10:47:37 2017
 */
/* Compiler settings for SevenFanli.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __SevenFanli_i_h__
#define __SevenFanli_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ISevenFanliBHO_FWD_DEFINED__
#define __ISevenFanliBHO_FWD_DEFINED__
typedef interface ISevenFanliBHO ISevenFanliBHO;
#endif 	/* __ISevenFanliBHO_FWD_DEFINED__ */


#ifndef __SevenFanliBHO_FWD_DEFINED__
#define __SevenFanliBHO_FWD_DEFINED__

#ifdef __cplusplus
typedef class SevenFanliBHO SevenFanliBHO;
#else
typedef struct SevenFanliBHO SevenFanliBHO;
#endif /* __cplusplus */

#endif 	/* __SevenFanliBHO_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __ISevenFanliBHO_INTERFACE_DEFINED__
#define __ISevenFanliBHO_INTERFACE_DEFINED__

/* interface ISevenFanliBHO */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ISevenFanliBHO;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0B492775-374F-43FA-9206-B9CED981708A")
    ISevenFanliBHO : public IDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct ISevenFanliBHOVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISevenFanliBHO * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISevenFanliBHO * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISevenFanliBHO * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISevenFanliBHO * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISevenFanliBHO * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISevenFanliBHO * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISevenFanliBHO * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } ISevenFanliBHOVtbl;

    interface ISevenFanliBHO
    {
        CONST_VTBL struct ISevenFanliBHOVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISevenFanliBHO_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISevenFanliBHO_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISevenFanliBHO_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISevenFanliBHO_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISevenFanliBHO_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISevenFanliBHO_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISevenFanliBHO_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISevenFanliBHO_INTERFACE_DEFINED__ */



#ifndef __SevenFanliLib_LIBRARY_DEFINED__
#define __SevenFanliLib_LIBRARY_DEFINED__

/* library SevenFanliLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_SevenFanliLib;

EXTERN_C const CLSID CLSID_SevenFanliBHO;

#ifdef __cplusplus

class DECLSPEC_UUID("412A357C-CB48-48E1-91C1-EA9B7DEDB3A4")
SevenFanliBHO;
#endif
#endif /* __SevenFanliLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


