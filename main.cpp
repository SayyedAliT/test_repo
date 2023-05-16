#pragma once

#include <iostream>
#include <memory>
#include <algorithm>
#include <string>
#include <vector>
#include "MissionHandler.hpp"

const char SEPARATOR = ' ';
const int MAX_SIZE = 10000;
const char ENTER = '\n';
using namespace std;

int read_input(string command, SystemHandler &system_manager) {
    try {
        if (command == "add_time_mission") {
            int mission_id, start_timestamp, end_timestamp, target_time_in_minute, reward_amount;
            cin >> mission_id >> start_timestamp >> end_timestamp >> target_time_in_minute >> reward_amount;
            system_manager.add_time_mission(mission_id, start_timestamp, end_timestamp, target_time_in_minute,
                                            reward_amount);
        } else if (command == "add_count_mission") {
            int mission_id, start_timestamp, end_timestamp, target_number, reward_amount;
            cin >> mission_id >> start_timestamp >> end_timestamp >> target_number >> reward_amount;
            system_manager.add_count_mission(mission_id, start_timestamp, end_timestamp, target_number, reward_amount);
        } else if (command == "add_distance_mission") {
            int mission_id, start_timestamp, end_timestamp, target_distance_in_meters, reward_amount;
            cin >> mission_id >> start_timestamp >> end_timestamp >> target_distance_in_meters >> reward_amount;
            system_manager.add_distance_mission(mission_id, start_timestamp, end_timestamp, target_distance_in_meters,
                                                reward_amount);

        } else if (command == "assign_mission") {
            int mission_id, driver_id;
            cin >> mission_id >> driver_id;
            system_manager.assign_mission_to_driver(mission_id, driver_id);
        } else if (command == "record_ride") {
            int start_timestamp, end_timestamp, driver_id, distance;
            cin >> start_timestamp >> end_timestamp >> driver_id >> distance;
            system_manager.record_ride(start_timestamp, end_timestamp, driver_id, distance);
        } else if (command == "show_missions_status") {
            int driver_id;
            cin >> driver_id;
            system_manager.show_mission_status(driver_id);
        } else
            throw "INVALID_ARGUMENTS";
    } catch (const char *error) {

        cout << error << endl;
    }
    cin.clear();
    cin.ignore(MAX_SIZE, ENTER);
}

int main() {
    string command;
    SystemHandler system_manager;
    while (getline(cin, command, SEPARATOR)) {
        read_input(command, system_manager);
    }
}