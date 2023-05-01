#pragma once

#ifdef HK_PLATFORM_WINDOWS
	#ifdef HK_BUILD_DLL
		#define HAKI_API __declspec(dllexport)
	#else
		#define HAKI_API __declspec(dllexport)
	#endif
#else 
	#error Haki only supports Windows
#endif
