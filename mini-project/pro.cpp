#include <iostream>
#include <iomanip>
using namespace std;


void displayArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}


void selectionSort(int arr[], int n, int &swaps, int &writes, int &comparisons)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            comparisons++;

            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;

            swaps++;
            writes += 3; // temp + two assignments
        }
    }
}

int main()
{
    int n;

    cout << "=========================================\n";
    cout << " CASE STUDY 12: MEMORY-CONSTRAINED SYSTEM\n";
    cout << "=========================================\n";
    cout << "Objective: Sort data with minimum writes\n";
    cout << "Algorithm Used: Selection Sort\n\n";

    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid input!\n";
        return 0;
    }

    int arr[n];

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int swaps = 0, writes = 0, comparisons = 0;

    cout << "\nOriginal Dataset:\n";
    displayArray(arr, n);

    selectionSort(arr, n, swaps, writes, comparisons);

    cout << "\nSorted Dataset:\n";
    displayArray(arr, n);

    cout << "\n=========== PERFORMANCE REPORT ===========\n";
    cout << left << setw(25) << "Comparisons:" << comparisons << endl;
    cout << left << setw(25) << "Swaps:" << swaps << endl;
    cout << left << setw(25) << "Memory Writes:" << writes << endl;

    cout << "\n=========== OUTCOME ======================\n";
    cout << "✔ Reduced unnecessary swaps\n";
    cout << "✔ Low memory write operations\n";
    cout << "✔ Suitable for embedded hardware systems\n";
    cout << "✔ Efficient when writes are expensive\n";

    return 0;
}