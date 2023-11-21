#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class TrafficViolation {
private:
    string vehicle_number;
    string type;
    string location;

public:
    // Getter functions
    string getVehicleNumber() const { return vehicle_number; }
    string getType() const { return type; }
    string getLocation() const { return location; }


    void editViolation(vector<TrafficViolation>& v) {
        TrafficViolation t1, t2;
        cout << "Enter original vehicle number: ";
        cin >> t1.vehicle_number;
        cout << "Enter type of violation: ";
        cin >> t1.type;
        cout << "Enter location of violation: ";
        cin.ignore();
        getline(cin, t1.location);

        cout << "Enter new vehicle number: ";
        cin >> t2.vehicle_number;
        cout << "Enter type of violation: ";
        cin >> t2.type;
        cout << "Enter new location of violation: ";
        cin.ignore();
        getline(cin, t2.location);

        for (auto& i : v) {
            if (i.vehicle_number == t1.vehicle_number && i.type == t1.type && i.location == t1.location) {
                i = t2;
                break;
            }
        }
    }

    void readAndStoreViolations(vector<TrafficViolation>& v) {
        ifstream file("A4-Q2.csv");
        if (!file.is_open()) {
            cerr << "Error while opening file\n";
            return;
        }

        TrafficViolation t;
        string line;
        getline(file, line); // Reading header line

        while (getline(file, line, '\n')) {
            stringstream ss(line);
            getline(ss, t.vehicle_number, '"');
            getline(ss, t.vehicle_number, '"');
            getline(ss, t.type, ',');
            getline(ss, t.type, ',');
            getline(ss, t.location);

            // Remove trailing spaces
            size_t endPos = t.location.find_last_not_of(" \t\n\r\f\v");
            if (endPos != string::npos)
                t.location.erase(endPos + 1);

            v.push_back(t);
        }

        file.close();
    }


    void deleteViolation(vector<TrafficViolation>& v) {
        TrafficViolation t;
        cout << "Enter vehicle number: ";
        cin >> t.vehicle_number;
        cout << "Enter type of violation: ";
        cin >> t.type;
        cout << "Enter location of violation: ";
        cin.ignore();
        getline(cin, t.location);

        for (auto it = v.begin(); it != v.end();) {
            if (it->vehicle_number == t.vehicle_number && it->type == t.type && it->location == t.location) {
                it = v.erase(it);
            } 
            else 
            {
                ++it;
            }
        }
    }


    void displayViolations(const vector<TrafficViolation>& v) const {
        for (const auto& i : v)
            cout << i.vehicle_number << " " << i.type << " " << i.location << "\n";
    }

    void addViolation(vector<TrafficViolation>& v) {
        TrafficViolation t;
        cout << "Enter vehicle number: ";
        cin >> t.vehicle_number;
        cout << "Enter type of violation: ";
        cin >> t.type;
        cout << "Enter location of violation: ";
        cin.ignore();
        getline(cin, t.location);

        v.push_back(t);
    }

    
    
};

int main() {
    // vector<TrafficViolation> violations;
    // TrafficViolation trafficViolation;

    // trafficViolation.readAndStoreViolations(violations);
    // trafficViolation.displayViolations(violations);

    // // Example usage:
    // trafficViolation.editViolation(violations);
    // trafficViolation.displayViolations(violations);

    // trafficViolation.addViolation(violations);
    // trafficViolation.displayViolations(violations);

    // trafficViolation.deleteViolation(violations);
    // trafficViolation.displayViolations(violations);


    TrafficViolation T;
    vector<TrafficViolation> t;
    T.readAndStoreViolations(t);

    while(1)
    {
        char choice;
        cout<<"Press 1 to display Violations data\n";
        cout<<"Press 2 to add new Violation\n";
        cout<<"Press 3 to delete Violation\n";
        cout<<"Press 4 to edit a Violation\n";
        cin>>choice;

        switch(choice)
        {
            case '1':
            T.displayViolations(t);
            break;
            case '2':
            T.addViolation(t);
            break;
            case '3':
            T.deleteViolation(t);
            break;
            case '4':
            T.editViolation(t);
            break;
            default:
            cout<<"Exiting question 2\n";
            return 0;
        }
    }



    
}
