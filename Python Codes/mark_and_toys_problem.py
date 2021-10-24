def maximumToys(prices, k):
    total=0
    cost=0
    prices.sort()
    for x in prices:
        if((cost+x)<k):
            cost=x+cost
            total=total+1
                
            
            
    return(total)
