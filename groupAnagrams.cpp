#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // add your code
    }
};

void test(){
	vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
	vector<vector<string>> ans = {{"bat"},{"tan","nat"},{"eat","tea","ate"}};
	assert(Solution().groupAnagrams(strs) == ans);
	
	strs = {""};
	ans = {{""}};
	assert(Solution().groupAnagrams(strs) == ans);
	
	strs = {"a"};
	ans = {{"a"}};
	assert(Solution().groupAnagrams(strs) == ans);
}

int main(){
	test();
	return 0;
}
