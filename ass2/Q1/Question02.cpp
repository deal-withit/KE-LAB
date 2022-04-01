/*
Author : Kundan Kumar 
Roll No: 207929
Assignment 02 'KE LAB'
*/

/*
  Part 01 :Implement Assignment 01 
  with Random Number of transactions
  and Random number of items. 
  
  Question 02: Read Transactions from
  file using file operations.   
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	fstream rd("database.txt");//Reading the database.txt file. 
  string str; 
  while(getline(rd,str)) 
  {
    cout<<str<<endl; //Reading all the transactions in database.txt and diplaying it. 
  }
	rd.close(); //After completion of transactions display, The file is closed. 
	return 0; 
}
