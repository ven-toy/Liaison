#pragma once

#include <memory>

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Liaison::Core {

    class Logger
    {

    public:
        static void Initialize();

        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetValidationLayerLogger() { return s_ValidationLayerLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
        static std::shared_ptr<spdlog::logger> s_ValidationLayerLogger;
    };

}

#define PH_LOG_TRACE(...) ::PhoenixHeart::Logger::GetClientLogger()->trace(__VA_ARGS__)
#define PH_LOG_INFO(...) ::PhoenixHeart::Logger::GetClientLogger()->info(__VA_ARGS__)
#define PH_LOG_WARN(...) ::PhoenixHeart::Logger::GetClientLogger()->warn(__VA_ARGS__)
#define PH_LOG_ERROR(...) ::PhoenixHeart::Logger::GetClientLogger()->error(__VA_ARGS__)
#define PH_LOG_CRITICAL(...) ::PhoenixHeart::Logger::GetClientLogger()->critical(__VA_ARGS__)

#define PH_CORE_LOG_TRACE(...) ::PhoenixHeart::Logger::GetCoreLogger()->trace(__VA_ARGS__)
#define PH_CORE_LOG_INFO(...) ::PhoenixHeart::Logger::GetCoreLogger()->info(__VA_ARGS__)
#define PH_CORE_LOG_WARN(...) ::PhoenixHeart::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define PH_CORE_LOG_ERROR(...) ::PhoenixHeart::Logger::GetCoreLogger()->error(__VA_ARGS__)
#define PH_CORE_LOG_CRITICAL(...) ::PhoenixHeart::Logger::GetCoreLogger()->critical(__VA_ARGS__)

#define PH_VALIDATION_LAYER_LOG_TRACE(...) ::PhoenixHeart::Logger::GetValidationLayerLogger()->trace(__VA_ARGS__)
#define PH_VALIDATION_LAYER_LOG_INFO(...) ::PhoenixHeart::Logger::GetValidationLayerLogger()->info(__VA_ARGS__)
#define PH_VALIDATION_LAYER_LOG_WARN(...) ::PhoenixHeart::Logger::GetValidationLayerLogger()->warn(__VA_ARGS__)
#define PH_VALIDATION_LAYER_LOG_ERROR(...) ::PhoenixHeart::Logger::GetValidationLayerLogger()->error(__VA_ARGS__)
#define PH_VALIDATION_LAYER_LOG_CRITICAL(...) ::PhoenixHeart::Logger::GetValidationLayerLogger()->critical(__VA_ARGS__)
