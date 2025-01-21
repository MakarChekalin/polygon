#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int test_passed = 0;
int test_failed = 0;



vector<int> comb_sort(vector<int> arr){
    int len = arr.size();

    float kf = 1.3; // кэф уменьшения

    int shag = len - 1; // шаг 

    bool is_sorted = false; // флаг

    while (is_sorted == false)
    {   
        shag /= kf;
        if(shag <= 1){
            shag = 1;
            is_sorted = true;
        }

        for(int i = 0; i < len - shag; i++){
            if(arr[i] > arr[i + shag]){
                swap(arr[i], arr[i + shag]);
                is_sorted = false; // что бы пузырьковая сортировка прошлась еще раз
            }
        
        }
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
    assertEqual(comb_sort({340, 185, 981, 932, 171, 102, 639, 954, 292, 581}), {102, 171, 185, 292, 340, 581, 639, 932, 954, 981}, "Test 1");

    assertEqual(comb_sort({1, 1, 1, 1, 1}), {1, 1, 1, 1, 1}, "Test 2");

    assertEqual(comb_sort({}), {}, "Test 3");

    assertEqual(comb_sort({0}), {0}, "Test 4");

    report();
    return 0;
}

// средний случай O(N log(n))
// худший случай O(n^2)
// пространственная сложность O(1)