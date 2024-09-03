#pragma once

#include <queue>
#include <memory>
#include <mutex>

#include "IEvent.h"
#include "IEventQueue.h"

namespace RixinSDL {
    class Queue : public IEventQueue {
    private:
        //  Private stuff here
        std::mutex mutex;
        std::queue<std::unique_ptr<IEvent>> eventQueue;
    public:
        //  Public stuff here
        void queueEvent(std::unique_ptr<IEvent> event);
        std::unique_ptr<IEvent> getEvent();
    };
} // EventQueue
