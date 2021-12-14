#pragma once
#ifndef cesarean_code
#define cesarean_code
#include <iostream>
#include <string>

using namespace std;

class CesareanCode
{
public :
	CesareanCode()
	{

	}
	CesareanCode(string inputStr)
	{
		str = inputStr;
	}
	CesareanCode(string inputStr, int inputKey)
	{
		str = inputStr;
		key = inputKey;
	}

	void SetKey(int inputKey) {
		key = inputKey;
	}
	int GetKey() {
		return key;
	}

	void SetStr(string inputStr) {
		str = inputStr;
	}
	string GetStr() {
		return str;
	}

	string Encryption() {
		if (key <= 0 || str == "") return "";

		for (int i = 0; i < key; i++)
		{
			for (int j = 0; j < str.length(); j++)
			{
				if (str[j] != ' ')
					for (int k = 0; k < cesarenLower.length(); k++)
					{
						if (str[j] == cesarenLower[k]) {
							if ((k + 1) > (cesarenLower.length() - 1)) str[j] = cesarenLower[(cesarenLower.length() - k - 1)];
							else str[j] = cesarenLower[k + 1];
							break;
						}
						else if (str[j] == cesarenUpper[k]) {
							if ((k + 1) > (cesarenUpper.length() - 1)) str[j] = cesarenUpper[(cesarenUpper.length() - k - 1)];
							else str[j] = cesarenUpper[k + 1];
							break;
						}
					}
			}
		}
		return str;
	}

	string Decryption() {
		for (int i = 0; i < key; i++)
		{
			for (int j = 0; j < str.length(); j++)
			{
				if (str[j] != ' ')
					for (int k = 0; k < cesarenLower.length(); k++)
					{
						if (str[j] == cesarenLower[k]) {
							if ((k - 1) < 0) str[j] = cesarenLower[(cesarenLower.length() - k - 1)];
							else str[j] = cesarenLower[k - 1];
							break;
						}
						else if (str[j] == cesarenUpper[k]) {
							if ((k - 1) < 0) str[j] = cesarenUpper[(cesarenUpper.length() - k - 1)];
							else str[j] = cesarenUpper[k - 1];
							break;
						}
					}
			}
		}
		return str;
	}

	string Decryption(string str, int key) {
		for (int i = 0; i < key; i++)
		{
			for (int j = 0; j < str.length(); j++)
			{
				if (str[j] != ' ')
					for (int k = 0; k < cesarenLower.length(); k++)
					{
						if (str[j] == cesarenLower[k]) {
							if ((k - 1) < 0) str[j] = cesarenLower[(cesarenLower.length() - k - 1)];
							else str[j] = cesarenLower[k - 1];
							break;
						}
						else if (str[j] == cesarenUpper[k]) {
							if ((k - 1) < 0) str[j] = cesarenUpper[(cesarenUpper.length() - k - 1)];
							else str[j] = cesarenUpper[k - 1];
							break;
						}
					}
			}
		}
		return str;
	}
	~CesareanCode(){}

private:
	string cesarenUpper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string cesarenLower = "abcdefghijklmnopqrstuvwxyz";
	string str = "";
	int key = 0;
};
#endif

