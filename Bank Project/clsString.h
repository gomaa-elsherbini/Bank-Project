#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;



class clsString
{
private:
	string _Value;
	enum enTrim { Right = 1, Left = 2, All = 3 };

public:
	clsString()
	{
		_Value = "";
	}

	clsString(string str)
	{
		_Value = str;
	}

	void SetValue(string value)
	{
		_Value = value;
	}

	string GetValue()
	{
		return _Value;
	}

	__declspec(property(get = GetValue, put = SetValue))string value;

	static short countWordInString(string str)
	{
		//       Mohammad   Abu-Hadhoud     Programming           Advices          
		string delim = " ";
		short pos = 0;
		string word = "";
		short counter = 0;

		while ((pos = str.find(delim)) != std::string::npos)
		{
			word = str.substr(0, pos);
			if (word != "")
				counter++;

			str.erase(0, pos + delim.length());
		}
		if (str != "")
			counter++;

		return counter;
	}
	short countWordInString()
	{
		return countWordInString(_Value);
	}

	static void printFirstLetterInEachWord(string str)
	{
		bool isFirstLetter = true;
		for (short i = 0; i < str.length(); i++)
		{
			/*if(i==0 && str[i]!=' ')
	//				cout << str[i];
	//			else if (str[i] == ' '&& str[i+1]!=' ')
	//				cout << str[i+1];*/

			if (str[i] != ' ' && isFirstLetter)
				cout << str[i] << " ";

			isFirstLetter = (str[i] == ' ') ? true : false;
		}
	}
	void printFirstLetterInEachWord()
	{
		return printFirstLetterInEachWord(_Value);
	}

	static string UpperFirstLetterInEachWord(string str)
	{
		bool isFirstLetter = true;

		for (short i = 0; i < str.length(); i++)
		{
			if (str[i] != ' ' && isFirstLetter)
				str[i] = toupper(str[i]);

			isFirstLetter = (str[i] == ' ') ? true : false;
		}

		return str;
	}
	string UpperFirstLetterInEachWord()
	{
		return UpperFirstLetterInEachWord(_Value);
	}

	static string lowerFirstLetterInEachWord(string str)
	{
		bool isFirstLetter = true;
		for (short i = 0; i < str.length(); i++)
		{
			if (str[i] != ' ' && isFirstLetter)
			{
				str[i] = tolower(str[i]);
			}
			isFirstLetter = (str[i] == ' ') ? true : false;
		}
		return str;
	}
	string lowerFirstLetterInEachWord()
	{
		return lowerFirstLetterInEachWord(_Value);
	}

	static string lowerAllLettersOfString(string str)
	{
		for (short i = 0; i < str.length(); i++)
			str[i] = tolower(str[i]);

		return str;
	}
	string lowerAllLettersOfString()
	{
		return lowerAllLettersOfString(_Value);
	}

	static string upperAllLettersOfString(string str)// gomaa el  sherbini
	{
		for (short i = 0; i < str.length(); i++)
			str[i] = toupper(str[i]);
		return str;
	}
	string upperAllLettersOfString()
	{
		return upperAllLettersOfString(_Value);
	}

	static char invertCharacterCase(char myChar)// gomaa el  sherbini
	{
		return isupper(myChar) ? tolower(myChar) : toupper(myChar);
	}
	char invertCharacterCase()
	{
		char myChar;
		cout << "please enter the character?\n";
		cin >> myChar;
		return invertCharacterCase(myChar);
	}

	static string invertAllLettersCase(string str)
	{
		for (short i = 0; i < str.length(); i++)
			str[i] = invertCharacterCase(str[i]);
		return str;
	}
	string invertAllLettersCase()
	{
		return invertAllLettersCase(_Value);
	}
	
	static void countCharacterCase(string str)
	{
		enum enCharCase { Small = 1, Capital = 2 };
		int smallLetters = 0;
		int capitalLetters = 0;
		
		for (short i = 0; i < str.length(); i++)
		{
			if (isupper(str[i]))
				capitalLetters++;
			else if (islower(str[i]))
				smallLetters++;
		}
			
		//cout << "\nString length = " << str.length() << endl;
		cout << "Number of Capital letters = " << capitalLetters << endl;
		cout << "Number of Small Letters = " << smallLetters << endl;
	}
	void countCharacterCase()
	{
		return countCharacterCase(_Value);
	}

	static short countCharInString(string str, char ch, bool matchCase = true)
	{
		int counter = 0;
		for (int i = 0; i < str.length(); i++)
		{
			if (matchCase)
			{
				if (str[i] == ch)
					counter++;
			}
			else
			{
				if (tolower(str[i]) == tolower(ch))
					counter++;
			}
		}
		return counter;
	}
	short countCharInString(char ch, bool matchCase)
	{
		return countCharInString(_Value, ch, matchCase);
	}

