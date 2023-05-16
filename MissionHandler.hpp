#ifndef A6_810101397_MISSIONHANDLER_HPP
#define A6_810101397_MISSIONHANDLER_HPP

#include "Mission.hpp"
#include "Driver.hpp"
#include "TimeMission.hpp"
#include "DistanceMission.hpp"
#include "CountMission.hpp"
#include "Trip.hpp"

class SystemHandler {
public:
    SystemHandler();

    void add_time_mission(int id, int start, int end, int target_time, int reward);

    void add_distance_mission(int id, int start, int end, int target_distance, int reward);

    void add_count_mission(int id, int start, int end, int target_count, int reward);

    void add_driver(int id);

    void assign_mission_to_driver(int mission_id, int driver_id);

    shared_ptr<Driver> find_driver_by_id(int driver_id);

    shared_ptr<Mission> find_mission_by_id(int mission_id);

    void record_ride(int start_time, int end_time, int driver_id, int distance);

    vector<shared_ptr<Mission>> get_completed_mission();

    void show_mission_status(int driver_id);

    void print_new_completed_mission(vector<shared_ptr<Mission>> completed_missions, int driver_id);

    bool is_time_arguments_valid(int start_timestamp_, int end_timestamp_);


private:
    vector<shared_ptr<Mission>> all_missions;
    vector<shared_ptr<Driver>> drivers;
    vector<shared_ptr<Trip>> completed_trips;
    vector<shared_ptr<Mission>> completed_missions;


};

#endif //A6_810101397_MISSIONHANDLER_HPP
