#include "IAdd.h"

extern long g_nComObjsInUse;

class CAddObj : public IAdd
{
public:
	HRESULT __stdcall QueryInterface(
		REFIID riid,
		void **ppObj);

	ULONG __stdcall AddRef();
	ULONG __stdcall Release();

	HRESULT __stdcall SetFirstNumber(long nX1);
	HRESULT __stdcall SetSecondNumber(long nX2);
	HRESULT __stdcall DoTheAddition(long *pBuffer);

private:
	long m_nX1, m_nX2;
	long m_nRefCount;
};
