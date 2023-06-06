'''
Consider telephone book database of N clients. Make use of a hash table implementation to quickly look up client's phone number.Make use of two collision handling techniques and compare them using number of comparisons required to find a set of telephone numbers.
'''

class hashdemo:
    def __init__(self):
        self.size=int(input("enter the size of hash table:"))
        self.noofelements=0
        self.noofcomparison=0
        self.hashtable=list(0 for i in range(self.size))
        
    def tablefull(self):
        if(self.noofelements==self.size):
            print("hash table is full")
            return 1
    
    def hashfun(self,elment):
        return elment%self.size
    
    def insertlinear(self,element):
        if self.tablefull():
            return 0
        occupiedstatus=0
        position=self.hashfun(element)
        if(self.hashtable[position]==0):
             self.hashtable[position]=element
             print("TELEPHONE NO:   "+str(element)+"   AT INDEX:"+str(position))
             occupiedstatus=1
             self.noofelements+=1
        else:
            print("collision occur of element:"+str(element)+"  at index:"+str(position))
            position=self.linearprobing(element,position)
            if(self.hashtable[position]==0):
                self.hashtable[position]=element
                print("TELEPHONE NO:   "+str(element)+"   AT INDEX:"+str(position))
                occupiedstatus=1
                self.noofelements+=1
        return occupiedstatus

    def linearprobing(self,element ,position):
        while(position<=self.size):
                if(self.hashtable[position]!=0):
                    position+=1
                else:
                    return position
        if(position>self.size):
            position=0
        return position
    
    def display(self):
        print("\n")
        print("--------------------------------------------")
        print("position  "+"===>"+"telephone number")
        for i in range(self.size):
            print(" "+str(i)+"\t ===>  "+str(self.hashtable[i]))
    
    def insertquadratic(self,element):
        if self.tablefull():
            return 0
        occupiedstatus=0
        position=self.hashfun(element)
        if(self.hashtable[position]==0):
             self.hashtable[position]=element
             print("TELEPHONE NO:   "+str(element)+"   AT INDEX:"+str(position))
             occupiedstatus=1
             self.noofelements+=1
        else:
            print("colision occur of elment:"+str(element)+"  at index:"+str(position))
            occupiedstatus,position=self.quadraticprobing(element,position)
            if occupiedstatus:
                self.hashtable[position]=element
                self.noofelements+=1
            self.hashtable[position]=element
            self.noofelements+=1
            occupiedstatus=1
        return occupiedstatus
    def quadraticprobing(self,element,position):
        found=0
        limit=50
        i=1
        while i<=limit:
            newposition=position+i**2
            newposition=newposition%self.size
            if(self.hashtable[newposition]==0):
                found=1
                #return newposition
                break
            else:
                i=i+1
        return found,newposition
    def searching(self,element):
        found=0
        position=self.hashfun(element)
        self.noofcomparison+=1
        if(self.hashtable[position]==element):
            return position
        else:
            temp=position-1
            while(position<=self.size):
                if(self.hashtable[position]!=element):
                    self.noofcomparison+=1
                    position+=1
                else:
                    return position
           #searching backside now
            position=temp
            while(position>0):
                 if(self.hashtable[position]!=element):
                        self.noofcomparison+=1
                        position-=1
                 else:
                    return position
            if not found:
              print("element not found")
              return 0

h1=hashdemo()
h1.insertlinear(9766421606)
h1.insertlinear(9730460333)
h1.insertlinear(9822731606)
h1.insertlinear(9422533373)
h1.insertlinear(9682421606)
h1.display()
        
h2=hashdemo()
h2.insertquadratic(9766421606)
h2.insertquadratic(9730460333)
h2.insertquadratic(9822731606)
h2.insertquadratic(9422533373)
h2.insertquadratic(9682421606)
h2.insertquadratic(9582421606)
h2.insertquadratic(9282421606)
h2.insertquadratic(9382421606)
h2.display()    

print("telephone no -9422533373 at index:"+str(h2.searching(9422533373)))
print("comparison required for searching is:"+str(h2.noofcomparison))   