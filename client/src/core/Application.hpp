#ifndef BELLUM_NAVALE_CLIENT_CORE_APPLICATION_HPP
#define BELLUM_NAVALE_CLIENT_CORE_APPLICATION_HPP

#pragma once
#include "config.hpp"
#include <string>
#include <tuple>

namespace gst {
    class BellumNavale {
    public:
        BellumNavale();
        ~BellumNavale();

        int run();

        static const std::string& version_string() { return version_string_; }
        static const auto& version() { return version_; }
        static const auto& build() { return build_; }

    private:
        static const inline std::string version_string_{ __APP_VERSION__ };
        static const inline std::tuple<std::string,std::string,std::string,std::string,std::string> version_{
            __APP_VERSION_MAJOR__,
            __APP_VERSION_MINOR__,
            __APP_VERSION_PATCH__,
            __APP_VERSION_PRTAG__,
            __APP_VERSION_prtag__
        };
        static const inline std::tuple<std::string,std::string,std::string,std::string,std::string> build_{
            __BUILD_OS__,
            __BUILD_ARCH__,
            __BUILD_TIME__,
            __BUILD_COMPILER_NAME__,
            __BUILD_COMPILER_VERSION__
        };
    };
}

#endif //BELLUM_NAVALE_CLIENT_CORE_APPLICATION_HPP
