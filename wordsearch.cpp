#include<iostream>
#include<vector>
#include<string>
using namespace std;


bool isSafe(int i,int rows,int j,int cols,vector<vector<int>>&visited){
    if(i<0 || i>=rows ||j<0 ||j >= cols || visited[i][j] != 0) 
        return false; 
    return true; //matrix ke andr hona chahiye aur visited 0 hona chahiye
}

bool exist(vector<vector<char>>&matrix,int rows,int cols, string &word,int k,int i,int j,vector<vector<int>>&visited){

    //base case
    if(k==word.size()) return true; //pooora word milgya

    if(matrix[i][j] != word[k]) return false;     //letter match krna chahiye
                
    visited[i][j]=1;
    if(isSafe(i-1,rows,j,cols,visited) &&  exist(matrix,rows,cols,word,k+1,i-1,j,visited)) return true; //up: (rows-1,cols)                
    if(isSafe(i+1,rows,j,cols,visited) && exist(matrix,rows,cols,word,k+1,i+1,j,visited)) return true; //down: (rows+1,cols)
    if(isSafe(i,rows,j-1,cols,visited) && exist(matrix,rows,cols,word,k+1,i,j-1,visited)) return true;//left: (rows,cols-1)
    if(isSafe(i,rows,j+1,cols,visited) && exist(matrix,rows,cols,word,k+1,i,j+1,visited)) return true;//right: (rows,cols+1)
    visited[i][j]=0;

    return false;
            
};      
    
int main() {
    int rows,cols;
    cout<<"Enter no of rows:";
    cin>>rows;
    cout<<"Enter no of cols:";
    cin>>cols;

    vector<vector<char>>matrix(rows,vector<char>(cols));
    
    cout<<"Input matrix:"<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cin>>matrix[i][j];
        }
    }
    cout<<"Output matrix:"<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<matrix[i][j]<<" ";
        }
       
        cout<<endl;
    }
   
    //input string
    string str;
    cout<<"Input the string to search"<<endl;
    cin>>str;

    //temp matrix with all elements 0
    vector<vector<int>> visited(rows,vector<int>(cols,0));

    //check for first word
    int k=0;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(str[k]==matrix[i][j]){ //first letter match
                //visited[i][j]=1; 
                if(exist(matrix,rows,cols,str,k,i,j,visited)){
                    cout<<"Word found!"<<endl;                    
                }
                else cout<<"Word not found"<<endl;
            } 
        }
    } 
 
    return 0; 
}
