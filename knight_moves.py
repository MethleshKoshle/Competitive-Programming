#valid knight moves
n, m = 4, 5
def moves(x, y):
    global n, m
    lst=0
    if x+2<n:
        if y-1>-1:
            lst+=1
        if y+1<m:
            lst+=1
    if x-2>-1:
        if y-1>-1:
            lst+=1
        if y+1<m:
            lst+=1
    if y+2<m:
        if x-1>-1:
            lst+=1
        if x+1<n:
            lst+=1
    if y-2>-1:
        if x-1>-1:
            lst+=1
        if x+1<n:
            lst+=1
    return lst
