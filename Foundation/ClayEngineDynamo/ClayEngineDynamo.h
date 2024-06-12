#pragma once

#include <cstring> // C99
#include <string> // STL

#ifndef DYNAMO_EXPORTS
#define DYNAMO_EXPORTS
#endif

#ifdef DYNAMO_EXPORTS
#define DYNAMO_API __declspec(dllexport)
#else
#define DYNAMO_API __declspec(dllimport)
#endif

namespace ClayEngine
{
	namespace Dynamo
	{
		class CClayEngineDynamo
		{
			std::string m_string;
		public:
			CClayEngineDynamo() = default;
			~CClayEngineDynamo() = default;

			void Initialize(const char * string, const int length)
			{
				//Convert const char * to std::string
			}
		};
	}
}

namespace
{
	using ClayEngineDynamo = ClayEngine::Dynamo::CClayEngineDynamo*;
	ClayEngineDynamo g_dynamo = nullptr;
}

namespace ClayEngine
{
	namespace Dynamo
	{
		inline void OnProcessAttached()
		{
			delete g_dynamo;
			g_dynamo = new ClayEngine::Dynamo::CClayEngineDynamo();
		}
		inline void OnProcessDetached()
		{
			delete g_dynamo;
			g_dynamo = nullptr;
		}
	}
}

extern "C"
{
	void DYNAMO_API initialize(char* string, int length)
	{
		delete g_dynamo;
		g_dynamo = new ClayEngine::Dynamo::CClayEngineDynamo();
	}
	void DYNAMO_API reset()
	{
		delete g_dynamo;
		g_dynamo = nullptr;
	}
}
