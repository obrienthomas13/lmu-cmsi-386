#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <stdexcept>

using namespace std;

int findIndex(vector< pair <string, int> > vec, string s){
  for(int i = 0; i < vec.size(); i++) {
    if(vec[i].first == s){
      return i;
    }
  }
  return -1;
}


int main() {

    string s = "Hello ha8pPy h/;^e78llo  23a8g a    da3^a#$y m8e hello";

    vector< pair <string, int> > potato;

    // Changes the string into lower case
    string sclone = "";
    for(int i = 0; i < s.length(); i++) {
      sclone += (char)tolower(s.at(i));
    }
    sclone += " ";
    int prev = 0;
    int current = 0;
    while(current < sclone.length()) {
      if(!isalpha(sclone.at(current))){
        if(prev != current) {
          if(findIndex(potato, sclone.substr(prev, current-prev)) == -1) {
            potato.push_back(make_pair(sclone.substr(prev, current-prev), 1));
          } else {
            potato[findIndex(potato, sclone.substr(prev, current-prev))].second++;
          }
          prev = current + 1;
        } else {
          prev++;
        }
      }
      current ++;
    }
    for(int i = 0; i < potato.size(); i++) {
      cout << potato[i].first << " : " << potato[i].second <<  '\n';
    }
	// cout<<"Vector " << sclone;
}
