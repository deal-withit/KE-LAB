#include<bits/stdc++.h>
using namespace std;

int main(){
	map<char,vector<string> > m;
	string text;
	ifstream file;
	file.open("sample.txt");
	while(getline(file,text)){
	  string tl=text.substr(0,2);
	  for(int i=3;i<text.length();i++)
	  {
	  	 if(isalpha(text[i]))
	  	 {		   
	  	  m[text[i]].push_back(tl);
	     }
	  }
	}
	ofstream file2;
	file2.open("sample4.txt");
   for (std::map<char,vector<string> >::iterator it=m.begin(); it!=m.end(); ++it)
   {
    std::cout << it->first<<" ";
    file2<<it->first<<" ";
     for(int i=0;i<it->second.size();i++)
     {
       std::cout << it->second[i]<<" ";
       file2<<it->second[i]<<" ";
   }
    cout<<endl;
    file2<<endl;
   }

	file.close();
	return 0;
}
