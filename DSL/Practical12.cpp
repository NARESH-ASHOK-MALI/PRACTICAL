// Queuesarefrequentlyusedincomputerprogramming,andatypicalexampleisthecreationofa
//  jobqueuebyanoperatingsystem. If theoperatingsystemdoesnotusepriorities, thenthejobs
//  areprocessedintheorder theyenter thesystem.WriteC++programforsimulatingjobqueue.
//  Writefunctionstoaddjobanddeletejobfromqueue.
#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Class to simulate the JobQueue system
class JobQueue {
private:
    queue<string> jobQueue;  // Queue to store jobs

public:
    // Function to add a job to the queue
    void addJob(const string &job) {
        jobQueue.push(job);  // Add the job to the queue
        cout << "Job '" << job << "' added to the queue." << endl;
    }

    // Function to delete a job from the queue (i.e., process the job)
    void deleteJob() {
        if (jobQueue.empty()) {
            cout << "No jobs in the queue to process." << endl;
        } else {
            cout << "Processing job: " << jobQueue.front() << endl;
            jobQueue.pop();  // Remove the job from the front of the queue
        }
    }

    // Function to display all jobs in the queue
    void displayQueue() {
        if (jobQueue.empty()) {
            cout << "No jobs in the queue." << endl;
            return;
        }
        cout << "Jobs in the queue: ";
        queue<string> tempQueue = jobQueue;  // Copy of the queue to avoid modifying the original
        while (!tempQueue.empty()) {
            cout << tempQueue.front() << " ";
            tempQueue.pop();
        }
        cout << endl;
    }
};

int main() {
    JobQueue jq;  // Create a JobQueue object
    int choice;
    string job;

    do {
        // Display menu options
        cout << "\nJob Queue System\n";
        cout << "1. Add Job\n";
        cout << "2. Delete Job (Process Job)\n";
        cout << "3. Display Jobs in Queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the job description: ";
                cin.ignore();  // To ignore any leftover newline character from previous input
                getline(cin, job);  // Get the job description from user
                jq.addJob(job);  // Add job to the queue
                break;

            case 2:
                jq.deleteJob();  // Process and remove job from the queue
                break;

            case 3:
                jq.displayQueue();  // Display all jobs in the queue
                break;

            case 4:
                cout << "Exiting the Job Queue System." << endl;
                break;

            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 4);  // Exit the loop when the user chooses option 4

    return 0;
}
