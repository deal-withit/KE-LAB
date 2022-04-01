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
#include <bits/stdc++.h>
using namespace std;
void subset(vector<string> input,vector<string> s,int ind,vector< vector<string> > &output){
    
    if(ind==input.size()){
        if(!s.empty())
          output.push_back(s);
    return;
    }
    subset(input,s,ind+1,output);
    s.push_back(input[ind]);
    subset(input,s,ind+1,output);
}

int main()
{
    string st,str;
    set<string> item;
    vector< vector<string> > tn;
    ifstream in("database.txt");
    vector<string> temp;
    while (in.eof()==0)
    {
      in>> st;
      if(st[0]!='T'){
      item.insert(st);
      temp.push_back(st);

      }else if(!temp.empty()){
          tn.push_back(temp);
          temp.clear();
      }
}
    
    vector<string> v(item.begin(),item.end());
    vector<string> s;
    vector< vector<string> > output;
    subset(v,s,0,output);
    int ind=0;
    map<int ,int> mp;
    for(auto x:output){
        
        
        for(auto z:tn){
           int c=0;
             for(auto y:x)
               if(binary_search(z.begin(),z.end(),y))
                 c++;
           if(c==x.size())
             mp[ind]++;
        }
        ind++;
        }
    
  
  int ms=(tn.size()*3)/10;
  ofstream wrt("Itemsets.txt");


    for(auto x:mp)
    {  if(x.second>ms){
        cout<<"{ ";
        wrt<<"{ ";
         for(int ind=0;ind<output[x.first].size();ind++){
           cout<<output[x.first][ind]<<" ";
           wrt<<output[x.first][ind]<<" ";}
        cout<<"}";
        wrt<<"}"<<"\n";
        cout<<endl;
    }
}
  in.close();
  wrt.close();
  return 0;
}
