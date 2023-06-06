''' To create ADT that implements the "set" concept. a]Add (new element) - Place a value into the set b]Remove (element) c]Contains 
d]Size e]Intersection f]Union g]Difference h]Subset '''

set1=[]
set2=[]

def accept():
    n=(int(input("Enter number of elements to be accepted: ")))
    for i in range(n):
        m=(int(input("Enter the elements: ")))
        set1.append(m)
    print("The set is: ",set1)

def removeno(set1):
    n=int(input("Enter the number to be removed from set: "))
    for i in (set1):
        if(i==n):
            set1.remove(n)
            print("Displayed elements are: ",set1)
            break
    print("Element not present in the list")

def contains(set1):
    m=int(input("Enter the element to check the set contains it or not: "))
    if m in set1 :
        print("Set contains the entered element ")
    else:
        print("Element not present in the list")

def size(set1):
    count=0
    for i in set1 :
        count+=1
    print("The size of set is: ",count)

def iterate(set1):
    iterator=iter(set1)
    print("The elements in the set are: ")
    for i in range(len(set1)):
        print(next(iterator))
        
def intersection(set1,set2):
    itsec=[]
    for i in set1:
        for j in set2:
            if(i==j):
                itsec.append(i)
    print("The intersection of set is: ",itsec)

def union(set1,set2):
    uni=[]
    uni.extend(set1)
    for i in set2:
        if i not in set1:
            uni.append(i)
    print("Union of two sets is: ",uni)

def difference(set1,set2):
    diff=[]
    for i in set1:
        if i not in set2:
            diff.append(i)
    print("Set1 - Set2 = ",diff)

def subset(set1,set2):
    subset=True
    for i in set2:
        if i not in set1:
            subset=False
    if subset==False:
        print("set2 is not subset of set1")
    else:
        print("set2 is subset of set1")

def main():
    n=int(input("Enter the number of elements in SET1: "))
    for i in range(n):
        set1.append(int(input("Enter the Set1 elements:")))
    ch=0
    for i in range(7):
        print(" Set Operations")
        print(" 1. Accept element in a set")
        print(" 2. Remove element from a set")
        print(" 3. Search element ")
        print(" 4. Find size of set")
        print(" 5. Iterator function")
        print(" 6. Set operations")
        print(" 7. EXIT")
        ch = int(input("\n Enter your choice: "))
        while True:
            if ch==1:
                accept()
                break
            elif ch==2:
                removeno(set1)
                break
            elif ch==3:
                contains(set1)
                break
            elif ch==4:
                size(set1)
                break
            elif ch==5:
                iterate(set1)
                break
            elif ch== 6:
                a=int(input("Enter the number of elements in SET2: "))
                for i in range(a):
                    set2.append(int(input("Enter the Set2 elements:")))
                for i in range(5):
                    print("**********Set Operations:************* ")
                    print("1) Intersection of Sets")
                    print("2) Union of Sets")
                    print("3) Difference of Sets")
                    print("4) Subset of a Set")
                    print("5) Exit")
                    choice=int(input("Enter your choice: "))
                    while True:
                        if choice==1:
                            intersection(set1,set2)
                            break
                        elif choice ==2:
                            union(set1,set2)
                            break
                        elif choice ==3:
                            difference(set1,set2)
                            break
                        elif choice==4:
                            subset(set1,set2)
                            break
                        else:
                            print("Exit")
                            break
            else:
                print("-----EXIT-----")
                break
main()