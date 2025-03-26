#include <iostream>
#include <string>
// Use ICU or a custom converter for robust Unicode handling; for simplicity, we'll use <codecvt> here (deprecated but works for C++17)
#include <codecvt>
#include <locale>

int main() {
    // UTF-32 string literal (12 code points: 5 Japanese + 7 Thai)
    const char32_t name[] = U"こんにちは สวัสดีครับ"; 

    // Calculate the correct length (number of char32_t values)
    size_t len = 0;
    while (name[len] != 0) ++len; // Count until null terminator (12 chars)

    // Convert UTF-32 (char32_t) to UTF-16 (char16_t)
    std::u16string greeting;
    for (size_t i = 0; i < len; ++i) {
        char32_t c = name[i];
        if (c <= 0xFFFF) { // Basic Multilingual Plane (BMP)
            greeting.push_back(static_cast<char16_t>(c));
        } else { // Non-BMP characters (e.g., emojis) need surrogate pairs
            c -= 0x10000;
            greeting.push_back(static_cast<char16_t>(0xD800 + (c >> 10)));
            greeting.push_back(static_cast<char16_t>(0xDC00 + (c & 0x3FF)));
        }
    }

    // Convert UTF-16 to UTF-8 using wstring_convert (deprecated, but works for C++17)
    std::wstring_convert<std::codecvt_utf8<char16_t>, char16_t> converter;
    std::string utf8_greeting = converter.to_bytes(greeting);

    // Ensure locale is set for UTF-8 output
    setlocale(LC_ALL, "en_US.UTF-8");

    // Use std::cout for UTF-8 output
    std::cout << utf8_greeting << std::endl;
    return 0;
}