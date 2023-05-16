#include "Driver.hpp"

void print_each_mission_info(shared_ptr<Mission> my_mission) {
    cout << "mission " << my_mission->get_mission_id() << ":" << endl;
    cout << "start timestamp: " << my_mission->get_start_timestamp() << endl;
    if (my_mission->is_completed()) {
        cout << "end timestamp: " << my_mission->get_end_timestamp() << endl;
    } else
        cout << "end timestamp: " << -1 << endl;
    cout << "reward: " << my_mission->get_reward_amount() << endl;
    if (my_mission->is_completed())
        cout << "status: completed" << endl;
    else
        cout << "status: ongoing" << endl;


}

bool Driver::is_duplicate_mission(int id) {
    for (shared_ptr<Mission> mission: missions) {
        if (mission->get_mission_id() == id) {
            return true;
        }
    }
    return false;

}

vector<shared_ptr<Mission>> Driver::get_completed_missions() {
    vector<shared_ptr<Mission>> completed_missions;
    for (shared_ptr<Mission> m: missions) {
        if (m->is_completed()) {
            completed_missions.push_back(m);
        }
    }
    return completed_missions;
}

void Driver::assign_mission(shared_ptr<Mission> mission) {
    if (is_duplicate_mission(mission->get_mission_id())) {
        throw "DUPLICATE_DRIVER_MISSION";
    }
    missions.push_back(mission->clone());
}

void Driver::update_missions(shared_ptr<Trip> trip) {
    for (shared_ptr<Mission> driver_mission: missions) {
        if ((driver_mission->is_trip_in_mission(trip)) && !driver_mission->is_completed()) {
            driver_mission->create_new_trip(trip);
        }
    }
}

void Driver::show_driver_missions() {
    if (missions.size() == 0) {
        throw "DRIVER_MISSION_NOT_FOUND";
    }
    sort(missions.begin(), missions.end(), compare_mission);
    cout << "missions status for driver " << this->get_driver_id() << ":" << endl;
    for (int index = 0; index < missions.size(); index++) {
        print_each_mission_info(missions[index]);
        if (index != missions.size() - 1)
            cout << endl;
    }

}

vector<shared_ptr<Mission>> Driver::get_new_completed_missions() {
    vector<shared_ptr<Mission>> new_completed_mission;
    for (int index = 0; index < missions.size(); index++) {
        if (missions[index]->is_completed() && !missions[index]->get_status()) {
            missions[index]->set_status_complete();
            new_completed_mission.push_back(missions[index]);
        }
    }
    return new_completed_mission;
}