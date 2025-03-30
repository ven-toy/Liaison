#include "Logger.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace PhoenixHeart {

	std::shared_ptr<spdlog::logger> Logger::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Logger::s_ClientLogger;
	std::shared_ptr<spdlog::logger> Logger::s_ValidationLayerLogger;

	void Logger::Initialize()
	{
		spdlog::set_pattern("[%T] | [%n] %^%v%$");
		s_CoreLogger = spdlog::stdout_color_mt("Phoenix Engine");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("Game");
		s_ClientLogger->set_level(spdlog::level::trace);

		s_ValidationLayerLogger = spdlog::stdout_color_mt("Validation Layer");
		s_ValidationLayerLogger->set_level(spdlog::level::trace);

#ifdef DIST
		s_CoreLogger->set_level(spdlog::level::warn);
		s_ClientLogger->set_level(spdlog::level::warn);
		s_ValidationLayerLogger->set_level(spdlog::level::warn);
#elif RELEASE
		s_CoreLogger->set_level(spdlog::level::info);
		s_ClientLogger->set_level(spdlog::level::info);
		s_ValidationLayerLogger->set_level(spdlog::level::info);
#elif DEBUG
		s_CoreLogger->set_level(spdlog::level::trace);
		s_ClientLogger->set_level(spdlog::level::trace);
		s_ValidationLayerLogger->set_level(spdlog::level::trace);
#endif
	}
}