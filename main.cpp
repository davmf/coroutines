#include <iostream>
#include <memory>
#include <coroutine>

class coroutine_result {
public:
    struct promise_type;
};

struct coroutine_result::promise_type {

    auto get_return_object() {
        std::cout << promise_type::get_return_object() << std::endl;
        return coroutine_result{42};
    }
}


int main(int, char**){
    std::cout << "Hello, from coro1!\n";
}
