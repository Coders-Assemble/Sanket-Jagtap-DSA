#include <iostream>
#include <string>
using namespace std;

bool compareStrings(string a, string b)
{
    if (a.length() != b.length())
    {
        return false;
    }

    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] != b[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{

    string str = "HelloWorld";

    // cin>>str;
    // getline(cin, str);

    cout << str << endl;

    // cout<<"Length: "<<str.length()<<endl;
    // cout<<"isEmpty: "<<str.empty()<<endl;
    // str.push_back('Z');
    // cout<<str<<endl;
    // str.pop_back();
    // cout<<str<<endl;
    // cout<<str.substr(1, 6)<<endl;

    string a = "Hello";
    string b = "Hellow";

    // if (compareStrings(a, b))
    // {
    //     cout << "String a and b are exactly same" << endl;
    // }
    // else
    // {
    //     cout << "String a and b are not same" << endl;
    // }

    // if (a.compare(b) == 0)
    // {
    //     cout << "String a and b are exactly same" << endl;
    // }
    // else
    // {
    //     cout << "String a and b are not same" << endl;
    // }

    // string x = "cbcd";
    // string y = "bcda";

    // cout<<x.compare(y)<<endl;

    string sentence = "String a and b are not same";
    string target = "we";

    // cout<<sentence.find(target)<<endl;
    // if(sentence.find(target) == string::npos){
    //     cout<<"Not Found"<<endl;
    // }

    string myStr = "This is my new message";
    string word = "old";

    // myStr.replace(11, 3, word);
    // myStr.replace(11, 3, "second");
    // cout << myStr << endl;

    string newStr = "ABCDEFGHIJKLMNOPQRSTUV";
    newStr.erase(5, 8);
    cout << newStr << endl;

    return 0;
}