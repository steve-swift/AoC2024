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
        return out;
}

bool isIncOrDec(vector<int> input){
        int balance = 0;

        for(int i = 1; i < input.size(); i++){
                int dif = input[i] - input[i-1];
                // no dif or too much dif
                if(abs(dif) == 0 || abs(dif) > 3) return false;
                //
                if(dif >= 1) balance += 1;
                else         balance -= 1;
        }

        if(abs(balance) == input.size()-1) return true;
        return false;
}

int main(){

        string lineIn;
        int sumOfSafe = 0;


        while(getline(cin, lineIn)){
                vector<int> data = tokenize(lineIn, ' ');
                for(int i = 0; i < data.size(); i++){
			vector<int> tmp = data; 
			tmp.erase(tmp.begin()+i);
			if(isIncOrDec(tmp)){
				sumOfSafe++;
				break;
			}
		}
        }

        cout << sumOfSafe << endl;
        return 0;
}
