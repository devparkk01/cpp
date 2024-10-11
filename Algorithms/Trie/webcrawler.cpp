/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

#include<iostream>
#include<mutex>
#include<thread>
#include<condition_variable>
#include <queue>
#include <unordered_set>
using namespace std; 

class Solution {
private:

    string extractHostName(string& url){
        int pos = url.substr(7).find('/');
        return url.substr(7 , pos) ; 
    }

public:

    vector<string> crawl(string startUrl, HtmlParser htmlParser){
        queue<string>q; 
        unordered_set<string>visited; 
        int thread_size = thread::hardware_concurrency();

        // Mutex for protecting shared data
        mutex m; 
        // Condition variable for signaling between threads
        condition_variable cv; 
        // Working keeps track of how many threads are currently executing tasks.
        int working = 0 ; 

        string hostname = extractHostName(startUrl);

        q.push(startUrl);
        visited.insert(startUrl);


        auto startCrawling = [&](){
            while(true) {
                // Lock the mutex before accessing shared data
                unique_lock<mutex> lock(m);

                // Wait until there is a URL to visit or all threads are done working
                cv.wait(lock, [&](){
                    return q.size() > 0 || (working == 0);
                });


                // cv.wait_for(lock , 20ms, [&](){
                //     return q.size() > 0; 
                // });

                if ( q.size() == 0 ){
                    return ; 
                }
                // indicate that this thread is in progress
                working++; 
                string curUrl = q.front() ; q.pop(); 

                lock.unlock();  // since getUrls can take a lot of time, release the lock.
                vector<string> urls = htmlParser.getUrls(curUrl); // crawl to get urls
                
                // Lock the mutex before accessing shared data
                lock.lock();
                for(auto &url: urls) {
                    //  if it has not been visited and it has the same hostname, add it to the queue and mark it as visited
                    if ( visited.find(url) == visited.end() && extractHostName(url) == hostname) {
                        visited.insert(url);
                        q.push(url);
                    }
                }
                working--;
                // notify all the threads either about finishing or about availability of tasks.
                cv.notify_all(); 
                lock.unlock();

            }
        };

        thread workers[thread_size];

        for(int i= 0 ; i < thread_size; ++i) {
            workers[i] = thread(startCrawling);
        }

        for(int i = 0 ; i < thread_size; ++i) {
            workers[i].join();
        }

        return vector<string>(visited.begin(), visited.end());
    }

};