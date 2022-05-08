#include <iostream>
#include <string>
using namespace std;

int findDog(string email)
{
    for (int i = 0; i < email.length(); i++)
        if (email[i] == '@')
            return i;
    return -1;
}

bool CountDog(string email)
{
    int count = 0;
    for (int i = 0; i < email.length(); i++)
        if (email[i] == '@')
            count++;
    return count != 1 ? 0 : 1;
}

string findFirstPart(string email, int dog)
{
    string firstPart = "";
    for (int i = 0; i < dog; i++)
        firstPart += email[i];
    return firstPart;
}

string findSecondPart(string email, int dog)
{
    string secondPart = "";
    for (int i = dog + 1; i < email.length(); i++)
        secondPart += email[i];
    return secondPart;
}

bool FirstPartValidation(string firstPart)
{
    string dictionary = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789.-!#$%&'*+-/=?^_`{|}~";
    for (int i = 0; i < firstPart.length(); i++) {
        bool flag = false;
        for (int j = 0; j < dictionary.length(); j++) {
            if (firstPart[i] == dictionary[j]) {
                flag = true;
                break;
            }
        }
        if (!flag)
            return 0;
    }
    return 1;
}

bool SecondPartValidation(string secondPart)
{
    string dictionary = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789.-";
    for (int i = 0; i < secondPart.length(); i++) {
        bool flag = false;
        for (int j = 0; j < dictionary.length(); j++) {
            if (secondPart[i] == dictionary[j]) {
                flag = true;
                break;
            }
        }
        if (!flag)
            return 0;
    }
    return 1;
}

bool PointCheck(string email)
{
    if (email[0] == '.' || email[email.length() - 1] == '.')
        return 0;
    else {
        for (int i = 1; i < email.length() - 2; i++)
            if (email[i] == '.' && email[i + 1] == '.')
                return 0;
    }
    return 1;
}

bool FirstPartLength(string fPart)
{
    return (fPart.length() + 1) > 0 && (fPart.length() + 1) < 65 ? 1 : 0;
}

bool SecondPartLength(string sPart)
{
    return (sPart.length() + 1) > 0 && (sPart.length() + 1) < 64 ? 1 : 0;
}

void ValidationEmailAddress(bool dogCount, bool pointCheck, bool firstPart, bool secondPart,
                            bool fPartLen, bool sPartLen)
{
    if (dogCount && pointCheck && firstPart && secondPart && fPartLen && sPartLen)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main() {
    string emailAddress;
    cin >> emailAddress;
    int dogLocation = findDog(emailAddress);
    string firstPart = findFirstPart(emailAddress, dogLocation);
    string secondPart = findSecondPart(emailAddress,dogLocation);
    ValidationEmailAddress(CountDog(emailAddress), PointCheck(emailAddress),
                           FirstPartValidation(firstPart), SecondPartValidation(secondPart),
                           FirstPartLength(firstPart), SecondPartLength(secondPart));
    return 0;
}