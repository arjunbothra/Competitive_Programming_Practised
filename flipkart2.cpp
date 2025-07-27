// #include<bits/stdc++.h>

// using namespace std;

// void findMostRecurrentSequences(int N, vector<string> &keywords)
// {
//     // A map to store substrings and their counts.
//     map<string, int> counts;

//     // Step 1: Generate all substrings of length >= 3 and count their occurrences.
//     for (const string &keyword : keywords)
//     {
//         for (int i = 0; i < keyword.length(); ++i)
//         {
//             for (int len = 3; i + len <= keyword.length(); ++len)
//             {
//                 string sub = keyword.substr(i, len);
//                 counts[sub]++;
//             }
//         }
//     }

//     vector<string> result_permutations;

//     // Step 2 & 3: Find recurring substrings and compute their next permutation.
//     for (auto const &[substring, count] : counts)
//     {
//         if (count > 1)
//         {
//             string perm = substring; // Make a copy to modify.

//             // std::next_permutation works in-place and returns false if it's already the last permutation.
//             if (next_permutation(perm.begin(), perm.end()))
//             {
//                 // A next permutation was found.
//                 result_permutations.push_back(perm);
//             }
//             else
//             {
//                 // It was the last permutation, so use the original substring as per the problem description.
//                 result_permutations.push_back(substring);
//             }
//         }
//     }

//     // Step 4: Sort the final results alphabetically.
//     sort(result_permutations.begin(), result_permutations.end());

//     // Print the sorted results in a single line, space-separated.
//     for (int i = 0; i < result_permutations.size(); ++i)
//     {
//         cout << result_permutations[i] << (i == result_permutations.size() - 1 ? "" : " ");
//     }
// }

// // The boilerplate main function provided in the problem.
// int main()
// {
//     int N;
//     cin >> N;
//     cin.ignore(); // Important: Consumes the newline character after reading N.

//     string line;
//     getline(cin, line);

//     vector<string> keywords;
//     stringstream ss(line);
//     string keyword;
//     while (ss >> keyword)
//     {
//         keywords.push_back(keyword);
//     }

//     findMostRecurrentSequences(N, keywords);

//     return 0;
// }

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

void findMostRecurrentSequences(int N, vector<string>& keywords) {
    // A map to store substrings and their counts.
    map<string, int> counts;

    // Step 1: Generate all substrings of length >= 3 and count their occurrences.
    for (const string& keyword : keywords) {
        for (int i = 0; i < keyword.length(); ++i) {
            for (int len = 3; i + len <= keyword.length(); ++len) {
                string sub = keyword.substr(i, len);
                counts[sub]++;
            }
        }
    }

    vector<string> result_permutations;

    // Step 2 & 3: Find recurring substrings and compute their next permutation.
    for (auto const& [substring, count] : counts) {
        if (count > 1) {
            string perm = substring; // Make a copy to modify.
            
            // std::next_permutation works in-place and returns false if it's already the last permutation.
            if (next_permutation(perm.begin(), perm.end())) {
                // A next permutation was found.
                result_permutations.push_back(perm);
            } else {
                // It was the last permutation, so use the original substring as per the problem description.
                result_permutations.push_back(substring);
            }
        }
    }

    // Step 4: Sort the final results alphabetically.
    sort(result_permutations.begin(), result_permutations.end());

    // Print the sorted results in a single line, space-separated.
    for (int i = 0; i < result_permutations.size(); ++i) {
        cout << result_permutations[i] << (i == result_permutations.size() - 1 ? "" : " ");
    }
}

// The boilerplate main function provided in the problem.
int main() {
    int N;
    cin >> N;
    cin.ignore(); // Important: Consumes the newline character after reading N.

    string line;
    getline(cin, line);

    vector<string> keywords;
    stringstream ss(line);
    string keyword;
    while (ss >> keyword) {
        keywords.push_back(keyword);
    }
    
    findMostRecurrentSequences(N, keywords);
    
    return 0;
}