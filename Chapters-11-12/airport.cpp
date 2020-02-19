/*-------------------------------
    Hunt J. Sparra, 2020
    Practical C++, Exercise 12.3

    REQUIRES C++11

    A simple program to print out
    all flights leaving TWO airpo
    -rts provided by the user.
---------------------------------*/

#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <string>

/* DATA STRUCTURES */

struct reservation {
    int flightNumber;
    std::string source, destination;
    int departue, arrival;
};

/* FUNCTIONS */

void initializeDummyAirports();
bool invalidAirport(std::string&);


/* VARIABLES */

std::map< std::string, std::list<reservation> > reservations;
std::list<std::string> validAirports({"AUS", "ATL", "PKE", "TPA", "SRQ", "JFK"});

int main() {
    initializeDummyAirports();

    std::string target;
    std::string lastTarget;
    std::ostringstream flightInformation;

    bool onSecondAirport; // Tracks if we are reading the first or second airport in (without dense/obfuscated code)

    std::cout << "Please input an airport to check reservations from (AUS, ATL, PKE, TPA, SRQ, JFK): ";
    for (std::cin >> target; !std::cin.eof(); std::cin >> target)
    {
        if (invalidAirport(target) || target == lastTarget) {
            std::cout << "Error, invalid airport. Please reinput: ";
            continue;
        }

        for (reservation r : reservations[target]) {
            flightInformation << "Flight " << r.flightNumber << " is leaving from " << r.source << " at " << r.departue
                              << " and arrives at " << r.destination << " at " << r.arrival << std::endl;
        }

        if (onSecondAirport) {
            std::cout << flightInformation.str();
            flightInformation.str(std::string());
            lastTarget = "";
        } else {
            lastTarget = target;
        }

        onSecondAirport = !onSecondAirport;

        std::cout << "Please input an airport to check reservations from (AUS, ATL, PKE, TPA, SRQ, JFK): ";
    }

    return(0);
}

void initializeDummyAirports() {
    std::list<reservation> flightsFromAUS({{8900, "AUS", "TPA", 1400, 1530},
                                           {8899, "AUS", "TPA", 1330, 1400},
                                           {7090, "AUS", "ATL", 0500, 0600},
                                           {2000, "AUS", "PKE", 1200, 1230},
                                           {8790, "AUS", "JFK", 1400, 1500},
                                           {8791, "AUS", "JFK", 1500, 1600},
                                           {8792, "AUS", "JFK", 1600, 1700}});
    reservations.insert(std::pair< std::string, std::list<reservation> >("AUS", flightsFromAUS));

    std::list<reservation> flightsFromTPA({{4231, "TPA", "AUS", 1400, 1530},
                                           {4200, "TPA", "ATL", 1330, 1400},
                                           {3000, "TPA", "ATL", 0500, 0600},
                                           {9899, "TPA", "JFK", 1400, 1500},
                                           {9999, "TPA", "JFK", 1500, 1600},
                                           {4908, "TPA", "JFK", 1600, 1700}});
    reservations.insert(std::pair< std::string, std::list<reservation> >("TPA", flightsFromTPA));

    std::list<reservation> flightsFromSRQ({{6000, "SQR", "TPA", 1400, 1530},
                                           {6001, "SRQ", "TPA", 1330, 1400}});
    reservations.insert(std::pair< std::string, std::list<reservation> >("SRQ", flightsFromSRQ));

    std::list<reservation> flightsFromATL({{6450, "ATL", "TPA", 1400, 1530},
                                           {7900, "ATL", "TPA", 1330, 1400},
                                           {6451, "ATL", "AUS", 0500, 0600},
                                           {5090, "ATL", "JFK", 1400, 1500},
                                           {5191, "ATL", "JFK", 1500, 1600},
                                           {5192, "ATL", "JFK", 1600, 1700}});
    reservations.insert(std::pair< std::string, std::list<reservation> >("ATL", flightsFromATL));

    std::list<reservation> flightsFromJFK({{8922, "JFK", "TPA", 1400, 1530},
                                           {8999, "JFK", "TPA", 1330, 1400},
                                           {8195, "JFK", "ATL", 0500, 0600},
                                           {9234, "JFK", "AUS", 1200, 1230},
                                           {890,  "JFK", "JFK", 1400, 1500},
                                           {5543, "JFK", "JFK", 1500, 1600},
                                           {1234, "JFK", "JFK", 1600, 1700}});
    reservations.insert(std::pair< std::string, std::list<reservation> >("JFK", flightsFromJFK));

    std::list<reservation> flightsFromPKE({{1, "PKE", "AUS", 1400, 1530},
                                           {2, "PKE", "SRQ", 1330, 1400},
                                           {3, "PKE", "ATL", 0500, 0600}});
    reservations.insert(std::pair< std::string, std::list<reservation> >("PKE", flightsFromPKE));
}

bool invalidAirport(std::string& id) {
    return std::find(validAirports.begin(), validAirports.end(), id) == validAirports.end();
}