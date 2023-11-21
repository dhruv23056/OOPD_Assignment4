#include <bits/stdc++.h>
using namespace std;

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
        if(!f.is_open())
        {
            cerr << "File not open\n";
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

    void addNewVehicle(vector<VehicleOwner>& v) {
        VehicleOwner temp;
        cout << "Enter Vehicle number with state code: ";
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


    void editVehicleInfo(vector<VehicleOwner>& v) {
        VehicleOwner temp;
        cout << "Enter the vehicle number: ";
        cin >> temp.Vehicle_Number;
        cout << "Enter first name: ";
        cin >> temp.FirstName;
        cout << "Enter last name: ";
        cin >> temp.LastName;
        cout << "Enter gender: ";
        cin >> temp.Gender;
        cout << "Enter Age: ";
        cin >> temp.Age;
        cout << "Enter address: ";
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

    void deleteVehicle(vector<VehicleOwner>& v) {
        string s;
        cout << "Enter Vehicle Number to be deleted with state code: ";
        cin >> s;

        auto it = remove_if(v.begin(), v.end(),
            [&s](const VehicleOwner& owner) { return owner.getVehicleNumber() == s; });

        if (it != v.end()) {
            v.erase(it, v.end());
        } else {
            cout << "No such vehicle exists. Delete aborted.\n";
        }
    }


};

int main() {
    // vector<VehicleOwner> owners;
    // VehicleOwner vehicleOwner;

    // vehicleOwner.readAndStorePeopleData(owners);
    // vehicleOwner.displayData(owners);

    // // Example usage:
    // vehicleOwner.editVehicleInfo(owners);
    // vehicleOwner.displayData(owners);

    // vehicleOwner.addNewVehicle(owners);
    // vehicleOwner.displayData(owners);

    // vehicleOwner.deleteVehicle(owners);
    // vehicleOwner.displayData(owners);

    // return 0;
    // VehicleOwner V;
    // vector<VehicleOwner> v;
    vector<VehicleOwner> owners;
    VehicleOwner vehicleOwner;

    vehicleOwner.readAndStorePeopleData(owners);

    while(1)
    {
        char choice;
        cout<<"Press 1 to display vehicle details\n";
        cout<<"Press 2 to add a vehicle\n";
        cout<<"Press 3 to delete vehicle details\n";
        cout<<"Press 4 to edit a vehicle details\n";
        cin>>choice;

        switch(choice)
        {
            case '1':
            vehicleOwner.displayData(owners);
            break;
            case '2':
            vehicleOwner.addNewVehicle(owners);
            break;
            case '3':
            vehicleOwner.deleteVehicle(owners);
            break;
            case '4':
            vehicleOwner.editVehicleInfo(owners);
            break;
            default:
            cout<<"Exiting question 1\n";
            return 0;
        }
    }
    
}
