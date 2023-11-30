#include <iostream>
#include <fstream>
#include <string>
#include <lmaccess.h>

using namespace std;

struct ColorConsole {

    static constexpr auto fg_read = "\033[38;5;196m";
    static constexpr auto fg_green = "\033[38;5;46m";
};

struct ConsoleBox {

    void new_text() { /* ... */ }
    void set_text(const string& text) { cout <<text << endl; }

};

void load_script(const char* filename, bool show_script = false) {

    string script;

    FILE* file = nullptr;

    try {
        file = fopen(filename, "r");
        if (file == nullptr) {
            throw runtime_error("Error al abrir el archivo");
        }

        int c;
        char buffer[1024];
        while ((c = fgetc(file)) != EOF) {
            script += c;
        }

        int buf;
        buf[c] = 0;
        script.append(buf);

    }

    fclose(file);
    file = nullptr;

    if (show_script) {
        cout << script << endl;
        cout << ColorConsole::fg_green << ColorConsole::fg_read;
    }

    ConsoleBox consoleBox;
    consoleBox.new_text();
    consoleBox.set_text(script);
}
