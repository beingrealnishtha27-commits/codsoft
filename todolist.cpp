#include <iostream>
#include <string>
using namespace std;

int main() {
    string tasks[100];      // array to store up to 100 tasks
    bool completed[100];    // array to store task completion status
    int taskCount = 0;
    int choice;

    while (true) {
        cout << "\n=== TO-DO LIST MENU ===\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {  // Add Task
            if (taskCount < 100) {
                cout << "Enter task: ";
                cin.ignore();
                getline(cin, tasks[taskCount]);
                completed[taskCount] = false;
                taskCount++;
                cout << "Task added successfully!\n";
            } else {
                cout << "Task list is full!\n";
            }
        }

        else if (choice == 2) {  // View Tasks
            if (taskCount == 0) {
                cout << "No tasks available.\n";
            } else {
                cout << "\n--- To-Do List ---\n";
                for (int i = 0; i < taskCount; i++) {
                    cout << i + 1 << ". " << tasks[i]
                         << " [" << (completed[i] ? "Completed" : "Pending") << "]\n";
                }
            }
        }

        else if (choice == 3) {  // Mark as Completed
            if (taskCount == 0) {
                cout << "No tasks to mark.\n";
            } else {
                int num;
                cout << "Enter task number to mark as completed: ";
                cin >> num;
                if (num >= 1 && num <= taskCount) {
                    completed[num - 1] = true;
                    cout << "Task marked as completed!\n";
                } else {
                    cout << "Invalid task number!\n";
                }
            }
        }

        else if (choice == 4) {  // Remove Task
            if (taskCount == 0) {
                cout << "No tasks to remove.\n";
            } else {
                int num;
                cout << "Enter task number to remove: ";
                cin >> num;
                if (num >= 1 && num <= taskCount) {
                    for (int i = num - 1; i < taskCount - 1; i++) {
                        tasks[i] = tasks[i + 1];
                        completed[i] = completed[i + 1];
                    }
                    taskCount--;
                    cout << "Task removed successfully!\n";
                } else {
                    cout << "Invalid task number!\n";
                }
            }
        }

        else if (choice == 5) {  // Exit
            cout << "Exiting... Goodbye!\n";
            break;
        }

        else {
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}