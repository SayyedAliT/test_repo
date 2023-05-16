//
// Created by sayyed ali on 5/16/2023.
//
#pragma once

#include "Mission.hpp"

Mission::Mission(int id_, long start_time_, long end_time_, long reward_) : mission_id(id_),
                                                                            start_timestamp(start_time_),
                                                                            end_timestamp(end_time_),
                                                                            reward_amount(reward_),
                                                                            status(false) {}


Mission::~Mission() {
}

bool Mission::is_trip_in_mission(shared_ptr<Trip> new_trip) {
    if (new_trip->get_start_timestamp() >= start_timestamp && (new_trip->get_start_timestamp() <= end_timestamp)) {
        return true;
    }
    return false;
}