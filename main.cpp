#include <iostream>
#include <string>

#include <unistd.h>

#include <cpprest/http_client.h>
#include <cpprest/filestream.h>

using namespace web;
using namespace web::http;
using namespace web::http::client;

std::string PAN {"http://192.168.94.58/axis-cgi/com/ptz.cgi?pan="};

int main() {

    for (int i = -90; i < 90; i++) {

        std::cout << PAN + std::to_string(i) << std::endl;

        http_client client( PAN + std::to_string(i));
        client.request(methods::GET).then([](http_response response) {
        std::cout << response.extract_string().get() << std::endl;
        }).wait();

        sleep(1);
    }

    return 0;
}