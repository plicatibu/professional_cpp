// strings - page 91
//         - page 139

#include <format>
#include <iostream>
#include <cstring>

using namespace std;

int main() {
    std::string s = {"Hello, MAO"};
    cout << format("My text: {}\n", s);
    cout << format("The 7th letter: {}\n", s[7]);



    char text1[] { "abcdef" };
    size_t s1 { sizeof(text1) };
    size_t s2 { strlen(text1) };

    cout << "text1: " << text1 << endl;
    cout << "sizeof(" << text1 << ") = " << s1 << endl;
    cout << "strlen(" << text1 << ") = " << s2 << endl;

    const char* text2 { "abcdef" };
    size_t s3 { sizeof(text2) };
    size_t s4 { strlen(text2) };

    cout << "text2: " << text2 << endl;
    cout << "sizeof(" << text2 << ") = " << s3 << endl;
    cout << "strlen(" << text2 << ") = " << s4 << endl;

    char arr[] = { "Hello" };
    size_t s5 = strlen(arr);
    for (size_t i = 0; i < s5; i++) {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }

    const char* str { "Hello \"World\"!" };
    cout << str << endl;

    const char* str2 { R"(Hello "World"!)" }; // Raw string literal - page 141
    cout << str2 << endl;

    const char *str3 { "Line1\nLine2" }; // multi-line string literal
    cout << str3 << endl;

    const char *str4  { R"(Line1
Line2)" }; // multi-line raw string literal
    cout << str4 << endl;

    const char* str5 { R"-(Embedded )" characters)-" };
    cout << str5 << endl;
    const char *str6 { R"(-this is (you know) your fault!-)" };
    cout << str6 << endl;
    const char *str7 { R"-(this is (you know) your fault!)-" }; // -( and -) are the delimiters
    cout << str7 << endl;
    const char *str8 { R"d-char-sequence(this is (you know) your fault!)d-char-sequence" }; // d-char-sequence( and )d-char-sequence are the delimiters
    cout << str8 << endl;

    std::string s6 { "28" };
    std::string s7 { "07" };
    std::string s8;
    s8 = s6 + s7;
    cout << s8 << endl;

    s8 = s7 + "/" + s6;
    cout << s8 << endl;

    auto result { s6 <=> s7 };
    if (is_lt(result)) { cout << s6 << " less than " << s7 << endl; }
    if (is_eq(result)) { cout << s6 << " equal to " << s7 << endl; }
    if (is_gt(result)) { cout << s6 << " greater than " << s7 << endl; }

    size_t pos = 1;
    size_t len = 7;
    cout << "s8 = " << s8 << ",substring s8 (pos 1, len = 7): " << s8.substr(pos, len) << endl;  // len is longer that the string s8.

    cout << "std::string::npos = " << std::string::npos << endl;

    auto s9 { "Hello World" };  //  s9 type: const char*
    auto s10 { "Hello World"s };  // s10 type: std::string
    cout << s9 << endl;
    //cout << s9.substr(0, 4);  // as s9 type is const char*, it does not have the std::string methods
    cout << s10 << endl;
    cout << s10.substr(0, 4);


    return 0;
}
