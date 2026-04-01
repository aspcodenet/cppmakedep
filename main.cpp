#include "crow.h"

int main() {
    crow::SimpleApp app;

    // 1. A simple HTML route
    CROW_ROUTE(app, "/")([](){
        return "<h1>Crow is flying!</h1><p>Check /json/yourname</p>";
    });

    // 2. A JSON API route with a parameter
    CROW_ROUTE(app, "/json/<string>")([](std::string name){
        crow::json::wvalue x({{"message", "Hello, " + name}, {"status", "success"}});
        return x;
    });

    app.port(8080).multithreaded().run();
}