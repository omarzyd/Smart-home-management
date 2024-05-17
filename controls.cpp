#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Device {
public:
    string name;
    map<string, string> features;

    Device(const string& name) : name(name) {}

    void setFeature(const string& feature, const string& value) {
        features[feature] = value;
    }

    void displayFeatures() const {
        cout << "Device: " << name << endl;
        for (const auto& feature : features) {
            cout << "  " << feature.first << ": " << feature.second << endl;
        }
    }
};

class Customize {
private:
    map<string, vector<Device>> homeLayout;

public:
    void CustomizeHomeDesign() {
        cout << "Setting up rooms in your home." << endl;
        int numberOfRooms;
        cout << "Enter number of rooms: ";
        cin >> numberOfRooms;
        cin.ignore();

        for (int i = 0; i < numberOfRooms; ++i) {
            string roomName;
            cout << "Enter name for room " << i + 1 << ": ";
            getline(cin, roomName);
            homeLayout[roomName] = vector<Device>();
        }
        cout << "Rooms setup complete." << endl;
    }

    void AddNewDevices() {
        string roomName;
        cout << "Enter the room to add devices to: ";
        getline(cin, roomName);

        if (homeLayout.find(roomName) == homeLayout.end()) {
            cout << "Room does not exist." << endl;
            return;
        }

        string deviceName, featureName, featureValue;
        cout << "Enter device name to add: ";
        getline(cin, deviceName);
        Device newDevice(deviceName);

        cout << "Enter feature name (type 'done' to finish adding features): ";
        while (getline(cin, featureName) && featureName != "done") {
            cout << "Enter value for " << featureName << ": ";
            getline(cin, featureValue);
            newDevice.setFeature(featureName, featureValue);
            cout << "Feature " << featureName << " set to " << featureValue << endl;
            cout << "Add another feature or type 'done': ";
        }
        homeLayout[roomName].push_back(newDevice);
        cout << deviceName << " added to " << roomName << " with configured properties." << endl;
    }

    void RemoveDevices() {
        string roomName, deviceName;
        cout << "Enter the room to remove devices from: ";
        getline(cin, roomName);

        if (homeLayout.find(roomName) == homeLayout.end()) {
            cout << "Room does not exist." << endl;
            return;
        }

        cout << "Enter device name to remove: ";
        getline(cin, deviceName);

        auto& devices = homeLayout[roomName];
        auto it = find_if(devices.begin(), devices.end(), [&](const Device& device) {
            return device.name == deviceName;
        });

        if (it != devices.end()) {
            devices.erase(it);
            cout << deviceName << " has been removed from " << roomName << "." << endl;
        } else {
            cout << "Device not found in " << roomName << "." << endl;
        }
    }

    void DisplayAllDevices() {
        for (const auto& room : homeLayout) {
            cout << "Room: " << room.first << " has the following devices:" << endl;
            for (const auto& device : room.second) {
                device.displayFeatures();
            }
        }
    }

    void Menu() {
        int choice;
        do {
            cout << "\nSelect an option:\n";
            cout << "1 - Customize Home Design\n";
            cout << "2 - Add New Devices\n";
            cout << "3 - Remove Devices\n";
            cout << "4 - Display All Devices\n";
            cout << "5 - Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore(); // Clear the buffer to handle the newline character after cin

            switch (choice) {
                case 1:
                    CustomizeHomeDesign();
                    break;
                case 2:
                    AddNewDevices();
                    break;
                case 3:
                    RemoveDevices();
                    break;
                case 4:
                    DisplayAllDevices();
                    break;
                case 5:
                    cout << "Exiting program." << endl;
                    return; // Return to exit the menu loop and thus the function
                default:
                    cout << "Invalid option, please try again." << endl;
                    break;
            }
        } while (choice != 5); // Loop until the user chooses to exit
    }
};

int main() {
    Customize customizeApp;
    customizeApp.Menu();
    return 0;
}
