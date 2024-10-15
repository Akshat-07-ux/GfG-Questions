#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends
#User function Template for python3

def check_status(a, b, flag):
    # Case 1: Either a or b (but not both) is non-negative and flag is False
    if (a >= 0 and b < 0 or a < 0 and b >= 0) and not flag:
        return True
    
    # Case 2: Both a and b are negative and flag is True
    if a < 0 and b < 0 and flag:
        return True
    
    # Otherwise, return False
    return False

#{ 
 # Driver Code Starts.

# Driver Code
def main():
    
    # Testcase input
    testcases = int(input())
    
    # Looping through testcases
    while(testcases > 0):
        a = int(input())
        b = int(input())
        flag = input()
        
        if(flag == "True"):
            flag = True
        else:
            flag = False
        
        if(check_status(a, b, flag) is True):
            print ("True")
        else:
            print ("False")
        
        testcases -= 1
 
if __name__ == '__main__':
    main()
# } Driver Code Ends