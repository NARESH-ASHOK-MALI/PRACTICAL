//  WriteC++programfor storingappointment scheduleforday.Appointmentsarebooked
//  randomlyusinglinkedlist.Setstartandendtimeandminandmaxdurationforvisitslot.
//  Writefunctionsfor
// A)DisplayfreeslotsB)Bookappointment C)Sortlistbasedontime
//  Cancelappointment(checkvalidity,timebounds,availability)
//  Sortlistbasedontimeusingpointermanipulation
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Node to store appointment information
class Appointment {
public:
    int startTime; // Appointment start time in 24-hour format (e.g., 900 for 9:00 AM)
    int endTime;   // Appointment end time in 24-hour format
    string description;
    Appointment* next;

    Appointment(int start, int end, string desc) : startTime(start), endTime(end), description(desc), next(nullptr) {}
};

// Appointment Schedule
class AppointmentSchedule {
private:
    Appointment* head;
    const int dayStart = 900;  // Day starts at 9:00 AM
    const int dayEnd = 1700;   // Day ends at 5:00 PM

    // Helper to check if two time slots overlap
    bool isOverlap(int start, int end) {
        Appointment* temp = head;
        while (temp) {
            if ((start >= temp->startTime && start < temp->endTime) || 
                (end > temp->startTime && end <= temp->endTime) ||
                (start <= temp->startTime && end >= temp->endTime)) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

public:
    AppointmentSchedule() : head(nullptr) {}

    // Display all free slots
    void displayFreeSlots() {
        cout << "Free slots for the day:" << endl;
        Appointment* temp = head;
        int currentTime = dayStart;

        while (temp) {
            if (currentTime < temp->startTime) {
                cout << setw(4) << setfill('0') << currentTime << " - "
                     << setw(4) << setfill('0') << temp->startTime << endl;
            }
            currentTime = temp->endTime;
            temp = temp->next;
        }

        if (currentTime < dayEnd) {
            cout << setw(4) << setfill('0') << currentTime << " - "
                 << setw(4) << setfill('0') << dayEnd << endl;
        }
    }

    // Book an appointment
    void bookAppointment(int start, int end, string description) {
        if (start < dayStart || end > dayEnd || start >= end) {
            cout << "Invalid time slot! Appointment must be between 09:00 AM and 05:00 PM." << endl;
            return;
        }
        if (isOverlap(start, end)) {
            cout << "Time slot overlaps with an existing appointment!" << endl;
            return;
        }

        Appointment* newAppointment = new Appointment(start, end, description);

        if (!head || start < head->startTime) {
            newAppointment->next = head;
            head = newAppointment;
        } else {
            Appointment* temp = head;
            while (temp->next && temp->next->startTime < start) {
                temp = temp->next;
            }
            newAppointment->next = temp->next;
            temp->next = newAppointment;
        }
        cout << "Appointment booked successfully from " << setw(4) << setfill('0') << start
             << " to " << setw(4) << setfill('0') << end << " for " << description << "." << endl;
    }

    // Cancel an appointment
    void cancelAppointment(int start, int end) {
        if (!head) {
            cout << "No appointments scheduled to cancel." << endl;
            return;
        }

        Appointment* temp = head;
        Appointment* prev = nullptr;

        while (temp && (temp->startTime != start || temp->endTime != end)) {
            prev = temp;
            temp = temp->next;
        }

        if (!temp) {
            cout << "Appointment not found for the given time slot." << endl;
            return;
        }

        if (prev) {
            prev->next = temp->next;
        } else {
            head = temp->next;
        }

        delete temp;
        cout << "Appointment from " << setw(4) << setfill('0') << start
             << " to " << setw(4) << setfill('0') << end << " has been canceled." << endl;
    }

    // Sort appointments based on time using pointer manipulation
    void sortAppointments() {
        if (!head || !head->next) return;

        Appointment* sorted = nullptr;

        while (head) {
            Appointment* current = head;
            head = head->next;

            if (!sorted || current->startTime < sorted->startTime) {
                current->next = sorted;
                sorted = current;
            } else {
                Appointment* temp = sorted;
                while (temp->next && temp->next->startTime < current->startTime) {
                    temp = temp->next;
                }
                current->next = temp->next;
                temp->next = current;
            }
        }
        head = sorted;
    }

    // Display all appointments
    void displayAppointments() {
        if (!head) {
            cout << "No appointments scheduled." << endl;
            return;
        }

        Appointment* temp = head;
        cout << "Scheduled appointments:" << endl;
        while (temp) {
            cout << setw(4) << setfill('0') << temp->startTime << " - "
                 << setw(4) << setfill('0') << temp->endTime << ": " << temp->description << endl;
            temp = temp->next;
        }
    }
};

int main() {
    AppointmentSchedule schedule;

    int choice;
    do {
        cout << "\n--- Appointment Scheduling System ---\n";
        cout << "1. Display free slots\n";
        cout << "2. Book an appointment\n";
        cout << "3. Cancel an appointment\n";
        cout << "4. Display appointments\n";
        cout << "5. Sort appointments\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                schedule.displayFreeSlots();
                break;
            case 2: {
                int start, end;
                string description;
                cout << "Enter start time (HHMM): ";
                cin >> start;
                cout << "Enter end time (HHMM): ";
                cin >> end;
                cin.ignore();
                cout << "Enter description: ";
                getline(cin, description);
                schedule.bookAppointment(start, end, description);
                break;
            }
            case 3: {
                int start, end;
                cout << "Enter start time (HHMM): ";
                cin >> start;
                cout << "Enter end time (HHMM): ";
                cin >> end;
                schedule.cancelAppointment(start, end);
                break;
            }
            case 4:
                schedule.displayAppointments();
                break;
            case 5:
                schedule.sortAppointments();
                cout << "Appointments sorted by time." << endl;
                break;
            case 6:
                cout << "Exiting the system. Thank you!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
