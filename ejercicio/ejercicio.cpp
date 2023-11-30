#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct ColorConsole {

    static constexpr auto fg_read = "\033[38;5;196m";
    static constexpr auto fg_green = "\033[38;5;46m";
};

struct ConsoleBox {

    void new_text() { /* ... */ }
    void set_text(const string& text) { cout <<text << endl; }

};
