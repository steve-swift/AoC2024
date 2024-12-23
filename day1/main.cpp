#include <iostream>
#include <queue>
#include <string>


using namespace std;
int main(){


        priority_queue<int> q1, q2;

        int num1, num2;
        string lineIn;


        while(getline(cin, lineIn)){
                int first_space = lineIn.find_first_of(' ');
                int last_space = lineIn.find_last_of(' ');

                num1 = atoi(lineIn.substr(0, first_space).c_str());
                num2 = atoi(lineIn.substr(last_space+1, lineIn.size()).c_str());

                q1.push(num1);
                q2.push(num2);
        }


        int sum = 0;


        while(!q1.empty()){

                int element = abs(q1.top() - q2.top());
                sum += element;

                q1.pop();
                q2.pop();

        }

        cout << sum << endl;

        return 0;

}
