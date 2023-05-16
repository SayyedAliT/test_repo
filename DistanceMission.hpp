//
// Created by sayyed ali on 5/16/2023.
//

#ifndef A6_810101397_DISTANCEMISSION_HPP
#define A6_810101397_DISTANCEMISSION_HPP

#include "Mission.hpp"

using namespace std;

class DistanceMission : public Mission {
private:
    int target_distance_in_meters;
public:
    DistanceMission(int id, int start, int end, int reward, int target_distance) : Mission(id, start, end, reward),
                                                                                   target_distance_in_meters(
                                                                                           target_distance) {}

    bool is_completed();

    shared_ptr<Mission> clone();

    void create_new_trip(shared_ptr<Trip> new_trip);

    int get_remaining_time() {
        return -1; // not applicable
    }

    int get_remaining_trips() {
        return -1; // not applicable
    }
};

#endif //A6_810101397_DISTANCEMISSION_HPP
