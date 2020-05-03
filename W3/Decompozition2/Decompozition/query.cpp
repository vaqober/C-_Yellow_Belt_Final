#include "query.h"

istream& operator >> (istream& is, Query& q) {
    string inputStr;
    is >> inputStr;
    if (inputStr == "NEW_BUS") {
        q.type = QueryType::NewBus;
        is >> q.bus;
        int stop_count = 0;
        is >> stop_count;
        q.stops.resize(stop_count);
        for (auto& stop : q.stops) {
            is >> stop;
        }
    }
    else if (inputStr == "BUSES_FOR_STOP") {
        q.type = QueryType::BusesForStop;
        is >> q.stop;
    }
    else if (inputStr == "STOPS_FOR_BUS") {
        q.type = QueryType::StopsForBus;
        is >> q.bus;
    }
    else if (inputStr == "ALL_BUSES") {
        q.type = QueryType::AllBuses;
    }
    return is;
}