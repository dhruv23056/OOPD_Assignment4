#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Person {
    string firstname;
    string lastname;
    int age;
    string gender;
    string address;
};

struct Violation {
    string vehicle_number;
    string type;
    string location;
};

class Evidence {
private:
    vector<Person> witnesses;
    Violation violationDetails;
    string responseText;
    string priorInfo;

public:
    Evidence() {}

    Evidence(const vector<Person>& u, const Violation& v, const string& w, const string& x) {
        witnesses = u;
        violationDetails = v;
        responseText = w;
        priorInfo = x;
    }

    void addWitness() {
        Person person;
        cout << "Enter first name: ";
        cin >> person.firstname;
        cout << "Enter last name: ";
        cin >> person.lastname;
        cout << "Enter age: ";
        cin >> person.age;
        cout << "Enter gender: ";
        cin >> person.gender;
        cout << "Enter address: ";
        getchar();
        getline(cin, person.address);

        witnesses.push_back(person);
    }

    void addViolationDetails() {
        Violation violation;
        cout << "Enter vehicle number: ";
        cin >> violation.vehicle_number;
        cout << "Enter type of violation: ";
        cin >> violation.type;
        cout << "Enter location of violation: ";
        getchar();
        getline(cin, violation.location);

        violationDetails = violation;
    }

    void addResponseText() {
        string text;
        cout << "Enter response text: ";
        getchar();
        getline(cin, text);
        responseText = text;
    }

    void addPriorInfo() {
        string info;
        cout << "Enter any prior information about the person: ";
        getchar();
        getline(cin, info);

        priorInfo = info;
    }

    const vector<Person>& getWitnesses() const {
        return witnesses;
    }

    const Violation& getViolationDetails() const {
        return violationDetails;
    }

    const string& getResponseText() const {
        return responseText;
    }

    const string& getPriorInfo() const {
        return priorInfo;
    }

    void writeToCSV(const string& fileName) const {
        ofstream file(fileName);
        if (!file.is_open()) {
            cerr << "Error while opening file\n";
            return;
        }

        for (const auto& witness : witnesses) {
            file << witness.firstname << ',' << witness.lastname << ',' << witness.age << ',' << witness.gender << ',' << witness.address << '\n';
        }

        file << violationDetails.vehicle_number << ',' << violationDetails.type << ',' << violationDetails.location << '\n';
        file << responseText << '\n';
        file << priorInfo << '\n';

        file.close();
    }
};

int main() {
    vector<Evidence> evidenceList;

    while (1) {
        int numWitnesses;
        cout << "Enter the number of witnesses for the accident: ";
        cin >> numWitnesses;

        Evidence evidence;
        while (numWitnesses--) {
            evidence.addWitness();
        }
        evidence.addViolationDetails();
        evidence.addResponseText();
        evidence.addPriorInfo();

        evidenceList.push_back(evidence);

        char choice;
        cout << "For adding more evidence for other accidents, press Y/y\n";
        cin >> choice;

        if (choice != 'Y' && choice != 'y')
            break;
    }

    for (int i = 0; i < evidenceList.size(); i++) {
        evidenceList[i].writeToCSV("evidence_" + to_string(i) + ".csv");
    }

    return 0;
}
