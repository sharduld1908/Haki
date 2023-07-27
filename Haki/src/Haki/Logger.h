#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Haki {

	class HAKI_API Logger
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger();
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger();
	private:

		static std::shared_ptr<spdlog::logger> pt_CoreLogger;
		static std::shared_ptr<spdlog::logger> pt_ClientLogger;
	};

}

#define HK_CORE_ERROR(...)      ::Haki::Logger::GetCoreLogger()->error(__VA_ARGS__)
#define HK_CORE_WARN(...)       ::Haki::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define HK_CORE_INFO(...)       ::Haki::Logger::GetCoreLogger()->info(__VA_ARGS__)
#define HK_CORE_TRACE(...)      ::Haki::Logger::GetCoreLogger()->trace(__VA_ARGS__)

#define HK_CLIENT_ERROR(...)    ::Haki::Logger::GetClientLogger()->error(__VA_ARGS__)
#define HK_CLIENT_WARN(...)     ::Haki::Logger::GetClientLogger()->warn(__VA_ARGS__)
#define HK_CLIENT_INFO(...)     ::Haki::Logger::GetClientLogger()->info(__VA_ARGS__)
#define HK_CLIENT_TRACE(...)    ::Haki::Logger::GetClientLogger()->trace(__VA_ARGS__)