#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;
int main(){


        priority_queue<int> q1, q2;
        unordered_map<int, int> map;
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


        while(!q2.empty()){

                map[q2.top()] += q2.top();
                q2.pop();

        }

        while(!q1.empty()){


                sum += map[q1.top()];
                q1.pop();

        }

        cout << sum << endl;

        return 0;

}