	static bool isVowelLetter(char ch)
	{
		char vowels[5] = { 'a', 'e', 'i', 'o', 'u' };

		for (short i = 0; i < 5; i++)
		{
			if (vowels[i] == tolower(ch))
				return true;
		}
		return false;
	}

	static short countVowelsInString(string str)
	{
		int counter = 0;
		for (int i = 0; i < str.length(); i++)
		{
			if (isVowelLetter(str[i]))
				counter++;
		}
		return counter;
	}
	short countVowelsInString()
	{
		return countVowelsInString(_Value);
	}

	static string VowelsIntoString(string str)
	{
		string vowelsString = " ";
		for (int i = 0; i < str.length(); i++)
		{
			if (isVowelLetter(str[i]))
				vowelsString = vowelsString + " " + str[i];
		}
		return vowelsString;
	}
	string VowelsIntoString()
	{
		return VowelsIntoString(_Value);
	}

	static void printEachWord(string str)
	{
		string delim = " ";
		int pos = 0;
		string word = "";

		while ((pos = str.find(delim)) != std::string::npos)
		{
			word = str.substr(0, pos);
			if (word != "")
				cout << word << endl;
			str.erase(0, pos + 1);
		}
		if (str != "")
			cout << str << endl;
	}
	void printEachWord()
	{
		return printEachWord(_Value);
	}

	static vector <string>splitString(string str, string delimiter)
	{
		short pos = 0;
		string word = "";
		vector <string> vWords;

		while ((pos = str.find(delimiter)) != std::string::npos)
		{
			word = str.substr(0, pos);
			if (word != "")
				vWords.push_back(word);
			str.erase(0, pos + delimiter.length());
		}
		if (str != "")
			vWords.push_back(str);
		return vWords;
	}
	vector <string>splitString(string delimiter)
	{
		return splitString(_Value, delimiter);
	}
	static string joinString(vector <string> vString, string delim)
	{
		string s = "";
		for (string& str : vString)
			s += str + delim;
		return s.substr(0, (s.length() - delim.length()));
	}
	static void reversString(vector <string>vStr)
	{
		string reversedString = "";
		string delim = " ";

		vector<string>::iterator iter = vStr.end();

		while (iter != vStr.begin())
		{
			iter--;
			reversedString += *iter + " ";
		}
		reversedString = reversedString.substr(0, reversedString.length() - 1);

		cout << reversedString << endl << endl;
	}

	static void printVectorTokens(string str, string delim, vector<string>vWords)
	{
		cout << "\n Tokens = " << countWordInString(str) << endl;
		for (string& word : vWords)
			cout << word << endl;
	}
	void printVectorTokens(string delim, vector<string>vWords)
	{
		return printVectorTokens(_Value, delim, vWords);
	}

	static string TrimLeftString(string str)
	{
		for (short i = 0; i < str.length(); i++)//    gomaa
		{
			if (str[i] != ' ')
				return str.substr(i, str.length());
		}
		return "";
	}
	string TrimLeftString()
	{
		return TrimLeftString(_Value);
	}

	static string TrimRightString(string str)
	{
		for (int i = str.length() - 1; i >= 0; i--)
		{
			if (str[i] != ' ')
				return str.substr(0, (i+1));
		}
		return "";
	}
	string TrimRightString()
	{
		return TrimRightString(_Value);
	}

	static string TrimString(string str)
	{
		return TrimRightString(TrimLeftString(str));
	}
	string TrimString()
	{
		return TrimString(_Value);
	}

	static string replaceString(string s1, string strToReplace, string strToReplaceTo)
	{
		short pos = s1.find(strToReplace);

		while (pos != -1)
		{
			s1.replace(pos, strToReplace.length(), strToReplaceTo);
			pos = s1.find(strToReplace);
		}
		return s1;
	}
	string replaceString(string strToReplace, string strToReplaceTo)
	{
		return (_Value, strToReplace, strToReplaceTo);
	}

	static string replaceWordInString( string myString,string word, string s2, bool matchCase = 1)
	{
		vector <string>vStr = splitString(myString," ");
		for (string& str : vStr)
		{
			if (matchCase)
			{
				if (str == word)
					str = s2;
			}
			else
			{
				if (lowerAllLettersOfString(str) == lowerAllLettersOfString(word))
					str = s2;
			}
		}
		return joinString(vStr, " ");
	}
	string replaceWordInString(string word, string s2, bool matchCase = 1)
	{
		return replaceWordInString(_Value, word, s2);
	}
	
	static string removePunctuations(string str)
	{
		string s2 = "";
		for (int i = 0; i < str.length(); i++)
		{
			if (!ispunct(str[i]))
				s2 += str[i];
		}
		return s2;
	}
	string removePunctuations()
	{
		return removePunctuations(_Value);
	}

};

