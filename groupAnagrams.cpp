#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<vector<string>> groupAnagrams(vector<string> &strs)
	{
		unordered_map<string, vector<string>> m;
		for (string s : strs)
		{
			auto t = s;
			sort(t.begin(), t.end());
			auto res = m.find(s);
			m[t].push_back(s);
		}

		vector<vector<string>> ans;
		for (auto pair : m)
		{
			ans.push_back(pair.second);
		}
		return ans;
	};
};

void test()
{
	vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
	vector<vector<string>> ans = {{"bat"}, {"tan", "nat"}, {"eat", "tea", "ate"}};
	assert(Solution().groupAnagrams(strs) == ans);

	strs = {""};
	ans = {{""}};
	assert(Solution().groupAnagrams(strs) == ans);

	strs = {"a"};
	ans = {{"a"}};
	assert(Solution().groupAnagrams(strs) == ans);
}

int main()
{
	test();
	return 0;
}
