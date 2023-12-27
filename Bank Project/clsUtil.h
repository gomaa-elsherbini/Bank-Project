#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "clsDate.h"
#include "clsString.h"
using namespace std;



class clsUtil
{
private:
    static enum enAnswer { No = 0, Yes };
    static enAnswer readAnswer()
    {
        short int num;
        cin >> num;

        return (enAnswer)num;
    }
    static string columnSeparator(int i) {
        if (i <= 9)
            return "  |";
        else
            return " |";
    }
    static string putCharS(int num)
    {
        if (num > 1)
            return "s";
        else
            return "";
    }
    static int getSumAllDivisorsFrom1ToN(int num)
    {
        int sum = 0;
        for (int i = 1; i <= round(num / 2); i++)
        {
            if (num % i == 0)
                sum += i;
        }
        return sum;
    }
    static int readElementToCheck()
    {
        int element = 0;
        cout << "enter the element to check in the array?\n";
        cin >> element;
        return element;
    }
    static int readNumber()
    {
        int num;

        cout << "pleases enter a number? ";
        cin >> num;

        return num;
    }
    static void saveNumberInArray(int arr[100], int& length, int num)
    {
        length++;
        arr[length - 1] = num;
    }
    static void tableHeader()
    {
        cout << "\n\n\t\t\tMultiplication table from 1 to 10\t\n\n";
        cout << "\t";
        for (int i = 1; i <= 10; i++)
        {
            cout << i << "\t";
        }
        cout << "\n-----------------------------------------------------------------------------------\n";
    }
    static string NameOfNumber(int digit)
    {
        switch (digit)
        {
        case 0:
            return "";
        case 1:
            return "One";
        case 2:
            return "Two";
        case 3:
            return "Three";
        case 4:
            return "Four";
        case 5:
            return "Five";
        case 6:
            return "Six";
        case 7:
            return "Seven";
        case 8:
            return "Eight";
        case 9:
            return "Nine";
        case 10:
            return "Ten";
        case 11:
            return "Eleven";
        case 12:
            return "Twelve";
        case 13:
            return "Thirteen";
        case 14:
            return "Fourteen";
        case 15:
            return "Fifteen";
        case 16:
            return "Sixteen";
        case 17:
            return "Seventeen";
        case 18:
            return "Eighteen";
        case 19:
            return "Nineteen";
        case 20:
            return "Twinty";
        case 30:
            return "Therty";
        case 40:
            return "Fourty";
        case 50:
            return "Fifty";
        case 60:
            return "Sixty";
        case 70:
            return "Seventy";
        case 80:
            return "Eighty";
        case 90:
            return "Ninety";
        default:
            break;
        }
    }

public:
    static enum enChar { SmallLetter = 1, CapitalLetter, SpecialChar, DigitInOrder, MixChar };
    static void printMultiplicationTableFrom1To10()
    {
        tableHeader();

        for (int i = 1; i <= 10; i++)
        {
            cout << " " << i << columnSeparator(i) << "\t";

            for (int x = 1; x <= 10; x++)
                cout << i * x << "\t";
            
            cout << endl;
        }

    }

    static int readPositiveNumber(string msg)
    {
        int num;
        do
        {
            cout << msg << endl;
            cin >> num;
        } while (num <= 0);
        return num;
    }

    static bool isPrimeNumber(int num)
    {
        if (num == 1 || num == 2)
            return 1;
        for (int i = 2; i <= round(num / 2); i++)
        {
            if ((num % i) == 0)
                return 0;
        }
        return 1;
    }

    static vector<int> getPrimeNumbersFrom1ToN(int number)
    {
        vector<int>vPrimeNumbers;
        cout << "outPut\n";
        for (short i = 1; i <= number; i++)
        {
            if (isPrimeNumber(i) == 1)
                vPrimeNumbers.push_back(i);
        }
        return vPrimeNumbers;
    }

