// QueuePriority.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

class QueuePriority 
{
public:
    QueuePriority(int max_size) : max_size_(max_size), size_(0) 
    {
        items_ = new string[max_size];
        priorities_ = new int[max_size];
    }

    ~QueuePriority()
    {
        delete[] items_;
        delete[] priorities_;
    }

    void enqueue(const string& item, int priority) 
    {
        if (size_ < max_size_)
        {
            items_[size_] = item;
            priorities_[size_] = priority;
            size_++;
        }
        else 
        {
            cout << "Queue is full. Cannot enqueue." << endl;
        }
    }

    string dequeue()
    {
        if (is_empty()) 
        {
            return "";
        }

        // Ищем элемент с наивысшим приоритетом
        int highest_priority_index = 0;
        for (int i = 1; i < size_; ++i)
        {
            if (priorities_[i] < priorities_[highest_priority_index])
            {
                highest_priority_index = i;
            }
        }

        // Извлекаем элемент и его приоритет
        string item = items_[highest_priority_index];

        // Удаляем элемент и его приоритет из массивов
        for (int i = highest_priority_index; i < size_ - 1; ++i) 
        {
            items_[i] = items_[i + 1];
            priorities_[i] = priorities_[i + 1];
        }
        size_--;

        return item;
    }

    bool is_empty() const
    {
        return size_ == 0;
    }

    int size() const 
    {
        return size_;
    }

private:
    int max_size_;
    int size_;
    string* items_;
    int* priorities_;
};

int main() {
    // Создаем объект очереди с приоритетом (максимальный размер 100)
    QueuePriority queue(100);

    // Добавляем элементы с приоритетом
    queue.enqueue("Task 1", 3);
    queue.enqueue("Task 2", 1);
    queue.enqueue("Task 3", 2);

    // Извлекаем элементы из очереди в порядке убывания приоритета
    cout << queue.dequeue() << endl; // Вывод: "Task 2"
    cout << queue.dequeue() << endl; // Вывод: "Task 3"
    cout << queue.dequeue() << endl; // Вывод: "Task 1"

    return 0;
}
