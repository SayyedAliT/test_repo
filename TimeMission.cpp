#include "TimeMission.hpp"

TimeMission::TimeMission(int id, int start, int end, int reward, int target_time) : Mission(id, start, end, reward),
                                                                                    target_time_in_minutes(
                                                                                            target_time) {}

bool TimeMission::is_completed() {
    return target_time_in_minutes <= 0;
}

void TimeMission::create_new_trip(shared_ptr<Trip> new_trip) {
    if (this->is_trip_in_mission(new_trip)) {
        int duration = new_trip->get_end_timestamp() - new_trip->get_start_timestamp();
        target_time_in_minutes -= duration;
        if (target_time_in_minutes <= 0)
            set_end_timestamp(new_trip->get_end_timestamp());
    }
}

shared_ptr<Mission> TimeMission::clone() {
    return make_shared<TimeMission>(*this);
}