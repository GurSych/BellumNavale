#ifndef BELLUM_NAVALE_CLIENT_GAME_BATTLEMAP_HPP
#define BELLUM_NAVALE_CLIENT_GAME_BATTLEMAP_HPP

#pragma once

#include <functional>
#include <vector>
#include <string>
#include <map>

#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/color.hpp>

namespace bn {
    class BattleMap {
    public:
        enum class MapType {
            OUR_GAME, OUR_PLACEMENT, ENEMY_GAME
        };
        BattleMap(MapType type, std::string style = "neoclassic") : type_(type), style_(style) {}
        ~BattleMap() {}

        class Cell {
        public:
            enum class CellState {
                EMPTY,
                OUR_EMPTY_HIT, ENEMY_EMPTY_HIT,
                OUR_SHIP, ENEMY_SHIP,
                OUR_SHIP_HIT, ENEMY_SHIP_HIT,
                OUR_SHIP_SUNK, ENEMY_SHIP_SUNK,
                BOARD_AREA
            };
            Cell() {}
            ~Cell() {}

            const CellState& state() const { return state_; }
            void setState(CellState state) { state_ = state; }

        private:
            CellState state_{CellState::EMPTY};
        };

        ftxui::Element ui() const;

        using style_map_t = std::map<Cell::CellState, std::function<ftxui::Element()>>;

        static inline std::map<std::string,style_map_t> ui_styles {
            {"modern", {
                {Cell::CellState::EMPTY,           [](){ return ftxui::text(" ·") | ftxui::color(ftxui::Color::White); }},
                {Cell::CellState::OUR_EMPTY_HIT,   [](){ return ftxui::text(" ▪") | ftxui::color(ftxui::Color::MediumVioletRed); }},
                {Cell::CellState::ENEMY_EMPTY_HIT, [](){ return ftxui::text(" ▪") | ftxui::color(ftxui::Color::NavyBlue); }},
                {Cell::CellState::OUR_SHIP,        [](){ return ftxui::text("  ") | ftxui::bgcolor(ftxui::Color::White); }},
                {Cell::CellState::ENEMY_SHIP,      [](){ return ftxui::text("  ") | ftxui::bgcolor(ftxui::Color::NavyBlue); }},
                {Cell::CellState::OUR_SHIP_HIT,    [](){ return ftxui::text("░░") | ftxui::color(ftxui::Color::White) | ftxui::bgcolor(ftxui::Color::MediumVioletRed); }},
                {Cell::CellState::ENEMY_SHIP_HIT,  [](){ return ftxui::text("░░") | ftxui::color(ftxui::Color::White) | ftxui::bgcolor(ftxui::Color::NavyBlue); }},
                {Cell::CellState::OUR_SHIP_SUNK,   [](){ return ftxui::text("░░") | ftxui::color(ftxui::Color::MediumVioletRed); }},
                {Cell::CellState::ENEMY_SHIP_SUNK, [](){ return ftxui::text("░░") | ftxui::color(ftxui::Color::NavyBlue); }},
                {Cell::CellState::BOARD_AREA,      [](){ return ftxui::text("  "); }}
            }},
            {"neoclassic", {
                {Cell::CellState::EMPTY,           [](){ return ftxui::text(" ·") | ftxui::color(ftxui::Color::NavajoWhite1); }},
                {Cell::CellState::OUR_EMPTY_HIT,   [](){ return ftxui::text(" ▪") | ftxui::color(ftxui::Color::Red3Bis) | ftxui::bold; }},
                {Cell::CellState::ENEMY_EMPTY_HIT, [](){ return ftxui::text(" ▪") | ftxui::color(ftxui::Color::BlueViolet) | ftxui::bold; }},
                {Cell::CellState::OUR_SHIP,        [](){ return ftxui::text("  ") | ftxui::bgcolor(ftxui::Color::NavajoWhite1); }},
                {Cell::CellState::ENEMY_SHIP,      [](){ return ftxui::text("  ") | ftxui::bgcolor(ftxui::Color::BlueViolet); }},
                {Cell::CellState::OUR_SHIP_HIT,    [](){ return ftxui::text("//") | ftxui::color(ftxui::Color::NavajoWhite1) | ftxui::bgcolor(ftxui::Color::Red3Bis) | ftxui::bold; }},
                {Cell::CellState::ENEMY_SHIP_HIT,  [](){ return ftxui::text("//") | ftxui::color(ftxui::Color::NavajoWhite1) | ftxui::bgcolor(ftxui::Color::BlueViolet) | ftxui::bold; }},
                {Cell::CellState::OUR_SHIP_SUNK,   [](){ return ftxui::text("//") | ftxui::color(ftxui::Color::Red3Bis) | ftxui::bold; }},
                {Cell::CellState::ENEMY_SHIP_SUNK, [](){ return ftxui::text("//") | ftxui::color(ftxui::Color::BlueViolet) | ftxui::bold; }},
                {Cell::CellState::BOARD_AREA,      [](){ return ftxui::text("  "); }}
            }}
        };
        static const inline std::string row_alphabet{"ABCDEFGHIJ"};
    private:
        MapType type_{MapType::OUR_GAME};
        const size_t width_{10};
        const size_t height_{10};
        std::vector<std::vector<Cell>> map_{height_, std::vector<Cell>{width_}};
        std::string style_{};
    };
}

#endif // BELLUM_NAVALE_CLIENT_GAME_BATTLEMAP_HPP