    static bool checkPerfectNumber(int num)
    {
        if (num == getSumAllDivisorsFrom1ToN(num))
            return 1;
        else
            return 0;
    }

    static vector <int>perfectNumbersFrom1ToN(int num)
    {
        vector<int>vPerfectNumbers;
        for (int i = 1; i <= num; i++)
        {
            if (checkPerfectNumber(i) == 1)
                vPerfectNumbers.push_back(i);
        }
        return vPerfectNumbers;
    }

    static void printReversedDigitsFromNumber(int num)
    {
        int reminder = 0;

        while (num > 0)
        {
            reminder = num % 10;
            num = num / 10;

            cout << reminder << endl;
        }
    }

    static int sumDigitsOfNumber(int num)
    {
        int Reminder = 0;
        int sum = 0;

        while (num > 0)
        {
            Reminder = num % 10;
            num = num / 10;

            sum += Reminder;
        }

        return sum;
    }

    static int reverseNumberDigits(int num)
    {
        int Reminder = 0;
        int reversedNumber = 0;
        while (num > 0)
        {
            Reminder = num % 10;
            num = num / 10;

            reversedNumber = reversedNumber * 10 + Reminder;
        }
        return reversedNumber;
    }

    static int getDigitFrequency(int  num, short digit)
    {
        int reminder = 0;
        int counter = 0;

        while (num > 0)
        {
            reminder = num % 10;
            num = num / 10;
            if (reminder == digit)
                counter++;
        }
        return counter;
    }

    static void AllDigitsFrequencies(int num)// 0112
    {
        for (int i = 0; i < 10; i++)
        {
            int digitFreq = getDigitFrequency(num, i);

            if (digitFreq > 0)
                cout << "Digit " << i << " is found " << digitFreq << endl;
        }
    }

    static bool checkPalindromeNumber(int num)
    {
        return num == reverseNumberDigits(num);
    }

    static void printInvertedNumberPattern(int num)
    {
        for (int i = num; i >= 1; i--)
        {
            for (int x = 1; x <= i; x++)
                cout << i;
            cout << "\n";
        }
    }

    static void printInvertedPattern(int num)
    {
        cout << "\n";
        for (int i = 1; i <= num; i++)
        {
            for (int x = 1; x <= i; x++)
                cout << i;
            cout << "\n";
        }
        cout << "\n";
    }

    static short readNumberInRangeFromTo(string msg, short From, short To)
    {
        short num = 0;
        do
        {
            cout << msg << endl;
            cin >> num;
        } while (num < From || num > To);

        return num;
    }

    static char getLetter(int num)
    {
        return char(num + 64);
    }

    static void printLetterPattern(int num)
    {
        for (int i = 1; i <= num; i++)
        {
            for (int x = 1; x <= i; x++)
                cout << getLetter(i);
            cout << endl;
        }
    }

    static void printAllWordsFromAAAToZZZ()
    {
        for (int i = 1; i <= 26; i++)
        {
            cout << "==============\n";
            cout << getLetter(i) << endl;
            cout << "==============\n";

            for (int x = 1; x <= 26; x++)
            {
                cout << "==============\n";
                cout << getLetter(x) << endl;
                cout << "==============\n";

                for (int y = 1; y <= 26; y++)
                    cout << getLetter(i) << getLetter(x) << getLetter(y) << endl;
            }
        }
    }

    static void checkPassword(string pass)
    {
        int counter = 0;
        string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string formedPassword = "";

        for (int i = 0; i < 26; i++)
        {
            for (int x = 0; x <= 26; x++)
            {
                for (int y = 0; y < 26; y++)
                {
                    formedPassword += letters[i];
                    formedPassword += letters[x];
                    formedPassword += letters[y];

                    if (pass == formedPassword)
                    {
                        cout << "===========================================\n";
                        cout << "Password is " << pass << endl;
                        cout << "Found after " << counter + 1 << " Trail(s)\n";
                        cout << "===========================================\n";
                        return;
                    }
                    formedPassword = "";
                    counter++;
                }
                cout << endl;
            }
        }
    }

