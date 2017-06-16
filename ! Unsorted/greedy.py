data = []
schedule =  []
def readFile(fname):
    fid = open(fname)    
    for line in fid:
        temp =[x.rstrip("\n") for x in line.split(" ")]
        data.append((temp[0],int(temp[1]),int(temp[2])))
  
def getKey(item):
    return item[2]

def  checkForCompatibility(job):
    if len(schedule) == 0:
        return True
    if job[1] <= schedule[-1][2]:
        return False
    else:
        return True


readFile("input")
data = sorted(data, key=getKey)
for job in data:
    if checkForCompatibility(job):
        schedule.append(job)
        
    


print("The Optimal Job scheduling is :")

print(len(data) - len(schedule))
# for eachJob in schedule:
#     print(eachJob)
    
