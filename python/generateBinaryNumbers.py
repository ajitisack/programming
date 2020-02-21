
def generatePrintBinary(n):
    
    import queue
    q = queue.Queue()
    q.put("1")
    
    while(n>0):
        n-= 1
        s1 = q.get()
        print(s1)
        q.put(s1+"0")
        q.put(s1+"1")

generatePrintBinary(10)
