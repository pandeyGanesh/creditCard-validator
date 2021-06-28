from os import write


namesFile = 'Names'
rangesFile = 'Range'
writeFile = 'commands.txt'
command='root.search'

wF = open(writeFile,"w")

with open(namesFile) as nF:
    namesData = nF.readlines()

with open(rangesFile) as rF:
    rangeData = rF.readlines()

for index in range(len(namesData)):
    ranges = rangeData[index].strip().split(',')
    for rng in ranges:
        if( '-' in rng ):
            x=rng.split('-')
            frm = int(x[0])
            to = int(x[1])
            for z in range(frm, to):
                message='cout<<"' + str(z) + '\\t"<<' + command + '("' + str(z) + '")<<endl;\n' 
                print(message)
                wF.write(message)
                #wF.write('cout<<','"',z,'\\t"<<',command,'("',z,'")','<<endl;\n')
                #print('cout<<','"',z,'\\t"<<',command,'("',z,'")','<<endl;',sep='')    
                #print(command,'("',number,'");',sep='')
        else:
            message='cout<<"'+str(rng.strip())+'\\t"<<'+command+'("'+str(rng.strip())+'")<<endl;\n' 
            wF.write(message)
            print(message)
            #wF.write('cout<<','"',rng.strip(),'\\t"<<',command,'("',rng.strip(),'")','<<endl;\n')
            #print('cout<<','"',rng.strip(),'\\t"<<',command,'("',rng.strip(),'")','<<endl;',sep='')

wF.close()