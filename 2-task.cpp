#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <ctime>

int main() {
    std::map<std::string, std::tm> bdays;
    std::string answer = "";

    while (answer != "end") {
        std::cout << "Input name and surname: ";
        getline(std::cin, answer);
        if (answer == "end") continue;
        std::string temp_names = answer;
        std::cout << "Input date(yyyy mm dd): ";
        getline(std::cin, answer);
        std::stringstream date_stream(answer);
        int temp_tm;
        date_stream >> temp_tm;
        bdays[temp_names].tm_year = temp_tm - 1900;
        date_stream >> temp_tm;
        bdays[temp_names].tm_mon = temp_tm - 1;
        date_stream >> bdays[temp_names].tm_mday;
    }
    std::time_t time_null = std::time(nullptr);
    std::tm* tm_ptr_localtime = std::localtime(&time_null);
    int today_yday = tm_ptr_localtime->tm_yday;
    int min_yday = 366;
    tm_ptr_localtime = NULL;
    std::vector<std::string> key_name;
    for (auto bd: bdays) {
        std::tm* temp_ptr = localtime(&time_null);
        temp_ptr->tm_year = bd.second.tm_year;
        temp_ptr->tm_mon = bd.second.tm_mon;
        temp_ptr->tm_mday = bd.second.tm_mday;
        std::mktime(temp_ptr);
        if (temp_ptr->tm_yday - today_yday >= 0 
                && temp_ptr->tm_yday - today_yday <= min_yday) {
            min_yday = temp_ptr->tm_yday - today_yday;
            key_name.push_back(bd.first);
        }
    }
    for (auto k: key_name) {
        std::cout << "Closest birthday: " << k << " "  << bdays[k].tm_mon + 1 << " " << bdays[k].tm_mday << std::endl;
    }
}

/*
Реализуйте простую программу по вычислению ближайшего дня рождения.
В начале программы пользователь последовательно вводит данные о 
днях рождения своих друзей: вводит имя друга и саму дату рождения
полностью, включая месяц и год, в формате год/месяц/день. Сигналом
окончания ввода дней рождения является “end” введённое в качестве имени.
После этого программа вычисляет ближайший день рождения по 
отношению к текущему времени и выводит его на экран вместе 
с именем в удобном, локальном формате - месяц/день. Если 
день рождения уже был в этом году, данные о пользователе 
пропускаются. Если у кого-то из друзей день рождения сегодня, 
то в консоль выводится специальное сообщение об этом. Учтите, 
что таких сообщений может быть несколько, ведь сразу 
несколько людей могут иметь дни рождения в один день.
*/