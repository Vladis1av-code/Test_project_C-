#include<string>
#include<queue>
#include <iostream>
#include <ctime>
using namespace std;

struct PrintJob {
    string user; 
    int priority;
    time_t timestamp; // время на распичатывание
};

// Равенство приоритетов
bool comparePrintJobs(const PrintJob& a, const PrintJob& b) 
{
    return a.priority > b.priority;
}

// Очередь распичатывание
class PrintQueue {

private:
    priority_queue<PrintJob, vector<PrintJob>, comparePrintJobs> queue; // очередь
    queue<PrintJob> history; // история сохранение

public:
    void addJob(const PrintJob& job) {
        queue.push(job);
    }

    void printNextJob() {
        setlocale(LC_ALL, "ru");
        if (!queue.empty()) {
            PrintJob job = queue.top();
            queue.pop();

            cout << "________________________________________________________" << endl;
            cout << "Друкується файл: " << job.user << ", пріоритет: " << job.priority << endl;
            this_thread::sleep_for(chrono::seconds(2)); // задержка для распичатывание
            cout << "________________________________________________________" << endl;
            // добавление в историю распичатывание
            history.push(job);
        }
    }

    void print_History() {
        setlocale(LC_ALL, "ru");
        cout << "________________________________________________________" << endl;
        cout << "История распичатывание:" << endl;
        cout << "________________________________________________________" << endl;
        while (!history.empty()) {
            PrintJob job = history.front();
            history.pop();
            cout << "________________________________________________________" << endl;
            cout << "Користувач: " << job.user << ", час надсилання: " << ctime(&job.timestamp) << endl;
            cout << "________________________________________________________" << endl;
        }
    }
};

int main() {
    PrintQueue queue;
    setlocale(LC_ALL, "ru");
    cout << "________________________________________________________" << endl;
    queue.addJob({ "users", 1 });
    queue.addJob({ "users_w", 3 });
    queue.addJob({ "users_q", 2 });
    cout << "________________________________________________________" << endl;
    // Распичатывание
    while (!queue.empty()) {
        queue.printNextJob();
    }

    queue.print_History();

    return 0;
}
//history - це змінна, яка декларується типу queue<PrintJob>.
//PrintJob - це структура, яка використовується для представлення завдання на друк.

