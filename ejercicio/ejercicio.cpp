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
        while ((c = fgetc(file)) != EOF) {
            script += c;
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

catch (const exception& e) {
    if (file != nullptr) {
        fclose(file);
    }
    cout << e.what() << endl;
}

void load_script() {
    char filename[2024];
    printf("Archivo: ");
    scanf("%s", filename);

    try {
        load_script(filename, true);
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }
}

int main() {
    load_script();


    return 0;
}







}