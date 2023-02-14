'''
This is a code for number to char  
Written by Keith Lin 
Date : 2022 / 4 /27 
'''
dic = {1: 'c', 2: 'd', 3: 'e', 4: 'f', 5: 'g', 6: 'a', 7: 'b', 8: 'c*'}
inp = str(input("code: "))
inp = list(map(int, inp.split()))
ans = [dic[i] for i in inp]
print('\"'+' '.join(ans)+'\"')f