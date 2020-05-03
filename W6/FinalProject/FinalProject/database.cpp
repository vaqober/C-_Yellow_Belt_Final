#include <algorithm>

#include "database.h"
#include "date.h"

using namespace std;

void Database::Add(const Date &date, const string &event) {
    const auto insert_it = entries_set[date].insert(event);

    if (insert_it.second) {
        entries[date].push_back(event);
    }
}

void Database::Print(ostream &os) const {
    for (const auto& entry : entries) {
        for (const auto& event : entry.second) {
            os << entry.first << " " << event << endl;
        }
    }
}

pair<Date, string> Database::Last(const Date& date) const {
    if (entries.empty() || date < entries.begin()->first) {
        throw invalid_argument("No entries");
    }

    auto it = prev(entries.upper_bound(date));

    return make_pair(it->first, it->second.back());
}
