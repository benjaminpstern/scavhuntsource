from os.path import join
import sys
def main():
    if len(sys.argv) < 2:
        print("please enter a directory")
        exit()
    directory = sys.argv[1]
    fileno = 1
    current = []
    for line in sys.stdin:
        if line == "-----\n":
            filename = join(directory, "cookie"+str(fileno))
            f = open(filename, "w")
            f.writelines(current)
            f.close()
            current = []
            fileno += 1
        else:
            current.append(line)

main()
