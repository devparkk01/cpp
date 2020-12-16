/*Given a set of N jobs where each job i has a deadline and profit associated to it.
Each job takes 1 unit of time to complete and only one job can be scheduled at a time.
We earn the profit if and only if the job is completed by its deadline. The task is to find
the maximum profit and the number of jobs done.

time : O(n*n) ,space : O(n)
*/

bool compare(Job&a , Job&b) {
    return a.profit > b.profit ;
}

pair<int, int> JobScheduling(Job arr[], int n)
{
    sort(arr , arr + n , compare ) ;
    bool slot[100] = {false}  ;
    int count = 0 , profit = 0 ;
    for (int i = 0 ; i < n ; ++i ) {
        int deadline  = arr[i].dead ;
        int j = deadline - 1 ;
        while (j >= 0 ) {
            if ( slot[j] == false ) {// book the slot for ith job
                slot[j] = 1 ;
                count++ ;
                profit += arr[i].profit ;
                break  ;
            }
            j-- ;
        }

    }

    return {count , profit } ;

}
