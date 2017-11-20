def allocreg():
    global regset
    for i in range(len(regset)):
        if regset[i]:   return i
    print("Out of registers :(")
    return -1

def simpleoperators(op, arg1, arg2, res):
    reg = allocreg()
    if reg == -1:   return 1
    if "tmp" not in arg1 and "tmp" not in arg2:
        outfile.write("MOV "+arg1+", R"+str(reg)+"\n")
        outfile.write(op+" "+arg2+", R"+str(reg)+"\n")
    elif "tmp" in arg1 and "tmp" not in arg2:
        outfile.write("MOV R"+str(vartoreg[arg1])+", R"+str(reg)+"\n")
        outfile.write(op+" "+arg2+", R"+str(reg)+"\n")
    elif "tmp" not in arg1 and "tmp" in arg2:
        outfile.write("MOV R"+str(vartoreg[arg2])+", R"+str(reg)+"\n")
        outfile.write(op+" "+arg1+", R"+str(reg)+"\n")
    else:
        outfile.write("MOV R"+str(vartoreg[arg1])+", R"+str(reg)+"\n")
        outfile.write(op+" "+str(vartoreg[arg2])+", R"+str(reg)+"\n")
    vartoreg[res] = reg
    return 0
        
inputfile = open('threeaddresscode.txt')
outfile = open('assemblycode.m','w')
intermidiatecode = inputfile.read().split("\n")
print((len(intermidiatecode), intermidiatecode[0]))
curline = 0
regset = [True for n in range(128)]
vartoreg = {}

while True:
    while ":" in intermidiatecode[curline]: curline += 1
    if "end" in intermidiatecode[curline]:  break
    print((curline,intermidiatecode[curline]))
    op, arg1, arg2, res = intermidiatecode[curline].split(",")
    val = 0 
    if "+" in op:   val = simpleoperators("ADD", arg1, arg2, res)
    if "-" in op:   val = simpleoperators("SUB", arg1, arg2, res)
    if "*" in op:   val = simpleoperators("MULT", arg1, arg2, res)
    if "/" in op:   val = simpleoperators("DIV", arg1, arg2, res)
    if(val):    break
    curline += 1
outfile.close()
            
        
            
            

