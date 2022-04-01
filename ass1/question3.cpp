#include<bits/stdc++.h>
using namespace std;

int main(){
	map<char,int> m;
	string text;
	ifstream f1;
	f1.open("sample.txt");
	while(getline(f1,text)){
	  for(int i=3;i<text.length();i++)
	  {
	  	 if(isalpha(text[i]))
	  	 {		   
	  	  if(m.find(text[i])==m.end())
	  	  m[text[i]]=1;
	  	  else
	  	  m[text[i]]++;
	     }
	  }
	}
	ofstream f2;
	f2.open("sample3.txt");
   for (std::map<char,int>::iterator it=m.begin(); it!=m.end(); ++it)
   {
    std::cout << it->first << " " << it->second << '\n';
    f2<<it->first<<" "<<it->second<<"\n";  
   }
    f2.close();
	f1.close();
	return 0;
}
