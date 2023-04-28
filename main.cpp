#include <iostream>
#include <cpr/cpr.h>

namespace methods {

}

int main() {
    std::string input;
    cpr::Response r;
    std::string key = "city", value = "Warsaw";

    while (input != "exit") {
        std::cout << "Input method(put, delete, get, post, patch): ";
        std::getline(std::cin, input);
        if (input == "post"){
            r = cpr::Post(cpr::Url("https://httpbin.org/post"),
                          cpr::Payload({
                              {key, value}
                          }));
            std::cout << r.text << std::endl;
        } else if (input == "put") {
            r = cpr::Put(cpr::Url("https://httpbin.org/put"),
                         cpr::Payload({
                             {key, value}
                         }));
            std::cout << r.text << std::endl;
        } else if (input == "patch"){
            r = cpr::Patch(cpr::Url("https://httpbin.org/patch"),
                           cpr::Payload({
                               {key, value}
                           }));
            std::cout << r.text << std::endl;
        } else if (input == "delete"){
            r = cpr::Delete(cpr::Url("https://httpbin.org/delete"),
                            cpr::Payload({
                                {key, value}
                            }));
            std::cout << r.text << std::endl;
        } else if (input == "get"){
            r = cpr::Get(cpr::Url("https://httpbin.org/get"));
            std::cout << r.text << std::endl;
        } else if (input != "exit") {
            std::cout << "Bad command! Try again." << std::endl;
        }

    }

}
