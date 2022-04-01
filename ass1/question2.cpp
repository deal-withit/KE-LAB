#include<bits/stdc++.h>
using namespace std; 

int main(){
    string txt; 
    fstream f1; 
    ofstream f2;
    f1.open("sample.txt"); 
    f2.open("sample2.txt");
    while(getline(f1,txt)){
        cout<<txt<<endl; 
        f2<<txt<<endl; 
    }

    f2.close(); 
    f1.close(); 
    return 0;  
}