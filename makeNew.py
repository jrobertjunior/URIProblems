import sys
import os


path = sys.argv[1] + " - " + sys.argv[2]
templatePath = "Templates/"
fileName = "main.cpp"

makeFileContent = "makeFile: main.cpp\n\tg++ -std=c++11 main.cpp -o main"

print "Creating path: " + path

if not os.path.exists(path):
        mainTemplate = open(templatePath+"main.cpp", "r")
        os.makedirs(path)
        main = open(path + "/" + fileName, "w")
        main.write(mainTemplate.read())
        mainTemplate.close()
        main.close()

        runTemplate = open(templatePath+"run.sh", "r")
        runMe = open(path + "/run.sh", "w")
        runMe.write(runTemplate.read())
        runTemplate.close()
        runMe.close()
        

        makeFile = open(path + "/makefile", "w")
        makeFile.write(makeFileContent)
        makeFile.close()
        
        inputFile = open(path + "/in.data", "w")
        inputFile.close()
        
else : 
    print "Test already exists"



