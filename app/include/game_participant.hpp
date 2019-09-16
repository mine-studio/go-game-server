#pragma once

#include <memory>


class game_participant {
public:
    virtual ~game_participant() {}

    virtual void deliver(const chat_message &msg) = 0;
};


typedef std::shared_ptr<game_participant> game_participant_ptr;

