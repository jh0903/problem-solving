def solution(s):
    s = s.strip("{""}")

    s1 = s.split("},{")
    li = []

    chk = [False for i in range(100001)]
    ans = []

    for i in s1:
        li.append(i.split(","))
    
    li.sort(key= lambda x:len(x))

    for i in li:
        for j in i:
            if(chk[(int)(j)] is False):
                ans.append((int)(j))
                chk[(int)(j)] = True
        
    return ans