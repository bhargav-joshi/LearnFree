/*
// C++ code to print all anagrams together 
#include <bits/stdc++.h>
using namespace std;

void solver(vector<string> my_list)
{
    
    // Inner hashmap counts frequency
    // of characters in a string.
    // Outer hashmap for if same
    // frequency characters are present in
    // in a string then it will add it to
    // the vector.
    map<map<char, int>, vector<string> > my_map;
    
    // Loop over all words
    for(string str : my_list)
    {
        
        // Counting the frequency of the
        // characters present in a string
        map<char, int> temp_map;
        vector<string> temp_my_list;
        for(int i = 0; i < str.length(); ++i) 
        {
            ++temp_map[str[i]];
        }
        
        // If the same frequency of chanracters
        // are alraedy present then add that
        // string into that arraylist otherwise
        // created a new arraylist and add that
        // string
        auto it = my_map.find(temp_map);
        if (it != my_map.end())
        {
            it->second.push_back(str);
        }
        else
        {
            temp_my_list.push_back(str);
            my_map.insert(make_pair(temp_map, temp_my_list));
        }
    }
    
    // Stores the result in a vector
    vector<vector<string> > result;

    for(auto it = my_map.begin();it != my_map.end(); ++it)
    {
        result.push_back(it->second);
    }

    for(int i = 0; i < result.size(); ++i) 
    {
          cout << "[";
        for(int j = 0; j < result[i].size(); ++j) 
        {
            cout << result[i][j] << ", ";
        }
          cout << "]";
    }
}

// Driver code
int main()
{
    vector<string> my_list= { "cat", "dog", "ogd", "god", "atc" };
    solver(my_list);
    return 0;
}
*/
// C++ program for finding all anagram
// pairs in the given array
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Utility function for
// printing anagram list
void printAnagram(
	unordered_map<string,
				vector<string> >& store)
{
	unordered_map<string,
				vector<string> >::iterator it;
	for (it = store.begin();
		it != store.end(); it++) {
		vector<string> temp_vec(it->second);
		int size = temp_vec.size();
		if (size >= 1) {
			for (int i = 0; i < size; i++) {
				cout << temp_vec[i] << " ";
			}
			cout << "\n";
		}
	}
}

// Utility function for storing
// the vector of strings into HashMap
void storeInMap(vector<string>& vec)
{
	unordered_map<string,
				vector<string> >
		store;
	for (int i = 0; i < vec.size(); i++) {

		string tempString(vec[i]);
		sort(tempString.begin(),
			tempString.end());

		// Check for sorted string
		// if it already exists
		if (store.find(
				tempString)
			== store.end()) {
			vector<string> temp_vec;
			temp_vec.push_back(vec[i]);
			store.insert(make_pair(
				tempString, temp_vec));
		}

		else {
			// Push new string to
			// already existing key
			vector<string> temp_vec(
				store[tempString]);
			temp_vec.push_back(vec[i]);
			store[tempString] = temp_vec;
		}
	}

	// print utility function for printing
	// all the anagrams
	printAnagram(store);
}

// Driver code
int main()
{
	// initialize vector of strings
	vector<string> arr;
	arr.push_back("geeksquiz");
	arr.push_back("geeksforgeeks");
	arr.push_back("abcd");
	arr.push_back("forgeeksgeeks");
	arr.push_back("zuiqkeegs");
	arr.push_back("cat");
	arr.push_back("act");
	arr.push_back("tca");

	// utility function for storing
	// strings into hashmap
	storeInMap(arr);
	return 0;
}
