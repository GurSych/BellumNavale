#include "core/Application.hpp"
#include <TinyColor/TinyColor.hpp>
#include <iostream>
#include <string>

namespace tcl = gst::tcl;

void printVersion();
void printHelp();

int main(int argc, char* argv[]) {
    bool gui{false};
    if (argc > 1) {
        std::string arg {argv[1]};
        if (arg == "--gui") gui = true;
        else {
            if (arg == "--version") printVersion();
            if (arg == "--help")    printHelp();
            return 0;
        }
    }
    gst::BellumNavale app;
    return app.run();
}

void printVersion() {
    std::cout << "BellumNavale client version "
              << std::get<0>(gst::BellumNavale::version()) << "."
              << std::get<1>(gst::BellumNavale::version()) << "."
              << std::get<2>(gst::BellumNavale::version()) << "-"
              << std::get<4>(gst::BellumNavale::version()) << " by GurSych" << std::endl;
    std::cout << "Build: " << std::get<0>(gst::BellumNavale::build()) << " ["
                           << std::get<1>(gst::BellumNavale::build()) << "], "
                           << std::get<3>(gst::BellumNavale::build()) << " "
                           << std::get<4>(gst::BellumNavale::build()) << ", "
                           << std::get<2>(gst::BellumNavale::build()) << std::endl;
    std::cout << tcl::colorize("BellumNavale", tcl::BLUE) << " is multiplayer naval battle game developed by "
              << tcl::colorize("|",tcl::RED,tcl::BOLD) + tcl::colorize("GurSych",tcl::BOLD)
              << " ╳ " << tcl::colorize("G",tcl::BOLD,tcl::GREEN,tcl::REVERSE) + tcl::colorize("Gergy",tcl::BOLD)
              << " team" << std::endl;
    std::cout << "Project repository: https://github.com/GurSych/BellumNavale" << std::endl;
}
void printHelp() {
    std::cout << "Usage: bellumnavale [options]" << std::endl;
    std::cout << "Using no options will run the CLI game itself." << std::endl;
    std::cout << "Options:" << "\n";
    std::cout << "  --version   Print version information" << "\n";
    std::cout << "  --help      Print help message" << std::endl;
}
