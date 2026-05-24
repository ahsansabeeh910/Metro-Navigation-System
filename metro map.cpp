#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Heap {
public:
    vector<T> data;
    unordered_map<T, int> map;

    void add(T item) {
        data.push_back(item);
        map[item] = data.size() - 1;
        upheapify(data.size() - 1);
    }

    void upheapify(int ci) {
        int pi = (ci - 1) / 2;
        if (isLarger(data[ci], data[pi]) > 0) {
            swap(pi, ci);
            upheapify(pi);
        }
    }

    void swap(int i, int j) {
        T ith = data[i];
        T jth = data[j];

        data[i] = jth;
        data[j] = ith;

        map[ith] = j;
        map[jth] = i;
    }

    void display() {
        for (const auto& item : data) {
            cout << item << " ";
        }
        cout << endl;
    }

    int size() {
        return data.size();
    }

    bool isEmpty() {
        return size() == 0;
    }

    T remove() {
        swap(0, data.size() - 1);
        T rv = data.back();
        data.pop_back();
        downheapify(0);

        map.erase(rv);
        return rv;
    }

    void downheapify(int pi) {
        int lci = 2 * pi + 1;
        int rci = 2 * pi + 2;
        int mini = pi;

        if (lci < size() && isLarger(data[lci], data[mini]) > 0) {
            mini = lci;
        }

        if (rci < size() && isLarger(data[rci], data[mini]) > 0) {
            mini = rci;
        }

        if (mini != pi) {
            swap(mini, pi);
            downheapify(mini);
        }
    }

    T get() {
        return data[0];
    }

    int isLarger(T t, T o) {
        if (t > o) {
            return 1;
        } else if (t < o) {
            return -1;
        } else {
            return 0;
        }
    }

    void updatePriority(T pair) {
        int index = map[pair];
        upheapify(index);
    }
};

class MetroMap {
public:
    struct Station {
        unordered_map<string, int> neighbors;
    };

    unordered_map<string, Station> stations;

    int numVertex() {
        return stations.size();
    }

    bool containsStation(const string& stationName) {
        return stations.find(stationName) != stations.end();
    }

    void addStation(const string& stationName) {
        stations[stationName] = Station();
    }

    void removeStation(const string& stationName) {
        Station& station = stations[stationName];
        unordered_set<string> neighborsToRemove;

        for (const auto& neighbor : station.neighbors) {
            stations[neighbor.first].neighbors.erase(stationName);
            neighborsToRemove.insert(neighbor.first);
        }

        for (const auto& neighbor : neighborsToRemove) {
            station.neighbors.erase(neighbor);
        }

        stations.erase(stationName);
    }

    int numEdges() {
        int count = 0;
        for (const auto& station : stations) {
            count += station.second.neighbors.size();
        }
        return count / 2;
    }

    bool containsEdge(const string& stationName1, const string& stationName2) {
        if (!containsStation(stationName1) || !containsStation(stationName2)) {
            return false;
        }
        return stations[stationName1].neighbors.find(stationName2) != stations[stationName1].neighbors.end();
    }

    void addEdge(const string& stationName1, const string& stationName2, int distance) {
        if (!containsStation(stationName1) || !containsStation(stationName2) || containsEdge(stationName1, stationName2)) {
            return;
        }
        stations[stationName1].neighbors[stationName2] = distance;
        stations[stationName2].neighbors[stationName1] = distance;
    }

    void removeEdge(const string& stationName1, const string& stationName2) {
        if (!containsEdge(stationName1, stationName2)) {
            return;
        }
        stations[stationName1].neighbors.erase(stationName2);
        stations[stationName2].neighbors.erase(stationName1);
    }

    bool hasPath(const string& stationName1, const string& stationName2, unordered_map<string, bool>& processed) {
        if (containsEdge(stationName1, stationName2)) {
            return true;
        }

        processed[stationName1] = true;

        for (const auto& neighbor : stations[stationName1].neighbors) {
            if (!processed[neighbor.first] && hasPath(neighbor.first, stationName2, processed)) {
                return true;
            }
        }

        return false;
    }

