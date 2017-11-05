#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <stdexcept>

using namespace std;

int main() {

    string s = "Hello ha8pPy   day m8e";

    vector< pair <string, int> > potato;

    // Changes the string into lower case
    string sclone = "";
    for(int i = 0; i < s.length(); i++) {
      sclone += (char)tolower(s.at(i));
    }

    int prev = 0;
    int current = 0;
    while(current < sclone.length()) {
      if(sclone.at(current) == ' '&& prev != current){
        potato.push_back(make_pair(sclone.substr(prev, current-prev), 1));
        prev = current + 1;
        current ++;
      }
      if(prev == current && sclone.at(current) == ' '){
        prev++;
      }
      current ++;
    }
    potato.push_back(make_pair(sclone.substr(prev, current-prev), 1));


    for(int i = 0; i < potato.size(); i++) {
      cout << potato[i].first << " : " << potato[i].second <<  '\n';
    }
	// cout<<"Vector " << sclone;
}
