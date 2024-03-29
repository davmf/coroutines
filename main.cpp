#include <iostream>
#include <coroutine>

class coroutine_result {

public:
    struct promise_type {

        auto get_return_object() {
            std::cout << "promise_type::get_return_object()" << std::endl;
            return coroutine_result{};
        }

        auto initial_suspend() {
            std::cout << "promise_type::initial_suspend()" << std::endl;
            return std::suspend_never{};
        }

        auto final_suspend() noexcept {
            std::cout << "promise_type::final_suspend()" << std::endl;
            return std::suspend_never{};
        }

        auto return_void() {
            std::cout << "promise_type::return_void()" << std::endl;
        }

        auto unhandled_exception() {
            std::cout << "promise_type::unhandled_exception()" << std::endl;
            std::terminate();
        }
    };
};


coroutine_result my_coroutine() {
    std::cout << "During my_coroutine" << std::endl;
    co_return;
}


int main(int, char**){
    std::cout << "Before my_coroutine\n";
    auto result = my_coroutine();
    std::cout << "After my_coroutine\n";
    return 0;
}
