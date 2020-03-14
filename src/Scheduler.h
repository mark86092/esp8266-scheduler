#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <functional>
#include <vector>
#include <Ticker.h>

struct TaskItem {
    typedef std::function<void()> Callback;

    Callback callback;
    uint32_t period;
};

class Scheduler {
    private:
        Ticker t;
        volatile bool flag = true;

        unsigned int step = 0;
        std::vector<TaskItem> tasks;

        static void handleTickerFlag(volatile bool* flag);
    public:
        void add(TaskItem::Callback) ;
        void sleep(uint32_t);
        void loop();
};

#endif
