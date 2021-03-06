// client.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "libdynamic.h"
#include "libstatic.h"

int main(int argc, char** argv)
{
	// call exported function (from dll)
	std::cout << "dynamic: " << dynFn(42) << "\n";

	// call function from static library
	std::cout << "static: " << fixer::BigAlgo::statFn(21) << "\n";

	// Regular C++ class (dll)
	// The class must be exported
	Worker w;
	std::cout << "dll worker direct: " << w.DoWork(10) << "\n";

#if _MSC_VER >= 1600    // VC++10.0 and higher

	// Use smart pointers from the Standard C++ library.
	typedef std::shared_ptr<IWorker> IWorkerPtr;

	IWorkerPtr ptrWorker(::GetWorker());

	if (ptrWorker)
	{
		std::cout << "dll worker smart pointer: " << ptrWorker->DoWork(10) << "\n";
	}
#endif

	// COM-like usage (dll)
	IWorker* pWorker = ::GetWorker();
	if (pWorker) {
		std::cout << "dll worker via handler: " << pWorker->DoWork(10) << "\n";
		pWorker->Release();
	}

	// Classic C language usage
	WORKERHANDLE hWrk = GetWorker();
	if (hWrk) {
		std::cout << "dll worker via handler (c-style): " << WorkerDoWork(hWrk,10) << "\n";
		WorkerRelease(hWrk);
	}
}
