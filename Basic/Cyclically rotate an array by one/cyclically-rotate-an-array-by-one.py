#User function Template for python3

def rotate( arr, n):
    # get the last element from array
    last=arr.pop(-1)
    # insert(idx,element to be inserted)
    return arr.insert(0,last)
    



#{ 
 # Driver Code Starts
#Initial Template for Python 3

def main():

    T = int(input())

    while(T > 0):
        n = int(input())
        a = [int(x) for x in input().strip().split()]
        rotate(a, n)
        print(*a)

        T -= 1


if __name__ == "__main__":
    main()





    
# } Driver Code Ends