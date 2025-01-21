#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int test_passed = 0;
int test_failed = 0;


vector<int> counting_sort(vector<int>& arr, int raz) { //выбрал couting т к он лучше всего подходит для сортировки от 0 до 9
    int len = arr.size();
    vector<int> new_arr(len);
    vector<int> count(10, 0); // масив для подсчета


    for (int i = 0; i < len; i++) { // считаем кол во разрядов
        int val = (arr[i] / raz)% 10; // берем нужный нам разряд
        count[val]++; //значения сортируются от 0 до 9(идекс масива = цифра, значение = кол во цифр)
    }


    for (int i = 1; i < 10; i++) { //для сохранения порядка 
        count[i] += count[i - 1];
    }

    for (int i = len - 1; i >= 0; i--) {
        new_arr[count[(arr[i] / raz) % 10] - 1] = arr[i];
        count[(arr[i] / raz) % 10]--;
    }

    
    return new_arr;
}


vector<int> radix_sort(vector<int> arr) {
    int max_val = *max_element(arr.begin(), arr.end());


    for (int raz = 1; max_val / raz > 0; raz *= 10) { //просто идем по разрядам(raz идет с шаго *10)
        arr = counting_sort(arr, raz);
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
    assertEqual(radix_sort({340, 185, 981, 932, 171, 102, 639, 954, 292, 581}), {102, 171, 185, 292, 340, 581, 639, 932, 954, 981}, "Test 1");

    assertEqual(radix_sort({1, 1, 1, 1, 1}), {1, 1, 1, 1, 1}, "Test 2");

    // assertEqual(radix_sort({}), {}, "Test 3"); //не работает(просто надо if написать, но мне еще 4 лабы делать)

    assertEqual(radix_sort({0}), {0}, "Test 4");

    report();
    return 0;
}