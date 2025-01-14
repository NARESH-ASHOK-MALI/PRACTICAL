/*Write C++ program for storing appointment schedule for day. Appointments are booked
randomly using linked list. Set start and end time and min and max duration for visit slot.
Write functions for A) Display free slots
B) Book appointment 
C) Sort list based on time
Cancel appointment ( check validity, time bounds, availability)
Sort list based on time using pointer manipulation*/
#include <iostream>
using namespace std;

struct Appointment {
    int startTime;  // Start time in minutes (e.g., 600 for 10:00 AM)
    int endTime;    // End time in minutes
    Appointment* next;
};

class Schedule {
private:
    Appointment* head;
    const int startDay = 480;  // 8:00 AM in minutes
    const int endDay = 1020;   // 5:00 PM in minutes
    const int minDuration = 30;
    const int maxDuration = 120;

public:
    Schedule() : head(nullptr) {}

    // Function to book an appointment
    void bookAppointment(int start, int duration) {
        if (duration < minDuration || duration > maxDuration || start < startDay || start + duration > endDay) {
            cout << "Invalid appointment time or duration!" << endl;
            return;
        }

        Appointment* newAppointment = new Appointment;
        newAppointment->startTime = start;
        newAppointment->endTime = start + duration;
        newAppointment->next = nullptr;

        if (head == nullptr || head->startTime >= newAppointment->endTime) {
            // Insert at the beginning
            newAppointment->next = head;
            head = newAppointment;
        } else {
            // Insert in sorted order based on time
            Appointment* current = head;
            while (current->next != nullptr && current->next->startTime < newAppointment->startTime) {
                current = current->next;
            }

            newAppointment->next = current->next;
            current->next = newAppointment;
        }

        cout << "Appointment booked from " << minutesToTime(start) << " to " << minutesToTime(newAppointment->endTime) << endl;
    }

    // Function to display free slots
    void displayFreeSlots() {
        int previousEnd = startDay;
        Appointment* current = head;

        cout << "Free slots:" << endl;

        while (current != nullptr) {
            if (previousEnd < current->startTime) {
                cout << minutesToTime(previousEnd) << " to " << minutesToTime(current->startTime) << endl;
            }
            previousEnd = current->endTime;
            current = current->next;
        }

        if (previousEnd < endDay) {
            cout << minutesToTime(previousEnd) << " to " << minutesToTime(endDay) << endl;
        }
    }

    // Function to cancel an appointment
    void cancelAppointment(int start) {
        if (head == nullptr) {
            cout << "No appointments to cancel." << endl;
            return;
        }

        if (head->startTime == start) {
            Appointment* toDelete = head;
            head = head->next;
            delete toDelete;
            cout << "Appointment at " << minutesToTime(start) << " canceled." << endl;
            return;
        }

        Appointment* current = head;
        while (current->next != nullptr && current->next->startTime != start) {
            current = current->next;
        }

        if (current->next == nullptr) {
            cout << "No appointment found at " << minutesToTime(start) << "." << endl;
        } else {
            Appointment* toDelete = current->next;
            current->next = current->next->next;
            delete toDelete;
            cout << "Appointment at " << minutesToTime(start) << " canceled." << endl;
        }
    }

    // Function to sort the appointment list based on time
    void sortAppointments() {
        if (head == nullptr || head->next == nullptr) {
            return; // Already sorted or empty list
        }

        Appointment* sorted = nullptr;

        while (head != nullptr) {
            Appointment* current = head;
            head = head->next;

            if (sorted == nullptr || sorted->startTime > current->startTime) {
                current->next = sorted;
                sorted = current;
            } else {
                Appointment* temp = sorted;
                while (temp->next != nullptr && temp->next->startTime < current->startTime) {
                    temp = temp->next;
                }
                current->next = temp->next;
                temp->next = current;
            }
        }

        head = sorted;
        cout << "Appointments sorted." << endl;
    }

    // Helper function to convert minutes to time in HH:MM format
    string minutesToTime(int minutes) {
        int hours = minutes / 60;
        int mins = minutes % 60;
        return (hours < 10 ? "0" : "") + to_string(hours) + ":" + (mins < 10 ? "0" : "") + to_string(mins);
    }

    // Destructor to free memory
    ~Schedule() {
        while (head != nullptr) {
            Appointment* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    cout<<"USER IS NARESH ASHOK MALI SCOD16"<<endl;
    Schedule schedule;
    int choice, start, duration;

    while (true) {
        cout << "\n1. Display Free Slots\n2. Book Appointment\n3. Cancel Appointment\n4. Sort Appointments\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            schedule.displayFreeSlots();
            break;
        case 2:
            cout << "Enter start time (in minutes from 00:00, e.g., 600 for 10:00 AM): ";
            cin >> start;
            cout << "Enter duration (in minutes): ";
            cin >> duration;
            schedule.bookAppointment(start, duration);
            break;
        case 3:
            cout << "Enter start time of the appointment to cancel (in minutes): ";
            cin >> start;
            schedule.cancelAppointment(start);
            break;
        case 4:
            schedule.sortAppointments();
            break;
        case 5:
            exit(0);
        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
