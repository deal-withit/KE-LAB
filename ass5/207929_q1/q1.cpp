#include<bits/stdc++.h>
using namespace std; 

int min_support = 3; 
fstream write,read;

map<string,int> mapOrder(vector<string>& unique_items){
    map<string,int> res;
    int idx = 1;  
    for(auto it: unique_items){
        res[it]=idx; 
        idx++; 
    }
    return res; 
}
void createSubsetofTwo(vector<string>arr, int n, int r, int index, vector<string>data, int i,vector<vector<string>>&req_data_set){
   if (index == r) {
      req_data_set.push_back(data);
      return;
   }
   if (i >= n)
      return;
   data[index] = arr[i];
   createSubsetofTwo(arr, n, r, index + 1, data, i + 1,req_data_set);
   createSubsetofTwo(arr, n, r, index, data, i + 1,req_data_set);
}

vector<string> splitData(string &x){
    vector<string> res;
    string str;
    stringstream obj(x);
    while(obj>>str){
        res.push_back(str);
    }
    return res;
}

map<string,vector<string>> readData(string file){
    read.open(file,ios::in);
    map<string,vector<string>> res;
    string str;
    while(getline(read,str)){
        vector<string> A = splitData(str);
        for(int i = 1;i < A.size();i++){
            res[A[0]].push_back(A[i]);
        }
    }
    return res;
}
int main(){
    set<string> temp; 
    map<string,vector<string>> data = readData("database.txt"); 
    cout<<"The Input data is given below."<<endl;
    for(auto it:data){
        cout<<it.first<<" ";
        vector<string> v = it.second; 
        for(auto i: v){
            cout<<i<<" ";
            temp.insert(i);  
        }
        cout<<endl; 
    }

    map<string,int> itemCount; 
    for(auto it: data){
        vector<string>v = it.second;
        for(auto it:v){
            itemCount[it]++; 
        }
    }

    //Creating C2 having 2 item sets. 
    //map<vector<string>,int> itemSet2 = createItemset2(data,temp); 
    vector<string> unique_items;
    
    for(auto it: temp)
    unique_items.push_back(it);
    map<string,int> itemOrder = mapOrder(unique_items); 

    vector<string>tempDataSetoftwo(2);
    vector<vector<string>>req_data_set; 
    createSubsetofTwo(unique_items, unique_items.size(), 2, 0,tempDataSetoftwo, 0,req_data_set);
    vector<string>tempDataSetofthree(3); 
    vector<vector<string>> req_data_set2; 
    createSubsetofTwo(unique_items, unique_items.size(), 3, 0,tempDataSetofthree, 0,req_data_set2);

    map<vector<string>,int> count_data_set_two;
     
    for(auto it: req_data_set){
        vector<string>temp1 = it;  
        for(auto i : data){
            vector<string> temp = i.second;
            if(find(temp.begin(),temp.end(),temp1[0])!=temp.end() && find(temp.begin(),temp.end(),temp1[1])!=temp.end()){
                count_data_set_two[temp1]++; 
            }
        }
    }

     map<vector<string>,int> count_data_set_three;
     for(auto it: req_data_set2){
        vector<string>temp1 = it;  
        for(auto i : data){
            vector<string> temp = i.second;
            if(find(temp.begin(),temp.end(),temp1[0])!=temp.end() 
            && find(temp.begin(),temp.end(),temp1[1])!=temp.end()
            && find(temp.begin(),temp.end(),temp1[2])!=temp.end()){
                count_data_set_three[temp1]++; 
            }
        }
    }

    map<vector<string>,int> resultHash(count_data_set_two);
    map<vector<string>,int> resultHash2(count_data_set_three);
    map<vector<string>,int> resultHash3(count_data_set_three);
   


    map<int,vector<vector<string>>> hashBucket;
    for(auto it: count_data_set_two) {
        string str1 = it.first[0]; 
        string str2 = it.first[1];
        int bucket = ((itemOrder[str1]*10)+(itemOrder[str2]))%7;
        int count = it.second; 
        for(int i=0; i<count; i++)
        hashBucket[bucket].push_back(it.first); 
    }

    map<int,vector<vector<string>>> hashBucket2;
    for(auto it: count_data_set_three) {
        string str1 = it.first[0]; 
        string str2 = it.first[1];
        string str3 = it.first[2];
        int bucket = ((itemOrder[str1]*10)+(itemOrder[str2]*5) + itemOrder[str3])%7;
        int count = it.second; 
        for(int i=0; i<count; i++)
        hashBucket2[bucket].push_back(it.first); 
    }

    //This is for my own Hash Function
    map<int,vector<vector<string>>> hashBucket3;
    for(auto it: count_data_set_three) {
        string str1 = it.first[0]; 
        string str2 = it.first[1];
        string str3 = it.first[2];
        int bucket = ((itemOrder[str1]*10)+(itemOrder[str2]*3) + itemOrder[str3])%7;
        int count = it.second; 
        for(int i=0; i<count; i++)
        hashBucket3[bucket].push_back(it.first); 
    }


    cout<<"The Frequent ItemSets for two length are following: "<<endl; 
    for(auto it:hashBucket){
        if(it.second.size()>=3){
            cout<<"Bucket No: "<<it.first<<endl;
            vector<vector<string>> temp = it.second; 
            for(int i=0; i<temp.size(); i++){
                for(int j=0; j<temp[0].size(); j++){
                    cout<<temp[i][j]<<" ";  
                }
                cout<<endl; 
           }
        }
    }

    cout<<"The Frequent ItemSets for three length are following: "<<endl; 
    for(auto it:hashBucket2){
        if(it.second.size()>=3){
            cout<<"Bucket No: "<<it.first<<endl;
            vector<vector<string>> temp = it.second; 
            for(int i=0; i<temp.size(); i++){
                for(int j=0; j<temp[0].size(); j++){
                    cout<<temp[i][j]<<" ";  
                }
                cout<<endl; 
           }
        }
    }

    cout<<"The Frequent ItemSets for three length for my own Hash Function are following: "<<endl; 
    for(auto it:hashBucket3){
        if(it.second.size()>=3){
            cout<<"Bucket No: "<<it.first<<endl;
            vector<vector<string>> temp = it.second; 
            for(int i=0; i<temp.size(); i++){
                for(int j=0; j<temp[0].size(); j++){
                    cout<<temp[i][j]<<" ";  
                }
                cout<<endl; 
           }
        }else 
        cout<<" NULL"<<endl; 
    }


    return 0; 
}