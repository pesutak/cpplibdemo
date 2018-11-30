#pragma once

#ifdef LIBDYNAMIC_EXPORTS
#define LIBDYNAMIC_API __declspec(dllexport)
#else
#define LIBDYNAMIC_API __declspec(dllimport)
#endif

extern "C" LIBDYNAMIC_API int dynFn(const int a);
