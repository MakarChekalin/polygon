import numpy as np
import time



#:np.array лучше чем списки python(т к реализованы на C)
#np.intersect1d - эта функция возвращает общие элементы 



def main(arr1:np.array, arr2:np.array):
    start_time = time.time() #как оказалось не нужно т к выполняется за 0.0000000000000000000000000000000001
    common_val = np.intersect1d(arr1, arr2)
    return [float(start_time - time.time()), common_val]



def generate_random_arr(len: int = 10, start_point: int = 0, end_point: int = 1000): #для тестов(+ тоже есть numpy)
    random_arr = np.random.randint(start_point, end_point + 1, size=len)
    return np.array(random_arr)



if __name__ == "__main__":
    arr1 = generate_random_arr(len = 10000000)
    arr2 = generate_random_arr(len = 10000000)
    answer = main(arr1,arr2)
    print(f"Answer = {answer[1]} Time = {answer[0]}")