#include "Scheduler.h"

void Scheduler::handleTickerFlag(Scheduler *s) {
    s->flag = true;
}

 void Scheduler::add(TaskItem::Callback callback) {
    TaskItem task;
    task.callback = callback;
    task.period = 0;
    tasks.push_back(task);
};

void Scheduler::sleep(uint32_t period) {
    TaskItem task;
    task.callback = nullptr;
    task.period = period;
    tasks.push_back(task);
};

void Scheduler::loop() {
    if (flag) {
        flag = false;
        TaskItem task = tasks[step];
        step = (step + 1) % tasks.size();
        if (task.callback) {
            task.callback();
        }
        t.once_ms(task.period, Scheduler::handleTickerFlag, this);
    }
}
