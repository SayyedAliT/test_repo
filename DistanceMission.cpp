#include "DistanceMission.hpp"

bool DistanceMission::is_completed() {
    return target_distance_in_meters <= 0;
}

void DistanceMission::create_new_trip(shared_ptr<Trip> new_trip) {
    if (this->is_trip_in_mission(new_trip)) {
        target_distance_in_meters -= new_trip->get_distance_traveled();
        if (target_distance_in_meters <= 0)
            set_end_timestamp(new_trip->get_end_timestamp());
    }
}

shared_ptr<Mission> DistanceMission::clone() {
    return make_shared<DistanceMission>(*this);
}