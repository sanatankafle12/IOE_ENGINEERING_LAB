def dequeque(page_sequence):
    page_sequence.remove(page_sequence[0])

def page_replacement(page_sequence,n):
    page = []
    hit = 0
    for i in page_sequence:
        if(len(page)<3):
            if(i not in page):
                page.append(i)
            else:
                hit+=1
        else:
            if(i not in page):
                dequeque(page)
                page.append(i)
            else:
                hit+=1
            
    print(page_sequence)
    print("Hit = ",hit)
    print("Hit Ratio= ",hit/n)
    print(page)

if __name__ == "__main__":
    n = int(input("Enter Number of page sequences. "))
    page_sequence = []
    for i in range(n):
        input1 = int(input(""))
        page_sequence.append(input1)
    page_replacement(page_sequence,n)