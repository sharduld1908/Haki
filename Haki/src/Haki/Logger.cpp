
#include "hkpch.h"
#include "Logger.h"

namespace Haki {

	std::shared_ptr<spdlog::logger> Logger::pt_CoreLogger;
	std::shared_ptr<spdlog::logger> Logger::pt_ClientLogger;

	void Logger::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");

		pt_CoreLogger = spdlog::stdout_color_mt("Haki");
		pt_CoreLogger->set_level(spdlog::level::trace);

		pt_ClientLogger = spdlog::stdout_color_mt("Application");
		pt_ClientLogger->set_level(spdlog::level::trace);
	}

	inline std::shared_ptr<spdlog::logger>& Logger::GetCoreLogger()
	{
		return pt_CoreLogger;
	}

	inline std::shared_ptr<spdlog::logger>& Logger::GetClientLogger()
	{
		return pt_ClientLogger;
	}

}
