// 3136. Valid Word


// Approach 1 
class Solution {
public:
bool isVowel(char ch){
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch == 'u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch == 'U' ) return true; 
    else return false; 
}

bool isSpecialCh(char ch){
     if(ch == '@' || ch == '#' || ch == '$') return true; 
     return false; 
}

bool isConsonant(char ch){
    if(isVowel(ch)) return false; 
    if(ch >= 'a' && ch <= 'z'  )  return true; 
    if(ch >= 'A' && ch <= 'Z') return true; 
    return false;
}
    bool isValid(string word) {
        int n = word.length();
        if(n < 3) return false; 

        bool vowel = false; 
        bool consonent = false; 

        for(int i = 0 ; i <n; i++){
            char ch =  word[i];

            if(isSpecialCh(ch)) return false;
          
           if(isVowel(ch)){
                vowel = true; 
            }
           if(isConsonant(ch)) consonent = true; 
        }

    

        if(vowel && consonent) return true; 
        return false; 
    }
};








//Approach 2 
class Solution {
public:
bool isVowel(char ch ){
    return (ch=='a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') ;
}

    bool isValid(string word) {
        int n =  word.length();
        if(n < 3  ) return false; 

        int vowel = false; 
        int consonant = false; 

        for(int i = 0 ; i  <n; i++){
            char ch = word[i];

            if(isalnum(ch)){
                ch = tolower(ch);
                if(isVowel(ch)) vowel = true; 
                else if(!isdigit(ch)){
                    consonant = true; 
                }

            }
            else  return false; 
        }

     

        return (vowel && consonant); 
    }
};