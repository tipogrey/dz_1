#include <iostream>
#include <string>
#include <algorithm>
#include <bitset>

using namespace std;

// Функция для выполнения поразрядного сложения двоичных чисел
string add(string num1, string num2)
{
    string result = "";
    int carry = 0;

    while (num1.length() < num2.length())
    {
        num1 = "0" + num1;
    }
    while (num2.length() < num1.length())
    {
        num2 = "0" + num2;
    }

    for (int i = num1.length() - 1; i >= 0; i--)
    {
        int digit1 = num1[i] - '0';
        int digit2 = num2[i] - '0';

        int sum = digit1 + digit2 + carry;
        carry = sum / 2;
        result = char(sum % 2 + '0') + result;
    }

    if (carry)
    {
        result = char(carry + '0') + result;
    }

    return result;
}

// Функция для выполнения поразрядного вычитания двоичных чисел
string subtract(string num1, string num2)
{
    string result = "";
    int borrow = 0;

    while (num1.length() < num2.length())
    {
        num1 = "0" + num1;
    }
    while (num2.length() < num1.length())
    {
        num2 = "0" + num2;
    }

    for (int i = num1.length() - 1; i >= 0; i--)
    {
        int digit1 = num1[i] - '0' - borrow;
        int digit2 = num2[i] - '0';

        if (digit1 < digit2)
        {
            digit1 += 2;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        result = char(digit1 - digit2 + '0') + result;
    }

    return result;
}

// Функция для выполнения поразрядного умножения двоичных чисел
string multiply(string num1, string num2)
{
    string result = "0";

    for (int i = num2.length() - 1; i >= 0; i--)
    {
        string temp = "";
        int carry = 0;

        for (int j = num1.length() - 1; j >= 0; j--)
        {
            int digit1 = num1[j] - '0';
            int digit2 = num2[i] - '0';

            int product = digit1 * digit2 + carry;
            carry = product / 2;
            temp = char(product % 2 + '0') + temp;
        }

        if (carry)
        {
            temp = char(carry + '0') + temp;
        }

        for (int k = num2.length() - 1; k > i; k--)
        {
            temp += "0";
        }

        result = add(result, temp);
    }

    return result;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    string num1 = "1011101"; 
    string num2 = "1001011"; 

    cout << "Сложение: " << add(num1, num2) << endl; 
    cout << "Вычитание: " << subtract(num1, num2) << endl; 
    cout << "Умножение: " << multiply(num1, num2) << endl;  

    return 0;
}