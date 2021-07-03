#define ip pair<int , int>
class LRUCache {
public:
	list<ip>cache ;
	unordered_map<int , list<ip>::iterator >ump ;
	int capacity ;

	LRUCache(int capacity) {
		this->capacity = capacity  ;
	}

	int get(int key) {
		if (ump.find(key) != ump.end()) { // if key is found
			auto it = ump[key] ;
			ip temp = *it ;
			cache.erase(it) ;
			cache.push_front(temp) ;
			ump[key] = cache.begin() ;
			return temp.second ;
		}
		else return -1;

	}

	void put(int key, int value) {
		if (ump.find(key) != ump.end()) { // if key is found
			list<ip>::iterator it = ump[key] ;
			cache.erase(it) ;
			cache.push_front({key , value }) ;
			ump[key] = cache.begin() ;
		}
		else if (cache.size() ==  capacity) {
			list<ip>::iterator it = cache.end() ;
			it-- ;
			int oldkey =  (*it).first ;
			cache.erase(it) ;

			ump.erase(oldkey) ;

			cache.push_front({key , value });
			ump[key] = cache.begin() ;

			// auto it= cache.begin() ;
			// while(it != cache.end()) {
			//     cout << (*it).first << " " ;
			//     it++ ;
			// }

		}
		else {
			cache.push_front({key, value }) ;
			ump[key] = cache.begin() ;
		}



	}
};
