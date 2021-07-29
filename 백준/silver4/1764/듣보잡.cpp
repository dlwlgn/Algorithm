#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N, M;
    
    cin >> N >> M;
    
    vector<string> v(N);
    vector<string> sol;
    string temp;
    for(int i=0; i<N; i++){
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());
    
    for(int i=0; i<M; i++){
        cin >> temp;
        int low = 0, high = N-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(temp == v[mid]){
                sol.push_back(temp);
                break;
            }
            else if(temp > v[mid]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
            
        }
    }
    
    sort(sol.begin(), sol.end());
    
    int len = sol.size();
    cout << len << "\n";
    for(int i=0; i<len; i++){
        cout << sol[i] << "\n";
    }
}