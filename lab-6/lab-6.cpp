#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) { //сделал максимально по канону ДП(разделяем + сохраняем резы)
    int len = height.size();
    vector<int> l_max_height(len, 0); //храним макс высоту для кажого столба(i)
    vector<int> r_max_height(len, 0);


    l_max_height[0] = height[0]; //сперва заполняем макс лев. высоту => идем вперед 
    for (int i = 1; i < len; i++) {
        l_max_height[i] = max(l_max_height[i - 1], height[i]);
    }

    
    r_max_height[len - 1] = height[len - 1]; // заполняем правые высоты => идем назад
    for (int i = len - 2; i >= 0; i--) {
        r_max_height[i] = max(r_max_height[i + 1], height[i]);
    }


    int val_of_water = 0; //ответ
    for (int i = 0; i < len; i++) { //идем по каждому столбу
        val_of_water += max(0, min(l_max_height[i], r_max_height[i]) - height[i]); //идет сбор для каждого столбца 
    }

    return val_of_water;
}


};





int main(){
    Solution test;
    vector<int> arr = {0,1,0,2,1,0,1,3,2,1,2,1};
    int ans = test.trap(arr);
    cout << ans;
    return 0;
}