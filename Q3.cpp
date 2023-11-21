#include <bits/stdc++.h>
using namespace std;

struct Person{
    string firstname;
    string lastname;
    int age;
    string gender;
    string address;
};

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


    void readAndStoreViolations(vector<TrafficViolation>& v) {
        ifstream file("A4-Q2.csv");
        cout << "file for Q2 is opening";
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

    void displayViolations(const vector<TrafficViolation>& v) const {
        for (const auto& i : v)
            cout << i.vehicle_number << " " << i.type << " " << i.location << "\n";
    }

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

class VehicleOwner {
private:
    string Vehicle_Number;
    string FirstName;
    string LastName;
    int Age;
    string Gender;
    string Address;

public:
    // Getter functions
    string getVehicleNumber() const { return Vehicle_Number; }
    string getFirstName() const { return FirstName; }
    string getLastName() const { return LastName; }
    int getAge() const { return Age; }
    string getGender() const { return Gender; }
    string getAddress() const { return Address; }

    void readAndStorePeopleData(vector<VehicleOwner>& v) {
          fstream f("A4-Q1.csv");
          cout << "File for Q1 is opening";
        if(!f.is_open())
        {
            cerr << "error while opening file\n";
        }
        string line;
        getline(f,line); // reading header line

        while(getline(f,line,'\n'))
        {
            VehicleOwner vo;
            string temp;
            stringstream ss(line);
            getline(ss,temp,',');
            vo.Vehicle_Number = temp;
            getline(ss,temp,',');
            temp = "," + temp ;
            vo.Vehicle_Number += temp;
            getline(ss,temp,',');
            vo.FirstName = temp;
            getline(ss,temp,',');
            vo.LastName = temp;
            getline(ss,temp,',');
            vo.Age = stoi(temp);
            getline(ss,temp,',');
            vo.Gender = temp;
            getline(ss,temp,',');
            vo.Address = temp;
            v.push_back(vo);
        }
        f.close();
        
    }

    void editVehicleInfo(vector<VehicleOwner>& v) {
        VehicleOwner temp;
        cout << "Enter Vehicle number with state code which you want to edit: ";
        cin >> temp.Vehicle_Number;
        cout << "Enter first name: ";
        cin >> temp.FirstName;
        cout << "Enter Last Name: ";
        cin >> temp.LastName;
        cout << "Enter Gender: ";
        cin >> temp.Gender;
        cout << "Enter age: ";
        cin >> temp.Age;
        cout << "Enter Address: ";
        cin.ignore();
        getline(cin, temp.Address);

        for (auto& owner : v) {
            if (owner.getVehicleNumber() == temp.getVehicleNumber()) {
                owner = temp;
                return;
            }
        }

        cout << "No such vehicle exists. Edit aborted.\n";
    }

    void addNewVehicle(vector<VehicleOwner>& v) {
        VehicleOwner temp;
        cout << "Enter Vehicle number ";
        cin >> temp.Vehicle_Number;
        cout << "Enter first name: ";
        cin >> temp.FirstName;
        cout << "Enter Last Name: ";
        cin >> temp.LastName;
        cout << "Enter Gender: ";
        cin >> temp.Gender;
        cout << "Enter age: ";
        cin >> temp.Age;
        cout << "Enter Address: ";
        cin.ignore();
        getline(cin, temp.Address);

        v.push_back(temp);
    }

    void deleteVehicle(vector<VehicleOwner>& v) {
        string s;
        cout << "Enter Vehicle Number which you want to delete ";
        cin >> s;

        auto it = remove_if(v.begin(), v.end(),
            [&s](const VehicleOwner& owner) { return owner.getVehicleNumber() == s; });

        if (it != v.end()) {
            v.erase(it, v.end());
        } else {
            cout << "No such vehicle exists.\n";
        }
    }

    // void displayData(const vector<VehicleOwner>& v) const {
    //     for (const auto& owner : v) {
    //         cout << owner.getVehicleNumber() << " "
    //              << owner.getFirstName() << " "
    //              << owner.getLastName() << " "
    //              << owner.getGender() << " "
    //              << owner.getAge() << " "
    //              << owner.getAddress() << "\n";
    //     }
    // }

    void displayData(vector<VehicleOwner> v)
    {
        for(auto i:v)
        {
            cout<<i.Vehicle_Number <<" "<<i.FirstName <<" "<<i.LastName<<" "<<i.Gender<<" "<<i.Age<<" "<<i.Address<<"\n";
        }
    }

};



int main()
{
    vector<VehicleOwner> owner;
    VehicleOwner vehicleOwner;
    vehicleOwner.readAndStorePeopleData(owner);

    TrafficViolation T;
    vector<TrafficViolation> t;
    T.readAndStoreViolations(t);


    vector<Person> P;
    fstream f("A4-Q3.csv");
    if(!f.is_open())
    {
        cerr << "error while opening file\n";
    }
    string line;
    getline(f,line);
    while(getline(f,line))
    {
        Person p;
        stringstream ss(line);
        getline(ss,p.firstname,',');
        getline(ss,p.lastname,',');
        getline(ss,line,',');
        p.age = stoi(line);
        getline(ss,p.gender,',');
        getline(ss,p.address,',');

        P.push_back(p);
    }

    f.close();
    
    
    cout<<"The Probable Addressees are : \n";
    cout<<t.size() << " " << owner.size();
    cout << t[0].getVehicleNumber();
    cout << owner[0].getVehicleNumber();

    for(int i=0;i<t.size();i++)
    {
        for(int j=0;j<owner.size();j++)
        {
            if(t[i].getVehicleNumber() == owner[j].getVehicleNumber())
            {
                for(int k=0;k<P.size();k++)
                {
                    if(P[k].firstname == owner[j].getFirstName() && P[k].lastname == owner[j].getLastName() && P[k].age == owner[j].getAge()
                     && P[k].gender == owner[j].getGender() && P[k].address!=owner[j].getAddress() )
                    cout<<P[k].firstname <<" "<<P[k].lastname <<" "<<P[k].age <<" "<<P[k].address<<"\n";
                }
            }
        }
    }
    return 0;
}
