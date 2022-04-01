/*
Author : Kundan Kumar 
Roll No: 207929
Assignment 02 'KE LAB'
*/

/*
  Part 01 :Implement Assignment 01 
  with Random Number of transactions
  and Random number of items. 
  
  Question 01: Creation of Transaction
  Database in a file.  
*/
 
#include <bits/stdc++.h>
#include <iostream>  
#include<sstream> 
using namespace std;
//Function to Create a Random number within a limit. 
int GetRandom(int low,int high){
   return rand()%(high-low+1)+1;
}

int main(){
     /* Creating a New Database set 
        which will contain all
         the transactions. 
     */
      ofstream wrt("database.txt");//Creating a new database.txt file to store transactions. 
      /*Calling the GetRandom function to 
       get any number between 0 and 100.
       This will be used as Random no. 
       of transactions.*/
      int N=GetRandom(1,100);  
      vector<string>final_string_vector;  //Creating a Vector which will stoer all the 
      
      //In this part I will be taking input of strings num(Above taken random number) no. of times.  
      for(int i=1;i<=N;i++){
        stringstream ss;  
        ss<<i;  
        string str;  
        ss>>str;  
          string T="T"+ str;
          /*Calling the GetRandom function to 
          get any number between 1 and 15.
          This will be used as Random no.
          of item in each transaction.*/
          int n=GetRandom(1,15);
          for(int j=1;j<=n;j++){
            int h=GetRandom(1,15);
            stringstream ss;  
            ss<<h;  
            string s1;  
            ss>>s1;  
            T+=(" i"+ s1);
          }
          final_string_vector.push_back(T); //All the transactions will be pushed to the main Vector. 
      }
      for(int i=0;i<N;i++){  
        wrt<<final_string_vector[i]<<endl; //Writing all the Transactions in Database.txt.  
      }
      wrt.close(); //After all the operations the Database.txt writing is closed. 
}
