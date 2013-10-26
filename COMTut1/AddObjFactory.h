#include <ObjBase.h>

extern long g_nComObjsInUse;
class CAddFactory : public IClassFactory
{
public:
	CAddFactory() 
	{
		m_nRefCount = 0;
		InterlockedIncrement(&g_nComObjsInUse);
	}

	~CAddFactory()
	{
		InterlockedDecrement(&g_nComObjsInUse);
	}

    //interface IUnknown methods 
    HRESULT __stdcall QueryInterface(
                                REFIID riid , 
                                void **ppObj);

    ULONG   __stdcall AddRef()
    {
        return InterlockedIncrement(&m_nRefCount) ;
    }

    ULONG   __stdcall Release()
    {
        long nRefCount=0;
        nRefCount=InterlockedDecrement(&m_nRefCount) ;
        if (nRefCount == 0) delete this;
        return nRefCount;
    }

    //interface IClassFactory methods 
    HRESULT __stdcall CreateInstance(IUnknown* pUnknownOuter,
	                                         const IID& iid,
	                                         void** ppv) ;
    HRESULT __stdcall LockServer(BOOL bLock) ; 
 
private:
    long m_nRefCount;
};
