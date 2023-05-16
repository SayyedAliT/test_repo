#ifndef A6_810101397_COUNTMISSION_HPP
#define A6_810101397_COUNTMISSION_HPP

#include "Mission.hpp"

using namespace std;

class CountMission : public Mission {
private:
    int target_number;
public:
    CountMission(int id, int start, int end, int reward, int target_count) : Mission(id, start, end, reward),
                                                                             target_number(target_count) {}

    bool is_completed();

    void create_new_trip(shared_ptr<Trip> new_trip);

    shared_ptr<Mission> clone();

};

#endif //A6_810101397_COUNTMISSION_HPP
