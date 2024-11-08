#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ToDoList {
private:
    vector<string> tasks;

public:
    // Function to add a task
    void addTask(const string &task) {
        tasks.push_back(task);
        cout << "Task added: " << task << endl;
    }

    // Function to view all tasks
    void viewTasks() const {
        if (tasks.empty()) {
            cout << "No tasks available." << endl;
            return;
        }

        cout << "To-Do List:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i] << endl;
        }
    }

    // Function to delete a task
    void deleteTask(int index) {
        if (index < 1 || index > tasks.size()) {
            cout << "Invalid task number." << endl;
            return;
        }
        cout << "Task deleted: " << tasks[index - 1] << endl;
        tasks.erase(tasks.begin() + index - 1);
    }
};

int main() {
    ToDoList todoList;
    int choice;
    string task;

    do {
        cout << "\nTo-Do List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Delete Task" << endl;
        cout << "4. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore(); // To ignore the newline character after the integer input

        switch (choice) {
            case 1:
                cout << "Enter the task: ";
                getline(cin, task);
                todoList.addTask(task);
                break;
            case 2:
                todoList.viewTasks();
                break;
            case 3:
                int taskNumber;
                cout << "Enter task number to delete: ";
                cin >> taskNumber;
                todoList.deleteTask(taskNumber);
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
