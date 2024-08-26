#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;

    Task(std::string desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& task) {
        tasks.push_back(Task(task));
        std::cout << "Task added successfully!\n";
    }

    void viewTasks() const {
        if (tasks.empty()) {
            std::cout << "No tasks in the list.\n";
            return;
        }

        std::cout << "To-Do List:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << (tasks[i].completed ? "[Completed] " : "[Pending] ") << tasks[i].description << "\n";
        }
    }

    void markTaskCompleted(size_t taskNumber) {
        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            tasks[taskNumber - 1].completed = true;
            std::cout << "Task marked as completed.\n";
        } else {
            std::cout << "Invalid task number.\n";
        }
    }

    void removeTask(size_t taskNumber) {
        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            tasks.erase(tasks.begin() + taskNumber - 1);
            std::cout << "Task removed successfully.\n";
        } else {
            std::cout << "Invalid task number.\n";
        }
    }
};

int main() {
    ToDoList todoList;
    int choice;
    do {
        std::cout << "\nTo-Do List Manager\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        std::cin.ignore(); // Ignore the newline character left in the input buffer

        switch (choice) {
            case 1: {
                std::string task;
                std::cout << "Enter the task description: ";
                std::getline(std::cin, task);
                todoList.addTask(task);
                break;
            }
            case 2:
                todoList.viewTasks();
                break;
            case 3: {
                size_t taskNumber;
                std::cout << "Enter the task number to mark as completed: ";
                std::cin >> taskNumber;
                todoList.markTaskCompleted(taskNumber);
                break;
            }
            case 4: {
                size_t taskNumber;
                std::cout << "Enter the task number to remove: ";
                std::cin >> taskNumber;
                todoList.removeTask(taskNumber);
                break;
            }
            case 5:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}