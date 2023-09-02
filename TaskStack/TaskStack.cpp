// TaskStack.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iostream>
#include <stack>
#include <string>

using namespace std;
class Task
{
public:
    Task(const string& date, const string& description) : date(date), description(description) {}

    string getDate() const
    {
        return date;
    }

    string getDescription() const
    {
        return description;
    }

private:
    string date;
    string description;
};

class TaskStack
{
public:
    void push(const Task& task) 
    {
        tasks.push(task);
    }

    void pop() 
    {
        if (!tasks.empty()) 
        {
            tasks.pop();
        }
        else 
        {
            cout << "Stack is empty." << endl;
        }
    }

    void listTasks() const 
    {
        cout << "\nTasks List:\n";
        int index = 1;
        stack<Task> tempStack = tasks;

        while (!tempStack.empty()) 
        {
            Task task = tempStack.top();
            cout << index << ". Data: " << task.getDate() << ", Description: " << task.getDescription() << endl;
            tempStack.pop();
            index++;
        }
    }

private:
    stack<Task> tasks;
};

int main()
{
    TaskStack taskStack;

    while (true) 
    {
        cout << "\nMenu:\n";
        cout << "1. Add Task\n";
        cout << "2. Do the last task\n";
        cout << "3. Exit\n";
        cout << "Make a choice: ";

        int choice;
        cin >> choice;

        if (choice == 1)
        {
            string date, description;
            cout << "Enter data of task: ";
            cin >> date;
            cout << "Enter description of task: ";
            cin.ignore();
            getline(cin, description);

            Task task(date, description);
            taskStack.push(task);
        }
        else if (choice == 2)
        {
            taskStack.pop();
        }
        else if (choice == 3) 
        {
            break;
        }
        else 
        {
            cout << "Wrong choice! Try again!" << endl;
        }

        taskStack.listTasks();
    }

    return 0;
}
