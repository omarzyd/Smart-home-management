#include <iostream>
#include <map>
#include <string>

using namespace std;




int main()
{

map<string,string> english ={
        {"prompt", "Enter the number: "},
        {"even", "The number is even: "},
        {"odd", "The number is odd: "}
};

map<string,string> arabic = {
        {"prompt", "أدخل الرقم: "},
        {"even", "الرقم زوجي: "},
        {"odd", "الرقم فردي: "}
};


// Choose language
 map<string, string>* currentLanguage;
 string languageChoice;
 cout << "Choose language (English/Arabic): ";
    cin >> languageChoice;

    if (languageChoice == "Arabic") {
        currentLanguage = &arabic;
    } else {
        // Default to English if Arabic is not selected
        currentLanguage = &english;
    }

int num;
cout << (*currentLanguage)["prompt"];
cin >> num;

while (true) {
        if (num % 2 == 0) 
        {
            cout << (*currentLanguage)["even"] << num << endl;
            break;
        } 
        else 
        {
            cout << (*currentLanguage)["odd"] << num << endl;
            break;
        }
}
}


// struct LanguageStrings {
//     map<string, string> strings;

//     void addString( string& key, string& value) {
//         strings[key] = value;
//     }

//     string getString(const string& key) {
//         return strings[key];
//     }
// };

// int main() {

//     LanguageStrings english, arabic;
//     english.addString("greeting", "Welcome!");
//     arabic.addString("greeting", "!مرحبا");

//     LanguageStrings* currentLanguage = &english;

//     string input;
//     cout << currentLanguage->getString("greeting") << endl;

//     cout << "Press 'a' to switch to Arabic, 'e' to switch to English, 'q' to quit:" << endl;
//     while (true) {
//         cin >> input;
//         if (input == "q") {
//             break;
//         } else if (input == "a") {
//             currentLanguage = &arabic;
//         } else if (input == "e") {
//             currentLanguage = &english;
//         }

//         cout << currentLanguage->getString("greeting") << endl;
//     }

//     return 0;
// }
