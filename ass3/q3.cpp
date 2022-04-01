/*
   Author : Kundan Kumar, RollNo:207929
   Question 03: Implement missing values using class labels
   (10 values for column with 2 labels,  2 missing values)  
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    //Defining A Vector of Pairs which have 2 columns each. 
    vector<pair<string,string>>v; 
    v={
        {"13","Laptop"},{" ","Computer"},{"17","Laptop"},
        {"21","Computer"},{" ","Laptop"},{"5","Computer"},
        {"19","Laptop"},  {"8","Computer"},{"30","Laptop"},
        {"40","Computer"},{"15","Laptop"},{"27","Computer"}
      };

    cout<<"Stored Data in The Array is following : "<<endl; 
    for(int i=0;i<v.size();i++)
       cout<<v[i].first<<"   "<<v[i].second<<endl;

    unordered_map<string,vector<string>>mp;
    for(int i=0;i<v.size();i++)
    mp[v[i].second].push_back(v[i].first);

    unordered_map<string,int>mp_temp;

    for(auto pr:mp)
    { 
        float sum=0;
        float count=0;
        for(int i=0;i<pr.second.size();i++){
            if(pr.second[i]!=" "){
              sum=sum+stoi(pr.second[i]);
              count++;
            }
        }
        mp_temp[pr.first]= sum/count;
    }

    for(int i=0;i<v.size();i++)
    {
        if(v[i].first==" ")
        v[i].first=to_string(mp_temp[v[i].second]);

    }

    cout<<endl;
    cout<<"Resultant Array : "<<endl;
    for(int i=0;i<v.size();i++)
    cout<<v[i].first<<"   "<<v[i].second<<endl;



}
