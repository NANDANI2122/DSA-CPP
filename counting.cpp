#include<iostream>
using namespace std;

void tailcounting(int n){
    if(n<=0) return;
    tailcounting(n-1);
    cout<<n<<endl;
}

void headcounting(int n){
    if(n<=0) return;
    cout<<n<<endl;    
    headcounting(n-1);

}
int main(){
    int n;
    cin>>n;
    cout<<endl;
    tailcounting(n);
    cout<<endl;
    headcounting(n);
}

