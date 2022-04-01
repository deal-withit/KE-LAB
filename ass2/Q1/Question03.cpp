/*
Author : Kundan Kumar 
Roll No: 207929
Assignment 02 'KE LAB'
*/

/*
  Part 01 :Implement Assignment 01 
  with Random Number of transactions
  and Random number of items. 
  
  Question 03: Find the Count of Items. 
*/
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main()
{
	ofstream wrt("Count_Freq.txt");//File to write all the frequency Counts. 
	fstream rd("database.txt");
	map<string,int>m;
	string str;
	/*
	  Couting all the items in database.txt.
	*/
	while(rd>>str)
	{
		if(str.length()>=2 && str[0]=='i')
		{
			m[str]++;
		}
	}
	map<string,int>::iterator it = m.begin();
	//Priting all the transactions items and their counts. 
	while (it != m.end())
	{
		cout<<it->first<<" "<<it->second<<endl;
		wrt<<it->first<<" "<<it->second<<endl;
		it++;
	}
	wrt.close(); //Closing the writing operation in file. 
	rd.close(); //Closing the Reading operation in file.
}