    static string readText()
    {
        string text = "";

        cout << "Please enter a text to encrypt?\n";
        getline(cin, text);

        return text;
    }

    static short getLength(string str)
    {
        short length = 0;
        short counter = 0;

        while (str[counter])
        {
            length++;
            counter++;
        }

        return length;
    }
    static short getLength(int arr[])
    {
        short length = 0;
        short counter = 0;

        while (arr[counter])
        {
            length++;
            counter++;
        }

        return length;
    }
    static short getLength(string arr[])
    {
        short length = 0;
        short counter = 0;

        while (arr[counter] != "")
        {
            length++;
            counter++;
        }

        return length;
    }

    static string EncryptText(string text)
    {
        short EncryptionKey = 2;
        short length = getLength(text);

        for (short i = 0; i < length; i++)
            text[i] = (short)text[i] + EncryptionKey;

        return text;
    }

    static string DecryptText(string text)
    {
        short EncryptionKey = 2;
        short length = getLength(text);

        for (short i = 0; i < length; i++)
            text[i] = (short)text[i] - EncryptionKey;

        return text;
    }

    static void sRand()
    {
       return srand((unsigned)time(NULL));
    }

    static short getRandomNumber(int From, int To)
    {
        return rand() % (To - From + 1) + From;
    }

    static void print3RandomNumbers(short From, short To)
    {
        for (short i = 1; i <= 3; i++)
            cout << getRandomNumber(From, To) << endl;
    }

    static char getRandomChar(short choice)
    {
        switch (choice)
        {
        case enChar::SmallLetter:
            return char(getRandomNumber(97, 122));
        case enChar::CapitalLetter:
            return char(getRandomNumber(65, 90));
        case enChar::SpecialChar:
            return char(getRandomNumber(33, 47));
        case enChar::DigitInOrder:
            return char(getRandomNumber(48, 57));
        case enChar::MixChar:
            choice = getRandomNumber(1, 4);
            return getRandomChar(choice);
        }
    }

    static string generateKey()
    {
        string key = "";

        for (int i = 1; i <= 4; i++)
        {
            for (int x = 1; x <= 4; x++)
                key += getRandomNumber(65, 90);
            if (i != 4)
                key += "-";
        }
        return key;
    }

    static void printGeneratedKeys(int numOfKeys)
    {
        for (int i = 1; i <= numOfKeys; i++)
            cout << "Key[" << i << "]: " << generateKey() << endl << endl;
    }

    static void readArrayElements(int numArr[100], int arrLength)
    {
        /*cout << "Enter How many elements in the array?\n";
        cin >> arrLength;*/

        for (int i = 0; i < arrLength; i++)
        {
            cout << "Element [" << i + 1 << "] : ";
            cin >> numArr[i];
        }
    }

    static void printArrayElements(int numArr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
            cout << numArr[i] << " ";
        cout << endl;
    }

    static void printArrayElements(string numArr[100], int arrLength)
    {
        cout << "===============================================\n";

        for (int i = 0; i < arrLength; i++)
            cout << numArr[i] << "\n";
        cout << "===============================================\n";
    }

    static void getElementFrequencyInArray(int arrLength)
    {
        int numArr[100];
        readArrayElements(numArr, arrLength);

        int counter = 0;
        int element = readElementToCheck();

        for (int i = 0; i < arrLength; i++)
        {
            if (element == numArr[i])
                counter++;
        }

        printArrayElements(numArr, arrLength);

        cout << "\n" << element << " is repeated " << counter << " time" << putCharS(counter) << endl;
        cout << "===============================================\n\n";
    }

