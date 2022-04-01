/*
Author : Kundan Kumar 
Roll No: 207929
Assignment 02 'KE LAB'
*/

/*
  Part 02 :Extract Frequent itemsets from transaction database
    consider assignment-1 transaction database(minimum support=2)
    and also random transaction database(minimum support=30%)  
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    srand(time(0));
    ofstream wrt("database.txt");//Creating a Database to store the transaction list. 
 
    int N=rand()%100+1;
    for(int i=1;i<=N;i++)
    {
        string T="T"+to_string(i);
        
        int n=rand()%15+1;
        for(int j=1;j<=n;j++)
        {
        
            T+=(" i"+ to_string(j));
        }
        wrt<<T<<endl;
    }
}
