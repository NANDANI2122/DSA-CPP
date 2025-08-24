#include<iostream>
#include<vector>
using namespace std;

void solve(vector <int> &nums, vector <int>output, int index, vector <vector<int>>&ans){
    if(index>=nums.size()){
        ans.push_back(output);
        return;
    }

    solve(nums,output,index+1,ans);
    output.push_back(nums[index]);
    solve(nums,output,index+1,ans);
    
}

int main(){

    int n;
    cin>>n;
    vector <int> nums(n);
    cout<<"Enter "<<n<<"elements:";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    vector <vector<int>> ans;
    vector <int> output;
    solve(nums, output, 0 ,ans);
        cout << "Subsets are: \n";
    for (auto subset : ans) {
        cout << "{ ";
        for (auto x : subset) {
            cout << x << " ";
        }
        cout << "}\n";
    }

    return 0;


}