    struct DijkstraPair {
        string stationName;
        string pathSoFar;
        int cost;

        bool operator>(const DijkstraPair& other) const {
            return cost > other.cost;
        }
    };

    int dijkstra(const string& src, const string& des, bool calculateTime) {
        unordered_map<string, DijkstraPair> distanceMap;
        priority_queue<DijkstraPair, vector<DijkstraPair>, greater<DijkstraPair>> minHeap;

        for (const auto& station : stations) {
            DijkstraPair dp;
            dp.stationName = station.first;
            dp.pathSoFar = "";
            dp.cost = INT_MAX;

            if (station.first == src) {
                dp.cost = 0;
                dp.pathSoFar = src;
            }

            distanceMap[station.first] = dp;
            minHeap.push(dp);
        }

        while (!minHeap.empty()) {
            DijkstraPair rp = minHeap.top();
            minHeap.pop();

            if (rp.stationName == des) {
                return rp.cost;
            }

            if (distanceMap[rp.stationName].cost != rp.cost) {
                continue;
            }

            for (const auto& neighbor : stations[rp.stationName].neighbors) {
                string nbrStationName = neighbor.first;
                int edgeWeight = neighbor.second;
                int newCost = rp.cost + (calculateTime ? (120 + 40 * edgeWeight) : edgeWeight);

                if (newCost < distanceMap[nbrStationName].cost) {
                    DijkstraPair dp;
                    dp.stationName = nbrStationName;
                    dp.pathSoFar = rp.pathSoFar + " -> " + nbrStationName;
                    dp.cost = newCost;

                    distanceMap[nbrStationName] = dp;
                    minHeap.push(dp);
                }
            }
        }

        return INT_MAX; // No path found
    }

    void displayMap() {
        cout << "\t Metro Map" << endl;
        cout << "\t------------------" << endl;
        cout << "----------------------------------------------------" << endl;
        cout << endl;

        for (const auto& station : stations) {
            cout << station.first << " =>" << endl;
            const Station& currentStation = station.second;

            for (const auto& neighbor : currentStation.neighbors) {
                cout << "\t" << neighbor.first << "\t" << neighbor.second << endl;
            }
        }

        cout << "\t------------------" << endl;
        cout << "---------------------------------------------------" << endl;
        cout << endl;
    }

    void displayStations() {
        cout << "\n***********************************************************************\n";
        int i = 1;
        for (const auto& station : stations) {
            cout << i << ". " << station.first << endl;
            i++;
        }
        cout << "\n***********************************************************************\n";
    }
};

