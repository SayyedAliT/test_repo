#include "MissionHandler.hpp"

SystemHandler::SystemHandler() {}

bool SystemHandler::is_time_arguments_valid(int start_timestamp_, int end_timestamp_) {
    if (start_timestamp_ < end_timestamp_)
        return true;
    return false;
}


void SystemHandler::add_time_mission(int id, int start, int end, int target_time, int reward) {
    for (shared_ptr<Mission> m: all_missions) {
        if (m->get_mission_id() == id) {
            throw "DUPLICATE_MISSION_ID";
        }
    }
    if (!is_time_arguments_valid(start, end) || target_time < 0 || reward < 0)
        throw "INVALID_ARGUMNETS";

    shared_ptr<Mission> mission = make_shared<TimeMission>(id, start, end, reward, target_time * 60);
    all_missions.push_back(mission);
    throw "OK";
}

void SystemHandler::add_distance_mission(int id, int start, int end, int target_distance, int reward) {
    for (shared_ptr<Mission> m: all_missions) {
        if (m->get_mission_id() == id) {
            throw "DUPLICATE_MISSION_ID";
        }
    }
    if (!is_time_arguments_valid(start, end) || target_distance < 0 || reward < 0)
        throw "INVALID_ARGUMNETS";
    shared_ptr<Mission> mission = make_shared<DistanceMission>(id, start, end, reward, target_distance);
    all_missions.push_back(mission);
    throw "OK";
}

void SystemHandler::add_count_mission(int id, int start, int end, int target_count, int reward) {
    for (shared_ptr<Mission> m: all_missions) {
        if (m->get_mission_id() == id) {
            throw "DUPLICATE_MISSION_ID";
        }
    }
    if (!is_time_arguments_valid(start, end) || target_count < 0 || reward < 0)
        throw "INVALID_ARGUMNETS";
    shared_ptr<Mission> mission = make_shared<CountMission>(id, start, end, reward, target_count);
    all_missions.push_back(mission);
    throw "OK";
}

shared_ptr<Mission> SystemHandler::find_mission_by_id(int mission_id) {
    for (shared_ptr<Mission> mission_: all_missions) {
        if (mission_->get_mission_id() == mission_id) {
            return mission_;
        }
    }
    return nullptr;
}

void SystemHandler::add_driver(int id) {
    for (shared_ptr<Driver> d: drivers) { // this part is for finding
        if (d->get_driver_id() == id) {
            throw "DUPLICATE_DRIVER";
        }
    }
    shared_ptr<Driver> driver = make_shared<Driver>(id);
    drivers.push_back(driver);
}

void SystemHandler::assign_mission_to_driver(int mission_id, int driver_id) { /// need a void that find the misson by id
    shared_ptr<Mission> mission_to_assign = nullptr;
    mission_to_assign = find_mission_by_id(mission_id);
    if (mission_to_assign == nullptr) {
        throw "MISSION_NOT_FOUND";
    }

    shared_ptr<Driver> driver = nullptr;   // find driver by id
    for (shared_ptr<Driver> d: drivers) {
        if (d->get_driver_id() == driver_id) {
            driver = d;
            break;
        }
    }
    if (driver == nullptr) {
        add_driver(driver_id);
        driver = drivers[drivers.size() - 1];
    }

    driver->assign_mission(mission_to_assign);
    throw "OK";
}

shared_ptr<Driver> SystemHandler::find_driver_by_id(int driver_id) {
    for (shared_ptr<Driver> driver: drivers) {
        if (driver->get_driver_id() == driver_id) {
            return driver;
        }
    }

    return nullptr;
}

void SystemHandler::print_new_completed_mission(vector<shared_ptr<Mission>> completed_missions, int driver_id) {
    cout << "completed missions for driver " << driver_id << ":" << endl;
    sort(completed_missions.begin(), completed_missions.end(), compare_mission);
    for (int index = 0; index < completed_missions.size(); index++) {
        cout << "mission: " << completed_missions[index]->get_mission_id() << endl;
        cout << "start timestamp: " << completed_missions[index]->get_start_timestamp() << endl;
        cout << "end timestamp: " << completed_missions[index]->get_end_timestamp() << endl;
        cout << "reward: " << completed_missions[index]->get_reward_amount() << endl;
        if (index != completed_missions.size() - 1) { cout << endl; }

    }
}

void SystemHandler::record_ride(int start_time, int end_time, int driver_id, int distance) {
    if (start_time > end_time)
        throw "INVALID_ARGUMENTS";
    shared_ptr<Trip> trip = make_shared<Trip>(start_time, end_time, driver_id, distance);
    completed_trips.push_back(trip);
    shared_ptr<Driver> target_driver = find_driver_by_id(driver_id);
    if (target_driver == nullptr) {
        add_driver(driver_id);
        target_driver = drivers[drivers.size() - 1];
    }
    target_driver->update_missions(trip);
    vector<shared_ptr<Mission>> new_completed = target_driver->get_new_completed_missions();

    print_new_completed_mission(new_completed, driver_id);

}

vector<shared_ptr<Mission>> SystemHandler::get_completed_mission() {
    for (shared_ptr<Mission> mission: all_missions) {
        if (mission->is_completed()) {
            completed_missions.push_back(mission);
        }
    }
    return completed_missions;
}

void SystemHandler::show_mission_status(int driver_id) {
    shared_ptr<Driver> target_driver = find_driver_by_id(driver_id);
    if (target_driver == nullptr)
        throw "MISSION_NOT_FOUND";
    target_driver->show_driver_missions();
}