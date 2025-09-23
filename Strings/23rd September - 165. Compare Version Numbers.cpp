// 165. Compare Version Numbers


// Appraoch 1
class Solution {
public:


    int compareVersion(string version1, string version2) {
        int n1 = version1.length();
        int n2 = version2.length();

        vector<string>revisions1; 
        vector<string>revisions2; 

        int st = 0 ; 
        for(int i = 0 ; i < n1; i++){
            if(version1[i] == '.'){
                string rev = version1.substr(st , i - st);
                revisions1.push_back(rev);
                st = i +1; 
            }
        }
         string revv = version1.substr(st );
                revisions1.push_back(revv);

        st = 0 ; 
        for(int i = 0 ; i < n2; i++){
            if(version2[i] == '.'){
                string rev = version2.substr(st , i - st);
                revisions2.push_back(rev);
                st = i +1; 
            }
        }
         string rev = version2.substr(st);
                revisions2.push_back(rev);


        for(int i = 0 ; i  < max(revisions1.size(), revisions2.size()); i++){
            int r1 = i < revisions1.size() ? stoi(revisions1[i]) : 0;
            int r2 = i < revisions2.size() ? stoi(revisions2[i]) : 0 ;

            if(r1 < r2) return -1; 
            if(r1 > r2)  return 1; 
        }
        return 0; 

        
    }
};







//Approach 2
class Solution {
public:
vector<string> getRevisions(string version){
    vector<string>revisions; 
    stringstream ss(version);
    string revision = "";

    while(getline(ss , revision , '.')){
        revisions.push_back(revision);

    }
    return revisions;
}

    int compareVersion(string version1, string version2) {
        vector<string>revisions1 = getRevisions(version1);
        vector<string>revisions2 = getRevisions(version2);

        for(int i = 0 ; i  < max(revisions1.size(), revisions2.size()); i++){
            int r1 = i < revisions1.size() ? stoi(revisions1[i]) : 0;
            int r2 = i < revisions2.size() ? stoi(revisions2[i]) : 0 ;

            if(r1 < r2) return -1; 
            if(r1 > r2)  return 1; 
        }
        return 0; 
    }
};