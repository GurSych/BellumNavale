#include "core/Application.hpp"
#include <iostream>
#include <string>

void printVersion();
void printHelp();

int main(int argc, char* argv[]) {
    bool gui{false};
    if (argc > 1) {
        std::string arg = argv[1];
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
    std::cout << "BellumNavale version " << gst::BellumNavale::version_string() << " by GurSych ╳ GGergy team" << std::endl;
}
void printHelp() {
    std::cout << "Usage: bellumnavale [options]" << std::endl;
    std::cout << "Using no options will run the CLI game itself." << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "  --version   Print version information" << std::endl;
    std::cout << "  --help      Print help message" << std::endl;
}
