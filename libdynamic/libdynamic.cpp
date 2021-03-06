// libdynamic.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "libdynamic.h"

class WorkerImpl : public IWorker
{
	int DoWork(const int n);
	void Release();
};

int WorkerImpl::DoWork(const int n)
{
	Worker w;
	return w.DoWork(n);
}

void WorkerImpl::Release()
{
	delete this;
}

////////////////////////////////////////////////////////////////////////////////
// Factory function that creates instances if the Worker object.

// Export both decorated and undecorated names.
//   GetWorker     - Undecorated name, which can be easily used with GetProcAddress
//                Win32 API function.
//   _GetWorker@0  - Common name decoration for __stdcall functions in C language.
//
// For more information on name decoration see here:
// "Format of a C Decorated Name"
// http://msdn.microsoft.com/en-us/library/x7kb4e2f.aspx

#if !defined(_WIN64)
// This pragma is required only for 32-bit builds. In a 64-bit environment,
// C functions are not decorated.
#pragma comment(linker, "/export:GetWorker=_GetWorker@0")
#endif  // _WIN64
LIBDYNAMIC_API WORKERHANDLE APIENTRY GetWorker(VOID)
{
	return new WorkerImpl();
}

LIBDYNAMIC_API INT WorkerDoWork(WORKERHANDLE handle, INT n)
{
	INT nResult = -1;

	if (handle)
	{
		nResult = handle->DoWork(n);
	}

	return nResult;
}

LIBDYNAMIC_API VOID WorkerRelease(WORKERHANDLE handle)
{
	if (handle) {
		handle->Release();
	}
}

int Worker::DoWork(const int a)
{
	
	return a * a;
}

int dynFn(const int a) {
	return a + a;
}
