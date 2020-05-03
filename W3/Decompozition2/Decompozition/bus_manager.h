
#ifndef PROJECT_BUS_MANAGER_H
#define PROJECT_BUS_MANAGER_H

#endif //BUS_MANAGER_H

#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "responses.h"

using namespace std;

class BusManager {
public:
    void AddBus(const string& bus, const vector<string>& stops);

    BusesForStopResponse GetBusesForStop(const string& stop) const;

    StopsForBusResponse GetStopsForBus(const string& bus) const;

    AllBusesResponse GetAllBuses() const;

private:
    map<string, vector<string>> buses_to_stops;
    map<string, vector<string>> stops_to_buses;
};