#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> computeTransitionFunction(string p)
{
    int m = p.size();
    vector <int> trans(m);
 
    int k = 0;
    for(int i = 1; i < m; i ++) {
        while(k > 0 && p[k] != p[i]) {
            k = trans[k-1];
        }
 
        if(p[k] == p[i]) k ++;
 
        trans[i] = k;
    }
 
    return trans;
}
 
vector <vector<int>> computeAutomatonFunction(string p)
{
    int m = p.size();
    vector <int> pi = computeTransitionFunction(p);
    vector <vector<int>> delta(m+1, vector<int>(26));
 
    delta[0][p[0] - 'a'] = 1;
 
    for(int i = 1; i <= m; i ++) {
        for(int j = 0; j < 26; j ++) {
            if(i == m || p[i] != j + 'a') {
                delta[i][j] = delta[pi[i-1]][j];
            } else {
                delta[i][j] = i + 1;
            }
 
        }
    }
 
    return delta;
}
 

void matchWithFiniteAutomaton(string &T, string &P)
{
    vector<vector<int>> delta = computeAutomatonFunction(P);
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
