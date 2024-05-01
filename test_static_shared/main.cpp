#include <iostream>
#include <functional>

#include "log_facade/log_facade.h"
#include "includes/log_group.h"
#include "shrd_lib/shrd_lib.h"


class module {
public:
    module() {
        facade::register_log_provider(std::bind(&module::write, this, std::placeholders::_1));
    }

    void write(const std::string &str) {
        std::cout << str << std::endl;

    }
};



int main() {
    std::cout << "Hello, World!" << std::endl;

    module m;


    shrd_lib sl;

    llog::write("pvk debug> test log");

    return 0;
}
