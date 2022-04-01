/*
   Author : Kundan Kumar, RollNo:207929
   Question 01: Implement any 3 missing values 
   techniques, considering 20 random values with 2 missing position 
*/
#include<bits/stdc++.h>
using namespace std;

/*
    Method 01: Skipping all the occurences which are Emppty. 
*/
void SkipEmptyTuple(vector<string>&str)
{
	cout<<"Skipping the Empty Tuples :"<<endl;
    //Finding the first occurence which is empty.
    vector<string>::iterator itr =find(str.begin(), str.end(), ""); 
    while(itr != str.end())
    {
      str.erase(itr);
      itr=find(str.begin(), str.end(), "");
    }
    for(int i=0;i<str.size();i++)
    cout<<str[i]<<" ";
    for(auto it:str)
    cout<<it<<" ";
    cout<<endl; 
}

/*
    Method 02: Placing all the occurences with "Empty" which are Empty. 
*/
void UsingGlobal(vector<string>&str)
{
	cout<<"Using Global Constant :"<<endl;
    for(int i=0;i<str.size();i++)
    { 
      if(str[i]=="")
      str[i]="Empty";
    }

    //Printing the updated vector. 
    for(int i=0;i<str.size();i++)
    cout<<str[i]<<" ";
    cout<<endl<<endl; 
}


/*
    Method 03: Using the Mean of Data. 
*/
void FillwithMean(vector<string>&str)
{
	int sum=0;
    int count=0;
    for(int i=0;i<str.size();i++)
    {   
       if(str[i]=="")
        continue;
       sum=sum+stoi(str[i]);
       count++;
    }

    int mean=sum/count;

    cout<<"Using Mean of Available data: "<<endl;
    for(int i=0;i<20;i++)
    { if(str[i]=="")
      str[i]=to_string(mean);
    }

    for(int i=0;i<str.size();i++)
    cout<<str[i]<<" ";
    cout<<"\n\n";
}
int main()
{
    //Initializing a Vector with 20 random string valules.
    vector<string>str={
        "221","222","223",
        "224","","998","997",
        "996","919","290","354",
        "865","123","","152","167",
        "345","864","125","333"
    };
    
    //Printing all the stored values. 
    cout<<"20 Random stored values are : "<<endl; 
    for(int i=0; i<str.size(); i++){
        cout<<str[i]<<" "; 
    }
    cout<<endl; 
    
    FillwithMean(str);
    UsingGlobal(str);
    SkipEmptyTuple(str);
    return 0;
}

