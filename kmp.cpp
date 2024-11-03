

/*
# KMP.cpp

this algorithm returns the start index of the position where pattern is found in the text (in 1 based indexing).

If the pattern is not found - returns 0.

*/

vector<int> computelps(string pat) {
    int n = pat.size();
    vector<int> lps(n, 0);
    for (int i = 1; i < n; i ++) {
        int j = 0;
        while (pat[i] == pat[j]) {
            lps[i] = lps[i-1] +1;
            i++, j ++;
        }
    }
    return lps;
}
int kmp (string txt, string pat) {
    int n = txt.size(), m = pat.size();
    int it = 0, ip = 0;
    
    vector<int> lps = computelps(pat);

    while (it < n && ip < m) {
        if (txt[it] == pat[ip]) {
            it++, ip++;
            if (ip >= m) return (it - ip + 1);
        } 
        else if (lps[ip] > 0) {
            it = it - ip + lps[ip] + 1;
            ip = lps[ip];
        } else {
            it = it - ip + 1;
            ip = 0;
        }
    }
    return 0;
}