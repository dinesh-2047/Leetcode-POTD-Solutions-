// 2213. Longest Substring of One Repeating Character


struct Node{
    int maxLen, pref, suff; 
    char leftChar, rightChar; 
};

vector<Node> segTree;
Node merge(Node L , Node R, int leftLen , int rightLen){
    Node result; 
    result.leftChar = L.leftChar; 
    result.rightChar = R.rightChar; 

    result.pref = L.pref; 

    if(L.pref == leftLen && L.rightChar == R.leftChar){
        result.pref = L.pref + R.pref; 
    }

    result.suff = R.suff; 
    if(R.suff == rightLen && L.rightChar == R.leftChar){
        result.suff = R.suff + L.suff; 
    }

    result.maxLen = max(L.maxLen, R.maxLen);

    if(L.rightChar == R.leftChar){
        result.maxLen = max(result.maxLen , L.suff + R.pref);
    }

    return result; 

}

void build(int i, int l , int r, string &s){
     if(l == r){
        segTree[i] = {1, 1, 1, s[l] , s[l]};
        return ; 
    }
    int mid = l + (r-l)/2; 
    build(2*i + 1, l , mid, s);
    build(2*i + 2, mid + 1, r , s);

    segTree[i] = merge(segTree[2*i + 1], segTree[2*i + 2], mid-l+1, r-mid);
}



void update(int i , int l , int r, int idx, char ch){
    if(l == r){
        segTree[i] = {1, 1, 1, ch , ch};
        return ; 
    }
     int mid = l + (r-l)/2; 

     if(idx <= mid){
        update(2*i + 1, l , mid, idx, ch);

     }
     else {
        update(2*i + 2, mid + 1, r, idx , ch);
     }

     segTree[i] = merge(segTree[2*i+1], segTree[2*i+2], mid - l + 1, r - mid);

}




class Solution {
public:
int n , k; 
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        n = s.length();
        k = queryCharacters.length();
        segTree.resize(4*n, Node());

        build(0, 0, n-1, s);
        vector<int> result(k);
        for(int i = 0 ; i  < k; i++){
            char ch = queryCharacters[i];
            int idx = queryIndices[i];

            update(0, 0, n-1, idx, ch);
            result[i] = segTree[0].maxLen; 
        }
        return result; 
    }
};