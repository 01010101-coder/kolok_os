#include <iostream>
#include <vector>
#include <stdexcept>
#include <cpprest/http_listener.h>
#include <cpprest/json.h>
#include "factorial.h"
#include "reverse_list.h"

// Функция для обработки запросов
void handle_factorial_request(web::http::http_request request) {
    try {
        auto query = request.query_parameters();
        if (query.find("n") != query.end()) {
            int n = std::stoi(query["n"]);
            if (n < 0) {
                request.reply(web::http::status_codes::BadRequest, "Parameter n must be a non-negative integer");
                return;
            }
            // Получаем факториалы
            web::json::value response = get_factorials(n);
            request.reply(web::http::status_codes::OK, response);
        } else {
            request.reply(web::http::status_codes::BadRequest, "Missing parameter 'n'");
        }
    }
    catch (const std::exception& e) {
        request.reply(web::http::status_codes::InternalError, "Error: " + std::string(e.what()));
    }
}

// Основная функция для получения факториалов и запуска HTTP-сервера
int main() {
    try {
        // Ввод числа n для вычисления факториалов
        int n;
        std::cout << "Enter a natural number n: ";
        std::cin >> n;

        if (n < 0) {
            std::cerr << "Error: n must be a non-negative integer." << std::endl;
            return 1;
        }

        // Вывод факториалов в консоль
        std::vector<long long> factorials = get_factorials(n);
        for (const auto& fact : factorials) {
            std::cout << fact << " ";
        }
        std::cout << std::endl;

        // Настройка и запуск HTTP-сервера
        web::http::experimental::listener::http_listener listener(U("http://localhost:8080"));
        listener.support(web::http::methods::GET, handle_factorial_request);

        listener
                .open()
                .then([]() { std::wcout << L"Server is running at http://localhost:8080\n"; })
                .wait();

        // Ожидание завершения сервера
        std::string line;
        std::getline(std::cin, line);
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
