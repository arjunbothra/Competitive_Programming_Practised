#include<bits/stdc++.h>
using namespace std;

class heap{
    public:
        int arr[100];
        int size;
        
        heap(){
            arr[0] = -1;
            size = 0;
        }

        void insert(int val){
            size = size + 1;
            int index = size;
            arr[index] = val;

            while(index>1){
                int parent = index / 2;

                if(arr[parent] < arr[index]){
                    swap(arr[parent], arr[index]);
                    index = parent;
                }
                else
                    return;
            }
        }

        void deletefromHeap()
    {   
        if(size==0){
            cout << "Nothing to print" << endl;
            return;
        }

        arr[1] = arr[size];
        size = size - 1;
        int leftIndex, rightIndex, i = 1;
        while(i<=size){
            leftIndex = 2 * i;
            rightIndex = (2 * i) + 1;
            
            if(rightIndex<=size && arr[leftIndex]>arr[i]&& arr[leftIndex]>arr[rightIndex]){
                swap(arr[leftIndex], arr[i]);
                i = leftIndex;
            }
            else if(leftIndex<=size && arr[rightIndex]>arr[i] && arr[rightIndex]>arr[leftIndex]){
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else
                return;
        }
    }

    
        void print(){
            for (int i = 1; i <= size; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

void heapify(int arr[], int size, int i){
    int largest = i;
    int leftIndex = 2 * i;
    int rightIndex= 2 *i + 1;
        
        if(leftIndex<=size && arr[leftIndex]>arr[largest]){
            largest = leftIndex;
        }
        if(rightIndex<=size && arr[rightIndex]>arr[largest]){
            largest = rightIndex;
        }

        if(largest != i){
            swap(arr[largest], arr[i]);
            heapify(arr, size, largest);
        }
    }


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // heap h;
    // h.insert(55);
    // h.insert(53);
    // h.insert(54);
    // h.insert(52);
    // h.insert(50);
    // h.print();
    // h.deletefromHeap();
    // h.print();

    int arr[6]={-1, 54, 53, 52, 50, 55};
    int n = 5;
    for(int i = n / 2; i > 0; i--){
        heapify(arr, n, i);
    }

    for (int i = 1; i <= n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
