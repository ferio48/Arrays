#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3+10;

int findUnique(vector<int> &nums)
{
	int n = nums.size();
	
	int frq[n] = {0};
	
	for(int i = 0; i < n; ++i)
	{
		frq[nums[i]]++;
	}
	
	for(int i = 0; i < n; ++i)
	{
		if(frq[i] == 1)
			return i;
	}
}

//Second Approach
int findUnique2(vector<int> &nums)
{
	int ans = 0;
	
	for(int i = 0; i < nums.size(); ++i)
	{
		ans = ans^nums[i]; //using XOR operation
		
		cout << "ans: " << ans << " ";
	}
	cout << endl;
	return ans;
}

bool uniqueNumberOfOccurences(vector<int> &arr)
{
	unordered_map<int, int> mp;
	for(int i: arr)
	{
		mp[i]++;
	}
	
	for(auto it: mp)
	{
		cout << it.first << " " << it.second << endl;
	}
	cout << "end" << endl;
	
	set<int> s;
	for(auto it = mp.begin(); it != mp.end(); it++)
	{
		s.insert(it->second);
	}
	
	for(auto it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	
	if(s.size() == mp.size())
		return true;
	else
		return false;
}

vector<int> IntersectionOfTwoArrays(vector<int> &arr1, vector<int> &arr2)
{
	// first of all sort all given arrays 
	int i = 0, j = 0;
	vector<int> ans;
	while(i < arr1.size() && j < arr2.size())
	{
		if(arr1[i] < arr2[j])
		{
			i++;
		}
		else if(arr1[i] > arr2[j])
		{
			j++;
		}
		else if(arr1[i] == arr2[j])
		{
			ans.push_back(arr1[i]);
			i++;
			j++;
		}
	}
	
	set<int> s;
	for(int x: ans)
	{
		s.insert(x);
	}
	
	vector<int> res(s.begin(), s.end());
	
	return res;
}

vector<pair<int, int>> pairSum(vector<int> &nums, int sum)
{
	sort(nums.begin(), nums.end());
	
	vector<pair<int ,int>> ans;
	
	int i = 0, j = nums.size()-1;
	
	while(i < j)
	{
		int x = nums[i] + nums[j];
		
		if(x < sum)
		{
			i++;
		}
		else if(x > sum)
		{
			j--;
		}
		else if(x == sum)
		{
			ans.push_back({nums[i], nums[j]});
			i++;
			j--;
		}
	}
	
	return ans;
}

void tripletWithGivenSumRecursion(int ind, vector<int> &nums, int sum, vector<int> &ds, vector<vector<int>> &ans)
{
	if(sum == 0 && ds.size() == 3)
	{
		ans.push_back(ds);
		return;
	}
	
	for(int i = ind; i < nums.size(); ++i)
	{
		if(i > ind && nums[i] == nums[i-1]) continue;
		
		if(nums[i] > sum) break;
		
		ds.push_back(nums[i]);
		tripletWithGivenSumRecursion(i+1, nums, sum - nums[i], ds, ans);
		
		ds.pop_back();
	}
}

vector<vector<int>> tripletWithGivenSum(vector<int> &nums, int sum)
{
	sort(nums.begin(), nums.end());
	
	vector<int> ds;
	vector<vector<int>> ans;
	
	tripletWithGivenSumRecursion(0, nums, sum, ds, ans);
	
	return ans;
}

void sort012(vector<int> &nums)
{
	int low = 0, mid = 0, high = nums.size()-1;

	while(mid <= high)
	{
		switch(nums[mid])
		{
			case 0:
			swap(nums[low], nums[mid]);
			low++;
			mid++;
			break;
			
			case 1:
			mid++;
			break;
			
			case 2:
			swap(nums[mid], nums[high]);
			high--;
			break;
		}
	}
}

int main()
{
	vector<int> nums = {0,1,1,0,1,2,1,2,0,0,0,1};
	// int sum = 6;
	
 // 	vector<vector<int>> ans;
 	
 // 	ans = tripletWithGivenSum(nums, sum);
 	
 // 	for(int i = 0; i < ans.size(); ++i)
 // 	{
 // 		for(int j = 0; j < ans[i].size(); ++j)
 // 		{
 // 			cout << ans[i][j] << " ";
 // 		}
 // 		cout << endl;
 // 	}
 // 	cout << endl;
	sort012(nums);
	
	for(int i = 0; i < nums.size(); ++i)
	{
		cout << nums[i] << " ";
	}
	cout << endl;
	
	return 0;
}