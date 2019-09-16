#pragma once

#include <map>
#include <utility>
#include <string>
#include <algorithm>
#include <spdlog/spdlog.h>
#include <spdlog/fmt/fmt.h>
#include <board_point.hpp>


class game_board {
public:
    // by default: 19 lines, black move first
    explicit game_board(int board_size = 19, stone_color to_move_ = stone_color::black)
        : board_size_(board_size), move_number_(0), to_move_(to_move_) {
        for (int i = 0; i < board_size*board_size; i++) {
            points_[i] = stone_color::empty;
        }
    }

    void print_top_index(std::stringstream &ss) {
        ss << "   ";
        for (char letter = 'A'; letter <= 'A' + board_size_; ++letter) {
            if (letter!='I') {
                ss << letter << " ";
            }
        }
        ss << std::endl;
    }

    void print() {
        std::stringstream ss;
        ss << "Board Size:   " << board_size_ << std::endl;
        ss << "Move number:  " << move_number_ << std::endl;
        ss << "To move:      " << to_move() << std::endl;
        ss << std::endl;

        print_top_index(ss);

        std::vector<std::string> rrows;
        std::stringstream s;
        for (auto &it: points_) {
            board_point p(it.first, it.second, board_size_);

            if (p.is_first_col()) {
                if (p.row_no_/10==0) {
                    s << " ";
                }
                s << p.row_no_ << " ";
            }

            if (p.is_central() || p.is_star()) {
                s << "+ ";
            } else {
                s << p.ascii_format_ << " ";
            }

            if (p.is_last_col()) {
                s << p.row_no_;
                s << std::endl;

                auto t = s.str();
                rrows.push_back(t);
                s.str("");
            }
        }
        for (auto v = rrows.rbegin(); v!=rrows.rend(); ++v) {
            ss << *v;
        }
        print_top_index(ss);

        spdlog::info("\n{}", ss.str());
    }

    std::string to_move() {
        return to_move_==stone_color::black ? std::string("black") : std::string("white");
    }

    /* suppose the black stone use -1,
               the white stone use 1.
    "10+3:-1" stand for: black side place his tone on:
         Point {
              Row:10+1=11
              Column:3+1=4
         }
    */
    void parse_move_stmt(std::string stmt) {

    }

    int board_size_;
    std::map<int, stone_color> points_;
    int move_number_;
    stone_color to_move_;
};
