#include <iostream>
#include <memory>
#include <coroutine>

class coroutine_result {
public:
    struct promise_type;
};

struct coroutine_result::promise_type {

    auto get_return_object() {
        std::cout << "promise_type::get_return_object()" << std::endl;
        return coroutine_result{42};
    }

    auto initial_suspend() {
        std::cout << "promise_type::initial_suspend()" << std::endl;
        return std::suspend_never{};
    }

    auto final_suspend() {
        std::cout << "promise_type::final_suspend()" << std::endl;

    }

    auto return_void() {
        std::cout << "promise_type::return_void()" << std::endl;

    }

    auto unhandled_exception() {
        std::cout << "promise_type::unhandled_exception()" << std::endl;
        std::terminate();
    }
}


int main(int, char**){
    std::cout << "Hello, from coro1!\n";
    return 0;
}
