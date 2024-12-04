/*

Given a string str of length N which consists of only 0, 1 or 2s, count the number of substring which
have equal number of 0s, 1s and 2s.


hint : Think of hashing . Almost same as finding no of subarrays having sum k
*/

// using map

long long getSubstringWithEqual012(string str)
{
    int diff01  , diff12 ;
    int count0 = 0 , count1 = 0 , count2 = 0 ;
    map<pair<int , int> , int > hash ;
    hash[ {0 , 0}] = 1 ;
    long long ans = 0 ;
    for (char &c : str) {
        int num = c - '0' ;
        if (num == 0 ) count0++ ;
        else if (num == 1 ) count1++ ;
        else  count2++ ;

        diff01 = count0 - count1 ;
        diff12 = count1 - count2 ;

        if (hash.find({diff01 , diff12}) != hash.end()) {
            ans += hash[ {diff01 , diff12}] ;
        }
        hash[ {diff01 , diff12}]++ ;

    }
    return ans ;


}

// using unordered_map
long long getSubstringWithEqual012(string str)
{
    int diff01  , diff12 ;
    string key ;
    int count0 = 0 , count1 = 0 , count2 = 0 ;
    unordered_map<string , int >hash ;
    hash["0|0"] = 1  ;
    long long ans = 0 ;
    for (char &c : str) {
        int num = c - '0' ;
        if (num == 0 ) count0++ ;
        else if (num == 1 ) count1++ ;
        else  count2++ ;

        diff01 = count0 - count1 ;
        diff12 = count1 - count2 ;
        key = to_string(diff01) + "|" + to_string(diff12) ;
        if (hash.find(key) != hash.end()) {
            ans += hash[key] ;
        }
        hash[key]++ ;

    }
    return ans ;


}
