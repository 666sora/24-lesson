#include <iostream>
#include <string>
#include <ctime>


void begin_task (std::time_t &task_time, std::string &task_name, std::string& str_status) {
    if (task_name != "") {
        str_status += task_name;
        std::time_t temp_time = std::time(nullptr);
        int temp_diff = difftime(temp_time, task_time);
        str_status += " time: " + std::to_string(temp_diff / 3600) + ':' + std::to_string(temp_diff % 3600 / 60) + ':' + std::to_string(temp_diff % 3600 % 60) + '\n';
    }
    std::cout << "Input name of task: ";
    std::cin >> task_name;
    task_time = std::time(nullptr);
}

void end_task (std::time_t &task_time, std::string &task_name, std::string& str_status) {
    if (task_name == "") return;
    str_status += task_name;
    std::time_t temp_time = std::time(nullptr);
    int temp_diff = difftime(temp_time, task_time);
    str_status += " time: " + std::to_string(temp_diff / 3600) + ':' + std::to_string(temp_diff % 3600 / 60) + ':' + std::to_string(temp_diff % 3600 % 60) + '\n';
    task_name = "";
    task_time = 0;
}

void check_status (std::time_t &task_time, std::string &task_name, std::string& str_status) {
    std::cout << str_status;
    if (task_name == "") return;
    std::cout << "Current task: ";
    std::time_t temp_time = std::time(nullptr);
    int temp_diff = difftime(temp_time, task_time);
    std::cout << task_name << " time: " << temp_diff / 3600 << ":" << temp_diff % 3600 / 60 << ":" << temp_diff % 3600 % 60 << std::endl;
}

int main() {
    std::string str_status = "";
    std::string task_name = "";
    
    std::time_t task_time = 0;
    
    std::string answer = "";

    while (answer != "exit") {
        std::cout << "Input command: ";
        std::cin >> answer;
        if (answer == "exit") continue;
        if (answer == "begin") begin_task(task_time, task_name, str_status);
        if (answer == "end") end_task(task_time, task_name, str_status);
        if (answer == "status") check_status(task_time, task_name, str_status);
    }
}

/*
Используя функцию получения текущего времени std::time, 
реализуйте простейший менеджер учёта времени.
Пользователь взаимодействует с программой с помощью команд:
Команда begin начинает отслеживание новой задачи. После ввода 
этой команды пользователь должен ввести название задачи, над которой 
он планирует сейчас работать. Если уже была начата какая-то другая задача, 
предыдущая должна быть автоматически завершена и начата новая.
Команда end заканчивает отслеживание текущей задачи. Если текущей начатой 
задачи нет, то команда ничего не делает.
Команда status выводит на экран информацию о всех законченных задачах и 
времени, которое было на них потрачено. Также выводится название текущей 
выполняемой задачи, если таковая имеется.
Команда exit выходит из программы.
*/