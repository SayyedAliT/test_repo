#include "CountMission.hpp"

bool CountMission::is_completed() {
    return target_number <= 0;
}

void CountMission::create_new_trip(shared_ptr<Trip> new_trip) {
    if (this->is_trip_in_mission(new_trip)) {
        target_number -= 1;
        if (target_number <= 0)
            set_end_timestamp(new_trip->get_end_timestamp());
    }
}

shared_ptr<Mission> CountMission::clone() {
    return make_shared<CountMission>(*this);
}