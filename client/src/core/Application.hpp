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
        static const std::tuple<std::string,std::string,std::string,std::string>& version() { return version_; }

    private:
        static const inline std::string version_string_{ __APP_VERSION__ };
        static const inline std::tuple<std::string,std::string,std::string,std::string> version_{
            __APP_VERSION_MAJOR__,
            __APP_VERSION_MINOR__,
            __APP_VERSION_PATCH__,
            __APP_VERSION_PRTAG__
        };
    };
}

#endif //BELLUM_NAVALE_CLIENT_CORE_APPLICATION_HPP
