#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <deque>

using namespace std;

int main() {
    // Core Data Structures from CS50 Curriculum
    deque<string> taskQueue;       // Incoming lab tasks queue (FIFO), deque so Undo can push to front
    stack<string> completedStack;  // History of completed tasks for Undo/Back (LIFO)
    vector<string> notesVector;    // Dynamic array to archive notes & commands

    int choice = 0;

    while (choice != 6) {
        // Main Menu UI
        cout << "\n============================================\n";
        cout << "              CS50 Guide System             \n";
        cout << "============================================\n";
        cout << "1. Add New Lab Task\n";
        cout << "2. View & Process Current Task (Next)\n";
        cout << "3. Go Back to Previous Task (Undo)\n";
        cout << "4. Save a Quick Note or Command\n";
        cout << "5. Search Saved Notes & Commands\n";
        cout << "6. Exit\n";
        cout << "Enter your choice (1-6): ";

        // Validate numeric input to avoid infinite loop on bad input
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "-> Invalid input! Please enter a number between 1 and 6.\n";
            continue;
        }

        cin.ignore(1000, '\n'); // Clear buffer for getline

        switch (choice) {
            case 1: {
                // Add new task to the queue
                string taskName;
                cout << "Enter Lab Task Title/Description: ";
                getline(cin, taskName);

                if (taskName.empty()) {
                    cout << "-> Task title can't be empty. Nothing was added.\n";
                } else {
                    taskQueue.push_back(taskName);
                    cout << "-> Task added to queue successfully!\n";
                }
                break;
            }

            case 2: {
                // Process current task (FIFO: First-In, First-Out)
                if (taskQueue.empty()) {
                    cout << "-> No pending tasks in queue! All tasks completed.\n";
                } else {
                    string currentTask = taskQueue.front();
                    taskQueue.pop_front(); // Remove task from queue

                    // Push to stack for undo/back capability
                    completedStack.push(currentTask);

                    cout << "\n--------------------------------------------\n";
                    cout << "-> COMPLETED TASK: " << currentTask << endl;
                    if (!taskQueue.empty()) {
                        cout << "-> NEXT ACTIVE TASK: " << taskQueue.front() << endl;
                    } else {
                        cout << "-> Great job! You finished all lab tasks in queue.\n";
                    }
                    cout << "--------------------------------------------\n";
                }
                break;
            }

            case 3: {
                // Re-open previous task using Stack (LIFO: Last-In, First-Out)
                if (completedStack.empty()) {
                    cout << "-> No finished tasks to go back to.\n";
                } else {
                    string lastTask = completedStack.top();
                    completedStack.pop();

                    // Re-insert task into the FRONT of the queue
                    taskQueue.push_front(lastTask);
                    cout << "-> Re-opened previous task: " << lastTask << endl;
                }
                break;
            }

            case 4: {
                // Push new note or command to Vector
                string note;
                cout << "Enter Note or Command to save: ";
                getline(cin, note);

                if (note.empty()) {
                    cout << "-> Note can't be empty. Nothing was saved.\n";
                } else {
                    notesVector.push_back(note);
                    cout << "-> Note saved to archive successfully!\n";
                }
                break;
            }

            case 5: {
                // Linear Search algorithm to find matching keywords in notes
                if (notesVector.empty()) {
                    cout << "-> Notes archive is empty.\n";
                } else {
                    string keyword;
                    cout << "Enter keyword to search in notes: ";
                    getline(cin, keyword);

                    bool found = false;
                    for (size_t i = 0; i < notesVector.size(); i++) {
                        // String matching using std::string::find
                        if (notesVector[i].find(keyword) != string::npos) {
                            cout << "-> Match [" << i + 1 << "]: " << notesVector[i] << endl;
                            found = true;
                        }
                    }
                    if (!found) {
                        cout << "-> No notes found containing: '" << keyword << "'\n";
                    }
                }
                break;
            }

            case 6:
                cout << "Exiting CS50 Guide. Good luck with your labs!\n";
                break;

            default:
                cout << "Invalid choice! Please select from 1 to 6.\n";
        }
    }

    return 0;
}