    static void fillArrayWithRandomNumbers(int numArr[100], int arrLength, int from, int to)
    {
        for (int i = 0; i < arrLength; i++)
            numArr[i] = getRandomNumber(from, to);
    }
    static void fillArrayWithRandomWords(string numArr[100], int arrLength, enChar charCase, int wordLength)
    {
        for (int i = 0; i < arrLength; i++)
            numArr[i] = GenerateWord(charCase, wordLength);
    }

    static int MaximumNumberOfArray(int numArr[100], int arrLength)
    {
        //fillArrayWithRandomNumbers(numArr, arrLength, from, to);
        printArrayElements(numArr, arrLength);

        int maxNumber = 0;
        for (int i = 0; i < arrLength; i++)
        {
            if (numArr[i] > maxNumber)
                maxNumber = numArr[i];
        }
        return maxNumber;
    }

    static int MinimumNumberOfArray(int numArr[100], int arrLength)
    {
        //fillArrayWithRandomNumbers(numArr, arrLength);
        printArrayElements(numArr, arrLength);

        int minNumber = 100;

        for (int i = 0; i < arrLength; i++)
        {
            if (numArr[i] < minNumber)//2 5 4 3 1
                minNumber = numArr[i];
        }
        return minNumber;
    }

    static int sumOfArrayElements(int numArr[100], int arrLength)
    {
        //fillArrayWithRandomNumbers(numArr, arrLength);
        printArrayElements(numArr, arrLength);

        int sum = 0;
        for (int i = 0; i < arrLength; i++)
            sum += numArr[i];
        return sum;
    }

    static float averageOFRandomArray(int numArr[100], int arrLength)
    {
        float sumOfArrElements = sumOfArrayElements(numArr, arrLength);
        return float(sumOfArrElements / arrLength);
    }

    static void copyArray(int arr1[100], int arr2[100], int arrLength)
    {
        //fillArrayWithRandomNumbers(arr1, arrLength);

        for (int i = 0; i < arrLength; i++)
            arr2[i] = arr1[i];
        
        cout << "Array1 Elements \n"; printArrayElements(arr1, arrLength);
        cout << "Array2 Elements \n"; printArrayElements(arr2, arrLength);

          
    }

    static void copyPrimeNumbersFromArray(int arr[100], int primeArr[100], int length, int& arr2Length)
    {
        //formArrayOfNumbers(arr, length);

        int counter = 0;
        for (int i = 0; i < length; i++)
        {
            if (isPrimeNumber(arr[i]) == 1)
            {
                primeArr[counter] = arr[i];
                counter++;
            }
        }
        arr2Length = counter;
        cout << "Array One Elements \n"; printArrayElements(arr, length);
        cout << "Prime Array Elements \n"; printArrayElements(primeArr, arr2Length);
    }

    static void sumTwoArrays(int arr1[100], int arr2[100], int arr3[100], int length)
    {
        //formArrayOfNumbers(arr1, length);
        //formArrayOfNumbers(arr2, length);

        for (int i = 0; i < length; i++)
            arr3[i] = arr1[i] + arr2[i];

        cout << "Array One Elements \n"; printArrayElements(arr1, length);
        cout << "Array Two Elements \n"; printArrayElements(arr2, length);
        cout << "Array Three Elements \n"; printArrayElements(arr3, length);
    }

    static void swap(int& num1, int& num2)
    {
        int temp = 0;

        temp = num1;
        num1 = num2;
        num2 = temp;
    }
    static void swap(string& str1, string& str2)
    {
        string temp = "";

        temp = str1;
        str1 = str2;
        str2 = temp;
    }
    static void swap(double& d1, double& d2)
    {
        double temp = 0;

        temp = d1;
        d1 = d2;
        d2 = temp;
    }
    static void swap(clsDate& Date1, clsDate& Date2)    
    {
        clsDate temp;

        temp = Date1;
        Date1 = Date2;
        Date2 = temp;
    }
    
