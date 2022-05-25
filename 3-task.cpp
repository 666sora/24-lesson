#include <iostream>
#include <ctime>
#include <iomanip>

int main() {
    std::tm timer = {};
    std::cout << "Set time on timer (mm:ss): ";
    std::cin >> std::get_time(&timer, "%M:%S");

    std::time_t timer_off = std::time(nullptr) + (60 * timer.tm_min) + timer.tm_sec;
    std::time_t time_local = std::time(nullptr);

    double diff_time = std::difftime(timer_off, time_local);

    while (diff_time > 0) {
        if (std::time(nullptr) - time_local > 0) {
            time_local = std::time(nullptr);
            diff_time = std::difftime(timer_off, time_local);
            if (diff_time < 0) continue;
            std::time_t temp_time = diff_time;
            std::tm* temp_time_ptr = localtime(&temp_time);
            std::cout << std::put_time(temp_time_ptr, "%M:%S") << std::endl;
        }
    }

    std::cout << "DING! DING! DING!";
}

/*
Реализуйте работу точного таймера с визуальной отдачей.
В начале программы пользователь вводит количество минут 
и секунд, которые требуется засечь на таймере, и нажимает «Ввод».
После этого начинается обратный отсчёт времени, 
о чём незамедлительно и последовательно сообщается пользователю. 
Формат вывода такой же, как и при вводе интервала: минуты и секунды.
Как только отсчёт на таймере иссяк, программа сообщает об этом 
с помощью вывода в консоль специального сообщения. 
Сообщение вместо аудиосигнала может выглядеть так: DING! DING! DING!
*/