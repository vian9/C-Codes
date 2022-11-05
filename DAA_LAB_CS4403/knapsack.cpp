#include<iostream>
using namespace std;

int knapSackGreedy(int* weight, int* value, int n, int capacity) {
    double profitRatio[n];
    double profit = 0;
    int currentCapacity = 0;

    //Profit per weight ratio calculation
    for (int i = 0; i < n; i++)
    {
        profitRatio[i] = value[i] / weight[i];
    }

    //Arranging in desceding order as per profit ration
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (profitRatio[i] < profitRatio[j])
            {
                swap(profitRatio[i], profitRatio[j]);
                swap(weight[i], weight[j]);
                swap(value[i], value[j]);
            }

        }

    }

    //fill the weight in container as per profit ratio
    for (int i = 0; i < n; i++)
    {
        if (currentCapacity + weight[i] <= capacity)
        {
            currentCapacity += weight[i];
            profit += value[i];
        } else
        {
            int leftCapacity = capacity - currentCapacity;
            currentCapacity += leftCapacity;
            profit += (profitRatio[i]) * leftCapacity;
            break;
        }

    }


    return profit;
}

int main() {
    cout << endl;
    int n;
    cout << "Enter the no. of elements: ";
    cin >> n;

    int weight[n], value[n];

    cout << "Enter weight and value of each elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i] >> value[i];
    }

    int capacity;
    cout << "Enter the capacity of Knapsack:";
    cin >> capacity;

    cout << "Max profit that we can get is: " << knapSackGreedy(weight, value, n, capacity) << endl;
    return 0;
}