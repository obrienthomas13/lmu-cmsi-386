#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <stdexcept>
#include <algorithm>

using namespace std;

// Returns the index of a given string in a vector, or -1 if string doesnt exist yet
int findIndex(vector< pair <string, int> > vec, string s){
  for(int i = 0; i < vec.size(); i++) {
    if(vec[i].first == s){
      return i;
    }
  }
  return -1;
}

bool sortFunction(const pair<string, int> &a, const pair<string, int> &b) {
  return a.second>b.second;
}

int main() {

    string s;
    getline(cin, s);

    vector< pair <string, int> > vec;

    // Changes the string into lower case
    string sclone = "";
    for(int i = 0; i < s.length(); i++) {
      sclone += (char)tolower(s.at(i));
    }
    // Adds a empty char at the end so the parse gets the last character
    sclone += " ";
    int prev = 0;
    int current = 0;
    // Loops through the length of the string
    while(current < sclone.length()) {
      if(!isalpha(sclone.at(current))){
        // This is the case that we have a desired string next
        if(prev != current) {
          if(findIndex(vec, sclone.substr(prev, current-prev)) == -1) {
            vec.push_back(make_pair(sclone.substr(prev, current-prev), 1));
          } else {
            vec[findIndex(vec, sclone.substr(prev, current-prev))].second++;
          }
          prev = current + 1;
        // This is the case that we have 2+ undesired characters in a row
        } else {
          prev++;
        }
      }
      current ++;
    }

    sort(vec.begin(), vec.end(), sortFunction);

    // Prints out the whole vector
    for(int i = 0; i < vec.size(); i++) {
      cout << vec[i].first << " " << vec[i].second <<  '\n';
    }
}
