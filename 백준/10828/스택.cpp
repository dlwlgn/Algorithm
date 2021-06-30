#include <iostream>
#include <string>

using namespace std;

int stack[100001];
int N, top = -1;

int main(){
    cin >> N; 
    for(int i=0; i<N; i++){
        string command;
        int number;
        cin >> command;
        if(command == "push") {
            cin >> number;
            stack[++top] = number;
        }
        else if(command == "top"){
            if(top == -1) cout << "-1\n";
            else cout << stack[top] << "\n";
        }
        else if(command == "size"){
            cout << top + 1 << "\n";
        }
        else if(command == "empty"){
            if(top == -1) cout << "1\n";
            else cout << "0\n";
        }
        else if(command == "pop"){
            if(top == -1) cout << "-1\n";
            else {
                cout << stack[top] << "\n";
                top--;
            }
        }
    }
}
