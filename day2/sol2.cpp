#include <sstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;



vector<int> tokenize(string input, const char delim){
        vector<int> out;
        istringstream iss(input);
        string temp;

        while(getline(iss, temp, delim)){
                out.push_back(atoi(temp.c_str()));
        }
        cout << out.size() << endl;
        return out;
}

bool isIncOrDec(vector<int> input){
        int balance = 0;
	bool slip_allowed = true;

        for(int i = 1; i < input.size(); i++){
                int dif = input[i] - input[i-1];
                // no dif or too much dif
                if(dif == 0 || abs(dif) > 3){
			if(slip_allowed){
				slip_allowed = false;
                                input.erase(input.begin()+i);
                                i--;
				continue; 
			}else{
				return false;
			}
		}
                //
                if(dif >= 1) balance += 1;
                else         balance -= 1;
        }
 
        if(abs(balance) == input.size()-1) return true;
        if(abs(balance) >= input.size()-
        return false;
}

int main(){

        string lineIn;
        int sumOfSafe = 0;


        while(getline(cin, lineIn)){
                vector<int> data = tokenize(lineIn, ' ');
                if(isIncOrDec(data)) sumOfSafe++;
        }

        cout << sumOfSafe << endl;
        return 0;
}
