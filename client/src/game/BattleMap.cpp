#include "BattleMap.hpp"
#include "ftxui/dom/elements.hpp"
#include <algorithm>
#include <ftxui/dom/elements.hpp>

using namespace bn;

ftxui::Element BattleMap::ui() const {
    auto style_map_it = ui_styles.find(style_);
    if (style_map_it == ui_styles.end()) {
        return ftxui::text(std::string{"||UI Error: ui style "} + style_ + " not found")|ftxui::color(ftxui::Color::Red);
    }
    const auto& style_map = style_map_it->second;
    std::vector<ftxui::Element> rows_elements{};
    rows_elements.reserve(height_+3);
    rows_elements.push_back(ftxui::hbox({ftxui::text("   "), ftxui::text(" 1 2 3 4 5 6 7 8 910")|ftxui::color(ftxui::Color::Black)|ftxui::bgcolor(ftxui::Color::White)}));
    rows_elements.push_back(ftxui::text("  ╔════════════════════╗")|ftxui::color(ftxui::Color::White));
    size_t row_number{};
    for (const auto& row : map_) {
        std::vector<ftxui::Element> row_elements{};
        row_elements.reserve(width_+3);
        row_elements.push_back(ftxui::text(std::string{' '}+row_alphabet[row_number++])|ftxui::color(ftxui::Color::Black)|ftxui::bgcolor(ftxui::Color::White));
        row_elements.push_back(ftxui::text("║")|ftxui::color(ftxui::Color::White));
        for (const auto& cell : row) {
            auto cell_style_it = style_map.find(cell.state());
            if (cell_style_it == style_map.end()) {
                row_elements.push_back(ftxui::text("??")|ftxui::color(ftxui::Color::Red));
            } else {
                row_elements.push_back(cell_style_it->second());
            }
        }
        row_elements.push_back(ftxui::text("║")|ftxui::color(ftxui::Color::White));
        rows_elements.push_back(ftxui::hbox(std::move(row_elements)));
    }
    rows_elements.push_back(ftxui::text("  ╚════════════════════╝")|ftxui::color(ftxui::Color::White));
    return ftxui::vbox(std::move(rows_elements));
}
