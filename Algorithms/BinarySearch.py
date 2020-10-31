list = [1,44,30,66,55,77,88,99,111]
searchfor = eval(input("Enter the element for search:"))
flag = 0
low = 0
high = len(list)-1
while low<= high :
                mid = (low+high)//2
                if searchfor == list[mid] :
                                 flag = 1
                                 position = mid+1
                                 break
                else :
                                 if searchfor > list[mid] :
                                                      low = mid+1
                                 else:
                                                      high = mid-1
if flag == 1 :
               print(searchfor,"is in the List in postion:",position)
else :
    print(searchfor,"is not in the List")