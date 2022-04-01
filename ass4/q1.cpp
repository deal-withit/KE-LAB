//Kundan Kumar 

#include<bits/stdc++.h>
using namespace std;

int minSupCount = 2;
fstream write,read;
map<vector<string>,int> subsetFreq;


void subset(int i,vector<string> &A,vector<string> &S,vector<vector<string>> &Ans){
    if(i == A.size()){
        if(!S.empty()) Ans.push_back(S);
        return;
    }
    S.push_back(A[i]);
    subset(i+1,A,S,Ans);
    S.pop_back();
    subset(i+1,A,S,Ans);
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

map<vector<string>,int> findSubsetFreq(map<string,vector<string>> &data){
    map<vector<string>,int> subsetFreq;
    vector<string> S;
    vector<vector<string>> ss;
    unordered_set<string> setUnique;
    
    for(auto i : data){
        S.clear();
        ss.clear();
        subset(0,i.second,S,ss);
        for(auto k : ss) subsetFreq[k]++;
    }
    return subsetFreq;

}

vector<vector<string>> find(vector<string> &A,int i,int k){
    if(k == 0) return vector<vector<string>> {{}};
    vector<vector<string>> ans;
    for(int j = i;j < A.size();j++){
        vector<vector<string>> T=find(A,j+1,k-1);
        for(auto v:T){
            v.push_back(A[j]);
            ans.push_back(v);
        }
    }
    return ans;
}

vector<vector<string>> findKSubset(vector<string> A,int k){
    return find(A,0,k);
}

int main(){
    map<string,vector<string>> data = readData("database.txt");
    
    subsetFreq = findSubsetFreq(data);

    set<string> setUnique;
    int maxTransactions = 0;

    for(auto i : data){
        maxTransactions = max(maxTransactions,int(i.second.size()));
        for(auto k : i.second) setUnique.insert(k);
    }

    vector<string> uniqueItems(setUnique.begin(),setUnique.end());

    int K = 1;

    

    vector<vector<string>> temp2,answer;

    while(K <= maxTransactions){

        vector<vector<string>> lk_substet = findKSubset(uniqueItems,K);

        answer = temp2;
        temp2.clear();

        for(auto i : lk_substet){
            vector<string> temp = i; sort(temp.begin(),temp.end());
            if(subsetFreq[temp] >= minSupCount){
                bool check = 1;
                vector<vector<string>> res;
                vector<string> x;
                subset(0,temp,x,res);
                for(auto j : res){
                    if(subsetFreq[j] < minSupCount){
                        check = 0;
                        break;
                    }
                }
                if(check) temp2.push_back(temp);   
            }
        }

        cout<<"\nC"<<K<<" :\n";

        if(temp2.empty()) cout<<"Blank Item Set\n";
        else{
            for(auto i : temp2){
                for(auto k : i) cout<<k<<' ';
                cout<<'\n';
            }
        }

        if(temp2.empty()) break;
        
        
        setUnique.clear();
        uniqueItems.clear();
        
        for(auto i : temp2){
            for(auto k : i) setUnique.insert(k);
        }

        for(auto i : setUnique) uniqueItems.push_back(i);

        K++;
    }

    write.open("answer.txt",ios::out);
    cout<<"\n\nThe final Frequent ItemSets are following : \n\n";
    
    for(auto i : answer){
        for(auto k : i) cout<<k<<' ',write<<k<<' ';
        cout<<"\n\n",write<<"\n\n";
    }
}