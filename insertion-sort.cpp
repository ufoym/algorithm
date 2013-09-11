#include <vector>
#include <iostream>

template<typename T>
void insertion_sort(std::vector<T> & arr)
{
    int len_arr = arr.size();
    for (int i = 1; i < len_arr; ++i) {
        T key = arr[i];
        int j = i-1;
        for (; j >= 0 && arr[j] > key; --j) {
            arr[j+1] = arr[j];
        }
        arr[j+1] = key;
    }
}

int main()
{
    std::vector<double> arr;
    arr.push_back(3);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(-2);
    insertion_sort(arr);

    for (int i = 0; i < arr.size(); ++i)
        std::cout << arr[i] << std::endl;
    return 0;
}