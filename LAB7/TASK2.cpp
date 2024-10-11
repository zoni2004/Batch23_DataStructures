#include <iostream>
#include <string>
using namespace std;

class Runner {
public:
    string name;
    int finishTime;  

    Runner() {}  

    Runner(string n, int t) {
        name = n;
        finishTime = t;
    }
};

void merge(Runner* arr, int left, int mid, int right) {
    int n1 = mid - left + 1;  
    int n2 = right - mid;   

    Runner L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].finishTime <= R[j].finishTime) {
            arr[k] = L[i];
            i++;
        } 
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(Runner* arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    const int totalRunners = 10;  
    const int topRunners = 5;    
    Runner runners[totalRunners]; 

    for (int i = 0; i < totalRunners; i++) {
        string name;
        int finishTime;

        cout << "Enter name of participant " << i + 1 << ": ";
        cin >> name;
        cout << "Enter finish time of " << name << " in seconds: ";
        cin >> finishTime;

        runners[i] = Runner(name, finishTime);
    }

    mergeSort(runners, 0, totalRunners - 1);


    cout << "\nTop " << topRunners << " fastest runners:\n";
    for (int i = 0; i < topRunners; i++) {
        cout << i + 1 << ". " << runners[i].name << " - " << runners[i].finishTime << " seconds\n";
    }

    return 0;
}