    static void shufflefArray(int arr[])
    {
        //formArrayOfNumbers(arr, length);

        int length = getLength(arr);
        cout << "Array Before Shuffling \n"; printArrayElements(arr, length);

        for (int i = 0; i < length; i++)
            swap(arr[getRandomNumber(0, (length - 1))], arr[getRandomNumber(0, (length - 1))]);
        
        cout << "Array After Shuffling \n"; printArrayElements(arr, length);
    }
    static void shufflefArray(string arr[])
    {
        //formArrayOfNumbers(arr, length);

        int length = getLength(arr);
        cout << "Array Before Shuffling \n"; printArrayElements(arr, length);

        for (int i = 0; i < length; i++)
            swap(arr[getRandomNumber(0, (length - 1))], arr[getRandomNumber(0, (length - 1))]);
        
        cout << "Array After Shuffling \n"; printArrayElements(arr, length);
    }

    static void copyArrayInReversedOrder(int arr1[100], int arr2[100], int length)
    {
        //formArrayOfNumbers(arr1, length);
        cout << "Original Array \n"; printArrayElements(arr1, length);

        int x = 0;
        for (int i = length - 1; i >= 0; i--)
        {
            arr2[x] = arr1[i];
            x++;
        }

        cout << "Reversed Array \n"; printArrayElements(arr2, length);
    }

    static string GenerateWord(enChar charCase, short length)
    {
        string Word = "";
        
        switch (charCase)
        {
        case clsUtil::SmallLetter:
            for (int i = 1; i <= length; i++)
                Word += getRandomNumber(97, 122);
            break;
        case clsUtil::CapitalLetter:
            for (int i = 1; i <= length; i++)
                Word += getRandomNumber(65, 90);
            break;
        case clsUtil::SpecialChar:
            for (int i = 1; i <= length; i++)
                Word += getRandomNumber(33, 47);
            break;
        case clsUtil::DigitInOrder:
            for (int i = 1; i <= length; i++)
                Word += getRandomNumber(48, 57);
            break;
        case clsUtil::MixChar:
            charCase = enChar(getRandomNumber(1, 4));
            return GenerateWord(charCase, length);
            break;
        }
        return Word;
    }

    static string GenerateKey(enChar charCase)
    {
        string word = "";
        for (int i = 1; i <= 4; i++)
        {
            word += GenerateWord(charCase, 4);
            if (i != 4) word += "-";
        }
        return word;
    }

    static void GenerateArrayOfKeys(enChar charCase, string arr[100], int length)
    {
        for (int i = 0; i < length; i++)
            arr[i] = GenerateKey(charCase);

        cout << "Keys Array \n"; printArrayElements(arr, length);
    }

    static bool isDigitExistsInArray( int arr[100], short length,  short digit)
    {
        //formArrayOfNumbers(arr, length);

        printArrayElements(arr, length);

        for (short i = 0; i < length; i++)
        {
            if (digit == arr[i])
                return 1;
            else
                return 0;
        }
    }

    static void getDigitPositionAndOrderInArray(int arr[100], int length, int digit)
    {
        //formArrayOfNumbers(arr, length);
        printArrayElements(arr, length);

        int posArr[100];
        int orderArr[100];

        int posArrLength = 0;
        int orderArrLength = 0;

        for (int i = 0; i < length; i++)
        {
            if (arr[i]==digit)
            {
                posArr[posArrLength] = i;
                posArrLength++;
                orderArr[orderArrLength] = i + 1;
                orderArrLength++;
            }
        }

        cout << "=============\n";
        if (posArrLength > 0)
        {
            cout << "____________________________\n";
            cout << "  Digit | Position | Order  \n";
            cout << "____________________________\n";

            for (int x = 0; x < posArrLength; x++)
            {
                cout <<"   "<< digit;
                for (int i = x; i <=x; i++)
                {
                        cout  <<"    |     "<< posArr[i] << "    |   "<< posArr[i]+1<<"\n";
                }
                cout << "____________________________\n";
            }
        }
        else
            cout <<"["<< digit << "]: Is Not exist!\n";
    }

