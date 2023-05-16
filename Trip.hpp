#ifndef A6_810101397_TRIP_HPP
#define A6_810101397_TRIP_HPP

class Trip {
private:
    int start_timestamp;
    int end_timestamp;
    int driver_id;
    int distance_traveled;
public:
    Trip(int start, int end, int driver, int distance) : start_timestamp(start), end_timestamp(end), driver_id(driver),
                                                         distance_traveled(distance) {}

    int get_start_timestamp() {
        return start_timestamp;
    }

    int get_end_timestamp() {
        return end_timestamp;
    }

    int get_driver_id() {
        return driver_id;
    }

    int get_distance_traveled() {
        return distance_traveled;
    }
};

#endif //A6_810101397_TRIP_HPP
