// 1912. Design Movie Rental System


class MovieRentingSystem {
public:
unordered_map<int , set<pair<int , int>>>unrented_movie_price_shop; 
unordered_map<int , set<pair<int , int>>>movie_shop_price; 
set<pair<int , pair<int , int>>>rented_price_shop_movie; 

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto &entry : entries){
            int shop = entry[0];
            int movie = entry[1];
            int price = entry[2];

            unrented_movie_price_shop[movie].insert({price, shop});
            movie_shop_price[movie].insert({shop , price});
        }
    }
    
    vector<int> search(int movie) {
         vector<int>result ; 
          int count = 0 ; 
         

          for(auto &s : unrented_movie_price_shop[movie] ){
               result.push_back(s.second);
               count++;
                 if(count == 5) break; 
          }
          return result; 
    }
    
    void rent(int shop, int movie) {
        auto priceit = movie_shop_price[movie].lower_bound({shop , INT_MIN});
        int price = priceit->second; 

        unrented_movie_price_shop[movie].erase({price, shop });
        rented_price_shop_movie.insert({price, {shop ,movie}});
        
    }
    
    void drop(int shop, int movie) {
         auto priceit = movie_shop_price[movie].lower_bound({shop , INT_MIN});
        int price = priceit->second; 

        unrented_movie_price_shop[movie].insert({price, shop });
        rented_price_shop_movie.erase({price, {shop ,movie}});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>>result; 
        int count = 0 ; 
        for(auto &s : rented_price_shop_movie){
            result.push_back({s.second.first, s.second.second});
            count++;
             if(count == 5){
                break;
            }
        }
        return result; 
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */