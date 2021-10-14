function majorityElement(a, size) {
    //your code here
    let charMap = {}
    let MaxNum = 0;
    let MaxChar;
    a.forEach((word) => {
        if (charMap[word]) {
            charMap[word]++;
        } else {
            charMap[word] = "-1"
        }
    })
    for (const char in charMap) {
        if (charMap[char] > MaxNum) {
            MaxNum = charMap[char]
            MaxChar = char
        }
    }
    console.log(MaxChar)
}
//console.log(majorityElement([6 ,1 ,15 ,19 ,9, 13 ,12, 6 ,7 ,2 ,10 ,4 ,1 ,14 ,11 ,14 ,14 ,13], 18))