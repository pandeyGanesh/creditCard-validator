namesFile = 'Names'
rangesFile = 'Range'
command='root.insert'
with open(namesFile) as nF:
    namesData = nF.readlines()

with open(rangesFile) as rF:
    rangeData = rF.readlines()

for index in range(len(namesData)):
    companyName = namesData[index].strip()
    ranges = rangeData[index].strip().split(',')
    for range in ranges:
        if( '-' in range ):
            x=range.split('-')
            print(command,'("',companyName,'","',x[0].strip(),'","',x[1].strip(),'");',sep='')
        else:
            print(command,'("',companyName,'","',range.strip(),'","',range.strip(),'");',sep='')