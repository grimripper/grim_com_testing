#include <ObjBase.h>
#include "AddObj.h"
#include "IAdd_i.c"

HRESULT __stdcall CAddObj::SetFirstNumber(long nX1)
{
	m_nX1 = nX1;
	return S_OK;
}

HRESULT __stdcall CAddObj::SetSecondNumber(long nX2)
{
	m_nX2 = nX2;
	return S_OK;
}

HRESULT __stdcall CAddObj::DoTheAddition(long *pBuffer)
{
	*pBuffer = m_nX1 + m_nX2;
	return S_OK;
}

HRESULT __stdcall CAddObj::QueryInterface(
	REFIID riid,
	void **ppObj)
{
	if (riid == IID_IUnknown)
	{
		*ppObj = static_cast<void*>(this);
		AddRef();
		return S_OK;
	}
	else if (riid == IID_IAdd)
	{
		*ppObj = static_cast<void*>(this);
		AddRef();
		return S_OK;
	}

	*ppObj = NULL;
	return E_NOINTERFACE;
}

ULONG __stdcall CAddObj::AddRef()
{
	return InterlockedIncrement(&m_nRefCount);
}

ULONG __stdcall CAddObj::Release()
{
    long nRefCount=0;
    nRefCount=InterlockedDecrement(&m_nRefCount) ;
    if (nRefCount == 0) delete this;
    return nRefCount;
}
