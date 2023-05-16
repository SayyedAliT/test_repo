
#ifndef A6_810101397_MISSION_HPP
#define A6_810101397_MISSION_HPP

#include <memory>
#include "Trip.hpp"
#include <memory>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Mission {
protected:
    int mission_id;
    int start_timestamp;
    int end_timestamp;
    int reward_amount;
    bool status;
public:
    Mission(int id, long start, long end, long reward);

    ~Mission();

    virtual bool is_completed() = 0;

    virtual void create_new_trip(shared_ptr<Trip> new_trip) = 0;

    virtual shared_ptr<Mission> clone() = 0;

    bool is_trip_in_mission(shared_ptr<Trip> new_trip);

    int get_mission_id() { return mission_id; }

    int get_start_timestamp() { return start_timestamp; }

    int get_end_timestamp() { return end_timestamp; }

    int get_reward_amount() { return reward_amount; }

    bool get_status() { return status; }

    bool set_status_complete() { status = true; }

    int set_end_timestamp(int end_time) { end_timestamp = end_time; }
};

#endif //A6_810101397_MISSION_HPP
