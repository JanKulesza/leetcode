class Solution {
public:
    void quicksort(vector<int>& arr, int l, int r) {
        if(l >= r)
            return;
        int pivot = arr[(l + r) / 2];
        int i = l;
        int j = r;
        while(i <= j) {
            while(arr[i] < pivot) i++;
            while(arr[j] > pivot) j--;

            if(i <= j) {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }
        quicksort(arr, l, j);
        quicksort(arr, i, r);
    }
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        quicksort(asteroids, 0, asteroids.size() - 1);
        unsigned long long sum = mass;
        for(int i = 0; i < asteroids.size(); i++) {
            if(sum < asteroids[i])
                return false;
            sum += asteroids[i];            
        }
        return true;
    }
};