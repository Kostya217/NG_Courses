#include <iostream>
#include <string>
using namespace std;


int main()
{
    string str = "yt ufxx ymnx yfxp fii dtzw sfrj fx htrrjsy bnym qnsp yt uwtlwfr ns lny";
    string cesaren = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 1; i < cesaren.length(); i++)
    {
	for (int j = 0; j < str.length(); j++)
	{	if(str[j] != ' ')
			for (int k = 0; k < cesaren.length(); k++)
			{
				if (str[j] == cesaren[k]) {
					if(k + 1 > cesaren.length() - 1) str[j] = cesaren[(cesaren.length() - k - 1)];
					else str[j] = cesaren[k + 1];
					break;
				}
			}
		}
		cout << endl << str << endl;
	}
}
