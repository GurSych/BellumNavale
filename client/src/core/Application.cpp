#include "Application.hpp"
#include <ftxui/dom/elements.hpp>

#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/component/component.hpp>

gst::BellumNavale::BellumNavale() {

}
gst::BellumNavale::~BellumNavale() {

}

int gst::BellumNavale::run() {
    auto screen = ftxui::ScreenInteractive::FitComponent();
    auto screen_exiter = screen.ExitLoopClosure();
    ftxui::Component app_renderer = ftxui::Renderer([&] {
        return ftxui::vbox({
            ftxui::border({
                ftxui::text("Open your eyes...") | ftxui::color(ftxui::Color::Yellow) | ftxui::bold,
            }) | ftxui::center | ftxui::color(ftxui::Color::NavyBlue),
            ftxui::text("Press 'q' to quit")
        });
    });
    app_renderer |= ftxui::CatchEvent([&](ftxui::Event event) {
        if (event.is_character()) {
            if (event.character() == "q") {
                screen_exiter();
                return true;
            }
        }
        return false;
    });
    screen.Loop(app_renderer);
    return 0;
}
