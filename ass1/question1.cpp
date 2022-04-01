#include<bits/stdc++.h>
using namespace std; 

int main(){
    ofstream file; 
    file.open("sample.txt"); 
    file<<"T1 a b c e"<<endl<<"T2 b d f"<<endl<<"T3 a c d f"<<endl<<"T4 d f"<<endl<<"T5 c d e"; 
    file.close(); 
    return 0; 
}