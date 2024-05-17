#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class Customize {
private:
    map<string, vector<string>> homeLayout;

public:
    void CustomizeHomeDesign() {
        cout << "Setting up rooms in your home." << endl;
        int numberOfRooms;
        cout << "Enter number of rooms: ";
        cin >> numberOfRooms;
        cin.ignore();  

        for (int i = 1; i <= numberOfRooms; i++) {
            string roomName;
            cout << "Enter name for room " << i << ": ";
            getline(cin, roomName);
            homeLayout[roomName] = vector<string>();
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

        string deviceName;
        while (true) {
            cout << "Enter device name to add in " << roomName << " (or type 'done' to finish): ";
            getline(cin, deviceName);
            if (deviceName == "done") {
                break;
            }
            homeLayout[roomName].push_back(deviceName);
            cout << deviceName << " has been added to " << roomName << "." << endl;
        }
    }

void RemoveDevices() {
    string roomName;
    cout << "Enter the room to remove devices from: ";
    getline(cin, roomName);

    if (homeLayout.find(roomName) == homeLayout.end()) {
        cout << "Room does not exist." << endl;
        return;
    }

    string deviceName;
    cout << "Enter device name to remove from " << roomName << ": ";
    getline(cin, deviceName);

    bool found = false;
    int index = 0; 
    for (int i = 0; i < homeLayout[roomName].size(); i++) {
        if (homeLayout[roomName][i] == deviceName) {
            index = i;
            found = true;
            break;
        }
    }

    if (found) {
        homeLayout[roomName].erase(homeLayout[roomName].begin() + index);
        cout << deviceName << " has been removed from " << roomName << "." << endl;
    } else {
        cout << "Device not found in " << roomName << "." << endl;
    }
}


    

    void Menu() {
        while (true) {
            cout << "\nSelect an option:\n";
            cout << "1 - Customize Home Design\n";
            cout << "2 - Add New Devices\n";
            cout << "3 - Remove Devices\n";
            cout << "4 - Exit\n";
            int choice;
            cin >> choice;
            cin.ignore(); // to clear the buffer

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
                    cout << "Exiting program." << endl;
                    return;
                default:
                    cout << "Invalid option, please try again." << endl;
            }
        }
    }
};

int main() {
    Customize customizeApp;
    customizeApp.Menu();
    return 0;
}
