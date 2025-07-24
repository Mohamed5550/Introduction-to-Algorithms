#include <iostream>
#include <string>
#include <vector>

using namespace std;

string generatePrefix(string &s, int k)
{
    string prefix = "";
    for(int i = 0; i < k; i ++) {
        prefix += s[i];
    }

    return prefix;
}

bool isSuffix(string &p, string &s)
{
    if(p.size() == 0) return true;
    int j = s.size() - 1;
    for(int i = p.size() - 1; i >= 0; i --, j --) {
        if(p[i] != s[j]) return false;
    }

    return true;
}

vector <vector<int>> computeTransitionFunction(string &P)
{
    int m = P.size();
    vector <vector<int>> delta(m + 1, vector<int>(26));
    string currentPrefix = "";
    for(int i = 0; i <= m; i ++) {
        for(int j = 0; j < 26; j ++) {
            int k = min(m, i + 1);
            currentPrefix.push_back('a' + j);
            string decreasingPrefix = generatePrefix(P, k);
            while(!isSuffix(decreasingPrefix, currentPrefix)) {
                k --;
                decreasingPrefix.pop_back();
            }
            currentPrefix.pop_back();
                // if(i == 0 && j == 0) cout << "\n" << decreasingPrefix << " " << currentPrefix << " " << isSuffix(decreasingPrefix, currentPrefix) k << " " << "\n";
            delta[i][j] = k;
        }
        currentPrefix.push_back(P[i]);
    }

    return delta;
}

void matchWithFiniteAutomaton(string &T, string &P)
{
    vector<vector<int>> delta = computeTransitionFunction(P);
    int currentState = 0;
    int n = T.size();
    int m = P.size();

    for(int i = 0; i < T.size(); i ++) {
        currentState = delta[currentState][T[i] - 'a'];
        if(currentState == m) {
            cout << "Pattern occurs with shift " << i - m + 1 << "\n";
        }
    }
}

int main()
{
    // T is the main string, P is the pattern
    string T, P; cin >> T >> P;

    matchWithFiniteAutomaton(T, P);
}
