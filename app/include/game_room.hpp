#pragma once

#include <set>
#include <game_participant.hpp>
#include <game_board.hpp>


class game_room {
public:
    explicit game_room()
        : board_() {
        board_.print();
    }

    void join(game_participant_ptr participant) {
        participants_.insert(participant);
        for (auto msg: recent_msgs_)
            participant->deliver(msg);
    }

    void leave(game_participant_ptr participant) {
        participants_.erase(participant);
    }

    void deliver(const chat_message &msg) {
        recent_msgs_.push_back(msg);
        while (recent_msgs_.size() > max_recent_msgs)
            recent_msgs_.pop_front();

        for (auto participant: participants_)
            participant->deliver(msg);

        board_.print();
    }

private:
    std::set<game_participant_ptr> participants_;
    enum {
        max_recent_msgs = 100
    };
    chat_message_queue recent_msgs_;
    game_board board_;
};


