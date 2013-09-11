#include <vector>
#include <iostream>

template<typename T>
void merge(std::vector<T> & arr, const int p, const int q, const int r)
{
    if (q > p + 1)
        merge(arr, p, (p + q) / 2, q);
    if (r > q + 1)
        merge(arr, q, (q + r) / 2, r);
    std::vector<T> arr_a(arr.begin() + p, arr.begin() + q);
    std::vector<T> arr_b(arr.begin() + q, arr.begin() + r);
    for (int i = p, idx_a = 0, idx_b = 0; i < r; ++i)
        arr[i] = (arr_a[idx_a] <= arr_b[idx_b] && idx_a < q-p || idx_b >= r-q)
               ? arr_a[idx_a++] : arr_b[idx_b++];
}

template<typename T>
void merge_sort(std::vector<T> & arr)
{
    int num = arr.size();
    if (num > 1)
        merge(arr, 0, num / 2, num);
}

int main()
{
    std::vector<double> arr;
    arr.push_back(3);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(-2);
    merge_sort(arr);

    for (int i = 0; i < arr.size(); ++i)
        std::cout << arr[i] << std::endl;
    return 0;
}