    static void fillArraySemiDynamicly(int arr[100], int& length, int& num)
    {
        enAnswer answer;
        do
        {
            saveNumberInArray(arr, length, readNumber());
            cout << "Do you want to add more numbers? [0]:No, [1]:Yes ";

        } while (readAnswer() == enAnswer::Yes);

        cout << "\n\nArray Length: " << length << "\n";
        cout << "Array elements: ";
        printArrayElements(arr, length);
    }

    static void copyArrayWithSaveFunction(int arr1[100], int arr2[100], int length, int length2)
    {
        //formArrayOfNumbers(arr1, length);
        cout << "Array1 elements: ";
        printArrayElements(arr1, length);

        for (int i = 0; i < length; i++)
            //addArrayElement(arr2, (i + 1), arr1[i]);
            saveNumberInArray(arr2, length2, arr1[i]);

        cout << "Array2 elements: ";
        printArrayElements(arr2, length);
    }

    static void copyOddElementToNewArray(int arr1[100], int arr2[100], int length, int& length2)
    {
        //formArrayOfNumbers(arr1, length);
        cout << "Array1 elements: ";
        printArrayElements(arr1, length);

        for (int i = 0; i < length; i++)
        {
            if (arr1[i] % 2 != 0)
                saveNumberInArray(arr2, length2, arr1[i]);
        }
        cout << "Array2 elements: ";
        printArrayElements(arr2, length2);
    }

    static bool isArrayIncludeNumber(int numsArr[100],int length, int num)
    {
        for (int x = 0; x < length; x++)
        {
            if (numsArr[x] == num)
                return true;
        }
        return false;
    } 

    static void copyPrimeNumbersToNewArr(int arr1[100], int arr2[100], int length1, int& length2)
    {
        //formArrayOfNumbers(arr1, length1);
        cout << "Array1 elements: ";
        printArrayElements(arr1, length1);

        for (int i = 0; i < length1; i++)
        {
            if (isPrimeNumber(arr1[i]))
                saveNumberInArray(arr2, length2, arr1[i]);
        }
        cout << "Array2 elements: ";
        printArrayElements(arr2, length2);
    }
        
    static void copyDistinctNumbersToNewArr(int arr1[100], int arr2[100], int length1, int& length2)
    {
        //formArrayOfNumbers(arr1, length1);

        cout << "Array1 elements: ";
        printArrayElements(arr1, length1);

        for (int i = 0; i < length1; i++)
        {
            while(!isArrayIncludeNumber(arr2, length2, arr1[i]))
                saveNumberInArray(arr2, length2, arr1[i]);
        }

        cout << "Array2 elements: ";
        printArrayElements(arr2, length2);
    }

    static void reverseArray(int arr1[100], int length1, int arr2[100])
    {
        cout << "Array1 elements: ";
        printArrayElements(arr1, length1);

        for (int i = 0; i < length1; i++)   
            arr2[i] = arr1[length1 - 1 - i];

        cout << "Array2 elements: ";
        printArrayElements(arr2, length1);
    }

    static bool isPalindromeArray(int arr[100], int length, int arr2[100])
    {
        
        reverseArray(arr, length, arr2);

        
        for (int i = 0; i < length; i++)
        {
            if (arr2[i] == arr[i])
                return 1;
            else
                return 0;
        }
    }

    static int countOddNumbersInArray(int arr[100], int length)
    {
        //formArrayOfNumbers(arr, length);
        cout << "Array1 elements: ";
        printArrayElements(arr, length);

        int counter = 0;
        for (int i = 0; i < length; i++)
        {
            if (arr[i] % 2 != 0)
                counter++;
        }
        return counter;
    }

