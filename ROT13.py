'''

ROT13
I am going to take the ASCII value using the built in functions ord and chr.
ord converts the string to its int ASCII value and while chr turns it back into
a character. The ASCII value for a space is 32.
> 77
>
'''

'''

def ROT13(string):
    mappings = {}
    for i in range(0, 26):
        addend = (i + 13) % 26 
        mappings[i + 97] = 97 + addend
        mappings[i + 65] = 65 + addend

    def sydbo(n):
        x = mappings.get(ord(n))
        if x is None:
            return n
        else:
            return chr(x)

    sydney = ""
    for n in string:
        sydney = sydney + sydbo(n)
    return sydney

    '''
#different commit
#This is happening in the iss2 branch.
#This is for the second commit in the iss2 branch.
def ROT13(string):
    temp = ""
    for n in string:
        if (ord(n) >= 65 and ord(n) < 123):
            if (ord(n) < 91 or ord(n) > 96):#checks to see if it is apart of the ascii characters we dont want to change
                if (ord(n) < 97): #checks to see if it is a capital letter or lowercase
                    if (ord(n) > 77):
                        print(chr(ord(n) - 13))
                        temp += chr(ord(n) - 13)
                    else:
                        print(chr(ord(n) + 13))
                        temp += chr(ord(n) + 13)
                else:
                    if (ord(n) > 109):
                        print(chr(ord(n) - 13))
                        temp += chr(ord(n) - 13)
                    else:
                        print(chr(ord(n) + 13))
                        temp += chr(ord(n) + 13)
            else:
                temp += n
        else:
            temp += n
    return temp
