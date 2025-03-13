#include <iostream>
#include <string>
#include <vector>
/*
(1) (6 marks) Consider a variation of the brute-force string matching problem. Given a
text string p, we try to find a longest substring (whose length ≥ L) in p that matches with
the first characters of a pattern string t.
For instance, let p = “I have an int variable in my program”. If L = 3 and t = “variable”,
then of course we can find that the whole pattern t appears in p.
If L = 3 and t = “integer”, we can only find that substring “int” should be returned, since
it satisfies the minimum length L and matches the first characters in t.
If L = 3 and t = “another”, we cannot find any substring that satisfies the conditions.
Though “an” in p matches the first characters of t but its length < L.
Design a brute-force algorithm to solve the problem. If there are many substrings that
satisfy the conditions, report all of them.
*/
//input: text t[0..n-1], pattern p[0..m-1], length l
//output: array of substrings that satisfy the condition
#include <vector>
#include <string>

std::vector<std::string> BruteForceStringMatch(std::string t, std::string p, int l) {
    std::vector<std::string> subStrings;

    int n = t.size();
    int m = p.size();

    // Iterate over each possible starting position in the text t.
    for (int i = 0; i < n - l; i++) {
        std::string currentMatch = "";

        // Compare characters starting from t[i] with p.
        int j = 0;
        while (i + j < n && j < m && t[i + j] == p[j]) {
            currentMatch += t[i + j];
            j++;
            
            // If the matched substring's length is at least l, add it to the result.
            if (j >= l) {
                subStrings.push_back(currentMatch);
            }
        }
    }

    return subStrings;
}
/*
Algorithm BruteForceStringMatch(t[0..n-1], p[0..m-1], l)
//input: Strings t, p. integer l
//output: array of subStrings greater than equal to length l found both in t & p

initialize vector subStrings //(bro i cant submit c++ im trying my best to write pseudo)
additions <- 0
for i <-0 to n-l
    currentMatch <- "" //bro allow this one too like reset that local variable
    j <- 0
    while i + j < n and j < m and t[i+j] == p[j] do
        currentMatch <- currentMatch + t[i+j]
        j <- j + 1
        if (j >= l) substrings[additions] <- currentMatch //add currentmatch to array subStrings.

return subStrings
*/



int BruteForeStringMatch(std::string t, std::string p) {
    int j = 0;
    int n = t.size(), m = p.size();
    for (int i = 0; i < n-m; i++) {     //from start of text t till t's end minus pattern p's length
        j = 0; //represents char matching
        while (j < m && p[j] == t[i+j]) {   //while matching is less than p, && match between p chars and t chars
            j++;}       //index j++
        if (j == m) return i; //if  reached the end of pattern and all matched return index where first char match is (i), otherwise repeat i++ and j=0
    }
    return -1; // no match
}
int main() {
    // std::string t = "NOBODY_NOICED_HIM", p = "NOT";
    // std::cout << BruteForeStringMatch(t, p);
    std::string text = "I have an int variable in my program";
    std::string pattern = "variable";
    int minLength = 3;

    std::vector<std::string> matches = BruteForceStringMatch(text, pattern, minLength);

    // Output the matches.
    for (const std::string& match : matches) {
        std::cout << match << std::endl;
    }
    std::cout << '\n';
    return 0;
}
