#pragma once

#include <utility>
#include <string>


enum class stone_color {
    black = -1,
    white = 1,
    empty = 0
};


class board_point {
public:
    board_point() = delete;

    explicit board_point(int point_index, stone_color color, int board_size)
        : point_index_(point_index), color_(color), board_size_(board_size) {
        row_no_ = row_number();
        col_no_ = col_number();

        switch (color_) {
        case stone_color::white:ascii_format_ = "0";
            break;
        case stone_color::black:ascii_format_ = "X";
            break;
        case stone_color::empty:
        default:ascii_format_ = ".";
        }
    }

    void print() {
        spdlog::info("Point<index: {}, row_no: {}, col_no: {}>", point_index_, row_no_, col_no_);
    }

    bool is_first_col() {
        return col_no_==1;
    }

    bool is_last_col() {
        return col_no_==board_size_;
    }

    bool is_first_row() {
        return row_no_==1;
    }

    bool is_last_row() {
        return row_no_==board_size_;
    }

    bool is_star() {
        board_point central = get_central();

        int col_distance = abs(central.col_no_ - col_no_);
        int row_distance = abs(central.row_no_ - row_no_);

        int fixed_distance = 6;
        if (board_size_==19) {
            fixed_distance = 6;
        }
        if (board_size_==13) {
            fixed_distance = 4;
        }
        if (board_size_==9) {
            fixed_distance = 2;
        }
        return (col_distance==fixed_distance && row_distance==fixed_distance);
    }

    bool is_central() {
        int central = (board_size_ + 1)/2;
        return col_no_==central && row_no_==central;
    }

    board_point get_central() {
        int central_point_index = (board_size_*board_size_)/2;
        return board_point(central_point_index, stone_color::empty, board_size_);
    }

    bool operator==(board_point &p) {
        return p.point_index_==this->point_index_;
    }

    // value range from 0 to (board_size_ * board_size -1)
    int point_index_;
    // all No. start from 1, not Zero
    int row_no_;
    int col_no_;
    int board_size_;
    stone_color color_;
    std::string ascii_format_;

private:
    // start from 1
    int row_number() {
        return point_index_/board_size_ + 1;
    }

    // start from 1
    int col_number() {
        return point_index_%board_size_ + 1;
    }
};





