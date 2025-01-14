// '''Write a program in C++ to use
// map associative container. The
// keys will be the names of states
// and the values will be the
// populations of the states. When
// the program runs, the user is
// prompted to type the name of a
// state. The program then looks in
// the map, using the state name as
// an index and returns the'''
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, long long> statePopulation;

    statePopulation["California"] = 39538223;
    statePopulation["Texas"] = 29145505;
    statePopulation["Florida"] = 21538187;
    statePopulation["New York"] = 20201249;
    statePopulation["Pennsylvania"] = 13002700;
    statePopulation["Illinois"] = 12812508;

    string state;
    cout << "Enter the name of a state to find its population: ";
    getline(cin, state);

    auto it = statePopulation.find(state);

    if (it != statePopulation.end()) {
        cout << "The population of " << state << " is " << it->second << endl;
    } else {
        cout << "State not found in the map." << endl;
    }

    return 0;
}
