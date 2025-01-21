#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int test_passed = 0;
int test_failed = 0;



vector<int> cocktail_sort(vector<int> arr){
    bool is_sorted = false; // флаг сортировки(чтоб лишних мувов не делать)
    int arr_len = arr.size();
    int start = 0;
    int end = arr_len - 1;

    while (is_sorted == false)
    {   
        is_sorted = true;

        for(int i = start; i < end; i++){
            if(arr[i] > arr[i + 1]){
                swap(arr[i], arr[i + 1]);
                is_sorted = false;
            }
        }
        end--; // сужаем отрезок 

        if(is_sorted == true){
            break;
        }

        is_sorted = true;

        for(int i = end; i > start; i--){ // идем обратно
            if(arr[i] < arr[i - 1]){ // тут другой знак т к идем обратно
                swap(arr[i], arr[i - 1]);
                is_sorted = false;
            }
        }

        start++; // сужаем отрезок 

        

    }



    return arr;
}




void assertEqual(vector<int> finded_lists, vector<int> expected_list, const std::string& testName) {
    if (finded_lists == expected_list) {
        std::cout << "[PASSED]" << testName << "\n";
        test_passed++;
    } else {
        std::cout << "[NOT PASSED]" << testName << "\n";
        test_failed++;
    }
}



void report(){
    std::cout << "\nPassed tests: " << test_passed << "\n";
    std::cout << "\nFailed tests: " << test_failed << "\n";
} 






int main(){
    assertEqual(cocktail_sort({340, 185, 981, 932, 171, 102, 639, 954, 292, 581}), {102, 171, 185, 292, 340, 581, 639, 932, 954, 981}, "Test 1");

    assertEqual(cocktail_sort({1, 1, 1, 1, 1}), {1, 1, 1, 1, 1}, "Test 2");

    assertEqual(cocktail_sort({}), {}, "Test 3");

    assertEqual(cocktail_sort({0}), {0}, "Test 4");

    report();
    return 0;
}