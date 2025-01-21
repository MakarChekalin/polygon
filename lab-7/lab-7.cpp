#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int minNumberOperations(vector<int>& target) {
//        vector new_list;
        int answer = 0;
        for(size_t i = 0; i < target.size(); i++){
            if(i == 0){
                answer += target[i]; // т к нам 100% надо его заполнить
            }
            else{ // в остальных случаях мы ищем возрастающие участки(только они влияют на ответ)
                answer += max(0, target[i] - target[i - 1]);
            }
        }
        return answer;
    }
};

int main() {
    Solution test;
    vector<int> target = {1, 2, 3, 2, 1};
    cout << test.minNumberOperations(target);;


    return 0;
}
