public class Manacher {
public:
  /*
  *
  * The O(n) algorithm to find the index of center of longest palindrome substring of the given string.
  * p[i] is the half length of palindrome string whose center index is i.
  *
  */
  int IdxofLongestPalindromeSubstr(string s){
    int idx = 0, res = 0;
    int n = s.size();
    string s1;
    s1.resize(2*n + 2);
    vector<int> p(2*n + 10, 0);
    s1[0] = '$';
    s1[1] = '#';
    for(int i = 0; i < n; ++ i){
        s1[(i + 1)<<1] = s[i];
        s1[((i + 1)<<1) + 1] = '#';
    }
    for(int id = 0, i = 1; i < s1.size(); ++ i){
        if(p[id] + id > i)
            p[i] = min(p[2*id - i], p[id] + id - i);
        else
            p[i] = 1;
        while(s1[p[i] + i] == s1[i - p[i]]) ++ p[i];
        if(i + p[i] > id + p[id])
            id = i;
        if(res < p[i]){
          res = max(res, p[i]);
          idx = i;
        }
    }
    //return the idx of center of longest palindrome substring
    //res is the length of longest palindrome substring
    return idx/2 - 1;
  }
}
