#include <iostream>
#include <string>
#include <locale>

using namespace std;

int main() {
// Set C locale for wctomb (needed for UTF-8 conversion)
setlocale(LC_ALL, "en_US.UTF-8");

// Set C++ locale for streams
locale::global(locale("en_US.UTF-8"));
wcout.imbue(locale("en_US.UTF-8")); // Imbue wcout for wide output

    string s = "Hello";
    wstring w = L"สวัสดี"; // Wide string for Thai text
    wchar_t smile = 0x1F603; 

    // Convert `wstring` to UTF-8 manually
    string utf8_string;
    for (wchar_t wc : w) {
        char buffer[4] = {0};
        int len = wctomb(buffer, wc); // Convert each wchar_t to multibyte (UTF-8)
        utf8_string.append(buffer, len);
    }

    cout << s << endl;
    cout << utf8_string << "!" << endl; // Print Thai text correctly in UTF-8
    wcout << w << "  " << smile << endl;

    return 0;
}