int main() {
    MetroMap metroMap;

    // Create the metro map
    metroMap.addStation("Noida Sector 62");
    metroMap.addStation("Botanical Garden");
    metroMap.addStation("Yamuna Bank");
    metroMap.addStation("Rajiv Chowk");
    metroMap.addStation("Vaishali");
    metroMap.addStation("Moti Nagar");
    metroMap.addStation("Janak Puri West");
    metroMap.addStation("Dwarka Sector 21");
    metroMap.addStation("Huda City Center");
    metroMap.addStation("Saket~Y");
    metroMap.addStation("Vishwavidyalaya");
    metroMap.addStation("Chandni Chowk");
    metroMap.addStation("New Delhi");
    metroMap.addStation("AIIMS");
    metroMap.addStation("Shivaji Stadium");
    metroMap.addStation("DDS Campus");
    metroMap.addStation("IGI Airport");
    metroMap.addStation("Rajouri Garden");
    metroMap.addStation("Netaji Subhash Place");
    metroMap.addStation("Punjabi Bagh West");

    metroMap.addEdge("Noida Sector 62", "Botanical Garden", 8);
    metroMap.addEdge("Botanical Garden", "Yamuna Bank", 12);
    metroMap.addEdge("Yamuna Bank", "Rajiv Chowk", 14);
    metroMap.addEdge("Rajiv Chowk", "Vaishali", 6);
    metroMap.addEdge("Rajiv Chowk", "Moti Nagar", 12);
    metroMap.addEdge("Moti Nagar", "Janak Puri West", 15);
    metroMap.addEdge("Janak Puri West", "Dwarka Sector 21", 25);
    metroMap.addEdge("Huda City Center", "Saket", 8);
    metroMap.addEdge("Saket", "Vishwavidyalaya", 15);
    metroMap.addEdge("Vishwavidyalaya", "Chandni Chowk", 12);
    metroMap.addEdge("Chandni Chowk", "New Delhi", 5);
    metroMap.addEdge("New Delhi", "AIIMS", 9);
    metroMap.addEdge("AIIMS", "Shivaji Stadium", 4);
    metroMap.addEdge("Shivaji Stadium", "DDS Campus", 10);
    metroMap.addEdge("DDS Campus", "IGI Airport", 7);
    metroMap.addEdge("Rajouri Garden", "Moti Nagar", 3);
    metroMap.addEdge("Rajouri Garden", "Netaji Subhash Place", 4);
    metroMap.addEdge("Netaji Subhash Place", "Punjabi Bagh West", 2);

    while (true) {
    cout << "-----------------------------------------------" << endl;
    cout << "Metro Map Menu:" << endl;
    cout << "1. Display Metro Map" << endl;
    cout << "2. Display List of Stations" << endl;
    cout << "3. Check If There Is A Path Between Two Stations" << endl;
    cout << "4. Find Shortest Path Between Two Stations" << endl;
    cout << "5. Find Minimum Time Between Two Stations" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";

    int choice;
    cin >> choice;

    // Clear the input buffer
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (choice) {
        case 1:
            metroMap.displayMap();
            break;
        case 2:
            metroMap.displayStations();
            break;
        case 3: {
    cin.ignore(); // Ignore any remaining newline characters in the input buffer
    string stationName1, stationName2;
    cout << "Enter the names of station 1: ";
    getline(cin, stationName1);
    cout << "Enter the names of station 2: ";
    getline(cin, stationName2);
    unordered_map<string, bool> processed;
    bool pathExists = metroMap.hasPath(stationName1, stationName2, processed);
    cout << "Path between " << stationName1 << " and " << stationName2 << " exists: " << (pathExists ? "Yes" : "No") << endl;
    break;
}
case 4: {
    cin.ignore(); // Ignore any remaining newline characters in the input buffer
    string stationName1, stationName2;
    cout << "Enter the names of station 1: ";
    getline(cin, stationName1);
    cout << "Enter the names of station 2: ";
    getline(cin, stationName2);

    // Check if the entered station names exist in the MetroMap
    if (!metroMap.containsStation(stationName1) || !metroMap.containsStation(stationName2)) {
        cout << "One or both of the entered station names do not exist." << endl;
    } else {
        int shortestPath = metroMap.dijkstra(stationName1, stationName2, false);
        if (shortestPath == INT_MAX) {
            cout << "No path found between " << stationName1 << " and " << stationName2 << "." << endl;
        } else {
            cout << "Shortest path distance between " << stationName1 << " and " << stationName2 << ": " << shortestPath << " km" << endl;
        }
    }
    break;
}
case 5: {
    cin.ignore(); // Ignore any remaining newline characters in the input buffer
    string stationName1, stationName2;
    cout << "Enter the names of station 1: ";
    getline(cin, stationName1);
    cout << "Enter the names of station 2: ";
    getline(cin, stationName2);
    // Check if the entered station names exist in the MetroMap
    if (!metroMap.containsStation(stationName1) || !metroMap.containsStation(stationName2)) {
        cout << "One or both of the entered station names do not exist." << endl;
    } else {
        int minTime = metroMap.dijkstra(stationName1, stationName2, true);
        if (minTime == INT_MAX) {
            cout << "No path found between " << stationName1 << " and " << stationName2 << "." << endl;
        } else {
            cout << "Minimum time between " << stationName1 << " and " << stationName2 << ": " << minTime << " minutes" << endl;
        }
    }
    break;
}


        case 6:
            cout << "Exiting the program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
    }
}

    return 0;
}

