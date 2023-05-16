#ifndef A6_810101397_TIMEMISSION_HPP
#define A6_810101397_TIMEMISSION_HPP

#include "Mission.hpp"

using namespace std;

class TimeMission : public Mission {
private:
    int target_time_in_minutes;
public:
    TimeMission(int id, int start, int end, int reward, int target_time);

    bool is_completed();

    void create_new_trip(shared_ptr<Trip> new_trip);

    shared_ptr<Mission> clone();
};

#endif //A6_810101397_TIMEMISSION_HPP
