#pragma once

#include <set>
#include <game_participant.hpp>

class game_room {
public:
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
    }

private:
    std::set<game_participant_ptr> participants_;
    enum {
        max_recent_msgs = 100
    };
    chat_message_queue recent_msgs_;
};


