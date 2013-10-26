#include "AddObj.h"
#include "AddObjFactory.h"

HRESULT __stdcall AddObjFactory::QueryInterface(
	REFIID riid,
	void **ppObj)
{
	if (riid == IID_IUnknown || riid == IID_IClassFactory)
	{
		*ppObj = static_cast<IClassFactory*>(this);
		this->AddRef();
		return S_OK;
	}

	*ppObj = NULL;
	return E_NOINTERFACE;
}

ULONG __stdcall AddObjFactory::AddRef()
{
	return InterlockedIncrement(&m_nRefCount);
}

ULONG __stdcall AddObjFactory::Release()
{
    long nRefCount=0;
    nRefCount=InterlockedDecrement(&m_nRefCount) ;
    if (nRefCount == 0) delete this;
    return nRefCount;
}
