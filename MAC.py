import hashlib

charsDict = {i: chr(i+65) for i in range(0, 26)}


def encrypt(plainText, K):
    cipherText = ''
    for i in plainText:
        if i.isnumeric():
            cipherText += i
            continue
        letterIndex = ord(i.upper()) - 65
        tempkey = (letterIndex + K) % 26
        if i.islower():
            cipherText += charsDict[tempkey].lower()
        else:
            cipherText += charsDict[tempkey]
    return cipherText


def decrypt(cipherText, K):
    plainText = ''
    for i in cipherText:
        if i.isnumeric():
            plainText += i
            continue
        letterIndex = ord(i.upper()) - 65
        tempkey = (letterIndex - K) % 26
        if i.islower():
            plainText += charsDict[tempkey].lower()
        else:
            plainText += charsDict[tempkey]
    return plainText


def verify(M, K):
    recv = decrypt(M, K)

    msgR, shaRecv = recv.split("xx")
    shaC = hashlib.sha256(msgR.encode()).hexdigest()

    print("\nSHA256 Calculated :", shaC)
    print("SHA256 Recieved :", shaRecv)
    if shaRecv == shaC:
        print(f"\nHence,\nMessage {msgR} Is Not Corrupted")
    else:
        print(f"\nHence,\nMessage {msgR} Is Corrupted")


msg = input("Enter Message :: ").replace(" ", "")
key = int(input("Enter The Key :: "))
sha = hashlib.sha256(msg.encode()).hexdigest()
send = encrypt(msg + "xx" + sha, key)
verify(send, key)
