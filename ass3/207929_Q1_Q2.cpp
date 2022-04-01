/*
   Author : Kundan Kumar, RollNo:207929
   MID LAB EXAM (KE Lab)
   Date : 13th March 2022
   Question 01 : 
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{

    int No_of_data=6; //No. of data 
    // Inputting all the datasets given in the question. 
    vector<vector<float>> a{
        {1.4,1.6},
        {1.5,-0.7},
        {0.8,-0.6},
        {-0.7,-1.7},
        {2.5,2.8},
        {3.21,1.56}
    };

    cout << "After Performing Normalization we get : " << endl;
    //Finding mean of both the attributes. 
    float mean_for_A1,mean_for_A2;
    int sum_A1=0,sum_A2=0;
    for (int i = 0; i < No_of_data; i++){
        sum_A1+=a[i][0];
        sum_A2+=a[i][1];
    }

    //These are the means of attributes. 
    mean_for_A1 = (sum_A1 / No_of_data);
    mean_for_A2 = (sum_A2 / No_of_data);
    float tmp1 = 0,tmp2 = 0, SD_A1,SD_A2;

    //Calculating the required data for finding Standard Deviation.
    for (int i = 0; i < No_of_data; i++){
        tmp1 = tmp1 + pow(a[i][0] - mean_for_A1, 2);
        tmp2 = tmp2 + pow(a[i][1] - mean_for_A2, 2);
    }

    //Final standard Deviatitions for both attributes. 
    SD_A1 = sqrt(tmp1 / No_of_data);
    SD_A2 = sqrt(tmp2 / No_of_data);

    //Printing the final normalized data. 
    for (int i = 0; i < No_of_data; i++){
        cout<<float(a[i][0] - mean_for_A1) / SD_A1<<"   "<<float(a[i][1] - mean_for_A2) / SD_A2<<endl;
    }

    cout << endl;
    return 0;
}

/*
   APPROACH: 
   I have normalized the data according to following steps.
   Step 1 :  Calculated the mean of both attribute column. 
   Step 2 : Calculated the Standard Deviation of all the data. 
   Step 3 : According to the formula of Normalization I printed the data. 

   OUTPUT: 
   After Performing Normalization we get : 
    0.302745   0.962692
    0.378431   -0.421178
    -0.151373   -0.361009
    -1.28667   -1.02286
    1.13529   1.68471 
    1.67267   0.938624
*/

/*
  Question 02 : 

*/
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

/*
  OUTPUT for Question 02:

  C1 :
Apple
Corn
Eggs
Ice_cream
Kidney_Beans
Nutmeg
Onion
Unicorn
Yogurt

C2 :
Apple Corn
Apple Eggs
Apple Kidney_Beans
Apple Unicorn
Apple Yogurt
Corn Yogurt
Eggs Kidney_Beans
Eggs Unicorn
Eggs Yogurt
Kidney_Beans Unicorn
Kidney_Beans Yogurt
Nutmeg Unicorn
Nutmeg Yogurt
Onion Unicorn
Onion Yogurt
Unicorn Yogurt

C3 :
Apple Corn Yogurt
Apple Eggs Unicorn
Apple Eggs Yogurt
Apple Kidney_Beans Unicorn
Apple Kidney_Beans Yogurt
Apple Unicorn Yogurt
Eggs Kidney_Beans Unicorn
Eggs Kidney_Beans Yogurt
Eggs Unicorn Yogurt
Kidney_Beans Unicorn Yogurt
Nutmeg Unicorn Yogurt
Onion Unicorn Yogurt

C4 :
Apple Eggs Unicorn Yogurt
Apple Kidney_Beans Unicorn Yogurt
Eggs Kidney_Beans Unicorn Yogurt

C5 :
Blank


Final frequent itemsets found are :

Apple Eggs Unicorn Yogurt

Apple Kidney_Beans Unicorn Yogurt

Eggs Kidney_Beans Unicorn Yogurt
*/

/*
   Justifications for Question 02:
   a. (Kidney Beans, Eggs, Onion) is the largest frequent itemset.
    ANS --> No, because for this itemset, the support count is less than 0.5. 

    b. There are exactly 9 frequent itemsets.
    ANS --> This statement is false because there are 3 frequent itemset

    c. There are exactly 10 frequent itemsets.
    ANS --> This statement is false because there are 3 frequent itemset

    d. (Kidney Beans, Eggs) is the most frequent itemset of size 2.
    ANS --> Yes, this statement is true. Because it is one of the most frequent itemset of size 2. 


    e. No frequent itemset has support 0.8
    ANS --> This statement is false because there is one itemset whose support count is 0.8 which are eggs and kidney_beans

    f. (Eggs, Yogurt) has support 0.5.
    ANS --> No , The support count of Eggs and Yogurt is not 0.5
*/