    static int countEvenNumbersInArray(int arr[100], int length)
    {
        //formArrayOfNumbers(arr, length);
        cout << "Array1 elements: ";
        printArrayElements(arr, length);

        int counter = 0;
        for (int i = 0; i < length; i++)
        {
            if (arr[i] % 2 == 0)
                counter++;
        }
        return counter;
    }

    static int countPositiveNumbersInArray(int arr[100], int length)
    {
        //formArrayOfNumbers(arr, length);
        cout << "Array1 elements: ";
        printArrayElements(arr, length);

        int counter = 0;
        for (int i = 0; i < length; i++)
        {
            if (arr[i] >= 0)
                counter++;
        }
        return counter;
    }

    static int countNegativeNumbersInArray(int arr[100], int length)
    {
        //formArrayOfNumbers(arr, length);
        cout << "Array1 elements: ";
        printArrayElements(arr, length);


        int counter = 0;
        for (int i = 0; i < length; i++)
        {
            if (arr[i] < 0)
                counter++;
        }
        return counter;
    }
    
    static int myRound(float num)
    {
        int integerPart = int(num);
        float fractionPart = num - integerPart;

        if (abs(fractionPart) >= .5)
        {
            if (num > 0)
                return ++integerPart;
            else
                return --integerPart;
        }
        else
            return integerPart;
    }

    static int myCeil(float num)
    {
        float fractionPart = num - int(num);

        if (fractionPart == 0 || num < 0)//10
            return int(num);
        else if (num > 0)
            return int(++num);

    }

    static int myFloor(float num)
    {
        if (num < 0)
            return (int)--num;
        else
            return int(num);
    }

    static float mySqrt(float num)//10.7*10=107 
    {
        /*for (float i = 2; i <= round(num / 2); i = i + 0.000001)
        {
            if (num == floor(i * i))
                return i;
        }
        return 0;*/
        return pow(num, 0.5);
    }

    static string tap(short space)
    {
        string dis = "";
        for (short i = 1; i <= space; i++)
        {
            dis += "\t";
        }
        return dis;
    }


    static string numberToText(int holeNumber)//123 155 425 656
    {
        string textOfNumber = "";

        string textOfDigit1 = "";
        string textOfDigit2 = "";
        string textOfDigit3 = "";

        short digit1 = 0;
        short digit2 = 0;
        short digit3 = 0;

        string valueOfNumber = "";
        static int counter = 1;
        int number = 0;

        number = holeNumber % 1000;

        digit1 = number % 10;
        number = number / 10;
        digit2 = number % 10;
        number = number / 10;
        digit3 = number % 10;

        if (digit2 == 1)
        {
            textOfDigit2 = NameOfNumber((digit2 * 10) + digit1);
            digit1 = 0;
        }
        else
            textOfDigit2 = NameOfNumber(digit2 * 10);

        textOfDigit3 = NameOfNumber(digit3);
        textOfDigit3 = (digit3 == 0) ? textOfDigit3 : ((digit3 == 1) ? textOfDigit3 + " Hundred " : textOfDigit3 + " Hundreds ");
        textOfDigit1 = NameOfNumber(digit1);

        textOfNumber = (((textOfDigit3 != "") ? textOfDigit3 : "") + ((textOfDigit2 != "") ? textOfDigit2 + " " : "") + textOfDigit1);

        if (textOfNumber == "One")
            valueOfNumber = (counter == 2) ? " Thouthand " : (counter == 3) ? " Milion " : (counter == 4) ? " Bilion " : "";
        else
            valueOfNumber = (counter == 2) ? " Thouthands " : (counter == 3) ? " Milions " : (counter == 4) ? " Bilions " : "";

        textOfNumber += valueOfNumber;

        holeNumber = holeNumber / 1000;

        if (holeNumber > 0)
        {
            counter++;
            textOfNumber = numberToText(holeNumber) + textOfNumber;
        }
        if (holeNumber == 0)
            counter = 1;


        return textOfNumber;
    }










};

