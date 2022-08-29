counter = 2 
nameTemplate = "test9x9_{}.txt"
with open("list.txt", 'r') as f:
    for line in f:
        if "Grid" in line:
            counter += 1
            fileName = nameTemplate.format(counter)
            tmpFile = open(fileName, 'w')
            tmpFile.write("9 9\n")
        else:
            tmpFile.write(" ".join(line))
            

