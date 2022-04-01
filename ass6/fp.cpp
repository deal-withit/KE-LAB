#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<string>>&data){
    for(int i=0; i<data.size(); i++){
        for(auto it: data[i])
        cout<<it<<" "; 
        cout<<endl; 
    }
}
int main(){
    vector<vector<string>>data; 
    ifstream read("database.txt");
    string str; 
    while(getline(read,str)){
        vector<string>tempdata; 
        stringstream ss(str);
        string temp;
        ss>>temp;
        while(ss>>temp){
            tempdata.push_back(temp); 
        }
        data.push_back(tempdata); 
    }
    print(data); 
}