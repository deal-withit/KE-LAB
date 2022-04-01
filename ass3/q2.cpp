/*
   Author : Kundan Kumar, RollNo:207929
   Question 01: Implement Binning techniques,
   considering 20 random values and text book values 
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
	
	//Storing Some Random Values in an Array.
    vector<int>values{
       11,45,78,63,81,54,
       59,144,98,789,89,
       22,724,34,30,16,
       83,98,100,357
    };
    
    sort(values.begin(),values.end());
    //Method 01 : Doing Partitions of The array of size size_of_bin. 
    int size_of_bin=4;
    cout<<"These are the equal Partitions: "<<endl;
    int j=1;
    for(int i=0;i<values.size();i++)
         { 
            cout<<"Bin No. "<<j<<": ";
             for(;i<j*size_of_bin;i++)
             {
                cout<<values[i]<<" ";
             }
             i--;
             j++;
             cout<<endl;
         }

    // Method 02: Smoothing Done according to the mean of Bins. 
    cout<<"Smoothing by bin means:"<<endl;
       j=1;
      for(int i=0;i<values.size();i++)
         { 
            cout<<"Bin No. "<<j<<": ";
            int sum=0;
             for(;i<j*size_of_bin;i++)
             {
                sum+=values[i];
             }
             for(int c=0;c<size_of_bin;c++)
             {
                cout<<sum/4<<" ";
             }
             i--;
             j++;
             cout<<endl;
         }

     // Method : 03 Smoothing Done By Bin Boundaries.
    cout<<"Smoothing by bin boundaries:" <<endl;
    j=1;
    for(int i=0;i<values.size();i++)
         { 
            cout<<"Bin "<<j<<": ";
            int mx=INT_MIN;
            int mi=INT_MAX;
             for(;i<j*size_of_bin;i++)
             {
                mx=max(mx,values[i]);
                mi=min(mi,values[i]);
             }
             i=i-size_of_bin;
             
             for(;i<j*size_of_bin;i++)
             {  if(mx-values[i]>values[i]-mi)
                   values[i]=mi;
                else
                   values[i]=mx;
                cout<<values[i]<<" ";     
             }
             i--;
             j++;
             cout<<endl;
         }
    return 0;
}
