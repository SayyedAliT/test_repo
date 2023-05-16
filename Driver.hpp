#ifndef A6_810101397_DRIVER_HPP
#define A6_810101397_DRIVER_HPP

#include "Mission.hpp"

using namespace std;

class Driver {
private:
    int driver_id;
    vector<shared_ptr<Mission>> missions;

    bool is_duplicate_mission(int id);

public:
    Driver(int id) : driver_id(id) {}

    void assign_mission(shared_ptr<Mission> mission);

    vector<shared_ptr<Mission>> get_completed_missions();

    int get_driver_id() { return driver_id; }

    void update_missions(shared_ptr<Trip> new_trip);

    void show_driver_missions();

    vector<shared_ptr<Mission>> get_new_completed_missions();

    vector<shared_ptr<Mission>> get_mission() { return missions; }
};

bool compare_mission(shared_ptr<Mission> a, shared_ptr<Mission> b) {
    if (a->get_start_timestamp() < b->get_start_timestamp())
        return 1;
    else
        return 0;
}

#endif //A6_810101397_DRIVER_HPP
