#pragma once

#ifdef LIBDYNAMIC_EXPORTS
#define LIBDYNAMIC_API __declspec(dllexport)
#else
#define LIBDYNAMIC_API __declspec(dllimport)
#endif

#ifdef __cplusplus
#define EXTERN_C     extern "C"
#else
#define EXTERN_C
#endif // __cplusplus

#ifdef __cplusplus
struct IWorker {
public:
	virtual int DoWork(const int a) = 0;
	virtual void Release() = 0;
};

class LIBDYNAMIC_API Worker {
public:
	int DoWork(const int a);
};


typedef IWorker* WORKERHANDLE;
#else
typedef struct tagWORKERHANDLE {} *WORKERHANDLE;
#endif

// c-style declarations
EXTERN_C LIBDYNAMIC_API WORKERHANDLE WINAPI GetWorker(VOID);
EXTERN_C LIBDYNAMIC_API INT APIENTRY WorkerDoWork(WORKERHANDLE handle, INT n);
EXTERN_C LIBDYNAMIC_API VOID APIENTRY WorkerRelease(WORKERHANDLE handle);

EXTERN_C LIBDYNAMIC_API int dynFn(const int a);
