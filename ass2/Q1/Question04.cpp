/*
Author : Kundan Kumar 
Roll No: 207929
Assignment 02 'KE LAB'
*/

/*
  Part 01 :Implement Assignment 01 
  with Random Number of transactions
  and Random number of items. 
  
  Question 04: Extract item-transaction list. 
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
  string str,final_str;
  ofstream wrt("Extracted_list.txt");
  fstream fin("database.txt"); //Reading all the transactions from database.txt
  map<string,vector<string >>m; //Map to store all the items and respective vector of transactions.
  while(fin.eof()==0){
    fin>>str;
    if(str[0]=='T')
    final_str=str;
    m[str].push_back(final_str); 
  }
  for(auto it:m){
    if(it.first[0]!='T'){ 
      cout<<it.first<<" "; //Displaying all the items in file. 
      wrt<<it.first<<" ";
    }
    for(int i=0;i<it.second.size();i++){
      cout<<it.second[i]<<" "; //Displaying all the transactions having that item. 
      wrt<<it.second[i]<<" ";  
    }
    cout<<endl; 
    wrt<<"\n"; 
  }
  wrt.close(); //Closing the writing operation in file.
  fin.close(); //Closing the Reading operation in file.
  return 0;
}